//============================================================================
// File        : 10482 - The Candyman Can.cpp
// Author      : AHAMED HANI IBRAHIM
// Copyright   : AHani
// Version     : UVa - Accepted - 0.564
// Created on September 15, 2012, 9:32 PM
//============================================================================

#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>
#include <map>
#include <algorithm>
#include <functional>
#define MaxI 30 + 5
#define MaxW 20 * 32
#define Max 200
#define INF 1000000000
//#define INT_MAX 2147483647
#define FOR(i, N) for( int i = 0 ; i < N ; i++ )
#define FOR1e(i, N) for( int i = 1 ; i <= N ; i++ )
#define FORe(i, N) for(int i = 0 ; i <= N ; i++ )
#define FOR1(i, N) for(int i = 1 ; i < N ; i++ )

using namespace std;

int TestCases, Items;
int Weights[MaxI];
int DPMemo[MaxI][MaxW][MaxW];

int Solve(int Index, int One, int Others){
    int A, B, C;
    
    if ( Index == Items )       return max(One, Others);
    if ( DPMemo[Index][One][Others] != -1 && DPMemo[Index][Others][One] != -1 )
        return min(DPMemo[Index][One][Others], DPMemo[Index][Others][One]);
    if ( DPMemo[Index][One][Others] != -1 )    return DPMemo[Index][One][Others];
    if ( DPMemo[Index][Others][One] != -1 )    return DPMemo[Index][Others][One];
    
    A = Solve(Index + 1, One + Weights[Index], Others + Weights[Index]);
    if ( One - Weights[Index] >= NULL ){
        B = Solve(Index + 1, abs(One - Weights[Index]), Others);
    }else{
        B = Solve(Index + 1, abs(One - Weights[Index]), Others + (abs(One - Weights[Index])));
    }
    if ( Others - Weights[Index] >= NULL ){
        C = Solve(Index + 1, One, abs(Others - Weights[Index]));
    }else{
        C = Solve(Index + 1, One + (abs(Others - Weights[Index])), abs(Others - Weights[Index]));
    }
    return DPMemo[Index][One][Others] = min(A, min(B, C));
    
}

int main(int argc, char** argv) {
//    freopen("Trojan.txt", "r", stdin);
    int Cases = 1;
    
    scanf("%d", &TestCases);
    while( TestCases-- ){
        
        scanf("%d", &Items);
        FOR(i, Items)   scanf("%d", &Weights[i]);
        
        FOR(i, Items)  FORe(j, Items * 20)  FORe(k, Items * 20)   DPMemo[i][j][k] = -1;
        printf("Case %d: %d\n", Cases++, Solve(NULL, NULL, NULL));
        
    }
    

    return 0;
}

