//============================================================================
// File        : 10443 - Rock.cpp
// Author      : AHMED HANI IBRAHIM
// Copyright   : AHani
// Version     : UVa - Accepted - 0.256
// Created on September 12, 2012, 2:18 AM
//============================================================================

//#include <cstdlib>
#include <stdio.h>
//#include <string.h>
//#include <string>
#include <iostream>
//#include <map>
#include <algorithm>
//#include <functional>
#define Max 100 + 5
//#define INF 1000000000
//#define INT_MAX 2147483647
//#define FOR(i, N) for( int i = 0 ; i < N ; i++ )
#define FOR1e(i, N) for( int i = 1 ; i <= N ; i++ )
//#define FORe(i, N) for(int i = 0 ; i <= N ; i++ )
//#define FOR1(i, N) for(int i = 1 ; i < N ; i++ )

using namespace std;

int TestCases;
int Row, Column, Days;
char IntialGrid[Max][Max];
char FinalGrid[Max][Max];

bool Find(char VS, int Row, int Column){
    if ( IntialGrid[Row + 1][Column] == VS || IntialGrid[Row - 1][Column] == VS || IntialGrid[Row][Column + 1] == VS || IntialGrid[Row][Column - 1] == VS)
        return true;
    return false;
}

int main(int argc, char** argv) {
//    freopen("Trojan.txt", "r", stdin);
    
    scanf("%d", &TestCases);
    while ( TestCases -- ){
        scanf("%d %d %d", &Row, &Column, &Days);
        
        FOR1e(i, Row){
            FOR1e(j, Column){
                cin >> IntialGrid[i][j];
            }
        }
        while ( Days-- ){
            FOR1e(i, Row){
                FOR1e(j, Column){
                   switch(IntialGrid[i][j]){
                       case 'R':
                           FinalGrid[i - 1][j - 1] = (Find('P', i, j) ? 'P' : 'R');
                           break;
                       case 'P':
                           FinalGrid[i - 1][j - 1] = (Find('S', i, j) ? 'S' : 'P');
                           break;
                       case 'S':
                           FinalGrid[i - 1][j - 1] = (Find('R', i, j) ? 'R' : 'S');
                           break;
                   } 
                }
            }
        
        FOR1e(i, Row){
            FOR1e(j, Column){
                IntialGrid[i][j] = FinalGrid[i - 1][j - 1];
            }
        }
        }
        FOR1e(i, Row){
            FOR1e(j, Column){
                printf("%c",IntialGrid[i][j]);
            }
            printf("\n");
        }
        if ( TestCases )        printf("\n");
        
    }

    return 0;
}

