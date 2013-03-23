//============================================================================
// File        : 11838 - Come and Go.cpp
// Author      : AHMED HANI IBRAHIM
// Copyright   : AHani
// Version     : UVa - Accepted - 0.100
// Created on November 26, 2012, 6:42 PM
//============================================================================

//#include <cstdlib>
#include <stdio.h>
#include <string.h>
//#include <string>
//#include <iostream>
#include <vector>
//#include <algorithm>
//#include <functional>
#define Max 2000 + 5
#define INF 1000000000
//#define INT_MAX 2147483647
#define FOR(i, N) for( int i = 0 ; i < N ; i++ )
#define FOR1e(i, N) for( int i = 1 ; i <= N ; i++ )
#define FORe(i, N) for(int i = 0 ; i <= N ; i++ )
#define FOR1(i, N) for(int i = 1 ; i < N ; i++ )

using namespace std;

int NumberOfNodes, NumberOfStreets;
int First, Second, IOrB;
bool Visited[Max], Answer;
vector<int> AdjList[Max];

int DFS(int Source) {
    int Result = 1;
    Visited[Source] = true;
    FOR(i, AdjList[Source].size()) {
        if(!Visited[AdjList[Source][i]])
           Result += DFS(AdjList[Source][i]);
    }
    return Result;
}

int main(int argc, char** argv) {
  // freopen("Trojan.txt", "r", stdin);
    while(scanf("%d %d", &NumberOfNodes, &NumberOfStreets) == 2, NumberOfNodes|NumberOfStreets) {
        memset(Visited, false, sizeof(Visited));
        FOR1e(i, Max)     AdjList[i].clear();
        
        FOR(i, NumberOfStreets) {
            scanf("%d %d %d", &First, &Second, &IOrB);
            if(IOrB == 1)       AdjList[First].push_back(Second);
            if(IOrB == 2)       AdjList[First].push_back(Second), AdjList[Second].push_back(First);
        }
        Answer = true;
       // memset(Visited, false, sizeof(Visited));
        
        FOR1e(i, NumberOfNodes){
            if(!Answer) break;
            FOR1e(j, NumberOfNodes)     Visited[j] = false;
            if(!Visited[i])             Answer = (DFS(i) == NumberOfNodes);
            
        }
        puts(Answer ? "1" : "0");
    }

    return 0;
}

