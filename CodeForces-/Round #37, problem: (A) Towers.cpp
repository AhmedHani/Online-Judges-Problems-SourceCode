//============================================================================
// File        : main.cpp
// Author      : AHMED HANI IBRAHIM
// Copyright   : AHani
// Version     : 
// Created on December 2, 2012, 4:05 PM
//============================================================================

#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>
#include <map>
#include <algorithm>
#include <functional>
#define Max 1000 + 5
#define INF 1000000000
//#define INT_MAX 2147483647
#define FOR(i, N) for( int i = 0 ; i < N ; i++ )
#define FOR1e(i, N) for( int i = 1 ; i <= N ; i++ )
#define FORe(i, N) for(int i = 0 ; i <= N ; i++ )
#define FOR1(i, N) for(int i = 1 ; i < N ; i++ )

using namespace std;

int NumberOfTowers;
int Tower;
int Counter[Max];
int Towers, High;

int main(int argc, char** argv) {
    //freopen("Trojan.txt", "r", stdin);
    scanf("%d", &NumberOfTowers);
    memset(Counter, NULL, sizeof(Counter));
    
    FOR(i, NumberOfTowers) {
        scanf("%d", &Tower);
        Counter[Tower]++;
    }
    Towers = High = NULL;
    FORe(i, Max - 5) {
        if(Counter[i] >= 1)     Towers++;
        High = max(High, Counter[i]);
    }
    printf("%d %d\n", High, Towers);
    
    
    return 0;
}
