// GFG Sudo Placement 2 - 2.2 Middle Pattern

Example(To be used only for expected ouput):
Input
2
PROGRAM
RAT

Output

            G$          GR$        GRA$      GRAM$    GRAMP$  GRAMPR$GRAMPRO$
        A$  AT$ATR$
 

void printPattern(string s)
{
   //Your code here
   int j = 1, flag = 0, mid = s.size()/2, y = s.size()-1;
   for (int i = 0; s[i] != '\0'; ++i) {
       if (s.size() % 2 ? i == mid + 1 : i == mid) {
            j = 1;
            flag = 1; 
        }
        int x = 0;
        while (x++ < y)
            cout << "  ";
        if (flag)
            cout << s.substr(mid, mid + 1) + s.substr(0, j) << "$";
        else
            cout << s.substr(mid, j) << "$";
        --y;
        ++j;
        
   }
}