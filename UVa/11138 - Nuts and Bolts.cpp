//============================================================================
// File        : 11138 - Nuts and Bolts.cpp
// Author      : AHMED HANI IBRAHIM
// Copyright   : AHani
// Version     : UVa - Accepted - 0.028
// Created on December 15, 2012, 10:57 PM
//============================================================================

#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>
#include <map>
#include <algorithm>
#include <functional>
#define Max 500 + 5
#define INF 1000000000
//#define INT_MAX 2147483647
#define FOR(i, N) for( int i = 0 ; i < N ; i++ )
#define FOR1e(i, N) for( int i = 1 ; i <= N ; i++ )
#define FORe(i, N) for(int i = 0 ; i <= N ; i++ )
#define FOR1(i, N) for(int i = 1 ; i < N ; i++ )

using namespace std;

int TestCases;
int First, Second;
int Result;
int Matrix[Max][Max];
int Left[Max], Right[Max];
bool Visited[Max];

int DFS(int Source) {
    FOR(i, Second) {
        if(Matrix[Source][i] && !Visited[i]) {
            Visited[i] = true;
            if(Right[i] < NULL || DFS(Right[i])) {
                Right[i] = Source;
                Left[Source] = i;
                return 1;
            }
        }
    }
    return 0;
}

int main(int argc, char** argv) {
   //freopen("Trojan.txt", "r", stdin);
    int Cases = 1;
    scanf("%d", &TestCases);
    while(TestCases--) {
        scanf("%d %d", &First, &Second);
        FOR(i, First) {
            Left[i] = -INF;
            FOR(j, Second) {
                Right[j] = -INF;
                scanf("%d", &Matrix[i][j]);
            }
        }
        Result = NULL;
        FOR(i, First) {
            memset(Visited, false, sizeof(Visited));
            Result += DFS(i);
        }
        printf("Case %d: a maximum of %d nuts and bolts can be fitted together\n", Cases++, Result);
    }

    return 0;
}

