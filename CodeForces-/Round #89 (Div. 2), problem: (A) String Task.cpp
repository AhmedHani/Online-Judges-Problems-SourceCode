#include <iostream>
#include <string>
#include <stdio.h>
#include <cstring>
using namespace std;

int Number;
char Line[105];
char V[]="aoyeui";

int main(){
  //freopen("Trojan.txt", "r", stdin);
    bool Flag;
    while(gets(Line)) {
        for(int i = 0; Line[i]; i++) {
            Flag = false;
            Line[i] = tolower(Line[i]);
            for(int j = 0; j < 6; j++) {
                if(Line[i] == V[j])     Flag = true;
            }
            if(Flag)    continue;
            printf(".%c", Line[i]);
        }
        printf("\n");
    }
    

return 0;
}
