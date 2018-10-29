/***********************************************************************************/

INCLUDED HEADERS

/***********************************************************************************/
#include <fstream.h>
#include <conio.h>
#include <string.h>
#include <process.h>
#include <stdlib.h>
#include <dos.h>
#include <stdio.h>
#include <iomanip.h>
	/***********************************************************************************/

	FREQUENTLY USED FUNCTIONS

	/***********************************************************************************/
 clrscr()
 getch()
 gotoxy()
 gets()
 open()
 close()
 seekg()
 tellg()
 exit()

	/***********************************************************************************/

	FUNCTION PROTOTYPES

	/***********************************************************************************/
	void display1();
void display2();
void page();
void timetable();
void exiter();
void timetable2();
void append1();
int check(int n);

/***********************************************************************************/

FUNCTION FOR BLINKING

	/***********************************************************************************/
	void
	blink(char *s)
{
	for (int i = 0; i < 10; i++)
	{
		clrscr();
		gotoxy(65, 25);
		delay(90);
		cout << s;
		delay(90);
	}
}
/***********************************************************************************/

FUNCTION REGARDING PASSWORDS

	/***********************************************************************************/
	void
	pass()
{
again:
	clrscr();
	int count = 0;
	char str[50];
	gotoxy(17, 2);
	cout << "User Login";
	gotoxy(5, 5);
	cout << "Password";
	gotoxy(15, 4);
	cout << "ÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜ";
	gotoxy(15, 5);
	cout << "Ý";
	gotoxy(30, 5);
	cout << "Þ";
	gotoxy(15, 6);
	cout << "ßßßßßßßßßßßßßßßß";
	//ÝclrscrÞ
	//ßßßßßßßß
	int i = 0;
	gotoxy(16, 5);
	str[i] = getch();

	cout << "*";
	while (str[i] != 13)
	{
		i++;
		gotoxy(16 + i, 5);
		str[i] = getch();
		cout << "*";
	}
	str[i] = '\0';
	if (strcmp(str, "chem") != 0)
	{
		blink("HACKER ALERT");
		clrscr();
		gotoxy(5, 7);
		cout << "HACKER ALERT";
		gotoxy(5, 9);
		cout << "You entered wrong password";
		gotoxy(5, 11);
		cout << "You will be given " << 5 - count - 1 << " more chance(s) to input correct password";
		gotoxy(5, 13);
		cout << " !! or all the info of database will be deleted !! ";
		count++;
		cout << " OK(?)";
		getch();
		if (count == 5)
		{
			remove("teach.dat");
			exiter();
		}
		goto again;
	}
	else
	{
		gotoxy(5, 10);
		cout << "Correct Password";
		delay(500);
	}
}

/***********************************************************************************/

FUNCTION REGARDING LOADING

	/***********************************************************************************/
	void
	load()
{
	clrscr();
	gotoxy(39, 2);
	cout << ".";
	gotoxy(39, 8);
	cout << ".";
	for (int i = 2; i < 6; i++)
	{
		gotoxy((38 - i), i);
		delay(75);
		cout << ".";
	}
	for (i = 2; i < 6; i++)
	{
		gotoxy((31 + i), 3 + i);
		delay(75);
		cout << ".";
	}
	for (i = 2; i < 6; i++)
	{
		gotoxy((40 + i), i);
		delay(75);
		cout << ".";
	}
	for (i = 2; i < 6; i++)
	{
		gotoxy((47 - i), 3 + i);
		delay(75);
		cout << ".";
	}
	gotoxy(36, 5);
	cout << "LOADING";
	for (i = 0; i < 67; i++)
	{
		gotoxy(6 + i, 8);
		cout << ".";
		gotoxy(6 + i, 11);
		cout << ".";
	}

	for (i = 0; i < 2; i++)
	{
		gotoxy(6, 9 + i);
		cout << ".";
		gotoxy(72, 9 + i);
		cout << ".";
	}
	for (i = 0; i < 55; i++)
	{
		gotoxy(8 + i, 10);
		delay(40);
		cout << "ß";
	}
	for (i = 0; i < 8; i++)
	{
		gotoxy(63 + i, 10);
		delay(140);
		cout << "ß";
	}
}
/***********************************************************************************/

FUNCTION REGARDING RECTANGLES

	/***********************************************************************************/
	void
	rect(char name[25])
{
	clrscr();
	for (int i = 0; i < 39; i++)
	{
		gotoxy(1 + i, 3);
		cout << "~";
		delay(8);
	}
	for (i = 0; i < 14; i++)
	{
		gotoxy(39, 3 + i);
		cout << "|";
		delay(8);
	}
	for (i = 0; i < 38; i++)
	{
		gotoxy(38 - i, 17);

		cout << "~";
		delay(8);
	}
	//sidekick
	for (i = 0; i < 30; i++)
	{
		gotoxy(45 + i, 5);
		cout << "~";
		delay(8);
	}
	for (i = 0; i < 10; i++)
	{
		gotoxy(75, 5 + i);
		cout << "|";
		delay(8);
	}
	for (i = 0; i < 29; i++)
	{
		gotoxy(74 - i, 15);
		cout << "~";
		delay(8);
	}
	for (i = 0; i < 10; i++)
	{
		gotoxy(45, 14 - i);
		cout << "|";
		delay(8);
	}
	for (i = 0; i < 30; i++)
	{
		gotoxy(46 + i, 6);
		cout << "~";
		delay(8);
	}
	for (i = 0; i < 10; i++)
	{
		gotoxy(76, 6 + i);
		cout << "|";
		delay(8);
	}
	for (i = 0; i < 29; i++)
	{

		gotoxy(75 - i, 16);
		cout << "~";
		delay(8);
	}
	for (i = 0; i < 10; i++)
	{
		gotoxy(46, 15 - i);
		cout << "|";
		delay(8);
	}
	gotoxy(57, 9);
	cout << "WELCOME";
	gotoxy(55, 11);
	cout << name;
}
/***********************************************************************************/

