//============================================================================
// File        : 10305 - Ordering Tasks.cpp
// Author      : AHMED HANI IBRAHIM
// Copyright   : AHani
// Version     : UVa - Accepted - 0.008
// Created on September 14, 2012, 7:00 PM
//============================================================================

#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <functional>
#define Max 200 + 5
#define INF 1000000000
//#define INT_MAX 2147483647
#define FOR(i, N) for( int i = 0 ; i < N ; i++ )
#define FOR1e(i, N) for( int i = 1 ; i <= N ; i++ )
#define FORe(i, N) for(int i = 0 ; i <= N ; i++ )
#define FOR1(i, N) for(int i = 1 ; i < N ; i++ )

using namespace std;

int NumberOfTasks, Relations;
int First, Second;
int IncomingEdges[Max];
vector<int> List;
queue<int> Set;

int main(int argc, char** argv) {
    freopen("Trojan.txt", "r", stdin);
    
    while ( scanf("%d %d", &NumberOfTasks, &Relations), NumberOfTasks|Relations ){
        vector<int> AdjList[Max];
        memset(IncomingEdges, NULL, sizeof(IncomingEdges));
        
        FOR(i, Relations){
            scanf("%d %d", &First, &Second);
            AdjList[First].push_back(Second);
            IncomingEdges[Second]++;
        }
        Set.empty();
        
        FOR1e(i, NumberOfTasks){
            if ( !IncomingEdges[i] )    Set.push(i);
        }
        List.clear();
        
        while ( !Set.empty() ){
            int TopValue = Set.front();
            Set.pop();
            
            List.push_back(TopValue);
            
            FOR(i, AdjList[TopValue].size()){
                IncomingEdges[AdjList[TopValue][i]]--;
                if ( !IncomingEdges[AdjList[TopValue][i]] )   Set.push(AdjList[TopValue][i]);
            }
        }
        FOR(i, List.size())     printf("%d ", List[i]);
        printf("\n");
    }

    return 0;
}

