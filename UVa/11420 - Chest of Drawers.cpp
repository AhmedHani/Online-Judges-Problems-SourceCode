//============================================================================
// File        : 11420 - Chest of Drawers.cpp
// Author      : AHMED HANI IBRAHIM
// Copyright   : AHani
// Version     : UVa - Accepted - 0.104
// Created on September 12, 2012, 10:06 PM
//============================================================================

//#include <cstdlib>
#include <stdio.h>
#include <string.h>
//#include <string>
//#include <iostream>
//#include <map>
//#include <algorithm>
//#include <functional>
#define Max 65 + 5
#define MaxL 2
//#define INF 1000000000
//#define INT_MAX 2147483647
//#define FOR(i, N) for( int i = 0 ; i < N ; i++ )
//#define FOR1e(i, N) for( int i = 1 ; i <= N ; i++ )
//#define FORe(i, N) for(int i = 0 ; i <= N ; i++ )
//#define FOR1(i, N) for(int i = 1 ; i < N ; i++ )

//using namespace std;

int NumberOfDrawers, Secured;
long long int DPMemo[Max][Max][MaxL];

long long int Solve(int N, int Start, int Lock){
    if ( N == NULL && Start == NULL )   return 1;
    else if ( Start > N || N < NULL || Start < NULL )        return 0;
    else if ( DPMemo[N][Start][Lock] != -1 )  return DPMemo[N][Start][Lock];
    else{
        if ( !Lock )   return DPMemo[N][Start][Lock] = Solve(N - 1, Start - 1 , NULL) + Solve(N - 1, Start, 1) ;
        else
           return DPMemo[N][Start][Lock] = Solve(N - 1, Start  , NULL) + Solve(N - 1, Start, 1);
    }
}

int main(int argc, char** argv) {
//    freopen("Trojan.txt", "r", stdin);
    
    while ( scanf("%d %d", &NumberOfDrawers, &Secured) == 2){
        if ( NumberOfDrawers <= NULL && Secured <= NULL )       break;
        memset(DPMemo, -1, sizeof(DPMemo));
        printf("%lld\n", Solve(NumberOfDrawers, Secured, NULL));
    }

    return 0;
}

