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
#define Max 100
#define INF 1000000000
//#define INT_MAX 2147483647
#define FOR(i, N) for( int i = 0 ; i < N ; i++ )
#define FOR1e(i, N) for( int i = 1 ; i <= N ; i++ )
#define FORe(i, N) for(int i = 0 ; i <= N ; i++ )
#define FOR1(i, N) for(int i = 1 ; i < N ; i++ )

using namespace std;

string Line;
int Counter1, Counter2;
bool Check;

int main(int argc, char** argv) {
  // freopen("Trojan.txt", "r", stdin);
    cin >> Line;
    Counter1 = Counter2 = NULL;
    Check = true;
    FOR(i, Line.size()) {
        if(Line[i] == '4')
            Counter1++;
        else if(Line[i] == '7')
            Counter2++;
    }
    
        puts((Counter1 + Counter2 == 7 || Counter1 + Counter2 == 4) ? "YES" : "NO");
    
    return 0;
}
