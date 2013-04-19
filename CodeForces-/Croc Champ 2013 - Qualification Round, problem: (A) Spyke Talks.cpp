//============================================================================
// File        : Croc Champ 2013 - Qualification Round, problem: (A) Spyke Talks.cpp
// Author      : AHMED HANI IBRAHIM
// Copyright   : AHani
// Version     : CF - Accepted
// Created on April 11, 2013, 2:33 AM
//============================================================================

#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <functional>
#include <map>
#define Max 1000 + 5
#define INF 1000000000
//#define INT_MAX 2147483647
#define FOR(i, N) for( int i = 0 ; i < N ; i++ )
#define FOR1e(i, N) for( int i = 1 ; i <= N ; i++ )
#define FORe(i, N) for(int i = 0 ; i <= N ; i++ )
#define FOR1(i, N) for(int i = 1 ; i < N ; i++ )

using namespace std;

map<int, int> Map;
int N;
int Tmp;
int Counter;

int main(int argc, char** argv) {
   // freopen("Trojan.txt", "r", stdin);
        scanf("%d", &N);
        Map.clear();
        Counter = 0;
        FOR(i, N) {
            scanf("%d", &Tmp);
            if(Tmp) ++Map[Tmp];
        }
        for(map<int, int>::iterator it = Map.begin(); it != Map.end(); it++) {
            if((*it).second == 2)Counter++;
            if((*it).second > 2) { Counter = -1; break; }
        }
        printf("%d\n", Counter);
    
    return 0;
}