FUNCTION REGARDING EXIT PAGE

	/***********************************************************************************/
	void
	exiter()
{
	clrscr();
	gotoxy(1, 3);
	cout << ".";
	gotoxy(77, 3);
	cout << ".";
	gotoxy(1, 5);
	cout << "`";
	gotoxy(77, 5);
	cout << "'";
	gotoxy(5, 22);
	cout << "`";
	gotoxy(72, 22);
	cout << "'";
	for (int i = 0; i < 75; i++)
	{
		gotoxy(2 + i, 3);
		cout << "-";
		gotoxy(2 + i, 5);
		cout << "-";
	}

	for (i = 0; i < 66; i++)
	{
		gotoxy(6 + i, 22);
		cout << "-";
	}
	for (i = 0; i < 16; i++)
	{
		gotoxy(5, 6 + i);
		cout << "|";
		gotoxy(72, 6 + i);
		cout << "|";
	}
	gotoxy(1, 4);
	cout << "|";
	gotoxy(77, 4);
	cout << "|";
	gotoxy(32, 4);
	cout << "PROJECT MADE BY:-";
	gotoxy(29, 8);
	cout << "Sambhav Jain XII B";
	gotoxy(34, 12);
	cout << "";
	cout << endl;
	gotoxy(20, 16);
	cout << "<<<<<<<<<<--HAVE A GREAT DAY-->>>>>>>>>>";
	delay(2000);
	exit(0);
	getch();
}
/***********************************************************************************/

FUNCTION FOR CERTIFICATE

	/***********************************************************************************/
	void
	certify()
{
	clrscr();
	char ch;
	gotoxy(28, 3);
	cout << "Project on Chemistry Lab";
	gotoxy(34, 5);
	cout << "CERTIFICATE:";
	gotoxy(2, 8);

	cout << " I wish to convey my deep feelings of gratitude to all those"
		 << " whose help and" << endl;
	gotoxy(1, 10);
	cout << "cooperation has enabled me to bring out my destination." << endl;
	gotoxy(2, 12);
	cout << " I sincerely thank 'MRS SEEMA SHARMA'.my C.S."
		 << "teacher for her informative and" << endl;
	gotoxy(1, 14);
	cout << "illuminating guidance and"
		 << "valuable cooperation without which my project would" << endl;
	gotoxy(1, 16);
	cout << "not have been successful.";
	gotoxy(55, 22);
	cout << "S";
	delay(75);
	gotoxy(56, 22);
	cout << "A";
	delay(75);
	gotoxy(57, 22);
	cout << "M";
	delay(75);
	gotoxy(58, 22);
	cout << "B";
	delay(75);
	gotoxy(59, 22);
	cout << "H";
	delay(75);
	gotoxy(60, 22);
	cout << "A";
	delay(75);
	gotoxy(61, 22);
	cout << "V";
	delay(75);
	gotoxy(63, 22);
	cout << "J";
	delay(75);
	gotoxy(64, 22);
	cout << "A";
	delay(75);
	gotoxy(65, 22);
	cout << "I";
	delay(75);

	gotoxy(66, 22);
	cout << "N";
	gotoxy(58, 23);
	cout << "XIIth B";
	ch = getch();
	if ((ch == 27) || (ch == 48))
		exiter();
}
/***********************************************************************************/

INSTRUCTIONS PAGE

	/***********************************************************************************/
	void
	instruct()
{
	clrscr();
	gotoxy(33, 2);
	cout << "INSTRUCTIONS:";
	gotoxy(2, 5);
	cout << "* There are 2 choices initially,"
		 << " one for teachers and other for students.";
	gotoxy(2, 7);
	cout << "* For either choice, the user would be redirected to"
		 << " the page acc. to choice " << endl
		 << " entered accompanied with"
		 << " given choices to choose from.";
	gotoxy(2, 10);
	cout << "* Let say user enters a choice to search for an record"
		 << " then it would reqiure a password(ID) to print that"
		 << " record on the screen.";
	gotoxy(2, 13);
	cout << "* This is an easy to handle code.";
	gotoxy(2, 16);
	cout << "* And also the users are enabled to exit the code by entering"
		 << " ESC Key or " << endl
		 << " either 0(ZERO) in different sights.";
	gotoxy(2, 20);
	getch();
}

/***********************************************************************************/

