//============================================================================
// File        : 11396 - Claw Decomposition.cpp
// Author      : AHMED HANI IBRAHIM
// Copyright   : AHani
// Version     : UVa - Accepted - 0.016
// Created on December 13, 2012, 12:56 PM
//============================================================================

#include <cstdlib>
#include <stdio.h>
#include <string.h>
//#include <string>
#include <iostream>
//#include <map>
#include <queue>
//#include <functional>
#define Max 300 + 5
#define INF 1000000000
//#define INT_MAX 2147483647
#define FOR(i, N) for( int i = 0 ; i < N ; i++ )
#define FOR1e(i, N) for( int i = 1 ; i <= N ; i++ )
#define FORe(i, N) for(int i = 0 ; i <= N ; i++ )
#define FOR1(i, N) for(int i = 1 ; i < N ; i++ )

using namespace std;

int NumberOfNodes;
int First, Second;
int AdjList[Max][Max], Size[Max];
bool Check;
bool Col[Max];
bool Visited[Max];

bool CheckBibar(int Source) {
    queue<int> Container;
    int Current;
    Container.push(Source);
    Visited[Source] = true;
    Col[Source] = true;
    while(!Container.empty()) {
        Current = Container.front();
        Container.pop();
        FOR(i, Size[Current]) {
            if(!Visited[AdjList[Current][i]]) {
                Visited[AdjList[Current][i]] = true;
                Col[AdjList[Current][i]] = 1 - Col[AdjList[Current][i]];
                Container.push(AdjList[Current][i]);
            } else {
                if(Col[AdjList[Current][i]] == Col[Current])      return false;
            }
        }
    }
    return true;
}

int main(int argc, char** argv) {
    //freopen("Trojan.txt", "r", stdin);
    while(scanf("%d", &NumberOfNodes) == 1, NumberOfNodes) {
        memset(Col, false, sizeof(Col));
        memset(Size, NULL, sizeof(Size));
        memset(Visited, false, sizeof(Visited));
        
        while(scanf("%d %d", &First, &Second) == 2) {
            if(First == NULL && Second == NULL) break;
            AdjList[First][Size[First]++] = Second;
            AdjList[Second][Size[Second]++] = First;
        }
        Check = true;
        FOR1e(i, NumberOfNodes) {
            if(!Visited[i])     Check &= CheckBibar(i);     
        }
        puts(Check ? "YES" : "NO");
    }
    
    return 0;
}

