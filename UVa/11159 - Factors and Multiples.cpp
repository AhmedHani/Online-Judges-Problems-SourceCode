//============================================================================
// File        :  11159 - Factors and Multiples.cpp
// Author      : AHMED HANI IBRAHIM
// Copyright   : AHani
// Version     : UVa - Accepted - 0,012
// Created on December 17, 2012, 4:12 PM
//============================================================================

#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#define Max 200 + 5
#define INF 1000000000
//#define INT_MAX 2147483647
#define FOR(i, N) for( int i = 0 ; i < N ; i++ )
#define FOR1e(i, N) for( int i = 1 ; i <= N ; i++ )
#define FORe(i, N) for(int i = 0 ; i <= N ; i++ )
#define FOR1(i, N) for(int i = 1 ; i < N ; i++ )

using namespace std;

int TestCases, Sum, Result;
int NumberOfElements[2];
int Input[2][Max], Size[Max], Matching[Max];
int AdjList[Max][Max];
bool Visited[Max];

int DFS(int Source) {
    Visited[Source] = true;
    FOR(i, Size[Source]) {
        if(Matching[AdjList[Source][i]] < NULL || (!Visited[Matching[AdjList[Source][i]]] && DFS(Matching[AdjList[Source][i]]))) {
            Matching[Source] = AdjList[Source][i];
            Matching[AdjList[Source][i]] = Source;
            return 1;
        }
    }
    return 0;
}

int main(int argc, char** argv) {
    //freopen("Trojan.txt", "r", stdin);
    int Cases = 1;
    scanf("%d", &TestCases);
    while(TestCases--) {
        memset(Size, NULL, sizeof(Size));
        memset(Visited, false, sizeof(Visited));
        
        FOR(i, 2) {
            scanf("%d", &NumberOfElements[i]);
            FOR(j, NumberOfElements[i]) {
                scanf("%d", &Input[i][j]);
            }
        }
        FOR(i, NumberOfElements[0]) {
            FOR(j, NumberOfElements[1]) {
                if(Input[0][i] == NULL) continue;
                else if(Input[1][j] == NULL) {
                    AdjList[i][Size[i]++] = NumberOfElements[0] + j;
                    AdjList[NumberOfElements[0] + j][Size[(NumberOfElements[0] + j)]++] = i;
                }
                else if(Input[1][j] % Input[0][i] == NULL) {
                    AdjList[i][Size[i]++] = NumberOfElements[0] + j;
                    AdjList[NumberOfElements[0] + j][Size[(NumberOfElements[0] + j)]++] = i;
                }
            }
        }
        Sum = Result = NULL;
        memset(Matching, -1, sizeof(Matching));
        Sum += NumberOfElements[0] + NumberOfElements[1];
        
        FOR(i, Sum) {
            if(Matching[i] < NULL) {
                memset(Visited, false, sizeof(Visited));
                if(DFS(i)) Result++;
            }
        }
        printf("Case %d: %d\n", Cases++, Result);
        
    }

    return 0;
}

