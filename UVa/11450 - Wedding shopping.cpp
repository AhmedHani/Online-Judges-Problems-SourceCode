//============================================================================
// File        : 11450 - Wedding shopping.cpp
// Author      : AHMED HANI IBRAHIM
// Copyright   : AHani
// Version     : UVa - Accepted - 0.032
// Created on September 12, 2012, 11:50 PM
//============================================================================

//#include <cstdlib>
#include <stdio.h>
#include <string.h>
//#include <string>
//#include <iostream>
//#include <map>
#include <algorithm>
#include <functional>
#define Max 200 + 5
#define INF 1000000000
//#define INT_MAX 2147483647
#define FOR(i, N) for( int i = 0 ; i < N ; i++ )
#define FOR1e(i, N) for( int i = 1 ; i <= N ; i++ )
#define FORe(i, N) for(int i = 0 ; i <= N ; i++ )
#define FOR1(i, N) for(int i = 1 ; i < N ; i++ )

using namespace std;

int TestCases, Money, Garments, NumberOfItems;
int Items[Max][Max];
int DPMemo[Max][Max];

int Solve(int i, int Cost){
 
    if ( Cost < NULL )  return -INF;
    else if ( i == Garments && Cost >= 0 )   return 0;
    else if ( DPMemo[i][Cost] != -1) return DPMemo[i][Cost];
    else{   
        int Maximum = -INF;
        int NumberOfItems = Items[i][0];
        for ( int j = 1; j <= NumberOfItems; j++ )
            Maximum = max(Maximum, Items[i][j] + Solve(i + 1, Cost - Items[i][j]));
        return DPMemo[i][Cost] = Maximum;
        
    }
}

int main(int argc, char** argv) {
//    freopen("Trojan.txt", "r", stdin);
    scanf("%d", &TestCases);
    
    while ( TestCases -- ){
        memset(DPMemo, -1, sizeof(DPMemo));
        scanf("%d %d", &Money, &Garments);
        
        FOR(i, Garments){
            scanf("%d", Items[i]);
            FOR1e(j, Items[i][0]){
                scanf("%d", &Items[i][j]);
            }
            
           
        }
        
        if ( Solve(NULL, Money) > NULL )        printf("%d\n", Solve(NULL, Money));
        else puts("no solution");
        
        
        
    }

    return 0;
}

