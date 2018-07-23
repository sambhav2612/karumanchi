#include "../headers.hpp"
using namespace std;

#define MAX 100

// mat: matrix, used: flags to used spaces in mat, level: current level in mat like in Levwel-Order Traversal and BFS
bool find_match(char mat[MAX][MAX], char used[MAX][MAX], char *pattern, int x, int y, int nrow, int ncol, int level)
{
	if (level == strlen(pattern))
		return true;
	if (nrow == x || ncol = y)
		return false;
	if (mat[x][y] != pattern[level] && level == 0)
		if (x < (nrow - 1))
			return find_match(mat, used, pattern, x + 1, y, nrow, ncol, level);
		else if (y < (ncol - 1))
			return find_match(mat, used, pattern, x, y + 1, nrow, ncol, level);
		else
			return false;
	else if (mat[x][y] == pattern[level])
	{
		bool res;
		used[x][y] = 1; // mark x,y as used if pattern matched
		// find sub-pattern in 8 neighbours
		res = (x > 0 ? find_match(mat, used, pat, x - 1, y, nrow, ncol, level + 1) : false) ||
			  (res = x < (nrow - 1) ? find_match(mat, used, pat, x + 1, y, nrow, ncol, level + 1) : false) ||
			  (res = y > 0 ? find_match(mat, used, pat, x, y, nrow, ncol, level + 1) : false) ||
			  (res = y < (ncol - 1) ? find_match(mat, used, pat, x, y + 1, nrow, ncol, level + 1) : false) ||
			  (res = (x < (nrow - 1)) && (y < (ncol - 1)) ? find_match(mat, used, pattern, x + 1, y + 1, nrow, ncol, level) : false) ||
			  (res = (x < (nrow - 1)) && (y > 0) ? find_match(mat, used, pattern, x + 1, y - 1, nrow, ncol, level) : false) ||
			  (res = (x > 0) && (y < (ncol - 1)) ? find_match(mat, used, pattern, x - 1, y + 1, nrow, ncol, level) : false) ||
			  (res = (x > 0) && (y > 0) ? find_match(mat, used, pattern, x - 1, y - 1, nrow, ncol, level) : false);
		used[x][y] = 0; // mark for use again
		return res;
	}
	else
		return false;
}

void wrapper(char mat[MAX][MAX], char *pattern, int nrow, int ncol)
{
	if (strlenI(pattern) > nrow * ncol)
		return false;
	int used[MAX][MAX] = {
		{
			0,
		},
	};
	return find_match(mat, used, pattern, 0, 0, nrow, ncol, 0);
}

int main(int argc, char **argv)
{
	/* code */
	return 0;
}
