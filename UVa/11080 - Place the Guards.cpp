//============================================================================
// File        : 11080 - Place the Guards.cpp
// Author      : AHMED HANI IBRAHIM
// Copyright   : AHani
// Version     : UVa - Accepted - 0.012
// Created on December 13, 2012, 12:56 PM
//============================================================================

#include <cstdlib>
#include <stdio.h>
#include <string.h>
//#include <string>
#include <iostream>
//#include <map>
//#include <vector>
//#include <functional>
#define Max 200 + 5
#define INF 1000000000
//#define INT_MAX 2147483647
#define FOR(i, N) for( int i = 0 ; i < N ; i++ )
#define FOR1e(i, N) for( int i = 1 ; i <= N ; i++ )
#define FORe(i, N) for(int i = 0 ; i <= N ; i++ )
#define FOR1(i, N) for(int i = 1 ; i < N ; i++ )

using namespace std;

enum BibartieGraph {M, LEFT, RIGHT};
int TestCases;
int NumberOfJun, NumberOfStreets;
int First, Second, All, Length, Guards, CurrentNode;
int AdjList[Max][Max], Size[Max];
int Col[Max];
bool Check;
bool Visited[Max];

int DFS(int Source, int Current, int &Leng) {
    Visited[Source] = true;
    Col[Source] = Current;
    if(Current == LEFT)    CurrentNode++;
    int NextCol = (Current == LEFT ? RIGHT : LEFT);
    
    FOR(i, Size[Source]) {
        if(Col[AdjList[Source][i]] && Col[AdjList[Source][i]] != NextCol)       return false;
        if(!Visited[AdjList[Source][i]])        Leng++, DFS(AdjList[Source][i], NextCol, Leng);
    }
    return true;
}

int main(int argc, char** argv) {
    freopen("Trojan.txt", "r", stdin);
    scanf("%d", &TestCases);
    while(TestCases--) {
        memset(Col, NULL, sizeof(Col));
        memset(Size, NULL, sizeof(Size));
        memset(Visited, false, sizeof(Visited));
        scanf("%d %d", &NumberOfJun, &NumberOfStreets);
        
        FOR(i, NumberOfStreets) {
            scanf("%d %d", &First, &Second);
            AdjList[First][Size[First]++]   = Second;
            AdjList[Second][Size[Second]++] = First;
        }
        Check = false;
        Guards = NULL;
        int G;
        
        FOR(i, NumberOfJun) {
            if(!Visited[i]) {
                CurrentNode = NULL;
                Length = 1;
                if(DFS(i, LEFT, Length)) {
                    G = min(CurrentNode, Length - CurrentNode);
                    if(G == NULL)       G = 1;
                    Guards += G;
                } else {
                    Check = true;
                    break;
                }
            }
        }       
            
            if(!Check)          printf("%d\n", Guards);
            else                puts("-1");
        
    }
    
    
    return 0;
}

