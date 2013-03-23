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
bool Result[Max];
set<int> Container;

void Lucky(int Num) {
    if(Num > Max)       return;
    if(Num > NULL)      Container.insert(Num);
    Num = Num * 10;
    Lucky(Num + 4);
    Lucky(Num + 7);
}


int main(int argc, char** argv) {
   //freopen("Trojan.txt", "r", stdin);
    Lucky(NULL);
        memset(Result, false, sizeof(Result));
        for(set<int>:: iterator it = Container.begin(); it != Container.end(); it++) {
            for(int j = *it; j < Max; j += *it) Result[j] = true;
        }
    while(scanf("%d", &Number) == 1) {
        puts(Result[Number] ? "YES" : "NO");
    }
        
    return 0;
}
