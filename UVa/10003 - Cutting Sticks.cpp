//============================================================================
// File        : 10003 - Cutting Sticks.cpp
// Author      : AHMED HANI IBRAHIM
// Copyright   : AHani
// Version     : UVa - Accepted - 0.572
// Created on September 11, 2012, 4:20 PM
//============================================================================

//#include <climits>
#include <stdio.h>
#include <string.h>
//#include <string>
//#include <iostream>
//#include <map>
#include <algorithm>
//#include <functional>
#define Max 50 + 5
#define INF 1000000000
//#define INT_MAX 2147483647
#define FOR(i, N) for( int i = 0 ; i < N ; i++ )
#define FOR1e(i, N) for( int i = 1 ; i <= N ; i++ )
#define FORe(i, N) for(int i = 0 ; i <= N ; i++ )
#define FOR1(i, N) for(int i = 1 ; i < N ; i++ )

using namespace std;

int LengthOfStick, NumberOfCuts;
int Sum[Max];
int DPMemo[Max][Max];

int Solve(int Start, int End){
    int MinCost;
    
    if ( Start + 1 == End )     return 0;
    if ( DPMemo[Start][End] != -1 )     return DPMemo[Start][End];
    
    MinCost = INF;
    
    for ( int i = Start + 1; i < End; i++ ){
        DPMemo[Start][i] = Solve(Start, i);
        DPMemo[i][End] = Solve(i, End);
        MinCost = min(MinCost, DPMemo[Start][i] + DPMemo[i][End] + Sum[End] - Sum[Start]);
    }
    return DPMemo[Start][End] = MinCost;
}

int main(int argc, char** argv) {
//    freopen("Trojan.txt", "r", stdin);
    
    while ( scanf("%d", &LengthOfStick) && LengthOfStick ){
        scanf("%d", &NumberOfCuts);
        memset(DPMemo, -1, sizeof(DPMemo));
        Sum[0] = NULL;
        
        FOR1e(i, NumberOfCuts){
            scanf("%d", &Sum[i]);
        }
        Sum[NumberOfCuts + 1] = LengthOfStick;
        printf("The minimum cutting is %d.\n", Solve(NULL, NumberOfCuts + 1));
        
    }

    return 0;
}

