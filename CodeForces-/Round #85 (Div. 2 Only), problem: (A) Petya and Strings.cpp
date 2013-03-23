#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define Max 100 + 100
#define INF 1000000000
//#define INT_MAX 2147483647
#define FOR(i, N) for( int i = 0 ; i < N ; i++ )
#define FOR1e(i, N) for( int i = 1 ; i <= N ; i++ )
#define FORe(i, N) for(int i = 0 ; i <= N ; i++ )
#define FOR1(i, N) for(int i = 1 ; i < N ; i++ )
 
using namespace std;
 
char Input[2][Max];
 
int main(int argc, char** argv) {
   // freopen("Trojan.txt", "r", stdin);
    FOR(i, 2) {
        gets(Input[i]);
        
        for(int j = 0; Input[i][j]; j++) {
            Input[i][j] = tolower(Input[i][j]);
        }
    }
    printf("%d\n", strcmp(Input[0], Input[1]));
}
