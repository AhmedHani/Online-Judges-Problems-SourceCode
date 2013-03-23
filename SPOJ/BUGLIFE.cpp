//============================================================================
// File        : main.cpp
// Author      : AHMED HANI IBRAHIM
// Copyright   : AHani
// Version     : 
// Created on March 6, 2013, 9:19 PM
//============================================================================

#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>
#include <map>
#include <algorithm>
#include <functional>
#include <math.h>
#include <vector>
#define Max 21000 + 5
#define INF 1000000000
#define BLUE 1
#define RED 2
//#define INT_MAX 2147483647
#define FOR(i, N) for( int i = 0 ; i < N ; i++ )
#define FOR1e(i, N) for( int i = 1 ; i <= N ; i++ )
#define FORe(i, N) for(int i = 0 ; i <= N ; i++ )
#define FOR1(i, N) for(int i = 1 ; i < N ; i++ )

using namespace std;

int TestCases;
int Color[Max];
int NumberOfBugs, Connections;
int First, Second;
vector<int> AdjList[Max];

bool DFS(int Source) {
    bool Result = true;
    FOR(i, AdjList[Source].size()) {
        int Current = AdjList[Source][i];
        if(Color[Current] == Color[Source])     return false;
        if(Color[Current] == 0) {
            Color[Current] = -Color[Source];
            Result = Result & DFS(Current);
        }
    }
    return Result;
}

int main(int argc, char** argv) {
   // freopen("Trojan.txt", "r", stdin);
    int Cases = 1;
    scanf("%d", &TestCases);
    while(TestCases--) {
        //memset(Visited, false, sizeof(Visited));
        scanf("%d %d", &NumberOfBugs, &Connections);
        FOR(i, NumberOfBugs)    Color[i] = 0, AdjList[i].clear();
        FOR(i, Connections) {
            scanf("%d %d", &First, &Second);
            AdjList[First].push_back(Second);
            AdjList[Second].push_back(First);
        }
        printf("Scenario #%d:\n", Cases++);
        bool Answer = true;
        FOR(i, NumberOfBugs) {
            if(Color[i] == 0) {
                Color[i] = 1;
                Answer = Answer & DFS(i);
            }
        }
        puts(Answer ? "No suspicious bugs found!" : "Suspicious bugs found!");
    }

    return 0;
}

