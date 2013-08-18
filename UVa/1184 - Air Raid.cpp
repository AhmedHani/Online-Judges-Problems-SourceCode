//============================================================================
// File        : 1184 - Air Raid.cpp
// Author      : AHMED HANI IBRAHIM
// Copyright   : AHani
// Version     : UVa - Accepted - 0.144
// Created on August 18, 2013, 6:00 AM
//============================================================================

#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <queue>
#define Max 500 + 5
#define MaxDirection 4
#define INF 1000000000
//#define INT_MAX 2147483647
#define FOR(i, N) for( int i = 0 ; i < N ; i++ )
#define FOR1e(i, N) for( int i = 1 ; i <= N ; i++ )
#define FORe(i, N) for(int i = 0 ; i <= N ; i++ )
#define FOR1(i, N) for(int i = 1 ; i < N ; i++ )

using namespace std;

int TestCases;
vector<int> AdList[Max];
int Match[Max];
bool Visited[Max];
int Minimum;
int First, Second;
int NumberOfNodes, Connections;

inline int Bibartite(int Source) {
    if(Visited[Source]) return 0;
    Visited[Source] = true;
    FOR(i, AdList[Source].size()) {
        if(Match[AdList[Source][i]] == -1 || Bibartite(Match[AdList[Source][i]])) {
            Match[AdList[Source][i]] = Source;
            return 1;
        }
    }
    return 0;
}

int main(int argc, char** argv) {
    //freopen("Trojan.txt", "r", stdin);
    scanf("%d", &TestCases);
    while(TestCases-- > 0) {
        memset(Match, -1, sizeof(Match));
        Minimum = NULL;
        FOR(i, Max) AdList[i].clear();
        
        scanf("%d\n%d", &NumberOfNodes, &Connections);
        FOR(i, Connections) scanf("%d %d", &First, &Second), AdList[--First].push_back(--Second);
        FOR(i, NumberOfNodes) memset(Visited, false, sizeof(Visited)), Minimum += Bibartite(i);
        printf("%d\n", NumberOfNodes - Minimum);
    }
    
    return 0;
}

