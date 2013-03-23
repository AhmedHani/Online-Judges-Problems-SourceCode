//============================================================================
// File        : 10912 - Simple Minded Hashing.cpp
// Author      : AHMED HANI IBRAHIM
// Copyright   : AHani
// Version     : UVa - Accepted - 0.726
// Created on September 12, 2012, 9:24 PM
//============================================================================

//#include <cstdlib>
#include <stdio.h>
#include <string.h>
//#include <string>
//#include <iostream>
//#include <map>
//#include <algorithm>
//#include <functional>
#define MaxSum 360 
#define MaxAlpha 30
#define INF 1000000000
//#define INT_MAX 2147483647
#define FOR(i, N) for( int i = 0 ; i < N ; i++ )
//#define FOR1e(i, N) for( int i = 1 ; i <= N ; i++ )
//#define FORe(i, N) for(int i = 0 ; i <= N ; i++ )
//#define FOR1(i, N) for(int i = 1 ; i < N ; i++ )

//using namespace std;

int Length, Sum;
int DPMemo[MaxSum][MaxAlpha][MaxAlpha];

int Solve(int i, int Start, int End){
    int Result = NULL;
    if ( i == Sum && End == Length )    return 1;
    if ( End >= Length || Start > 26 || i >= Sum )  return 0;
    if ( DPMemo[i][Start][End] != -1 )  return DPMemo[i][Start][End];
    
    for ( int ii = Start; ii < 27; ii++ )       Result += Solve(i + ii, ii + 1, End + 1);
    return DPMemo[i][Start][End] = Result;
}

int main(int argc, char** argv) {
//    freopen("Trojan.txt", "r", stdin);
    int Cases = 1;
    while ( scanf("%d %d", &Length, &Sum), Length|Sum ){
            memset(DPMemo, -1, sizeof(DPMemo));
            printf("Case %d: %d\n", Cases++, Solve(NULL, 1, NULL));
    }

    return 0;
}

