//============================================================================
// File        : main.cpp
// Author      : AHMED HANI IBRAHIM
// Copyright   : AHani
// Version     : 
// Created on January 25, 2013, 7:44 PM
//============================================================================

#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>
#include <queue>
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

int Number;
int Arr[Max];
int Result;

int main () {
    //freopen("Trojan.txt", "r", stdin);
    while(scanf("%d", &Number) == 1) {
        Result = 0;
        FOR(i, Number)  scanf("%d", &Arr[i]);
        FOR(i, Number) {
            int Tmp = 0;
            for(int j = i; j < Number; j++) {
                Tmp ^= Arr[j];
                Result = max(Result, Tmp);
            }
        }
        printf("%d\n", Result);
    }
    
    
    return 0;
 
}