FUNCTION REGARDING TIME - TABLES

	/***********************************************************************************/
	void
	timetable()
{
	clrscr();
	char abc;
	gotoxy(28, 2);
	cout << "TIME-TABLE(Week-Wise):-";
	delay(500);
	for (int i = 0; i < 75; i++)
	{
		gotoxy(2 + i, 6);
		cout << "-";
		gotoxy(2 + i, 8);
		cout << "-";
		gotoxy(2 + i, 10);
		cout << "-";
		gotoxy(2 + i, 12);
		cout << "-";
		gotoxy(2 + i, 14);
		cout << "-";
		gotoxy(2 + i, 16);
		cout << "-";
		gotoxy(2 + i, 18);
		cout << "-";
	}
	for (i = 0; i < 13; i++)
	{
		gotoxy(2, 6 + i);
		cout << "-";
		gotoxy(77, 6 + i);
		cout << "-";
		gotoxy(16, 6 + i);
		cout << "-";
		gotoxy(28, 6 + i);
		cout << "-";
		gotoxy(40, 6 + i);
		cout << "-";
		gotoxy(51, 6 + i);
		cout << "-";
		gotoxy(62, 6 + i);

		cout << "-";
	}
	gotoxy(4, 5);
	cout << "PERIODS->>";
	gotoxy(18, 5);
	cout << "(1). Ist";
	gotoxy(30, 5);
	cout << "(2). IInd";
	gotoxy(42, 5);
	cout << "(3).IIIrd";
	gotoxy(53, 5);
	cout << "(4). IVth";
	gotoxy(64, 5);
	cout << "(5). Vth";
	gotoxy(4, 7);
	cout << "MONDAY";
	gotoxy(4, 9);
	cout << "TUESDAY";
	gotoxy(4, 11);
	cout << "WEDNESDAY";
	gotoxy(4, 13);
	cout << "THURSDAY";
	gotoxy(4, 15);
	cout << "FRIDAY";
	gotoxy(4, 17);
	cout << "SATURDAY";
	gotoxy(20, 7);
	cout << "XII A";
	gotoxy(20, 9);
	cout << "XII A";
	gotoxy(20, 11);
	cout << "XI A";
	gotoxy(20, 13);
	cout << "XI C";
	gotoxy(20, 15);
	cout << "XII B";
	gotoxy(20, 17);
	cout << "XII B";
	gotoxy(32, 7);
	cout << "XII A";
	gotoxy(32, 9);
	cout << "XII A";

	gotoxy(32, 11);
	cout << "XI A";
	gotoxy(32, 13);
	cout << "XI C";
	gotoxy(32, 15);
	cout << "XII B";
	gotoxy(32, 17);
	cout << "XII B";
	gotoxy(44, 7);
	cout << "XI B";
	gotoxy(44, 9);
	cout << "XI B";
	gotoxy(44, 11);
	cout << "XI C";
	gotoxy(44, 13);
	cout << "XI A";
	gotoxy(44, 15);
	cout << "XI D";
	gotoxy(44, 17);
	cout << "XI D";
	gotoxy(55, 7);
	cout << "XII E";
	gotoxy(55, 9);
	cout << "XII E";
	gotoxy(55, 11);
	cout << "XI C";
	gotoxy(55, 13);
	cout << "XI A";
	gotoxy(55, 15);
	cout << "XI B";
	gotoxy(55, 17);
	cout << "XI B";
	gotoxy(66, 7);
	cout << "XII D";
	gotoxy(66, 9);
	cout << "XII D";
	gotoxy(66, 11);
	cout << "XII E";
	gotoxy(66, 13);
	cout << "XII E";
	gotoxy(66, 15);
	cout << "XII C";

	gotoxy(66, 17);
	cout << "XII C";
	delay(1000);
abc:
	gotoxy(2, 20);
	cout << "Press 6(SIX) to View More:";
	abc = getch();
	if (abc == 54)
		timetable2();
	if ((abc == 27) || (abc == 48))
		exiter();
	getch();
}
void timetable2()
{
	clrscr();
	char abc;
	gotoxy(28, 2);
	cout << "TIME-TABLE(Week-Wise):-";
	delay(500);
	for (int i = 0; i < 51; i++)
	{
		gotoxy(2 + i, 6);
		cout << "-";
		gotoxy(2 + i, 8);
		cout << "-";
		gotoxy(2 + i, 10);
		cout << "-";
		gotoxy(2 + i, 12);
		cout << "-";
		gotoxy(2 + i, 14);
		cout << "-";
		gotoxy(2 + i, 16);
		cout << "-";
		gotoxy(2 + i, 18);
		cout << "-";
	}
	for (i = 0; i < 13; i++)
	{
		gotoxy(2, 6 + i);
		cout << "-";

		gotoxy(40, 6 + i);
		cout << "-";
		gotoxy(52, 6 + i);
		cout << "-";
		gotoxy(16, 6 + i);
		cout << "-";
		gotoxy(28, 6 + i);
		cout << "-";
	}
	gotoxy(4, 5);
	cout << "PERIODS->>";
	gotoxy(18, 5);
	cout << "(6). VIth";
	gotoxy(30, 5);
	cout << "(7). VIIth";
	gotoxy(42, 5);
	cout << "(8).VIIIth";
	gotoxy(4, 7);
	cout << "MONDAY";
	gotoxy(4, 9);
	cout << "TUESDAY";
	gotoxy(4, 11);
	cout << "WEDNESDAY";
	gotoxy(4, 13);
	cout << "THURSDAY";
	gotoxy(4, 15);
	cout << "FRIDAY";
	gotoxy(4, 17);
	cout << "SATURDAY";
	gotoxy(20, 7);
	cout << "XII D";
	gotoxy(20, 9);
	cout << "XII D";
	gotoxy(20, 11);
	cout << "XII C";
	gotoxy(20, 13);
	cout << "XII C";
	gotoxy(20, 15);
	cout << "XI E";
	gotoxy(20, 17);
	cout << "XI E";
	gotoxy(32, 7);

	cout << "XI D";
	gotoxy(32, 9);
	cout << "XI D";
	gotoxy(32, 11);
	cout << "NIL";
	gotoxy(32, 13);
	cout << "NIL";
	gotoxy(32, 15);
	cout << "NIL";
	gotoxy(32, 17);
	cout << "NIL";
	gotoxy(44, 7);
	cout << "NIL";
	gotoxy(44, 9);
	cout << "NIL";
	gotoxy(44, 11);
	cout << "NIL";
	gotoxy(44, 13);
	cout << "NIL";
	gotoxy(44, 15);
	cout << "XI E";
	gotoxy(44, 17);
	cout << "XI E";
	for (i = 0; i < 19; i++)
	{
		gotoxy(57 + i, 7);
		cout << "-";
		gotoxy(57 + i, 9);
		cout << "-";
	}
	for (i = 0; i < 5; i++)
	{
		gotoxy(55 + i, 8);
		cout << ".";
		gotoxy(73 + i, 8);
		cout << ".";
	}
	for (i = 0; i < 3; i++)
	{
		gotoxy(66, 4 - i);
		cout << ".";
		gotoxy(66, 12 + i);

		cout << ".";
	}
	for (i = 0; i < 9; i++)
	{
		gotoxy(68, 4 + i);
		cout << "|";
		gotoxy(64, 4 + i);
		cout << "|";
	}
	gotoxy(62, 16);
	cout << "--";
	gotoxy(68, 16);
	cout << "--";
	gotoxy(62, 17);
	cout << "||";
	gotoxy(68, 17);
	cout << "||";
	gotoxy(58, 18);
	cout << "KEYBOARD SNIPPET";
	gotoxy(66, 5);
	cout << "-";
	gotoxy(66, 11);
	cout << "-";
	gotoxy(66, 6);
	cout << "8";
	gotoxy(66, 10);
	cout << "2";
	gotoxy(62, 8);
	cout << "4";
	gotoxy(66, 8);
	cout << "5";
	gotoxy(70, 8);
	cout << "6";
	gotoxy(60, 8);
	cout << "|";
	gotoxy(72, 8);
	cout << "|";
	gotoxy(64, 8);
	cout << "|";
	gotoxy(68, 8);
	cout << "|";
	delay(1000);

abc:
	gotoxy(2, 20);
	cout << "Press 4(FOUR) to View Less:";
	abc = getch();
	if (abc == 52)
		timetable();
	if ((abc == 27) || (abc == 48))
		exiter();
	getch();
}
/***********************************************************************************/

