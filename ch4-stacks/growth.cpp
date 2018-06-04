#include "../headers.h"

void sg(int *temp)
{
	int temp2;

	cout << "\nOne: " << temp;
	cout << "\nTwo: " << &temp2;

	if (temp > &temp2)
	{
		cout << endl
			 << "UP";
	}
	else
	{
		cout << endl
			 << "DOWN";
	}
}

int main()
{
	int temp;
	sg(&temp);

	return 0;
}
