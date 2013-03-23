//============================================================================
// File        : main.cpp
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
#include <assert.h>
#define MaxI 100 + 10
#define MaxS 100 * 25 + 5
#define INF 1000000000
//#define INT_MAX 2147483647
#define FOR(i, N) for( int i = 0 ; i < N ; i++ )
#define FOR1e(i, N) for( int i = 1 ; i <= N ; i++ )
#define FORe(i, N) for(int i = 0 ; i <= N ; i++ )
#define FOR1(i, N) for(int i = 1 ; i < N ; i++ )
#define BLUE 1
#define RED 2
#define MOD 1000000007
using namespace std;

int TestCases;
char Line[MaxI];
int Length, Sum;
int DP[MaxI][MaxS];

int Solve(int index, int sum) {
    int Result;
    if(sum < NULL) return 0;
    if(index < NULL) {
        if(sum > NULL)  return 0;
        return 1;
    }
    if(DP[index][sum] != -1)    return DP[index][sum];
    Result = 0;
    FOR(i, 26)  Result += Solve(index - 1, sum - i), Result %= MOD;
    return DP[index][sum] = Result;
}

int main(int argc, char** argv) {
   // freopen("Trojan.txt", "r", stdin);
    scanf("%d", &TestCases);
    memset(DP, -1, sizeof(DP));
    while(TestCases--) {
        scanf("%s", &Line);
        Sum = NULL;
        int Length = strlen(Line);
        FOR(i, Length)    Sum += Line[i] - 'a';
       // int Answer = (S;
        printf("%d\n", (Solve(strlen(Line) - 1, Sum) % MOD) - 1);
    }
    
    
    return 0;
}
