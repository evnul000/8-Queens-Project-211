// Hossain, Evnul
// CS211  Waxman
#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int queen[8] = {0}, r = 0, c = 0, solutionNum = 1;
    
    queen[0] = 0;
    
next_col:
    c++;
    if(c == 8) goto print;
    
    queen[c] = -1;
    
next_row:
    queen[c]++;
    
    if(queen[c] == 8) goto backtrack;
    
    // row test
    for(int i = 0; i < c; i++)
        if((queen[i] == queen[c]) || ((c - i) == abs(queen[c] - queen[i]))) goto next_row;

    goto next_col;
    
backtrack:
    c--;
    if(c == -1) return 0;
    
    goto next_row;
    
print:
    cout << "Solution " << solutionNum << endl;
    for (int a = 0; a <= 7; a++) {
        for (int d = 0; d <= 7; d++) {
            if(queen[a] == d)
                cout << "1";
            else {
                cout <<"0";
            }
        }
        cout << endl;
    }
    
    solutionNum++;
    goto backtrack;
    
}