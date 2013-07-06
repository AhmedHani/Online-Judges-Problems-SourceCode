//============================================================================
// File        : 615 - Is It A Tree?.cpp
// Author      : AHMED HANI IBRAHIM
// Copyright   : AHani
// Version     : UVa - Accepted - 0.008
// Created on September 20, 2012, 7:31 PM
//============================================================================

#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#define Max 10000 + 5
#define INF 1000000000
//#define INT_MAX 2147483647
#define FOR(i, N) for( int i = 0 ; i < N ; i++ )
#define FOR1e(i, N) for( int i = 1 ; i <= N ; i++ )
#define FORe(i, N) for(int i = 0 ; i <= N ; i++ )
#define FOR1(i, N) for(int i = 1 ; i < N ; i++ )

using namespace std;

int First, Second, Index, Root, RootCounter;
map<int, int> ConatinerMap;
map<int, int> InDegree;
vector<int> AdjList[Max];
bool Visited[Max];

void DFS(int X){
    Visited[X] = true;
    
    FOR(i, AdjList[X].size()){
        if(Visited[AdjList[X][i]] == false )
            DFS(AdjList[X][i]);
    }
}

int main(int argc, char** argv) {
//    freopen("Trojan.txt", "r", stdin);
    int Cases = 1;
    
    while ( scanf("%d %d", &First, &Second) ){
        if ( First < NULL && Second < NULL )    break;
        ConatinerMap.clear();
        InDegree.clear();
        memset(Matrix, NULL, sizeof(Matrix));
        memset(Visited, false, sizeof(Visited));
        
        Index = 1;
        ConatinerMap[First]  = Index++;         ConatinerMap[Second] = Index++;
        
        AdjList[ConatinerMap[First]].push_back(ConatinerMap[Second]);
        InDegree[ConatinerMap[First]]  = InDegree[ConatinerMap[Second]] = NULL;
        InDegree[ConatinerMap[Second]]++; 
        
        if ( First == NULL && Second == NULL ){ printf ("Case %d is a tree.\n", Cases++); continue; }
        
        while ( scanf("%d %d", &First, &Second), First|Second ){
            if( !ConatinerMap[First] ){
                ConatinerMap[First] = Index++;
                InDegree[ConatinerMap[First]]  = NULL;
            }if( ! ConatinerMap[Second] ){
                ConatinerMap[Second] = Index++;
                InDegree[ConatinerMap[Second]] = NULL;
            }
            AdjList[ConatinerMap[First]].push_back(ConatinerMap[Second]);
            InDegree[ConatinerMap[Second]]++;
        }
        RootCounter = NULL;
        bool One = true;
        
        for ( map<int, int> ::iterator it = InDegree.begin(); it != InDegree.end(); it++ ){
            if ( (*it).second == NULL ){
                RootCounter++;
                Root = (*it).first;
            }
            else if( (*it).second > 1 ) One = false;
        }
        printf ("Case %d is ", Cases++);
        
        if(!One || RootCounter == NULL || RootCounter > 1 ){
            printf ("not a tree.\n");   continue;
        }
        
        DFS(Root);
        bool Tree = true;
        
        FOR1(i, Index){
            if ( Visited[i] == false )
                Tree = false;
        }
        
        if(Tree)        printf ("a tree.\n");
        else            printf ("not a tree.\n");
        
    }

    return 0;
}

