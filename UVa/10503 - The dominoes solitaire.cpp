//============================================================================
// File        : 10503 - The dominoes solitaire.cpp
// Author      : AHMED HANI IBRAHIM
// Copyright   : AHani
// Version     : UVa - Accepted - 0.516
// Created on February 19, 2013, 10:45 PM
//============================================================================

#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>
#include <map>
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

int Spaces, NumOfPieces;
int Pieces[Max][Max];
bool Visited[Max];

bool BackTrack(int Last, int Depth) {
    if(Depth == Spaces) {
        if(Last == Pieces[1][0])
            return true;
        return false;
    }
    FOR1(i, NumOfPieces + 1) {
        if(Visited[i])  continue;
        Visited[i] = true;
        if(Pieces[i][0] == Last)
            if(BackTrack(Pieces[i][1], Depth + 1))      return true;
        if(Pieces[i][1] == Last)
            if(BackTrack(Pieces[i][0], Depth + 1))      return true;
        Visited[i] = false;
    }
    return false;
}

int main(int argc, char** argv) {
    //freopen("Trojan.txt", "r", stdin);
    while(scanf("%d", &Spaces) == 1, Spaces) {
        memset(Pieces, NULL, sizeof(Pieces));
        memset(Visited, false, sizeof(Visited));
    
        scanf("%d", &NumOfPieces);
        NumOfPieces += 2;
        FOR(i, NumOfPieces)        scanf("%d %d", &Pieces[i][0], &Pieces[i][1]);
        Visited[0] = Visited[1] = true;
        puts((BackTrack(Pieces[0][1], NULL)) ? "YES" : "NO");
    }
             
    return 0;
}

