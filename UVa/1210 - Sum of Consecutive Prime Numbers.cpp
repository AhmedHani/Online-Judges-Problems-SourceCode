//============================================================================
// File        : 1210 - Sum of Consecutive Prime Numbers.cpp
// Author      : AHMED HANI IBRAHIM
// Copyright   : AHani
// Version     : UVa - Accepted - 0.008
// Created on November 28, 2012, 9:31 PM
//============================================================================

#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#define Max 10000 + 5
#define INF 1000000000
//#define INT_MAX 2147483647
#define FOR(i, N) for( int i = 0 ; i < N ; i++ )
#define FOR1e(i, a, N) for( int i = a ; i <= N ; i++ )
#define FORe(i, N) for(int i = 0 ; i <= N ; i++ )
#define FOR1(i, N) for(int i = 1 ; i < N ; i++ )

using namespace std;

long int Number, Index;
bool AllPrimes[Max];
int NumberOfWays[Max];
vector<int> PrimesNeeded;

void Seive() {
    AllPrimes[NULL] = false;
    AllPrimes[1]    = false;
    FOR1e(i, 2, Max) {
        if(AllPrimes[i] == true) {
            PrimesNeeded.push_back(i);
            for(int j = i * i; j <= Max; j += i)
                AllPrimes[j] = false;
        }
    }
}

void PreCalculation() {
    FOR(i, PrimesNeeded.size()) {
        Index = NULL;
        for(int j = i; j < PrimesNeeded.size(); j++) {
            Index += PrimesNeeded[j];
            if(Index >= Max)     continue;
            NumberOfWays[Index]++;
        }
    }
}

int main(int argc, char** argv) {
   //freopen("Trojan.txt", "r", stdin);
   
   memset(AllPrimes, true, sizeof(AllPrimes));
   Seive();
   memset(NumberOfWays, NULL, sizeof(NumberOfWays));
   PreCalculation();
   
   while(scanf("%ld", &Number) == 1, Number)     printf("%d\n", NumberOfWays[Number]);
   
    

    return 0;
}

