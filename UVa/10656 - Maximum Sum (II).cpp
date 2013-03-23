//============================================================================
// File        : 10656 - Maximum Sum (II).cpp
// Author      : AHMED HANI IBRAHIM
// Copyright   : AHani
// Version     : UVa - Accepted - 10656
// Created on September 15, 2012, 3:07 PM
//============================================================================

//#include <cstdlib>
#include <stdio.h>
//#include <string.h>
//#include <string>
//#include <iostream>
//#include <map>
//#include <algorithm>
//#include <functional>
#define Max 10000 + 5
#define INF 1000000000
//#define INT_MAX 2147483647
#define FOR(i, N) for( int i = 0 ; i < N ; i++ )
#define FOR1e(i, N) for( int i = 1 ; i <= N ; i++ )
#define FORe(i, N) for(int i = 0 ; i <= N ; i++ )
#define FOR1(i, N) for(int i = 1 ; i < N ; i++ )

using namespace std;

int Numbers;
int Sequence[Max];
bool Space;

int main(int argc, char** argv) {
//    freopen("Trojan.txt", "r", stdin);
    
    while ( scanf("%d", &Numbers) && Numbers){
        Space = false;
        
        FOR(i, Numbers){
            scanf("%d", &Sequence[i]);
        }
        
        FOR(i, Numbers){
            if ( Sequence[i] != NULL ){
                if ( Space )    printf(" ");
                Space = true;
                printf("%d", Sequence[i]);
            }
        }
        if ( !Space )   printf("0");
        printf("\n");
    }

    return 0;
}

