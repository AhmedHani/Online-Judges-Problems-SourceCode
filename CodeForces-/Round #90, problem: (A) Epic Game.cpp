#include <iostream>
#include <string>
#include <stdio.h>
#include <cstring>
using namespace std;

int First, Second, Stones;

int GCD(int X, int Y) {
    return X == NULL ? Y : GCD(Y % X, X);
}

int main() {
  //freopen("Trojan.txt", "r", stdin);
    scanf("%d %d %d", &First, &Second, &Stones);
    int Turn = NULL;
    
    while(Stones >= NULL) {
        ++Turn;
        Stones = Stones - GCD((Turn % 2) ?  First : Second , Stones);
    }
    printf((Turn % 2) ? "1" : "0");

return 0;
}
