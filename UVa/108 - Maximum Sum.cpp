//============================================================================
// File        : 108 - Maximum Sum.cpp
// Author      : AHMED HANI IBRAHIM
// Copyright   : AHani
// Version     : UVa - Accepted - 0.104
// Created on September 9, 2012, 1:12 PM
//============================================================================

//#include <cstdlib>
#include <stdio.h>
#include <string.h>
//#include <string>
//#include <iostream>
//#include <map>
//#include <algorithm>
//#include <functional>
#define Max 200 + 5
//#define INF 1000000000
//#define INT_MAX 2147483647
#define FOR(i, N) for( int i = 0 ; i < N ; i++ )
#define FOR1e(i, N) for( int i = 1 ; i <= N ; i++ )
#define FORe(i, N) for(int i = 0 ; i <= N ; i++ )
#define FOR1(i, N) for(int i = 1 ; i < N ; i++ )

//using namespace std;


long Value[Max][Max];
int Size;
long Maximum;
int Grid[Max][Max];

int main(int argc, char** argv) {
//    freopen("Trojan.txt", "r", stdin);
    
    while ( scanf("%d", &Size) != EOF ){
        Maximum = NULL;
          memset(Value, 0, sizeof(Value));
        
        FOR1e(i, Size){
            FOR1e(j, Size){
                scanf("%d", &Grid[i][j]);
            }
        }
        
        FOR1e(i, Size){
            FOR1e(j, Size){
                FOR1e(ii, i){
                    FOR1e(jj, j){
                        Value[i][j] += Grid[ii][jj];
                    }
                }
            }
        }
        
        FORe(i, Size)
            FORe(j, Size)
                FORe(ii, i)
                    FORe(jj, j){
                        long Tmp = Value[i][j] - Value[i][jj] - Value[ii][j] + Value[ii][jj];
                        if ( Tmp > Maximum )
                            Maximum = Tmp;
                    }
                
            
        
        
        printf("%ld\n", Maximum);
      
    }

    return 0;
}