HOW CAN I HELP YOU ? ?

					 /***********************************************************************************/
	void
	hcihy()
{
	gotoxy(2, 15);
	cout << "H";
	delay(50);
	gotoxy(3, 15);
	cout << "o";
	delay(50);
	gotoxy(4, 15);
	cout << "w";
	delay(50);
	gotoxy(6, 15);
	cout << "c";
	delay(50);
	gotoxy(7, 15);
	cout << "a";
	delay(50);
	gotoxy(8, 15);
	cout << "n";
	delay(50);
	gotoxy(10, 15);
	cout << "I";
	delay(50);
	gotoxy(12, 15);
	cout << "h";
	delay(50);
	gotoxy(13, 15);
	cout << "e";

	delay(50);
	gotoxy(14, 15);
	cout << "l";
	delay(50);
	gotoxy(15, 15);
	cout << "p";
	delay(50);
	gotoxy(17, 15);
	cout << "y";
	delay(50);
	gotoxy(18, 15);
	cout << "o";
	delay(50);
	gotoxy(19, 15);
	cout << "u";
	delay(50);
	gotoxy(20, 15);
	cout << "??";
}
///////////////////////////////////////////-CLASSES START HERE-///////////////////////////////////////////
/***********************************************************************************/

DEFINING CLASS : “TEACHERS”

	/***********************************************************************************/
	class teachers
{
	int dd;
	int mm;
	int yy;
	int idpass;
	char name[25];
	char desig[10];
	char purpose[50];

  public:
	void getdata();
	void moddata();
	void printdata();
	int returnidpass()
	{
		return idpass;
	}
	char *returnname()
	{
		return name;
	}
} teach;

/***********************************************************************************/

FUNCTION GETING DATA for “stud.dat” binary file:

/***********************************************************************************/
void teachers::getdata()
{
	cout << "\nEnter Date of Entry:" << endl;
a:
	cout << "Day:";
	cin >> dd;
	if ((dd > 1) && (dd < 32))
	{
	b:
		cout << "\nMonth:";
		cin >> mm;
		if ((mm > 1) && (mm < 13))
		{
		c:
			cout << "\nYear:";
			cin >> yy;
			if ((yy > 2000) && (yy < 2050))
			{
			men:
				randomize();
				idpass = random(10000);
				cout << "Enter Name:";
				gets(name);
				cout << "Enter Designation:";
				gets(desig);
				cout << "Enter Purpose of Login:";
				gets(purpose);
				delay(500);
				cout << "\n\n!!ENTRY Successfully Added to File!!";
				delay(500);
				cout << "\n\nLog-In ID is " << idpass << " ,retain it for future.";
			}
			else
			{
				cout << "\nYear must be between 2000 and 2050 only...";
				delay(500);
				goto c;
			}
		}

		else
		{
			cout << "\nMonth must be between 01 and 12 only...";
			delay(500);
			goto b;
		}
	}
	else
	{
		cout << "\nDay must be between 01 and 31 only...";
		delay(500);
		goto a;
	}
}
/***********************************************************************************/

FUNCTION MODIFING DATA for “teach.dat” binary file:

/***********************************************************************************/
void teachers::moddata()
{
	cout << "\nEnter Date of Entry:" << endl;
a:
	cout << "Day:";
	cin >> dd;
	if ((dd > 1) && (dd < 32))
	{
	b:
		cout << "\nMonth:";
		cin >> mm;
		if ((mm > 1) && (mm < 13))
		{
		c:
			cout << "\nYear:";
			cin >> yy;
			if ((yy > 2000) && (yy < 2050))
			{
			men:
				cout << "Enter Name:";
				gets(name);
				cout << "Enter Designation:";
				gets(desig);
				cout << "Enter Purpose of Login:";
				gets(purpose);
				delay(500);
				cout << "\n\n!!ENTRY Successfully Added to File!!";
				delay(500);
			}
			else
			{
				cout << "\nYear must be between 2000 and 2050 only...";
				delay(500);
				goto c;
			}
		}
		else
		{
			cout << "\nMonth must be between 01 and 12 only...";
			delay(500);
			goto b;
		}
	}
	else
	{
		cout << "\nDay must be between 01 and 31 only...";
		delay(500);
		goto a;
	}
}
/***********************************************************************************/

FUNCTION PRINTING DATA for “teach.dat” binary file:

