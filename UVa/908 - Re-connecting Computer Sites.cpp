//============================================================================
// File        : 908 - Re-connecting Computer Sites.cpp
// Author      : AHMED HANI IBRAHIM
// Copyright   : AHani
// Version     : UVa - Accepted - 0.012
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
#define Max 200 + 5
#define INF 1000000000
//#define INT_MAX 2147483647
#define FOR(i, N) for( int i = 0 ; i < N ; i++ )
#define FOR1e(i, N) for( int i = 1 ; i <= N ; i++ )
#define FORe(i, N) for(int i = 0 ; i <= N ; i++ )
#define FOR1(i, N) for(int i = 1 ; i < N ; i++ )
#define BLUE 1
#define RED 2
using namespace std;

vector<pair<int, int> > AdjList[Max];
int NumberOfSites, NewHS;
int First, Second, Cost;
int PrevCost;
int FinalCost;


int main(int argc, char** argv) {
   // freopen("Trojan.txt", "r", stdin);
    bool Line = true;
    while(scanf("%d", &NumberOfSites) == 1) {
        if(Line)        Line = false;
        else            puts("");
        FOR(i, Max)     AdjList[i].clear();
        PrevCost = NULL;
        FinalCost = NULL;
        FOR(i, NumberOfSites - 1) {
            scanf("%d %d %d", &First, &Second, &Cost);
            AdjList[First].push_back(make_pair(Second, Cost));
            AdjList[Second].push_back(make_pair(First, Cost));
            PrevCost += Cost;
        }
        scanf("%d", &NewHS);
        FOR(i, NewHS) {
            scanf("%d %d %d", &First, &Second, &Cost);
            int Maxii = 0;
            int MaxValue, Node, Counter;
            FOR(j, AdjList[First].size()) {
                if(AdjList[First][j].second > Maxii) {
                    Maxii = AdjList[First][j].second;
                    MaxValue = j;
                    Node = First;
                    Counter = Second;
                }
            }
            FOR(j, AdjList[Second].size()) {
                if(AdjList[Second][j].second > Maxii) {
                    Maxii = AdjList[Second][j].second;
                    MaxValue = j;
                    Node = Second;
                    Counter = First;
                }
            }
            if(Maxii <= Cost)   continue;
            FinalCost = Maxii - Cost;
            AdjList[Node][MaxValue].first = Counter;
            AdjList[Node][MaxValue].second = Cost;
        }
        int M;
        scanf("%d", &M);
        FOR(i, M)       scanf("%d %d %d", &First, &Second, &Cost);
        printf("%d\n%d\n", PrevCost, PrevCost - FinalCost);
    }
            
   
    return 0;
}

