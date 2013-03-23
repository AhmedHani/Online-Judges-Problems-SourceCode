//============================================================================
// File        : 10465 - Homer Simpson.cpp
// Author      : AHMED HANI IBRAHIM
// Copyright   : AHani
// Version     : UVa - Accepted - 1.756
// Created on September 11, 2012, 6:31 PM
//============================================================================

//#include <cstdlib>
#include <stdio.h>
#include <string.h>
//#include <string>
//#include <iostream>
//#include <vector>
#include <algorithm>
//#include <functional>
#define Max 100005
#define INF 1000000000
//#define INT_MAX 2147483647
//#define FOR(i, N) for( int i = 0 ; i < N ; i++ )
//#define FOR1e(i, N) for( int i = 1 ; i <= N ; i++ )
//#define FORe(i, N) for(int i = 0 ; i <= N ; i++ )
//#define FOR1(i, N) for(int i = 1 ; i < N ; i++ )

using namespace std;

int KrustBurger, AbuBurger, TotalTime;
int N, M, Enough, A, B;
int DPWays1Memo[Max], DPWays2Memo[Max];

int FirstWay(int i, int j){
    if ( i == 0 )       return i;
    if ( i - N < NULL && i - M < NULL && i > NULL)      return i;
    if ( (i - N < NULL || i - M < NULL) && i < NULL )   return INF;
    if ( DPWays1Memo[i] != -1 ) return DPWays1Memo[i];
    return DPWays1Memo[i] = min(FirstWay(i - N, j + 1), FirstWay(i - M, j + 1));
}

int SecondWay(int i, int j){
    if ( i == Enough )  return j;
    if ( i < NULL )     return 0;
    if ( DPWays2Memo[i] != -1 ) return DPWays2Memo[i];
    return DPWays2Memo[i] = max(SecondWay(i - N, j + 1), SecondWay(i - M, j + 1));
}

int main(int argc, char** argv) {
//    freopen("Trojan.txt", "r", stdin);
    
    while ( scanf("%d %d %d", &KrustBurger, &AbuBurger, &TotalTime) == 3 ){
        N = max(KrustBurger, AbuBurger);
        M = min(KrustBurger, AbuBurger);
        
        memset(DPWays1Memo, -1, sizeof(DPWays1Memo));
        memset(DPWays2Memo, -1, sizeof(DPWays2Memo));
        
        Enough = NULL;
        A = FirstWay(TotalTime, NULL);
        Enough = A;
        B = SecondWay(TotalTime, NULL);
        
        if (A == NULL) printf("%d\n", B);
        else    printf("%d %d\n", B, A);
        
    }

    return 0;
}

