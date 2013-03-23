//============================================================================
// File        : 10714 - Ants.cpp
// Author      : AHMED HANI IBRAHIM
// Copyright   : AHani
// Version     : UVa - Accepted - 0.016 (4)
// Created on September 21, 2012, 5:58 PM
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

int TestCases, Position, Length, NumberOfAnts, MiniMum, MaxiMum;


int main(int argc, char** argv) {
    freopen("Trojan.txt", "r", stdin);
    scanf("%d", &TestCases);
    while(TestCases--) {
        MiniMum = NULL;
        MaxiMum = NULL;
        scanf("%d %d", &Length, &NumberOfAnts);
        while(NumberOfAnts--) {
            scanf("%d", &Position);
            Position = Position < Length - Position ? Position : Length - Position;
            
            if(Position > MiniMum)      MiniMum = Position;
            if(Length - Position > MaxiMum)     MaxiMum = Length - Position;
        }
        printf("%d %d\n", MiniMum, MaxiMum);
    }
    return 0;
}

