//============================================================================
// File        : 532 - Dungeon Master.cpp
// Author      : AHMED HANI IBRAHIM
// Copyright   : AHani
// Version     : UVa - Accepted - 0.024
// Created on March 4, 2013, 3:55 PM
//============================================================================

#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#define Max 60 + 5
#define INF 1000000000
int dx[] = {-1, 1, 0, 0, 0, 0};
int dy[] = {0, 0, -1, 1, 0, 0};
int dz[] = {0, 0, 0, 0, -1, 1};
//#define INT_MAX 2147483647
#define FOR(i, N) for( int i = 0 ; i < N ; i++ )
#define FOR1e(i, N) for( int i = 1 ; i <= N ; i++ )
#define FORe(i, N) for(int i = 0 ; i <= N ; i++ )
#define FOR1(i, N) for(int i = 1 ; i < N ; i++ )

using namespace std;

int Layers, Rows, Columns;
char Grid[Max][Max][Max];
//char C[Max][Max][Max];
char Visited[Max][Max][Max];
string Line;
int StartLayer, StartR, StartC;
int FinLayer, FinR, FinC;
int Steps[Max][Max][Max];

inline void BFS() {
    queue<int> Q;
    FOR(i, Max) FOR(j, Max) FOR(k, Max) Steps[i][j][k] = INF;
    memset(Visited, 'F', sizeof(Visited));
    Visited[StartLayer][StartR][StartC] = 'T';
    Steps[StartLayer][StartR][StartC] = NULL;
    Q.push(StartLayer); Q.push(StartR); Q.push(StartC);
    while(!Q.empty()) {
        int L = Q.front();Q.pop();
        int R = Q.front();Q.pop();
        int C = Q.front();Q.pop();
        FOR(i, 6) {
            int Lay = L + dx[i];
            int Ro = R + dy[i];
            int Col = C + dz[i];
            if(Lay >= NULL && Lay < Layers && Ro >= NULL && Ro < Rows && Col >= NULL && Col < Columns) {
                if(Visited[Lay][Ro][Col] == 'F' && (Grid[Lay][Ro][Col] == '.' || Grid[Lay][Ro][Col] == 'E')) {
                    Visited[Lay][Ro][Col] = 'T';
                    Steps[Lay][Ro][Col] = Steps[L][R][C] + 1;
                    Q.push(Lay);
                    Q.push(Ro);
                    Q.push(Col);
                }
            }
        }
        Visited[L][R][C] = 'V';
    }
}

int main(int argc, char** argv) {
    freopen("Trojan.txt", "r", stdin);
    while(scanf("%d %d %d", &Layers, &Rows, &Columns) == 3, Layers|Rows|Columns) {
        FOR(i, Layers) {
            FOR(j, Rows) {
                FOR(k, Columns) {
                    cin >> Grid[i][j][k];
                    if(Grid[i][j][k] == 'S') {
                        StartLayer = i;
                        StartR = j;
                        StartC = k;
                    }
                    if(Grid[i][j][k] == 'E') {
                        FinLayer = i;
                        FinR = j;
                        FinC = k;
                    }
                }
            }
        }
        BFS();
        if(Steps[FinLayer][FinR][FinC] == INF)  puts("Trapped!");
        else    printf("Escaped in %d minute(s).\n", Steps[FinLayer][FinR][FinC]);
    }

    return 0;
}

