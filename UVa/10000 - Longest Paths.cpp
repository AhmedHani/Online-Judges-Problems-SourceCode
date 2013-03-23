//============================================================================
// File        : 10000 - Longest Paths.cpp
// Author      : AHMED HANI IBRAHIM
// Copyright   : AHani
// Version     : UVa - Accepted - 0.088
// Created on August 23, 2012, 11:27 PM
//============================================================================

#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include<string>
#include<iostream>
#include<map>
#include<algorithm>
#include<functional>
#define Max 100 + 5
#define INF 1000000000
//#define INT_MAX 2147483647
#define FOR(i , N) for( int i = 0 ; i < N ; i++ )
#define FOR1e(i , N) for( int i = 1 ; i <= N ; i++ )
#define FORe(i , N) for(int i = 0 ; i <= N ; i++ )
#define FOR1(i , N) for(int i = 1 ; i < N ; i++ )

using namespace std;

int NumberOfPoints , StartPoint , First , Second;
int Distance[Max][Max];

int main(int argc, char** argv) {
    freopen("Trojan.txt", "r", stdin);
    int Cases = 1;
    
    while ( scanf("%d" , &NumberOfPoints) && NumberOfPoints ){
        FORe(i , NumberOfPoints){
            Distance[i][i] = 0;
        }
        memset(Distance , -1 , sizeof(Distance));
        scanf("%d" , &StartPoint);
        
        while ( scanf("%d %d" , &First , &Second) , First|Second ){
           
            Distance[First][Second] = 1;
        }
        
        FOR1e(k , NumberOfPoints){
            FOR1e(i , NumberOfPoints){
                if ( Distance[i][k] != -1){
                FOR1e(j , NumberOfPoints){
                    if ( Distance[k][j] != -1 )
                        Distance[i][j] = max(Distance[i][j] , Distance[i][k] + Distance[k][j]);
                }
            }
        }
        }
        int Length = 0;
        int End ;
        
        FOR1e(j , NumberOfPoints){
            if ( Length < Distance[StartPoint][j] ){
                Length = Distance[StartPoint][j];
                End = j;
            }
        }
        printf ("Case %d: The longest path from %d has length %d, finishing at %d.\n\n",Cases++, StartPoint, Length, End);

    }

    return 0;
}