/***********************************************************************************/
void teachers::printdata()
{
	cout << dd << "/" << mm << "/" << yy;
	cout << setw(15) << idpass << setw(15) << name;
	cout << setw(15) << desig << setw(15) << purpose << endl;
}

/***********************************************************************************/

DEFINING CLASS : “STUDENTS”

	/***********************************************************************************/
	class students
{
	int admno;
	char name[25];
	char clas[5];
	char section[5];
	char purpose[50];

  public:
	void getdata();
	void printdata();
	int returnadmno()
	{
		return admno;
	}
} stud;
/***********************************************************************************/

FUNCTION GETING DATA for “stud.dat” binary file:

/***********************************************************************************/
void students::getdata()
{
	cout << "\nEnter Admisssion No.:";
	cin >> admno;
	cout << "\nEnter Name:";
	gets(name);
	cout << "\nEnter Class:";
	gets(clas);
	cout << "\nEnter Section:";
	gets(section);
	cout << "\nEnter Purpose of Login:";
	gets(purpose);
	delay(500);
	cout << "\n\n!!ENTRY Successfully Added to File!!";
}

/***********************************************************************************/

FUNCTION PRINTING DATA for “stud.dat” binary file:

/***********************************************************************************/
void students::printdata()
{
	cout << setw(10) << admno << setw(25) << name;
	cout << setw(12) << clas << setw(2) << section;
	cout << setw(16) << purpose << endl;
}
//////////////////////////////////////////--CLASSES END HERE--//////////////////////////////////////////
/***********************************************************************************/

FUNCTION CREATING DATA FILE - “teach.dat”

							  /***********************************************************************************/
							  //Functions to create file for each CLASS
							  void
							  create1() //function for teachers class
{
	clrscr();
	ofstream fout;
	fout.open("teach.dat", ios::binary | ios::out);
	if (!fout)
		cout << "\nUnable to open file.";
	else
	{
		cout << "\nFile already created";
		delay(500);
		cout << "\n\nTERMINATING";
		exiter();
	}
	fout.close();
	getch();
}
/***********************************************************************************/

FUNCTION CREATING DATA FILE - “stud.dat”

							  /***********************************************************************************/
							  void
							  create2() //for students class
{
	ofstream fout;
	fout.open("stud.dat", ios::binary | ios::out);
	if (!fout)
		cout << "\n<<<404_FILE_NOT_FOUND>>>";

	else
	{
		stud.getdata();
		fout.write((char *)&stud, sizeof(stud));
	}
	fout.close();
	getch();
} //Functions to create files(independent) ends here.
/***********************************************************************************/

FUNCTION APPEND for Ist CLASS

/***********************************************************************************/
//Now, Functions to append data into each files:
void append1() //for teachers class
{
	clrscr();
	char ch;
	cout << endl;
	cout << "ßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßß" << endl;
	cout << " RECORD CREATOR:- " << endl;
	cout << "ÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜ" << endl;
	ofstream fout;
	fout.open("teach.dat", ios::binary | ios::app);
	if (!fout)
		cout << "\nUnable to open file.";
	do
	{
		teach.getdata();
		fout.write((char *)&teach, sizeof(teach));
		cout << "\nWant to enter more records??";
		cin >> ch;
	} while ((ch == 'y') || (ch == 'Y'));
	fout.close();
	getch();
}

/***********************************************************************************/

FUNCTION APPEND for IInd CLASS

/***********************************************************************************/
void append2() //for students class
{
	clrscr();
	cout << endl;
	cout << "ßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßß" << endl;
	cout << " RECORD CREATOR:- " << endl;
	cout << "ÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜ" << endl;
	ofstream fout;
	fout.open("stud.dat", ios::binary | ios::app);
	if (!fout)
		cout << "\n<<<404_FILE_NOT_FOUND>>>";
	else
	{
		stud.getdata();
		fout.write((char *)&stud, sizeof(stud));
	}
	fout.close();
	getch();
}
/***********************************************************************************/

FUNCTION SEARCH for Ist CLASS (uses no.)

/***********************************************************************************/
//Functions to search for a member and display the record:
void search1()//for teacher class
{
	clrscr();
	int passid;
	char ch;
	cout << endl;
	cout << "ßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßß" << endl;
	cout << " RECORD SEARCHER:- " << endl;
	cout << "ÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜ" << endl;
men:
	cout << "\nEnter ID to be searched:";
	cin >> passid;
	if (passid == 0)
	{
		cout << "\nYou are terminating your code...";

		delay(500);
		exiter();
	}
	ifstream fin;
	fin.open("teach.dat", ios::binary | ios::in);
	if (!fin)
	{
		cout << "\nUnable to open file.";
	}
	else
	{
		while (fin.read((char *)&teach, sizeof(teach)))
		{
			if (teach.returnidpass() == passid)
			{
				cout << "\nRecord(s) IS:\n";
				cout << ".----------------------------------------------------------------------------." << endl;
				cout << "|" << setw(7) << "DATE" << setw(18) << "School ID";
				cout << setw(12) << "NAME" << setw(18) << "DESIGNATION";
				cout << setw(22) << "LOGIN PURPOSE |" << endl;
				cout << "`----------------------------------------------------------------------------'" << endl;
				cout << endl;
				teach.printdata();
				delay(500);
				cout << "\nWant to search more....??";
				cin >> ch;
				if ((ch == 'y') || (ch == 'Y'))
					goto men;
				if (ch == 48)
					exiter();
			}
		}
	}
	fin.close();
	getch();
}

/***********************************************************************************/

FUNCTION SEARCH for Ist CLASS (uses name)

