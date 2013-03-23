//============================================================================
// File        : 988 - Many Paths, One Destination.cpp
// Author      : AHMED HANI IBRAHIM
// Copyright   : AHani
// Version     : UVa - Accepted - 0.012
// Created on January 30, 2013, 12:26 AM
//============================================================================

#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>
#include <map>
#include <algorithm>
#include <functional>
#include <vector>
#define Max 500 + 10
#define INF 1000000000
//#define INT_MAX 2147483647
#define FOR(i, N) for( int i = 0 ; i < N ; i++ )
#define FOR1e(i, N) for( int i = 1 ; i <= N ; i++ )
#define FORe(i, N) for(int i = 0 ; i <= N ; i++ )
#define FOR1(i, N) for(int i = 1 ; i < N ; i++ )

using namespace std;

int NumberOfEvents, NumberOfChoices;
int Start;
int Size[Max];
int AdjList[Max][Max];
int Memo[Max];

int DFS(int Source) {
    if(Source == NULL)  return 1;
    if(Memo[Source] != -1)      return Memo[Source];
    Memo[Source] = 0;
    FOR(i, Size[Source])        Memo[Source] += DFS(AdjList[Source][i]);
    return Memo[Source];
}

int main(int argc, char** argv) {
   // freopen("Trojan.txt", "r", stdin);
    bool Line = true;
    while(scanf("%d", &NumberOfEvents) == 1) {
        if(Line)        Line = false;
        else            puts("");
        memset(AdjList, NULL, sizeof(AdjList));
        memset(Memo, -1, sizeof(Memo));
        memset(Size, NULL, sizeof(Size));
        int Counter = 0;
        FOR(i, NumberOfEvents) {
            scanf("%d", &NumberOfChoices);
            if(NumberOfChoices == NULL) Counter += DFS(i);
            FOR(j, NumberOfChoices) {
                scanf("%d", &Start);
                AdjList[Start][Size[Start]++] = i;
            }
        }
        printf("%d\n", Counter);
    }

    return 0;
}

