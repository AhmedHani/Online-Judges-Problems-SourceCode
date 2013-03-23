//============================================================================
// File        : 10891 - Game of Sum.cpp
// Author      : AHMED HANI IBRAHIM
// Copyright   : AHani
// Version     : UVa - Accepted - 0.072
// Created on September 10, 2012, 2:49 PM
//============================================================================

//#include <cstdlib>
#include <stdio.h>
#include <string.h>
//#include <string>
//#include <iostream>
//#include <map>
#include <algorithm>
//#include <functional>
#define Max 200 + 5
#define INF 1000000000
//#define INT_MAX 2147483647
#define FOR(i, N) for( int i = 0 ; i < N ; i++ )
#define FOR1e(i, N) for( int i = 1 ; i <= N ; i++ )
#define FORe(i, N) for(int i = 0 ; i <= N ; i++ )
#define FOR1(i, N) for(int i = 1 ; i < N ; i++ )

using namespace std;

int NumberOfElements;
int Sum[Max];
int DP[Max][Max];

int Solve(int Begin, int End){
    int Maximum = -INF;
    
    if ( End < Begin )  return 0;
    if ( DP[Begin][End] != -1 )  return DP[Begin][End];
    
    for ( int i = Begin ; i <= End ; i++ ){
        Maximum = max(Maximum, Sum[End] - Sum[Begin - 1] - Solve(i + 1, End));
    }for( int i = End ; i >= Begin ; i-- ){
        Maximum = max(Maximum, Sum[End] - Sum[Begin - 1] - Solve(Begin, i - 1));
    }
    return DP[Begin][End] = Maximum;
    
    
}

int main(int argc, char** argv) {
//    freopen("Trojan.txt", "r", stdin);
    
    while ( scanf("%d", &NumberOfElements) && NumberOfElements ){
        memset(DP, -1, sizeof(DP));
        memset(Sum, 0, sizeof(Sum));
        
        Sum[0] = NULL;
        
        FOR1e(i, NumberOfElements){
            scanf("%d", &Sum[i]);
            Sum[i] += Sum[i - 1];
        }
        
        printf("%d\n", 2 * Solve(1, NumberOfElements) - Sum[NumberOfElements]);
        
    }

    return 0;
}

