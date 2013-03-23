#include <iostream>
#include <string>
#include <stdio.h>
#include <cstring>
using namespace std;

int Number;
char Line[100];

int main(){
  //freopen("Trojan.txt", "r", stdin);
  while(scanf("%d", &Number) == 1)      puts((Number % 2 || Number == 2) ? "NO" : "YES");
    
return 0;
}
