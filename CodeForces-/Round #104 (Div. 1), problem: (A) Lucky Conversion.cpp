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
#include <functional>
#define Max 50 + 5
#define INF 1000000000
//#define INT_MAX 2147483647
#define FOR(i, N) for( int i = 0 ; i < N ; i++ )
#define FOR1e(i, N) for( int i = 1 ; i <= N ; i++ )
#define FORe(i, N) for(int i = 0 ; i <= N ; i++ )
#define FOR1(i, N) for(int i = 1 ; i < N ; i++ )

using namespace std;

string First, Second;

int Solve() {
    int Counter1 = NULL, Counter2 = NULL;
    FOR(i, First.length()) {
        if(First[i] != Second[i]) {
            if(First[i] == '4') Counter1++;
            else                Counter2++;
        }
    }
    return max(Counter1, Counter2);
}

int main(int argc, char** argv) {
   //freopen("Trojan.txt", "r", stdin);
    while(cin >> First >> Second)
        printf("%d\n", Solve());
   
    return 0;
}
