//============================================================================
// File        : 10017 - The Never Ending Towers of Hanoi.cpp
// Author      : AHMED HANI IBRAHIM
// Copyright   : AHani
// Version     : UVa - Accepted - 020
// Created on April 21, 2013, 14:03 PM
//============================================================================

#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <functional>
#include <math.h>
#include <list>
#define Max 5
#define INF 1000000000
//#define INT_MAX 2147483647
#define FOR(i, N) for( int i = 0 ; i < N ; i++ )
#define FOR1e(i, N) for( int i = 1 ; i <= N ; i++ )
#define FORe(i, N) for(int i = 0 ; i <= N ; i++ )
#define FOR1(i, N) for(int i = 1 ; i < N ; i++ )

using namespace std;

enum P {First, Second, Third};
vector<int> Pegs[Max];
int NumberOfDisks, LastMoveCount;

void Print() {
    FOR(i, 3) {
        cout << (char) ('A' + i) << "=>";
        if(Pegs[i].size()) {
            printf("  ");
            FOR(j, Pegs[i].size())      printf(" %d", Pegs[i][j]);
        }
        puts("");
    }
    puts("");
}

void SolveHanoi(const int& From, const int& Middle, const int& To, int NumberOfDisks) {
    if(NumberOfDisks > 0) {
        SolveHanoi(From, To, Middle, NumberOfDisks - 1);
        Pegs[To].push_back(Pegs[From].back());
        Pegs[From].pop_back();
        if(LastMoveCount-- > 0)      Print();
        else            return;
        SolveHanoi(Middle, From, To, NumberOfDisks - 1);
    }
}

int main(int argc, char** argv) {
    //freopen("Trojan.txt","r",stdin);
    int Cases = 1;
    while(scanf("%d %d", &NumberOfDisks, &LastMoveCount) == 2, NumberOfDisks|LastMoveCount) {
        FOR(i, Max)     Pegs[i].clear();
        printf("Problem #%d\n", Cases++);
        puts("");
        FOR(i, NumberOfDisks)   Pegs[First].push_back(NumberOfDisks - i);
        
        Print();
        SolveHanoi(First, Second, Third, NumberOfDisks);
    }
    
    return 0;
}

