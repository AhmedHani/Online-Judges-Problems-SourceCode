#include <iostream>
#include <string>
#include <stdio.h>
#include <cstring>
using namespace std;

int TestCases, Length;
char Line[105];

int main() {
//  freopen("Trojan.txt", "r", stdin);
    scanf("%d", &TestCases);
    getchar();
    while(TestCases--) {
        gets(Line);
        Length = strlen(Line);
        if(Length <= 10) {
            puts(Line);
            continue;
        }
        printf("%c%d%c\n", Line[0], Length - 2, Line[Length - 1]);
        
    }

return 0;
}
