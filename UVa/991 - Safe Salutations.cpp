//============================================================================
// File        : 991 - Safe Salutations.cpp
// Author      : AHMED HANI IBRAHIM
// Copyright   : AHani
// Version     : UVa - Accepted - 0.008
// Created on September 9, 2012, 2:42 PM
//============================================================================

#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>
#include <map>
#include <algorithm>
#include <functional>
#define Max 10 + 5
#define INF 1000000000
//#define INT_MAX 2147483647
#define FOR(i, N) for( int i = 0 ; i < N ; i++ )
#define FOR1e(i, N) for( int i = 1 ; i <= N ; i++ )
#define FORe(i, N) for(int i = 0 ; i <= N ; i++ )
#define FOR1(i, N) for(int i = 1 ; i < N ; i++ )

using namespace std;

int Table[Max];


int main(int argc, char** argv) {
    freopen("Trojan.txt", "r", stdin);
    Table[0] = Table[1] = 1;
    for(int i = 2; i < 11; i++){
        Table[i] = Table[i - 1] * (4 * i - 2) / (i + 1);
    }
    int n;
    bool first = true;

    while( scanf("%d", &n) != EOF){
        if(first) first = false; else printf("\n");
       printf("%d\n", Table[n]);
    }

    return 0;
}