/***********************************************************************************/
void search2()//for teacher class
{
	clrscr();
	char passnm[25];
	char ch;
	cout << endl;
	cout << "ßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßß" << endl;
	cout << " RECORD SEARCHER:- " << endl;
	cout << "ÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜ " << endl;
men:
	cout
		<< "\nEnter Teacher's Name to be searched:";
	gets(passnm);
	if (strcmpi(passnm, "chem") == 0)
	{
		cout << "\nYou are terminating your code...";
		delay(500);
		exiter();
	}
	ifstream fin;
	fin.open("teach.dat", ios::binary | ios::in);
	if (!fin)
	{
		cout << "\nUnable to open file.";
	}
	else
	{
		while (fin.read((char *)&teach, sizeof(teach)))
		{
			if (strcmpi(teach.returnname(), passnm) == 0)
			{
				cout << "\nRecord(s) IS:\n";
				cout << ".----------------------------------------------------------------------------." << endl;
				cout << "|" << setw(7) << "DATE" << setw(18) << "School ID";
				cout << setw(12) << "NAME" << setw(18) << "DESIGNATION";
				cout << setw(22) << "LOGIN PURPOSE |" << endl;
				cout << "`----------------------------------------------------------------------------'" << endl;
				cout << endl;
				teach.printdata();
				delay(500);

				cout << "\nWant to search more....??";
				cin >> ch;
				if ((ch == 'y') || (ch == 'Y'))
					goto men;
				if (ch == 48)
					exiter();
			}
		}
	}
	fin.close();
	getch();
}
/***********************************************************************************/

FUNCTION SEARCH for IInd CLASS (using only no.)

/***********************************************************************************/
void search3()//for students class
{
	clrscr();
	int admn;
	cout << endl;
	cout << "ßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßß" << endl;
	cout << " RECORD SEARCHER:- " << endl;
	cout << "ÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜ" << endl;
men:
	cout << "\nEnter Admission No. for login:";
	cin >> admn;
	if (admn == 0)
	{
		cout << "\nYou are terminating the code...";
		delay(500);
		exiter();
	}
	ifstream fin;
	fin.open("stud.dat", ios::binary | ios::in);
	if (!fin)
		cout << "\n<<<404_FILE_NOT_FOUND>>>";
	else
	{
		while (fin.read((char *)&stud, sizeof(stud)))
		{
			if (stud.returnadmno() == admn)

			{
				cout << "\nRecords are:\n";
				cout << ".------------------------------------------------------------------------." << endl;
				cout << "|" << setw(12) << "Admn No.";
				cout << setw(18) << "NAME" << setw(18) << "CLASS";
				cout << setw(29) << "LOGIN PURPOSE |" << endl;
				cout << "`------------------------------------------------------------------------'" << endl;
				cout << endl;
				stud.printdata();
			}
		}
	}
	fin.close();
	getch();
}
/***********************************************************************************/

FUNCTION DELETE for Ist CLASS

/***********************************************************************************/
//Function to delete a record from the file:
void Delete1()//for teacher class
{
	clrscr();
	int no;
	cout << endl;
	cout << "ßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßß" << endl;
	cout << " RECORD DELETOR:- " << endl;
	cout << "ÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜ" << endl;
men:
	ifstream fin;
	fin.open("teach.dat", ios::binary | ios::in);
	ofstream fout;
	fout.open("teach2.dat", ios::binary | ios::out);
	display1();
	cout << "\nEnter ID No. who's record is to be deleted:";
	cin >> no;
	if (no == 0)
	{
		cout << "\nYou are terminating the code...";
		delay(500);
		exiter();
	}

	if ((!fin) || (!fout))
	{
		cout << "\nUnable to open file.";
	}
	else
	{
		while (fin.read((char *)&teach, sizeof(teach)))
		{
			if (teach.returnidpass() == no)
			{
				cout << "\n\nDELETING....." << endl;
				delay(500);
				cout << "\n<<<Record Successfully Deleted>>>";
			}
			else
			{
				fout.write((char *)&teach, sizeof(teach));
			}
		}
	}
	fin.close();
	fout.close();
	remove("teach.dat");
	rename("teach2.dat", "teach.dat");
}
/***********************************************************************************/

FUNCTION DELETE for IInd CLASS

/***********************************************************************************/
void Delete2()//for students class
{
	clrscr();
	int no;
	cout << endl;
	cout << "ßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßß" << endl;
	cout << " RECORD DELETOR:- " << endl;
	cout << "ÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜ" << endl;
men:
	ifstream fin;
	fin.open("stud.dat", ios::binary | ios::in);
	ofstream fout;
	fout.open("stud2.dat", ios::binary | ios::out);

	if ((!fin) || (!fout))
	{
		cout << "\n<<<404_FILE_NOT_FOUND>>>";
	}
	display2();
	cout << "\nEnter Admission No. who's record is to be deleted:";
	cin >> no;
	if (no == 0)
	{
		cout << "\nYou are terminating the code...";
		delay(500);
		exiter();
	}
	while (fin.read((char *)&stud, sizeof(stud)))
	{
		if (stud.returnadmno() == no)
		{
			cout << "\n\nDELETING....." << endl;
			delay(500);
			cout << "\n<<<Record Successfully Deleted>>>";
		}
		else
		{
			fout.write((char *)&stud, sizeof(stud));
		}
	}
	fin.close();
	fout.close();
	remove("stud.dat");
	rename("stud2.dat", "stud.dat");
}
/***********************************************************************************/

FUNCTION MODIFY for Ist CLASS

