//============================================================================
// File        : main.cpp
// Author      : AHMED HANI IBRAHIM
// Copyright   : AHani
// Version     : 
// Created on December 2, 2012, 4:05 PM
//============================================================================

#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#define Max 50 + 5
#define INF 1000000000
//#define INT_MAX 2147483647
#define FOR(i, N) for( int i = 0 ; i < N ; i++ )
#define FOR1e(i, N) for( int i = 1 ; i <= N ; i++ )
#define FORe(i, N) for(int i = 0 ; i <= N ; i++ )
#define FOR1(i, N) for(int i = 1 ; i < N ; i++ )

using namespace std;

int First, Second;

int Solve(int Number) {
    int Result = NULL;
    int Tens = 1;
    
    while(Number) {
        if(Number % 10) {
            Result = Result + (Number % 10) * Tens;
            Tens = Tens * 10;
        }
        Number = Number / 10;
    }
    return Result;
}

int main(int argc, char** argv) {
   // freopen("Trojan.txt", "r", stdin);
    while(scanf("%d %d", &First, &Second) == 2)
        puts(Solve(First + Second) == Solve(First) + Solve(Second) ? "YES" : "NO");
    
    
    
    return 0;
}
