//============================================================================
// File        : 10304 - Optimal Binary Search Tree.cpp
// Author      : AHMED HANI IBRAHIM
// Copyright   : AHani
// Version     : UVa - Accepted - 8,572
// Created on September 12, 2012, 7:31 PM
//============================================================================

//#include <cstdlib>
#include <stdio.h>
#include <string.h>
//#include <string>
//#include <iostream>
//#include <map>
#include <algorithm>
#include <functional>
#define Max 250 + 5
#define INF 1000000000
//#define INT_MAX 2147483647
#define FOR(i, N) for( int i = 0 ; i < N ; i++ )
#define FOR1e(i, N) for( int i = 1 ; i <= N ; i++ )
#define FORe(i, N) for(int i = 0 ; i <= N ; i++ )
#define FOR1(i, N) for(int i = 1 ; i < N ; i++ )

using namespace std;

int Size;
int Sum[Max];
int DP[Max][Max];

int Solve(int Start, int End){
    if ( End < Start )  return 0;
    if ( DP[Start][End] != -1 ) return DP[Start][End];
    int Min = INF;
    
    for ( int i = Start; i <= End; i++){
        Min = min(Min, Solve(Start, i - 1) + Solve(i + 1, End) + (Sum[End] - Sum[Start - 1]) - (Sum[i] - Sum[i - 1]));
    }
    return DP[Start][End] = Min;
}

int main(int argc, char** argv) {
//    freopen("Trojan.txt", "r", stdin);
    
    while( scanf("%d", &Size) != EOF){
        memset(DP, -1, sizeof(DP));
        Sum[0] = NULL;
        
        FOR1e(i, Size){
            scanf("%d", &Sum[i]);
            Sum[i] += Sum[i - 1];
        }
        
        printf("%d\n", Solve(1, Size));
    }

    return 0;
}

