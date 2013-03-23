//============================================================================
// File        : 11518 - Dominos 2.cpp
// Author      : AHMED HANI IBRAHIM
// Copyright   : AHani
// Version     : UVa - Accepted
// Created on November 23, 2012, 4:36 PM
//============================================================================

#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>
#include <map>
#include <algorithm>
#include <functional>
#define Max 10000 + 5
#define INF 1000000000
//#define INT_MAX 2147483647
#define FOR(i, N) for( int i = 0 ; i < N ; i++ )
#define FOR1e(i, N) for( int i = 1 ; i <= N ; i++ )
#define FORe(i, N) for(int i = 0 ; i <= N ; i++ )
#define FOR1(i, N) for(int i = 1 ; i < N ; i++ )

using namespace std;

int TestCases;
int NumberOfDominoes, Dependancy, FirstKnocked, First, Second, Tmp;
int Size[Max];
vector<int> AdjList[Max];
bool Visited[Max];

void DFS(int Source) {
    if(Visited[Source]) return;
    Visited[Source] = true;
    
    FOR(i, Size[Source])        DFS(AdjList[Source][i]);
    
}

int main(int argc, char** argv) {
    freopen("Trojan.txt", "r", stdin);
    scanf("%d", &TestCases);
    while(TestCases--) {
        memset(AdjList, NULL, sizeof(AdjList));
        memset(Visited, false, sizeof(Visited));
       memset(Size, NULL, sizeof(Size));
        scanf("%d %d %d", &NumberOfDominoes, &Dependancy, &FirstKnocked);
        
        FOR(i, Dependancy) {
            scanf("%d %d", &First, &Second);
            AdjList[First][Size[First]++] = Second;
        }
        FOR(i, FirstKnocked) {
            scanf("%d", &Tmp);
            DFS(Tmp);
        }
        int Counter = NULL;
        FOR1e(i, NumberOfDominoes)      if(Visited[i])  Counter++;
        printf("%d\n", Counter);
    }

    return 0;
}

