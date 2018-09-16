// GFG Sudo Placement 2 - 2.2 Middle Pattern

/*
 *  Author: Sambhav Jain
 *  Contact: sambhavjain2612@gmail.com
 *  Tested on GCC 7.3.0
 * 
 *   Input
 *   2
 *   PROGRAM
 *   RAT
 *
 *   Output
 *
 *           G$          GR$        GRA$      GRAM$    GRAMP$  GRAMPR$GRAMPRO$
 *       A$  AT$ATR$
 * 
 */

#include <bits/stdc++.h>

void printPattern(std::string s)
{
   int j = 1, flag = 0, mid = s.size()/2, y = s.size()-1;
   for (int i = 0; s[i]; ++i) {
       if (s.size() % 2 ? i == mid + 1 : i == mid) {
            j = 1;
            flag = 1; 
        }
        int x = 0;
        while (x++ < y)
            cout << "  ";
        if (flag)
            cout << s.substr(mid, mid + 1) + s.substr(0, j);
        else
            cout << s.substr(mid, j);
        cout  << "$";
        --y;    ++j;
   }
}

int main(void) {
    int t = 0;
    std::cin >> t;
    while (t--) {
        std::string str = "";
        getline(std::cin, str);
        printPattern(str);
    }
    return 0;
}