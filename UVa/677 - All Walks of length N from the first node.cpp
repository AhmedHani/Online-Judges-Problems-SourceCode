//============================================================================
// File        : 677 - All Walks of length "n" from the first node.cpp
// Author      : AHMED HANI IBRAHIM
// Copyright   : AHani
// Version     : UVa - Accepted - 0.080
// Created on April 5, 2013, 09:23 PM
//============================================================================

#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
#define Max 200 + 5
#define INF 1000000000
//#define INT_MAX 2147483647
#define FOR(i, N) for( int i = 0 ; i < N ; i++ )
#define FOR1e(i, N) for( int i = 1 ; i <= N ; i++ )
#define FORe(i, N) for(int i = 0 ; i <= N ; i++ )
#define FOR1(i, N) for(int i = 1 ; i < N ; i++ )

using namespace std;

int Nodes;
int Walks, Counter;
bool Matrix[Max][Max];
bool Visited[Max];
bool Line;
int X;
deque<int> Walk;

inline void Solve(int Source) {
    if(Walk.size() == Walks) {
        ++Counter;
        printf("(1");
        FOR(i, Walks) printf(",%d", Walk[i] + 1);
        puts(")");
    } else {
        FOR(i, Nodes) {
            if(Matrix[Source][i] && !Visited[i]) {
                Visited[i] = true;
                Walk.push_back(i);
                Solve(i);
                Walk.pop_back();
                Visited[i] = false;
            }
        }
    } 
}

int main(int argc, char** argv) {
    freopen("Trojan.txt", "r", stdin);
    Line = true;
    while(scanf("%d %d", &Nodes, &Walks) == 2) {
        if(!Line)   puts("");
        else        Line = false;
        Counter = 0;
        memset(Matrix, NULL, sizeof(Matrix));
        memset(Visited, false, sizeof(Visited));
        Walk.clear();
        FOR(i, Nodes)   FOR(j, Nodes)   scanf("%d", &X), Matrix[i][j] = X == 1;
        Visited[0] = true;
        Solve(0);
        if(Counter == 0)    printf("no walk of length %d\n", Walks);
        int rubbish;
        scanf("%d", &rubbish);
    }
    
    return 0;
}
