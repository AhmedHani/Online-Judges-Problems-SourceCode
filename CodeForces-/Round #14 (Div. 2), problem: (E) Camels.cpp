//============================================================================
// File        : main.cpp
// Author      : AHMED HANI IBRAHIM
// Copyright   : AHani
// Version     : 
// Created on February 5, 2013, 7:44 AM
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
#define BLUE 1
#define RED 2
#define LL long long
using namespace std;

int N, T;
LL Memo[Max][10][10][12][12];

LL solve(int Index, int Last1, int Last2, int Counter1, int Counter2) {
    if (Index == N) {
        if (Counter1 == T && Counter2 == T - 1)
            return 1;
        return 0;
    }
    if (Counter1 > T)
        return 0;
    if (Counter2 > T - 1)
        return 0;
    LL &Result = Memo[Index][Last1][Last2][Counter1][Counter2];
    if (Result < 0) {
        Result = 0;
        FOR(i, 4) if (i != Last2) {
            if (Last1 == 4 || Last2 == 4) {
                Result += solve(Index + 1, Last2, i, Counter1, Counter2);
            } else {
                int Count1 = Counter1;
                int Count2 = Counter2;
                if (Last1 < Last2 && Last2 > i)
                    ++Count1;
                if (Last1 > Last2 && Last2 < i)
                    ++Count2;
                Result += solve(Index + 1, Last2, i, Count1, Count2);
            }
        }
    }
    return Result;
}

int main(int argc, char** argv) {
      // freopen("Trojan.txt", "r", stdin);
    scanf("%d %d", &N, &T);
    memset(Memo, -1, sizeof(Memo));
    cout << solve(0, 4, 4, 0, 0) << endl;
    
    return 0;
}
