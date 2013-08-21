//============================================================================
// File        : 1121 - Subsequence.c
// Author      : AHMED HANI IBRAHIM
// Copyright   : AHani
// Version     : UVa - Accepted - 0.144
// Created on August 21, 2013, 1:19 PM
//============================================================================
 
#include <stdio.h>
#include <stdlib.h>
#define Max 100000 + 5
#define INF 1000000000
#define FOR(i, N) for( i = 0 ; i < N ; i++ )
 
 
int Numbers, Sum;
int CurrentSum, Index;
int Arr[Max];
int i, j;
 
int main(int argc, char** argv) {
    
    while(scanf("%d %d", &Numbers, &Sum) == 2) {
        CurrentSum = 0;
        Index = -1;
        FOR(i, Numbers) scanf("%d", &Arr[i]);
        int Minimum = INF;
        FOR(i, Numbers) {
            while(CurrentSum < Sum && Index + 1 < Numbers) CurrentSum += Arr[++Index];
            if(Minimum > Index - i && CurrentSum >= Sum) Minimum = Index - i;
            CurrentSum -= Arr[i];
        }
        printf(Minimum == INF ? "0\n" : "%d\n", Minimum + 1);
    }
 
    return (EXIT_SUCCESS);
}
 
