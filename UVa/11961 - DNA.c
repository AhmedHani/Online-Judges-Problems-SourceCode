//============================================================================
// File        : 11961 - DNA.c
// Author      : AHMED HANI IBRAHIM
// Copyright   : AHani
// Version     : UVa - Accepted - 0.019 (Rank 11)
// Created on August 21, 2013, 2:25 PM
//============================================================================
 
#include <stdio.h>
#include <stdlib.h>
#define Max 100000 + 5
#define INF 1000000000
#define FOR(i, N) for( i = 0 ; i < N ; i++ )
 
int TestCases; 
int Length, K;
char Sequence[Max];
char Out[Max];
int Result;

void Solve(int Index, int Current) {
    if(Current > K) return;
    if(Index == Length) {
        Result++;
        return;
    }
    Out[Index] = 'A';
    Solve(Index + 1, Current + (Out[Index] != Sequence[Index]));
    Out[Index] = 'C';
    Solve(Index + 1, Current + (Out[Index] != Sequence[Index]));
    Out[Index] = 'G';
    Solve(Index + 1, Current + (Out[Index] != Sequence[Index]));
    Out[Index] = 'T';
    Solve(Index + 1, Current + (Out[Index] != Sequence[Index]));
}

void Print(int Index, int Current) {
    if(Current > K) return;
    if(Index == Length) {
        Out[Index] = '\0';
        puts(Out);
        return;
    }
    Out[Index] = 'A';
    Print(Index + 1, Current + (Out[Index] != Sequence[Index]));
    Out[Index] = 'C';
    Print(Index + 1, Current + (Out[Index] != Sequence[Index]));
    Out[Index] = 'G';
    Print(Index + 1, Current + (Out[Index] != Sequence[Index]));
    Out[Index] = 'T';
    Print(Index + 1, Current + (Out[Index] != Sequence[Index]));
}

int main(int argc, char** argv) {
    freopen("Trojan.txt", "r", stdin);
    scanf("%d", &TestCases);
    while(TestCases-- > 0) {
        scanf("%d %d", &Length, &K);
        Result = 0;
        scanf("%s", Sequence);
        Solve(0, 0);
        printf("%d\n", Result);
        Print(0, 0);
    }
    
    return (EXIT_SUCCESS);
}
 
