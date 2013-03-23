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
#include <set>
#define Max 1000 + 5
#define INF 1000000000
//#define INT_MAX 2147483647
#define FOR(i, N) for( int i = 0 ; i < N ; i++ )
#define FOR1e(i, N) for( int i = 1 ; i <= N ; i++ )
#define FORe(i, N) for(int i = 0 ; i <= N ; i++ )
#define FOR1(i, N) for(int i = 1 ; i < N ; i++ )

using namespace std;

int Number;
int All;
int Result[Max];

int main(int argc, char** argv) {
        //freopen("Trojan.txt", "r", stdin);
        scanf("%d", &Number);
        FOR1e(i, Number) {
            scanf("%d", &All);
            All = All % 2;
            Result[All] = !Result[All] ? i : -1;
        }
        FOR(i, 2)       if(Result[i] != -1)     printf("%d\n", Result[i]);
    
    return 0;
}
