//============================================================================
// File        : 11906 - Knight in a War Grid.cpp
// Author      : AHMED HANI IBRAHIM
// Copyright   : AHani
// Version     : UVa - Accepted - 0.035
// Created on May 9, 2013, 5:16 PM
//============================================================================

#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>
#include <map>
#include <algorithm>
#include <functional>
#include <list>
#include <sstream>
#include <set>
#define Max 200 + 5
#define INF 1000000000
//#define INT_MAX 2147483647
#define FOR(i, N) for( int i = 0 ; i < N ; i++ )
#define FOR1e(i, N) for( int i = 1 ; i <= N ; i++ )
#define FORe(i, N) for(int i = 0 ; i <= N ; i++ )
#define FOR1(i, N) for(int i = 1 ; i < N ; i++ )

using namespace std;

int TestCases;
int Rows, Columns, M, N;
int Water, WaterRow, WaterColumn;
bool WaterIsHere[Max][Max];
set<pair<int, int> > Movements;
int Answer[Max];
bool Visited[Max][Max];

void DFS(int R, int C) {
    Visited[R][C] = true;
    int Counter = 0;
    for(set<pair<int, int> >::iterator it = Movements.begin(); it != Movements.end(); it++) {
        int CurrentR = R + it->first;
        int CurrentC = C + it->second;
        if(CurrentR >= NULL && CurrentR < Rows && CurrentC >= NULL && CurrentC < Columns && !WaterIsHere[CurrentR][CurrentC]) {
            Counter++;
            if(!Visited[CurrentR][CurrentC])    DFS(CurrentR, CurrentC);
        }
    }
    Answer[Counter % 2]++;
}

int main(int argc, char** argv) {
    //freopen("Trojan.txt", "r", stdin);   
    int Cases = 1;
    scanf("%d", &TestCases);
    while(TestCases-- > 0) {
        Movements.clear();
        memset(Answer, NULL, sizeof(Answer));
        memset(Visited, false, sizeof(Visited));
        memset(WaterIsHere, false, sizeof(WaterIsHere));
        
        scanf("%d %d %d %d\n", &Rows, &Columns, &M, &N);
        scanf("%d", &Water);
        
        FOR(i, Water) scanf("%d %d", &WaterRow, &WaterColumn), WaterIsHere[WaterRow][WaterColumn] = true;
        
        for(int k = 0; k < 2; k++) {
            for(int dr = -1; dr <= 1; dr++) {
                for(int dc = -1; dc <= 1; dc++) {
                    if(dr && dc)        Movements.insert(make_pair(dr * M, dc * N));
                }
            }
            swap(M, N);
        }
        
        Answer[0] = Answer[1] = 0;
        DFS(NULL, NULL);
        printf("Case %d: %d %d\n", Cases++, Answer[0], Answer[1]);
    }

    return 0;
}

