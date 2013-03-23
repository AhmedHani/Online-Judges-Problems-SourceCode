//============================================================================
// File        : main.cpp
// Author      : AHMED HANI IBRAHIM
// Copyright   : AHani
// Version     : 
// Created on December 18, 2012, 10:47 PM
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
#define INF 1000000000
#define LLU unsigned long long
//#define INT_MAX 2147483647
#define FOR(i, N) for( int i = 0 ; i < N ; i++ )
#define FOR1e(i, N) for( int i = 1 ; i <= N ; i++ )
#define FORe(i, N) for(int i = 0 ; i <= N ; i++ )
#define FOR1(i, N) for(int i = 1 ; i < N ; i++ )

using namespace std;

int N, M;
int MaxC, MaxR, MinR, MinC;
char Grid[Max][Max];

int main(int argc, char** argv) {
   // freopen("Trojan.txt", "r", stdin);
    MaxC = MaxR = NULL;
    MinC = MinR = 60;
    scanf("%d %d", &N, &M);
    FOR(i, N) {
        FOR(j, M) {
            cin >> Grid[i][j];
            if(Grid[i][j] == '*') {
                if(i < MinR)    MinR = i;
                if(i > MaxR)    MaxR = i;
                if(j > MaxC)    MaxC = j;
                if(j < MinC)    MinC = j;
            }
        }
    }
    for(int i = MinR; i <= MaxR; i++) {
        for(int j = MinC; j <= MaxC; j++) {
            cout << Grid[i][j];
        }
         puts("");
    }
    
    return 0;
}
