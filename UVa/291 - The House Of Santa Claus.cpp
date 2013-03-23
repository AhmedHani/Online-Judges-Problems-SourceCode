//============================================================================
// File        : 291 - The House Of Santa Claus.cpp
// Author      : AHMED HANI IBRAHIM
// Copyright   : AHani
// Version     : UVa - Accepted - 0.008
// Created on October 6, 2012, 6:49 PM
//============================================================================

#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>
#include <map>
#include <algorithm>
#include <functional>
#define Max 8
#define INF 1000000000
//#define INT_MAX 2147483647
#define FOR(i, N) for( int i = 0 ; i < N ; i++ )
#define FOR1e(i, N) for( int i = 1 ; i <= N ; i++ )
#define FORe(i, N) for(int i = 0 ; i <= N ; i++ )
#define FOR1(i, N) for(int i = 1 ; i < N ; i++ )

using namespace std;

typedef struct E { int First;   int Second; } E;
E All[Max] = {{1,2}, {1,3}, {1,5}, {2,3}, {2,5}, {3,4}, {3,5}, {4,5}};
bool Visited[Max];
int Current[Max + 1];

void Solve(int I, int C){
    Current[C] = I;
    if(C == 8){
        FOR(i, Max + 1)         printf("%d", Current[i]);
        puts("");               
        return;
    }
    FOR(i, Max){
        if(!Visited[i]){
            if(All[i].First == I){
                Visited[i] = true;
                Solve(All[i].Second, C + 1);
                Visited[i] = false;
            } else if(All[i].Second == I){
                Visited[i] = true;
                Solve(All[i].First, C + 1);
                Visited[i] = false;
            }
        }
    }
}

int main(int argc, char** argv) {
//    freopen("Trojan.txt", "r", stdin);
    memset(Visited, false, sizeof(Visited));
    Solve(1, NULL);

    return 0;
}

