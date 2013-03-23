//============================================================================
// File        : 10036 - Divisibility.cpp
// Author      : AHMED HANI IBRAHIM
// Copyright   : AHani
// Version     : UVa - Accepted - 0.308
// Created on September 13, 2012, 8:25 PM
//============================================================================

#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>
#include <map>
#include <algorithm>
#include <functional>
#define Max 100 + 5
#define MaxS 10005
#define INF 1000000000
//#define INT_MAX 2147483647
#define FOR(i, N) for( int i = 0 ; i < N ; i++ )
#define FOR1e(i, N) for( int i = 1 ; i <= N ; i++ )
#define FORe(i, N) for(int i = 0 ; i <= N ; i++ )
#define FOR1(i, N) for(int i = 1 ; i < N ; i++ )

using namespace std;

int TestCases, NumberOfSequence, Target;
int Sequence[MaxS];
int DPMemo[Max][MaxS];

int NegativeMod(int Sum,int Targ){
    return (Sum % Targ + Targ) % Targ;
}

int Solve(int Value, int Index){
//    int ResultM = NegativeMod(Value, Target);
    if ( Index == NumberOfSequence ){
        if ( NegativeMod(Value, Target) == NULL )      return 1;
        else    return 0;
    }
    if ( DPMemo[NegativeMod(Value, Target)][Index] != -1 )   return DPMemo[NegativeMod(Value, Target)][Index];
    
    return DPMemo[NegativeMod(Value, Target)][Index] = max( Solve(Value - Sequence[Index], Index + 1), Solve(Value + Sequence[Index], Index + 1));
}

int main(int argc, char** argv) {
//    freopen("Trojan.txt", "r", stdin);
    
    scanf("%d", &TestCases);
    while ( TestCases-- ){
        memset(DPMemo, -1, sizeof(DPMemo));
        scanf("%d %d", &NumberOfSequence, &Target);
        
        FOR(i, NumberOfSequence){
            scanf("%d", &Sequence[i]);
        }
        
        if ( Solve(NULL, NULL) != NULL )        printf("Divisible\n");
        else    printf("Not divisible\n"); 

        
    }

    return 0;
}

