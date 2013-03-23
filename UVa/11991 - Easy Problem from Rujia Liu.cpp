//============================================================================
// File        : 11991 - Easy Problem from Rujia Liu?.cpp
// Author      : AHMED HANI IBRAHIM
// Copyright   : AHani
// Version     : UVa - Accepted - 0.244
// Created on January 30, 2013, 12:26 AM
//============================================================================

#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>
#include <map>
#include <algorithm>
#include <functional>
#include <vector>
#define Max 1000000 + 10
#define INF 1000000000
//#define INT_MAX 2147483647
#define FOR(i, N) for( int i = 0 ; i < N ; i++ )
#define FOR1e(i, N) for( int i = 1 ; i <= N ; i++ )
#define FORe(i, N) for(int i = 0 ; i <= N ; i++ )
#define FOR1(i, N) for(int i = 1 ; i < N ; i++ )

using namespace std;

int Size, Queries;
int First, Second;
int Numbers[Max];
vector<int> AdjList[Max];

int main(int argc, char** argv) {
   // freopen("Trojan.txt", "r", stdin);
    while(scanf("%d %d", &Size, &Queries) == 2) {
        FOR(i, Max)     AdjList[i].clear();
        FOR(i, Size)    scanf("%d", &Numbers[i]);
        FOR(i, Size)    AdjList[Numbers[i]].push_back(i + 1);
        FOR(i, Queries) scanf("%d %d", &First, &Second), printf(AdjList[Second].size() < First ? "0\n" : "%d\n", AdjList[Second][First - 1]);
    }

    return 0;
}

