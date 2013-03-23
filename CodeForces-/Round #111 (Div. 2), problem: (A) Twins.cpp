//============================================================================
// File        : main.cpp
// Author      : AHMED HANI IBRAHIM
// Copyright   : AHani
// Version     : 
// Created on December 9, 2012, 5:51 PM
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

int NumberOfCoins;
int Coins[Max];
int Result, Sum, All;

int main(int argc, char** argv) {
    //freopen("Trojan.txt", "r", stdin);
    while(scanf("%d", &NumberOfCoins) == 1) {
        Result = Sum = All = NULL;
        FOR(i, NumberOfCoins) {
            scanf("%d", &Coins[i]);
            Sum += Coins[i];
        }
        sort(Coins, Coins + NumberOfCoins);
        for(int i = NumberOfCoins - 1; i >= NULL && All <= Sum / 2; i--) {
            All += Coins[i];
            Result++;
        }
        printf("%d\n", Result);
    }

    return 0;
}
