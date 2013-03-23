//============================================================================
// File        : 11686 - Pick up sticks.cpp
// Author      : AHMED HANI IBRAHIM
// Copyright   : AHani
// Version     : UVa - Accpted - 0.768
// Created on September 15, 2012, 1:57 AM
//============================================================================

#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#define Max 1000001 + 5
#define INF 1000000000
//#define INT_MAX 2147483647
#define FOR(i, N) for( int i = 0 ; i < N ; i++ )
#define FOR1e(i, N) for( int i = 1 ; i <= N ; i++ )
#define FORe(i, N) for(int i = 0 ; i <= N ; i++ )
#define FOR1(i, N) for(int i = 1 ; i < N ; i++ )

using namespace std;

int NumberOfSticks, Relations;
int First, Second, Index;
int List[Max];
int Visited[Max];
vector<int> AdjList[Max];

int DFS(int i, int j){
    Visited[j] = 1;
    int F;
    
    FOR(k, AdjList[j].size()){
        F = AdjList[j][k];
        if ( Visited[F] == 1)       return 0;
        if ( !Visited[F] && !DFS(i, F) )        return 0;
    }
    List[++Index] = j;
    Visited[j] = 1;
    return 1;
}

int main(int argc, char** argv) {
    freopen("Trojan.txt", "r", stdin);
    
    while ( scanf("%d %d", &NumberOfSticks, &Relations), NumberOfSticks|Relations ){
        memset(List, NULL, sizeof(List));
        memset(Visited, false, sizeof(Visited));
        FOR1e(i, NumberOfSticks) AdjList[i].clear();
        Index = NULL;
        
        while ( Relations-- ){
            scanf("%d %d", &First, &Second);
            AdjList[First].push_back(Second);
        }
        bool Check = true;
        int Start = NULL;
        
        FOR1e(i, NumberOfSticks){
            if ( !Visited[i] )  Check &= DFS(++Start, i);
        }
        
        if (Check) for(int i = NumberOfSticks; i > NULL; i-- )     printf("%d\n", List[i]);
        else     printf("IMPOSSIBLE\n");
        
    }

    return 0;
}

