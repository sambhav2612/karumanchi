#include <bits/stdc++.h>
using namespace std;

int convert(int num, int from, int to) {
    int result = 0, multiply = 1;

    while (num % 10 > 0) {
        int remainder = num % 10;
        
        if (remainder == from)
            result = result + to * multiply;
        else
            result = result + remainder * multiply;

        multiply *= 10;
        num /= 10;
    }
}

void min_max(int num1, int num2) {
    int min = convert(num1, 6, 5) + convert(num2, 6, 5), max = convert(num1, 5, 6) + convert(num2, 5, 6);
    cout << "MIN - " << min << "\nMAX - " << max;
}

int main(int argc, char *argv[]) {
    int num1 = atoi(argv[1]), num2 = atoi(argv[2]);
    cout << "\n";
    min_max(num1, num2);
    return 0;
}