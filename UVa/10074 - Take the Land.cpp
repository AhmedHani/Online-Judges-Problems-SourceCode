//============================================================================
// File        : 10074 - Take the Land.cpp
// Author      : AHMED HANI IBRAHIM
// Copyright   : AHani
// Version     : UVa - Accepted - 0.412
// Created on September 10, 2012, 7:44 PM
//============================================================================

//#include <cstdlib>
#include <stdio.h>
//#include <string.h>
//#include <string>
//#include <iostream>
//#include <map>
#include <algorithm>
//#include <functional>
#define Max 200 + 5
//#define INF 1000000000
//#define INT_MAX 2147483647
#define FOR(i, N) for( int i = 0 ; i < N ; i++ )
#define FOR1e(i, N) for( int i = 1 ; i <= N ; i++ )
#define FORe(i, N) for(int i = 0 ; i <= N ; i++ )
#define FOR1(i, N) for(int i = 1 ; i < N ; i++ )

using namespace std;

int TestCases, Row, Column;
char Grid[Max];
int Counter;
int Sum[Max][Max];

int Solve(int i, int j, int ii, int jj){
    int Answer = Sum[ii][jj];
    if (i - 1 >= NULL && j - 1 >= NULL) Answer += Sum[i - 1][j - 1];
    if (j - 1 >= NULL)  Answer -= Sum[ii][j - 1];
    if (i - 1 >= NULL)  Answer -= Sum[i - 1][jj];
    return Answer; 
}

int main(int argc, char** argv) {
//    freopen("Trojan.txt", "r", stdin);
    
//    scanf("%d %d", &Row, &Column);
    
    while ( scanf("%d %d", &Row, &Column), Row|Column ){
       
        FOR(i, Row){
            FOR(j, Column){
                scanf("%d", &Sum[i][j]);
            }
        }
        
        FOR(i, Row){
            FOR1(j, Column){
                Sum[i][j] += Sum[i][j - 1];
            }
        }
        FOR(i, Column){
            FOR1(j, Row){
                Sum[j][i] += Sum[j - 1][i];
            }
        }
        Counter = NULL;
        
        for ( int i = 0; i < Row; i++ ){
            for ( int j = 0; j < Column; j++ ){
                for ( int ii = i; ii < Row; ii++){
                    for ( int jj = j; jj < Column; jj++){
                        if ( !Solve(i, j, ii, jj))
                            Counter = max(Counter, (ii - i + 1) * (jj - j + 1));
                    }
                }
            }
        }
        printf("%d\n", Counter);
//        if (TestCases)  putchar('\n');
        
        
        
    }

    return 0;
}

