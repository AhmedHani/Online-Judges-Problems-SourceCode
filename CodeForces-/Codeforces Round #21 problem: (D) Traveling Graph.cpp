//============================================================================
// File        : Codeforces Round #21 problem: (D) Traveling Graph.cpp
// Author      : AHMED HANI IBRAHIM
// Copyright   : AHani
// Version     : CF  - Accepted
// Created on April 15, 2013, 13:43 PM
//============================================================================

#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <functional>
#include <math.h>
#define Max 20 + 5
#define INF 1000000000
//#define INT_MAX 2147483647
#define FOR(i, N) for( long long i = 0 ; i < N ; i++ )
#define FOR1e(i, N) for( long long i = 1 ; i <= N ; i++ )
#define FORe(i, N) for(long long i = 0 ; i <= N ; i++ )
#define FOR1(i, N) for(long long i = 1 ; i < N ; i++ )

using namespace std;

int NumberOfNode, NumberOfEdges, Cost;
int First, Second;
int Result;
int Degree[Max];
bool Visited[Max];
vector<int> OddDegrees;
int Distance[Max][Max];

int Solve(int Start, int Costt) {
    if(Start == OddDegrees.size())     return Costt;
    if(Visited[Start])          return Solve(Start + 1, Costt);
    int Answer = INF;
    
    for(int To = Start + 1; To < OddDegrees.size(); To++) {
        if(!Visited[To]) {
            Visited[To] = true;
            Answer = min(Answer, Solve(Start + 1, Costt + Distance[OddDegrees[Start]][OddDegrees[To]]));
            Visited[To] = false;
        }
    }
    return Answer;
}

int main(int argc, char** argv) {
   // freopen("Trojan.txt","r",stdin);
    
    scanf("%d %d", &NumberOfNode, &NumberOfEdges);
    
    FOR(i, NumberOfNode)    FOR(j, NumberOfNode)    if(i != j)      Distance[i][j] = INF;
    Result = 0;

    FOR(i, NumberOfEdges) {
        scanf("%d %d %d", &First, &Second, &Cost);
        First--, Second--;
        Distance[First][Second] = Distance[Second][First] = min(Distance[First][Second] , Cost);
        Degree[First]++;
        Degree[Second]++;
        Result += Cost;
    }
    // Floyed
    FOR(k, NumberOfNode) {
        FOR(i, NumberOfNode) {
            FOR(j, NumberOfNode) {
                Distance[i][j] = min(Distance[i][j], Distance[i][k] + Distance[k][j]);
            }
        }
    }
    if(NumberOfEdges > NULL && Degree[0] == 0) {
        puts("-1");
        return 0;
    }
    for(int i = 0; i < NumberOfNode; i++) {
        for(int j = i + 1; j < NumberOfNode; j++) {
            if(Distance[i][j] == INF && Degree[i] > NULL && Degree[j] > NULL) {
                puts("-1");
                return 0;
            }
        }
    }
    FOR(i, NumberOfNode)    if(Degree[i] % 2 != 0)  OddDegrees.push_back(i);
    Result += Solve(0, 0);
    printf("%d\n", Result);
    
    return 0;
}
