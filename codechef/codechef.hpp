int findmax(int array[])
{
	int max = INT_MIN;
	int len = sizeof(array) / sizeof(array[0]);

	for (int i = 0; i < len; ++i)
		if (max <= array[i])
			max = array[i];

	return max;
}

int findmin(int array[])
{
	int min = INT_MAX;
	int len = sizeof(array) / sizeof(array[0]);

	for (int i = 0; i < len; ++i)
		if (min >= array[i])
			min = array[i];

	return min;
}