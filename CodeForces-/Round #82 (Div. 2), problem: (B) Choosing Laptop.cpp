//============================================================================
// File        : main.cpp
// Author      : AHMED HANI IBRAHIM
// Copyright   : AHani
// Version     : 
// Created on December 18, 2012, 10:47 PM
//============================================================================

#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#define Max 500 + 5
#define INF 1000000000
//#define INT_MAX 2147483647
#define FOR(i, N) for( int i = 0 ; i < N ; i++ )
#define FOR1e(i, N) for( int i = 1 ; i <= N ; i++ )
#define FORe(i, N) for(int i = 0 ; i <= N ; i++ )
#define FOR1(i, N) for(int i = 1 ; i < N ; i++ )

using namespace std;

int NumberOfLaptops, Current, Index;
int Ram[Max], Speed[Max], Hdd[Max], Cost[Max];
bool Visited[Max];

int main(int argc, char** argv) {
    //freopen("Trojan.txt", "r", stdin);
    while(scanf("%d", &NumberOfLaptops) == 1) {
        Current = INF;
        FOR(i, NumberOfLaptops) scanf("%d %d %d %d", &Speed[i], &Ram[i], &Hdd[i], &Cost[i]);
        FOR(i, NumberOfLaptops) {
            memset(Visited, false, sizeof(Visited));
            FOR(j, NumberOfLaptops) {
                if(Speed[j] > Speed[i] && Ram[j] > Ram[i] && Hdd[j] > Hdd[i])
                    Visited[i] = true;
            }
            if(!Visited[i] && Current > Cost[i])    Current = Cost[i], Index = i ;
        }
        printf("%d\n", Index + 1);
    }

    return 0;
}
