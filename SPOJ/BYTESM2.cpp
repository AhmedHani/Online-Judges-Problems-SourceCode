//============================================================================
// File        : main.cpp
// Author      : AHMED HANI IBRAHIM
// Copyright   : AHani
// Version     : 
// Created on February 3, 2013, 11:31 AM
//============================================================================

#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>
#include <map>
#include <algorithm>
#include <functional>
#define Max 500 + 5
#define INF 1000000000
//#define INT_MAX 2147483647
#define FOR(i, N) for( int i = 0 ; i < N ; i++ )
#define FOR1e(i, N) for( int i = 1 ; i <= N ; i++ )
#define FORe(i, N) for(int i = 0 ; i <= N ; i++ )
#define FOR1(i, N) for(int i = 1 ; i < N ; i++ )

using namespace std;

int Grid[Max][Max];
int DPMemo[2][Max];
int Rows, Cols;
int TestCases;

int main(int argc, char** argv) {
 // freopen("Trojan.txt", "r", stdin);
    scanf("%d", &TestCases);
    while(TestCases--) {
        scanf("%d %d", &Rows, &Cols);
        FOR(i, Rows) {
            FOR(j, Cols) {
                scanf("%d", &Grid[i][j]);
            }
        }
        FOR(i, Cols)    DPMemo[(Rows - 1) & 1][i] = Grid[Rows - 1][i];
        for(int i = Rows - 2; i >= NULL; i--) {
            for(int j = 0; j < Cols; j++) {
                DPMemo[i & 1][j] = DPMemo[1 - i & 1][j];
                if(j)   DPMemo[i & 1][j] = max(DPMemo[i & 1][j], DPMemo[1 - i & 1][j - 1]);
                if(j + 1 < Cols)       DPMemo[i & 1][j] = max(DPMemo[i & 1][j], DPMemo[1 - i & 1][j + 1]);
                DPMemo[i & 1][j] += Grid[i][j];
            }
        }
        int Result = 0;
        FOR(i, Cols)    Result = max(Result, DPMemo[0][i]);
        printf("%d\n", Result);
    }
   
  return 0;
}


