//============================================================================
// File        : 10616 - Divisible Group Sums.cpp
// Author      : AHMED HANI IBRAHIM
// Copyright   : AHani
// Version     : UVa - Accepted - 0.028
// Created on September 13, 2012, 11:44 PM
//============================================================================

//#include <cstdlib>
#include <stdio.h>
#include <string.h>
//#include <string>
//#include <iostream>
//#include <map>
//#include <algorithm>
#include <cmath>
#define N 200 + 5
#define D 10 + 5
#define M 20 + 5
#define INF 1000000000
//#define INT_MAX 2147483647
#define FOR(i, N) for( int i = 0 ; i < N ; i++ )
#define FOR1e(i, N) for( int i = 1 ; i <= N ; i++ )
#define FORe(i, N) for(int i = 0 ; i <= N ; i++ )
#define FOR1(i, N) for(int i = 1 ; i < N ; i++ )

//using namespace std;

int Numbers, NumberOfQuaries;
int Sequence[N];
int DPMemo[N][D][M];
int TargetDiv, Chosen;

int NegativeMod(int X, int Y){
    return (X % Y + Y) % Y;
}

int Solve(int Num, int Chosen, int Sum){
    if ( Num == NULL && Chosen != NULL )   return 0;
    if (!Chosen) return DPMemo[Num][Chosen][Sum]=( Sum == 0 );
    if ( DPMemo[Num][Chosen][Sum] != -1 )        return DPMemo[Num][Chosen][Sum];

    return DPMemo[Num][Chosen][NegativeMod(Sum, TargetDiv)] = Solve(Num - 1, Chosen - 1, NegativeMod(Sum - Sequence[Num - 1], TargetDiv)) + Solve(Num - 1, Chosen, Sum);
}

int main(int argc, char** argv) {
//    freopen("Trojan.txt", "r", stdin);
    int Cases = 1;
    
    while ( scanf("%d %d", &Numbers, &NumberOfQuaries), Numbers|NumberOfQuaries ){
        printf("SET %d:\n",Cases++);
       
        FOR(i, Numbers){
            scanf("%d", &Sequence[i]);
        }
 
        FOR1e(i, NumberOfQuaries){
            scanf("%d %d", &TargetDiv, &Chosen);
            memset(DPMemo, -1, sizeof(DPMemo));
            printf("QUERY %d: %d\n", i, Solve(Numbers, Chosen, TargetDiv));
            
        }
    }
    

    return 0;
}

