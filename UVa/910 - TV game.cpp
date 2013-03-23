//============================================================================
// File        : 910 TV game.cpp
// Author      : AHMED HANI IBRAHIM
// Copyright   : AHani
// Version     : UVa - Accepted - 0.008
// Created on February 20, 2013, 10:15 PM
//============================================================================

#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#define Max 50 + 5
#define MOD 1000000007
#define INF 1000000000
//#define INT_MAX 2147483647
#define FOR(i, N) for( int i = 0 ; i < N ; i++ )
#define FOR1e(i, N) for( int i = 1 ; i <= N ; i++ )
#define FORe(i, N) for(int i = 0 ; i <= N ; i++ )
#define FOR1(i, N) for(int i = 1 ; i < N ; i++ )

using namespace std;

int Nodes;
int Moves;
int DPMemo[Max][Max];
int Matrix[Max][Max];
char Line[Max];
int Solve(int Postion, int Mov) {
        if(Mov == 0)    return Matrix[Postion][2];
        if(DPMemo[Postion][Mov] != -1)  return DPMemo[Postion][Mov];
        return DPMemo[Postion][Mov] = Solve(Matrix[Postion][0], Mov - 1) + Solve(Matrix[Postion][1], Mov - 1);
    }

int main(int argc, char** argv) {
    //freopen("Trojan.txt", "r", stdin);
    while(scanf("%d", &Nodes) == 1) {
        memset(DPMemo, -1, sizeof(DPMemo));
        getchar();
        FOR(i, Nodes) {
            gets(Line);
            Matrix[Line[0] - 'A'][0] = Line[2] - 'A';
            Matrix[Line[0] - 'A'][1] = Line[4] - 'A';
            Matrix[Line[0] - 'A'][2] = Line[6] == 'x' ? 1 : 0;
        }
        scanf("%d", &Moves);
        printf("%d\n", Solve(0, Moves));
    }
             
    return 0;
}

