//============================================================================
// File        : 11504 - Dominos.cpp
// Author      : AHMED HANI IBRAHIM
// Copyright   : AHani
// Version     : UVa - Accepted - 0.220
// Created on November 26, 2012, 5:21 PM
//============================================================================

#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#define Max 100000 + 5
#define INF 1000000000
//#define INT_MAX 2147483647
#define FOR(i, N) for( int i = 0 ; i < N ; i++ )
#define FOR1e(i, N) for( int i = 1 ; i <= N ; i++ )
#define FORe(i, N) for(int i = 0 ; i <= N ; i++ )
#define FOR1(i, N) for(int i = 1 ; i < N ; i++ )

using namespace std;

int TestCases;
int NumberOfDom, Bridges;
int First, Second, Counter, Index;
bool Visited[Max];
vector<int> Edges[Max];
vector<int> ReNodes;

void DFS(int Source) {
    Visited[Source] = true;
    FOR(i, Edges[Source].size()) 
        if(!Visited[Edges[Source][i]])
            DFS(Edges[Source][i]);
    ReNodes.push_back(Source);
}

int main(int argc, char** argv) {
  //  freopen("Trojan.txt", "r", stdin);
    scanf("%d", &TestCases);
    while(TestCases--) {
        memset(Visited, false, sizeof(Visited));
        FOR(i, Max)     Edges[i].clear();
        ReNodes.clear();
        scanf("%d %d", &NumberOfDom, &Bridges);
        FOR(i, Bridges) {
            scanf("%d %d", &First, &Second);
            Edges[First].push_back(Second);
        }
    //    Index = 0;
        FOR1e(i, NumberOfDom)     if(!Visited[i])         DFS(i);
        Counter = NULL;
        
        memset(Visited, false, sizeof(Visited));
        
        for(int i = ReNodes.size() - 1; i >= NULL; i--) 
            if(!Visited[ReNodes[i]])    Counter++, DFS(ReNodes[i]);
        
        printf("%d\n", Counter);
        
    }

    return 0;
}

