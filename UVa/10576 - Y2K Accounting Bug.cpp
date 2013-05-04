//============================================================================
// File        : 10576 - Y2K Accounting Bug.cpp
// Author      : AHMED HANI IBRAHIM
// Copyright   : AHani
// Version     : UVa - Accepted - 0.272
// Created on May 04, 2013, 04:31 PM
//============================================================================

#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <set>
#include <bitset>
#include <iomanip>
#include <map>
#define Max 100050 + 5
#define INF 1000000000
//#define INT_MAX 2147483647
#define FOR(i, N) for( int i = 0 ; i < N ; i++ )
#define FOR1e(i, N) for( int i = 1 ; i <= N ; i++ )
#define FORe(i, N) for(int i = 0 ; i <= N ; i++ )
#define FOR1(i, N) for(int i = 1 ; i < N ; i++ )

using namespace std;

int Surplus, Defcite;
int AllSurplus, FiveMonths, Result;
bool Flag;

int main(int argc, char** argv) {
    freopen("Trojan.txt", "r", stdin);
    while(scanf("%d %d", &Surplus, &Defcite) == 2) {
        Result = -1;
        Flag = true;
        FOR(Mask, (1 << 12)) {
            AllSurplus = 0;
            Flag = true;
            FOR(i, 12) {
                (Mask & (1 << i)) != 0 ? AllSurplus += Surplus : AllSurplus -= Defcite;
                if(i + 5 <= 12) {
                    FiveMonths = 0;
                    for(int j = i; j < i + 5; j++) {
                        (Mask & (1 << j)) != 0 ? FiveMonths += Surplus : FiveMonths -= Defcite;
                    }
                    if(FiveMonths >= NULL)Flag = false;
                }
            }
            if(Flag)    Result = max(Result, AllSurplus);
        }
        if(Result == -1)        puts("Deficit");
        else                    printf("%d\n", Result);
    }
    
    return 0;
}

