//============================================================================
// File        : 1261 - String Popping.cpp
// Author      : AHMED HANI IBRAHIM
// Copyright   : AHani
// Version     : UVa - Accepted - 0.144
// Created on November 28, 2012, 9:31 PM
//============================================================================

//#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <functional>
//#define Max 10000 + 5
//#define INF 1000000000
//#define INT_MAX 2147483647
//#define FOR(i, N) for( int i = 0 ; i < N ; i++ )
//#define FOR1e(i, a, N) for( int i = a ; i <= N ; i++ )
//#define FORe(i, N) for(int i = 0 ; i <= N ; i++ )
//#define FOR1(i, N) for(int i = 1 ; i < N ; i++ )

using namespace std;

int TestCases;
bool Null;
string Line;

void Solve(string L) {
    if(Null)    return;
    if(L.empty()) {
        Null = true;
        return;
    }
    int i, j;
    for(i = 0; i < L.size() && !Null; i++) {
        for(j = i; L[i] == L[j] && j < L.size(); j++) {;} 
          //  if(L[i] == L[j])  continue;
            if(j - i >= 2)      Solve(L.substr(NULL, i) + L.substr(j));
           i = j - 1;
        
    }
}

int main(int argc, char** argv) {
 //  freopen("Trojan.txt", "r", stdin);
    //int Cases = 1;
    scanf("%d", &TestCases);
    while(TestCases--) {
        Null = false;
        cin >> Line;
        Solve(Line);
        puts(Null ? "1" : "0");
    }
   
    return 0;
}

