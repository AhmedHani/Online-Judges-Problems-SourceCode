//============================================================================
// File        : 10721 - Bar Codes.cpp
// Author      : AHMED HANI IBRAHIM
// Copyright   : AHani
// Version     : UVa - Accepted - 0.016
// Created on September 12, 2012, 8:15 PM
//============================================================================

//#include <cstdlib>
#include <stdio.h>
#include <string.h>
//#include <string>
//#include <iostream>
//#include <map>
//#include <algorithm>
//#include <functional>
#define Max 50 + 5
//#define INF 1000000000
//#define INT_MAX 2147483647
//#define FOR(i, N) for( int i = 0 ; i < N ; i++ )
#define FOR1e(i, N) for( int i = 1 ; i <= N ; i++ )
//#define FORe(i, N) for(int i = 0 ; i <= N ; i++ )
//#define FOR1(i, N) for(int i = 1 ; i < N ; i++ )

//using namespace std;

int Units, NumberOfbars, MostUnits;
long long int DPMemo[Max][Max];

long long int Solve(int i, int j){
    long long int Result = NULL;
    if ( i > Units || j > NumberOfbars) return 0;
    if ( i == Units && j == NumberOfbars )      return 1;
    if ( DPMemo[i][j] != -1 )   return DPMemo[i][j];
    
    FOR1e(ii, MostUnits){
        Result += Solve(i + ii, j + 1);
    }
    return DPMemo[i][j] = Result;
    
}

int main(int argc, char** argv) {
//    freopen("Trojan.txt", "r", stdin);
    
    while ( scanf("%d %d %d", &Units, &NumberOfbars,  &MostUnits) == 3 ){
        memset(DPMemo, -1, sizeof(DPMemo));
        printf("%lld\n", Solve(NULL, NULL));
    }

    return 0;
}

