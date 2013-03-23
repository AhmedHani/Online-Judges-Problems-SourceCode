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
#include <vector>
#include <algorithm>
#include <cmath>
#define Max 50
#define INF 1000000000
//#define INT_MAX 2147483647
#define FOR(i, N) for( int i = 0 ; i < N ; i++ )
#define FOR1e(i, N) for( int i = 1 ; i <= N ; i++ )
#define FORe(i, N) for(int i = 0 ; i <= N ; i++ )
#define FOR1(i, N) for(int i = 1 ; i < N ; i++ )

using namespace std;

char Line[Max];
char C;
int Result, Counter;

int main(int argc, char** argv) {
    //freopen("Trojan.txt", "r", stdin);
    gets(Line);
    C = 'a';
    Counter = 1;
    Result = 1;
    FOR(i, strlen(Line)) {
        if(Line[i] == C) {
            Counter++;
            if(Counter > Result)
                Result = Counter;
        } else {
            C = Line[i];
            Counter = 1;
        }
    }
    puts(Result >= 7 ? "YES" : "NO");
    
    
}
