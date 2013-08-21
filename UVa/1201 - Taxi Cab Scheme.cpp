//============================================================================
// File        : 1201 - Taxi Cab Scheme.cpp
// Author      : AHMED HANI IBRAHIM
// Copyright   : AHani
// Version     : UVa - Accepted - 0.144
// Created on August 21, 2013, 12:13 PM
//============================================================================

#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <queue>
#define Max 500 + 5
#define MaxDirection 4
#define INF 1000000000
//#define INT_MAX 2147483647
#define FOR(i, N) for( int i = 0 ; i < N ; i++ )
#define FOR1e(i, N) for( int i = 1 ; i <= N ; i++ )
#define FORe(i, N) for(int i = 0 ; i <= N ; i++ )
#define FOR1(i, N) for(int i = 1 ; i < N ; i++ )

using namespace std;

int TestCases;
vector<int> AdList[Max];
int Match[Max];
bool Visited[Max];
int Minimum;
int Size;
int Hours, Mins;
int SourceX[Max], SourceY[Max];
int SinkX[Max], SinkY[Max];
int Time[Max], Cost[Max];

inline int Bibartite(int Source) {
    if(Visited[Source]) return 0;
    Visited[Source] = true;
    FOR(i, AdList[Source].size()) {
        if(Match[AdList[Source][i]] == -1 || Bibartite(Match[AdList[Source][i]])) {
            Match[AdList[Source][i]] = Source;
            return 1;
        }
    }
    return 0;
}

int main(int argc, char** argv) {
    //freopen("Trojan.txt", "r", stdin);
    scanf("%d", &TestCases);
    while(TestCases-- > 0) {
        memset(Match, -1, sizeof(Match));
        Minimum = NULL;
        FOR(i, Max) AdList[i].clear();
        
        scanf("%d", &Size);
        FOR(i, Size) {
            scanf("%d:%d %d %d %d %d", &Hours, &Mins, &SourceX[i], &SourceY[i], &SinkX[i], &SinkY[i]);
            Time[i] = Hours * 60 + Mins;
            Cost[i] = abs(SourceX[i] - SinkX[i]) + abs(SourceY[i] - SinkY[i]);
        }
        
        FOR(i, Size) {
            FOR(j, Size) {
                int CurrentCost = abs(SinkX[i] - SourceX[j]) + abs(SinkY[i] - SourceY[j]);
                if(Time[j] > Time[i] + Cost[i] + CurrentCost) {
                    AdList[i].push_back(j + Size);
                }
            }
        }
        FOR(i, Size) memset(Visited, false, sizeof(Visited)), Minimum += Bibartite(i);
        printf("%d\n", Size - Minimum);
    }
    
    return 0;
}
