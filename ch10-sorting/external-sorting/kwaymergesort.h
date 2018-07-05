/****************************************************************************
   kwaymergesort.h (c) 2009,2010,2011 Aaron Quinlan
   Center for Public Health Genomics
   University of Virginia
   All rights reserved.

   MIT License

****************************************************************************/
#ifndef KWAYMERGESORT_H
#define KWAYMERGESORT_H

#include <iostream>
#include <fstream>
#include <algorithm>
#include <stdlib.h>
#include <string.h>
#include <sstream>
#include <vector>
#include <queue>
#include <cstdio>
#include <errno.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <libgen.h> //for basename()
using namespace std;

bool isRegularFile(const string &filename);
// STLized version of basename()
// (because POSIX basename() modifies the input string pointer)
// Additionally: removes any extension the basename might have.
std::string stl_basename(const std::string &path);

template <class T>
class MERGE_DATA
{

  public:
	// data
	T data;
	istream *stream;
	bool (*compFunc)(const T &a, const T &b);

	// constructor
	MERGE_DATA(const T &data,
			   istream *stream,
			   bool (*compFunc)(const T &a, const T &b))
		: data(data),
		  stream(stream),
		  compFunc(compFunc)
	{
	}

	// comparison operator for maps keyed on this structure
	bool operator<(const MERGE_DATA &a) const
	{
		// recall that priority queues try to sort from
		// highest to lowest. thus, we need to negate.
		return !(compFunc(data, a.data));
	}
};

//************************************************
// DECLARATION
// Class methods and elements
//************************************************
template <class T>
class KwayMergeSort
{

  public:
	// constructor, using custom comparison function
	KwayMergeSort(const string &inFile,
				  ostream *out,
				  bool (*compareFunction)(const T &a, const T &b) = NULL,
				  int maxBufferSize = 1000000,
				  bool compressOutput = false,
				  string tempPath = "./");

	// constructor, using T's overloaded < operator.  Must be defined.
	KwayMergeSort(const string &inFile,
				  ostream *out,
				  int maxBufferSize = 1000000,
				  bool compressOutput = false,
				  string tempPath = "./");

	// destructor
	~KwayMergeSort(void);

	void Sort();														 // Sort the data
	void SetBufferSize(int bufferSize);									 // change the buffer size
	void SetComparison(bool (*compareFunction)(const T &a, const T &b)); // change the sort criteria

  private:
	string _inFile;
	bool (*_compareFunction)(const T &a, const T &b);
	string _tempPath;
	vector<string> _vTempFileNames;
	vector<ifstream *> _vTempFiles;
	unsigned int _maxBufferSize;
	unsigned int _runCounter;
	bool _compressOutput;
	bool _tempFileUsed;
	ostream *_out;

	// drives the creation of sorted sub-files stored on disk.
	void DivideAndSort();

	// drives the merging of the sorted temp files.
	// final, sorted and merged output is written to "out".
	void Merge();

	void WriteToTempFile(const vector<T> &lines);
	void OpenTempFiles();
	void CloseTempFiles();
};

//************************************************
// IMPLEMENTATION
// Class methods and elements
//************************************************

// constructor
template <class T>
KwayMergeSort<T>::KwayMergeSort(const string &inFile,
								ostream *out,
								bool (*compareFunction)(const T &a, const T &b),
								int maxBufferSize,
								bool compressOutput,
								string tempPath)
	: _inFile(inFile), _out(out), _compareFunction(compareFunction), _tempPath(tempPath), _maxBufferSize(maxBufferSize), _runCounter(0), _compressOutput(compressOutput)
{
}

// constructor
template <class T>
KwayMergeSort<T>::KwayMergeSort(const string &inFile,
								ostream *out,
								int maxBufferSize,
								bool compressOutput,
								string tempPath)
	: _inFile(inFile), _out(out), _compareFunction(NULL), _tempPath(tempPath), _maxBufferSize(maxBufferSize), _runCounter(0), _compressOutput(compressOutput)
{
}

// destructor
template <class T>
KwayMergeSort<T>::~KwayMergeSort(void)
{
}

// API for sorting.
template <class T>
void KwayMergeSort<T>::Sort()
{
	DivideAndSort();
	Merge();
}

// change the buffer size used for sorting
template <class T>
void KwayMergeSort<T>::SetBufferSize(int bufferSize)
{
	_maxBufferSize = bufferSize;
}

// change the sorting criteria
template <class T>
void KwayMergeSort<T>::SetComparison(bool (*compareFunction)(const T &a, const T &b))
{
	_compareFunction = compareFunction;
}

template <class T>
void KwayMergeSort<T>::DivideAndSort()
{

	istream *input = new ifstream(_inFile.c_str(), ios::in);
	// gzipped
	// if ((isGzipFile(_inFile) == true) && (isRegularFile(_inFile) == true)) {
	//     delete input;
	//     input = new igzstream(_inFile.c_str(), ios::in);
	// }

	// bail unless the file is legit
	if (input->good() == false)
	{
		cerr << "Error: The requested input file (" << _inFile << ") could not be opened. Exiting!" << endl;
		exit(1);
	}
	vector<T> lineBuffer;
	lineBuffer.reserve(100000);
	unsigned int totalBytes = 0; // track the number of bytes consumed so far.

	// track whether or not we actually had to use a temp
	// file based on the memory that was allocated
	_tempFileUsed = false;

	// keep reading until there is no more input data
	T line;
	while (*input >> line)
	{

		// add the current line to the buffer and track the memory used.
		lineBuffer.push_back(line);
		totalBytes += sizeof(line); // bugg