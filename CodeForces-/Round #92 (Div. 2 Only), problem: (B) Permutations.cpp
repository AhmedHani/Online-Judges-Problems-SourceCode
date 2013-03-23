//============================================================================
// File        : CodeForces#92 DivII (B).cpp
// Author      : AHMED HANI IBRAHIM
// Copyright   : AHani
// Version     : 
// Created on February 12, 2013, 10:22 AM
//============================================================================

#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#define Max 10 + 5
#define INF 1000000000
//#define INT_MAX 2147483647
#define FOR(i, N) for( int i = 0 ; i < N ; i++ )
#define FOR1e(i, N) for( int i = 1 ; i <= N ; i++ )
#define FORe(i, N) for(int i = 0 ; i <= N ; i++ )
#define FOR1(i, N) for(int i = 1 ; i < N ; i++ )
#define BLUE 1
#define RED 2
using namespace std;

char Number[Max][Max];
int All[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
int Row, Colmuns;
int Value, Minimum, Maximum, Result;

int main(int argc, char** argv) {
   // freopen("Trojan.txt", "r", stdin);
    scanf("%d %d", &Row, &Colmuns);
    Result = INF;
    Minimum = INF;
    Maximum = -INF;
    FOR(i, Row) scanf("%s", Number[i]);
    
    do {
        FOR(i, Row) {
            Value = 0;
            FOR(j, Colmuns)     Value = Value * 10 + Number[i][All[j]];
            if(i == 0 || Value < Minimum)       Minimum = Value;
            if(i == 0 || Value > Maximum)       Maximum = Value;
        }
        if(Result > Maximum - Minimum)  Result = Maximum - Minimum;
    } while(next_permutation(All, All + Colmuns));
    
    printf("%d\n", Result);
    return 0;
}