/***********************************************************************************/
//Function to modify a record in a file:
void modify1()//for first class
{
	clrscr();
	int no;
	char ch;
	cout << endl;

	cout << "ßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßß" << endl;
	cout << " RECORD MODIFICATOR:- " << endl;
	cout << "ÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜ" << endl;
men:
	cout << "\nEnter ID No. who's record is to be modified:";
	cin >> no;
	if (no == 0)
	{
		cout << "\nYou are terminating the code...";
		delay(500);
		exiter();
	}
	ifstream fin;
	fin.open("teach.dat", ios::binary | ios::in);
	ofstream fout;
	fout.open("teach2.dat", ios::binary | ios::out);
	if ((!fin) || (!fout))
	{
		cout << "\nERR_OR";
	}
	while (fin.read((char *)&teach, sizeof(teach)))
	{
		if (teach.returnidpass() == no)
		{
			cout << "\nPREVOIUS_RECORD:-\n";
			cout << ".----------------------------------------------------------------------------." << endl;
			cout << "|" << setw(7) << "DATE" << setw(18) << "School ID";
			cout << setw(12) << "NAME" << setw(18) << "DESIGNATION";
			cout << setw(22) << "LOGIN PURPOSE |" << endl;
			cout << "`----------------------------------------------------------------------------'" << endl;
			cout << endl;
			teach.printdata();
			cout << "\nWant to change data??";
			cin >> ch;
			if ((ch == 'y') || (ch == 'Y'))
			{
				delay(500);
				clrscr();
				cout << "\nENTER_NEW_DATA:-";
				teach.moddata();
				fout.write((char *)&teach, sizeof(teach));
				delay(500);

				cout << "\nData Successfully Changed!!";
			}
		}
		else
		{
			fout.write((char *)&teach, sizeof(teach));
		}
	}
	fin.close();
	fout.close();
	remove("teach.dat");
	rename("teach2.dat", "teach.dat");
}
/***********************************************************************************/

FUNCTION MODIFY for IInd CLASS

/***********************************************************************************/
void modify2()//for second class
{
	clrscr();
	int no;
	cout << endl;
	cout << "ßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßß" << endl;
	cout << " RECORD MODIFICATOR:- " << endl;
	cout << "ÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜ" << endl;
men:
	display2();
	cout << "\nEnter Admission No. who's record is to be modified:";
	cin >> no;
	if (no == 0)
	{
		cout << "\nYou are terminating the code...";
		delay(500);
		exiter();
	}
	ifstream fin;
	fin.open("stud.dat", ios::binary | ios::in);
	ofstream fout;
	fout.open("stud2.dat", ios::binary | ios::out);
	if ((!fin) || (!fout))
	{
		cout << "\n<<<404_FILE_NOT_FOUND>>>";
	}
	while (fin.read((char *)&stud, sizeof(stud)))
	{
		if (stud.returnadmno() == no)
		{
			cout << "\nPREVOIUS_RECORD:-\n";
			cout << ".----------------------------------------------------------------------------." << endl;
			cout << "|" << setw(12) << "Admn No.";
			cout << setw(18) << "NAME" << setw(18) << "CLASS";
			cout << setw(29) << "LOGIN PURPOSE |" << endl;
			cout << "`----------------------------------------------------------------------------'" << endl;
			cout << endl;
			stud.printdata();
			cout << "\nENTER_NEW_DATA:-";
			stud.getdata();
			fout.write((char *)&stud, sizeof(stud));
		}
		else
		{
			cout << "\nNO entry found with this ID";
			fout.write((char *)&stud, sizeof(stud));
		}
	}
	fin.close();
	fout.close();
	remove("stud.dat");
	rename("stud2.dat", "stud.dat");
}
/***********************************************************************************/

FUNCTION to ensure proper entry in teacher’s database(demonstration)

	/***********************************************************************************/
	void getinst1()
{
	clrscr();
	cout << endl;
	cout << "ßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßß" << endl;
	cout << " RECORD CREATOR INSTRUCTION PAGE:- " << endl;
	cout << "ÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜ" << endl;
	delay(500);
	gotoxy(2, 6);
	cout << "--- NOTE: After this you will be automatically redirected to main page---" << endl;

	delay(500);
	cout << "\nEnter Date of Entry:" << endl;
	delay(500);
	cout << "Day:";
	delay(500);
	gotoxy(30, 9);
	cout << "<-- Fill appropriate day of entry" << endl;
	delay(500);
	cout << "\nMonth:";
	delay(500);
	gotoxy(30, 11);
	cout << "<-- Fill appropriate month of entry" << endl;
	delay(500);
	cout << "\nYear:";
	delay(500);
	gotoxy(30, 13);
	cout << "<-- Fill appropriate year of entry" << endl;
	delay(500);
	cout << "\n\nEnter Name:";
	delay(500);
	gotoxy(30, 16);
	cout << "<-- Fill correct name of entrier" << endl;
	delay(500);
	cout << "\nEnter Designation:";
	delay(500);
	gotoxy(30, 18);
	cout << "<-- Fill accurate desig. of entrier" << endl;
	delay(500);
	cout << "\nEnter Purpose of Login:";
	delay(500);
	gotoxy(30, 20);
	cout << "<-- That's self-explanatory LOL :)" << endl;
	delay(500);
	cout << "\n\n!!ENTRY Successfully Added to File!!";
	delay(1250);
	clrscr();
	gotoxy(20, 3);
	cout << "Redirecting";
	for (int i = 0; i < 10; i++)
	{
		gotoxy(32 + i, 3);
		cout << ".";
		delay(75);
	}
}

/***********************************************************************************/

FUNCTION DISPLAY for Ist CLASS

/***********************************************************************************/
//Function to display all records from file:
void display1()//for teachers class
{
	load();
	clrscr();
	cout << endl;
	cout << ".----------------------------------------------------------------------------." << endl;
	cout << "|" << setw(7) << "DATE" << setw(18) << "School ID";
	cout << setw(12) << "NAME" << setw(18) << "DESIGNATION";
	cout << setw(22) << "LOGIN PURPOSE |" << endl;
	cout << "`----------------------------------------------------------------------------'" << endl;
	cout << endl
		 << endl;
	ifstream fin("teach.dat", ios::binary | ios::in);
	if (!fin)
		cout << "Unable to open file.";
	while (fin.read((char *)&teach, sizeof(teach)))
	{
		teach.printdata();
	}
	fin.close();
	getch();
}
/***********************************************************************************/

