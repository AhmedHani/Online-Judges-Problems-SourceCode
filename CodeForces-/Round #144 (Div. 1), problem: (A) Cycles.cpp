//============================================================================
// File        : main.cpp
// Author      : AHMED HANI IBRAHIM
// Copyright   : AHani
// Version     : 
// Created on February 12, 2013, 10:22 AM
//============================================================================

#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <assert.h>
#define Max 1000 + 5
#define INF 1000000000
//#define INT_MAX 2147483647
#define FOR(i, N) for( int i = 0 ; i < N ; i++ )
#define FOR1e(i, N) for( int i = 1 ; i <= N ; i++ )
#define FORe(i, N) for(int i = 0 ; i <= N ; i++ )
#define FOR1(i, N) for(int i = 1 ; i < N ; i++ )
#define BLUE 1
#define RED 2
using namespace std;

bool Matrix[Max][Max];
int Cycles;

int main(int argc, char** argv) {
  //  freopen("Trojan.txt", "r", stdin);
    scanf("%d", &Cycles);
    int N = 2;
    memset(Matrix, false, sizeof(Matrix));
    Matrix[0][1] = Matrix[1][0] = true;
    while(Cycles > 0) {
        Matrix[0][N] = Matrix[N][0] = true;
        //int Current;
        FOR1(i, N) {
            if(i > Cycles)      break;
            Cycles -= i;
            Matrix[i][N] = Matrix[N][i] = true;
        }
        N++;
        assert(N <= 100);
    }
    printf("%d\n", N);
    FOR(i, N) {
        FOR(j, N)       printf("%d", Matrix[i][j]);
        puts("");
    }
    
    return 0;
}
