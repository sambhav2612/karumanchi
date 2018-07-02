#include <iostream>
#include "codechef.h"
using namespace std;

int main(int argc, char const *argv[])
{
	int t;
	cin >> t;

	if (t >= 1 && t <= 100)
	{
		for (int j = 0; j < t; ++j)
		{
			int n;
			cin >> n;
			
			int wages[n] = {0};

			for (int i = 0; i < n; ++i)
				cin >> wages[i];

			int max = findmax(wages);
			int min = findmin(wages); 
		}
	}
	return 0;
}