FUNCTION DISPLAY FOR IInd CLASS

	/***********************************************************************************/
	void
	display2() //for students class
{
	load();
	clrscr();
	cout << endl;
	cout << ".----------------------------------------------------------------------------." << endl;
	cout << "|" << setw(12) << "Admn No.";
	cout << setw(18) << "NAME" << setw(18) << "CLASS";
	cout << setw(29) << "LOGIN PURPOSE |" << endl;
	cout << "`----------------------------------------------------------------------------'" << endl;
	cout << endl;
	ifstream fin("stud.dat", ios::binary | ios::in);
	if (!fin)

		cout << "\n<<<404_FILE_NOT_FOUND>>>";
	while (fin.read((char *)&stud, sizeof(stud)))
	{
		stud.printdata();
	}
	fin.close();
	getch();
}
char nm[25];

/***********************************************************************************/
FUNCTION REGARDING TEACHERS
	/***********************************************************************************/
	void
	pgteach()
{
	char abc;
	clrscr();
men:
	rect(nm);
	gotoxy(50, 2);
	cout << "Press <ESC> to Terminate";
	gotoxy(7, 4);
	cout << "WELCOME to TEACHER'S CLUB" << endl;
	gotoxy(4, 6);
	cout << "(1). Search + Display a Record";
	gotoxy(4, 7);
	cout << "(2). Create a Record";
	gotoxy(4, 8);
	cout << "(3). Modify a Record";
	gotoxy(4, 9);
	cout << "(4). Delete a Record";
	gotoxy(4, 10);
	cout << "(5). Display all Record(s)";
	gotoxy(4, 11);
	cout << "(6). View Time-Table";
	gotoxy(4, 12);
	cout << "(7). Back to Main-Menu";
	gotoxy(4, 13);
	cout << "(8). QUIT";
	delay(250);
	hcihy();
	abc = getch();

	if ((abc == 27) || (abc == 48))
		exiter();
	switch (abc)
	{
	case '1':
		clrscr();
		gotoxy(4, 4);
		cout << "BY ID Press 1";
		gotoxy(4, 5);
		cout << "BY NAME Press 2";
		abc = getch();
		if (abc == 49)
			search1();
		if (abc == 50)
			search2();
		break;
	case '2':
		getinst1();
		append1();
		break;
	case '3':
		modify1();
		break;
	case '4':
		Delete1();
		break;
	case '5':
		display1();
		break;
	case '6':
		timetable();
		break;
	case '7':
		page();
		break;
	case '8':
		exiter();
		break;
	default:
		cout << "\nValue Must be b/w 1 and 8 only and you"
			 << " will be redirected...";
	}
	goto men;
}

/***********************************************************************************/

FUNCTION FOR STUDENTS

	/***********************************************************************************/
	void
	pgstud()
{
	char abc;
	clrscr();
men:
	rect(nm);
	gotoxy(50, 2);
	cout << "Press <ESC> to Terminate";
	gotoxy(6, 5);
	cout << "WELCOME to STUDENT'S COUNCIL" << endl;
	gotoxy(4, 7);
	cout << "(1). Search + Display a Record";
	gotoxy(4, 8);
	cout << "(2). Create a Record";
	gotoxy(4, 9);
	cout << "(3). Modify a Record";
	gotoxy(4, 10);
	cout << "(4). Delete a Record";
	gotoxy(4, 11);
	cout << "(5). Display all Record(s)";
	gotoxy(4, 12);
	cout << "(6). Back to Main-Menu";
	gotoxy(4, 13);
	cout << "(7). QUIT";
	delay(250);
	hcihy();
	abc = getch();
	if ((abc == 27) || (abc == 48))
		exiter();
	switch (abc)
	{
	case '1':
		search3();
		break;
	case '2':
		append2();
		break;
	case '3':
		modify2();
		break;
	case '4':
		Delete2();
		break;

	case '5':
		display2();
		break;
	case '6':
		page();
		break;
	case '7':
		exiter();
		break;
	default:
		cout << "\nValue Must be b/w 1 and 7 only and you"
			 << " will be redirected...";
		clrscr();
		delay(1000);
		goto men;
	}
	getch();
}
/***********************************************************************************/

FUNCTION FOR MAIN PAGE

	/***********************************************************************************/
	void
	page()
{
	char abc;
	while (1)
	{
		clrscr();
	agg:
		gotoxy(4, 4);
		cout << "Please enter your name: ";
		gets(nm);
	men:
		if (!nm)
			goto agg;
		rect(nm);
		gotoxy(50, 2);
		cout << "Press <ESC> to Terminate";
		gotoxy(8, 5);
		cout << "WELCOME to CHEMISRTY LAB" << endl;
		gotoxy(4, 8);
		cout << "(1). TEACHER Entry";
		gotoxy(4, 9);
		cout << "(2). STUDENT Entry" << endl;
		gotoxy(4, 10);
		cout << "(3). Read INSTRUCTIONS" << endl;

		gotoxy(4, 11);
		cout << "(4). QUIT" << endl;
		delay(250);
		hcihy();
		abc = getch();
		if ((abc == 27) || (abc == 48))
			exiter();
		switch (abc)
		{
		case '1':
			pass();
			pgteach();
			break;
		case '2':
			pgstud();
			break;
		case '3':
			instruct();
			break;
		case '4':
			exiter();
			break;
		default:
			cout << "\nValue must be either 1 or 2 or 3 and you"
				 << " will be redirected...";
			clrscr();
			delay(1000);
			goto men;
		}
	}
}
/***********************************************************************************/

MAIN FUNCTION

	/***********************************************************************************/
	void
	main()
{
	clrscr();
	certify();
	page();
	getch();
}
