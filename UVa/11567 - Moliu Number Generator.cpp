//============================================================================
// File        : 11567 - Moliu Number Generator.cpp
// Author      : AHMED HANI IBRAHIM
// Copyright   : AHani
// Version     : UVa - Accepted - 0.316
// Created on September 15, 2012, 4:20 PM
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

long long Number;

long long Solve(long long Number){
    int Step = 1;
    
    if ( Number == NULL )       return 0;
//    if ( Number == 3 )  return Step + Step;
    if ( Number == 1 )  return Step;
    if ( Number % 2 == 1 )      return Step + min(Solve(Number - 1), Solve(Number + 1));
    
    return Step + Solve(Number / 2);
}

int main(int argc, char** argv) {
    freopen("Trojan.txt", "r", stdin);
    
    while ( scanf("%lld", &Number) != EOF ){
        printf("%lld\n", Solve(Number));
    }

    return 0;
}

