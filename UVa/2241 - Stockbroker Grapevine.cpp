//============================================================================
// File        : 2241 - Stockbroker Grapevine.cpp
// Author      : AHMED HANI IBRAHIM
// Copyright   : AHani
// Version     : Live Archive - Accepted
// Created on April 15, 2013, 13:43 PM
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
#include <math.h>
#define Max 200 + 5
#define P pair<int, double>
#define INF 1000000000
//#define INT_MAX 2147483647
#define FOR(i, N) for( int i = 0 ; i < N ; i++ )
#define FOR1e(i, N) for( int i = 1 ; i <= N ; i++ )
#define FORe(i, N) for(int i = 0 ; i <= N ; i++ )
#define FOR1(i, N) for(int i = 1 ; i < N ; i++ )

using namespace std;

int Distance[Max][Max];
int N;
int First, Second;
int Maximum[Max];

int main(int argc, char** argv) {
   freopen("Trojan.txt","r",stdin);
    while(scanf("%d", &N) == 1, N) {
        memset(Maximum, NULL, sizeof(Maximum));
        FOR(i, Max)     FOR(j, Max)     Distance[i][j] = INF;
        FOR(i, Max)     Distance[i][i] = 0;
        
        FOR(i, N) { 
            for(scanf("%d", &First); First > 0; First--) {
                scanf("%d", &Second);
                cin >> Distance[i][Second - 1];
            }
        }
        // Floyed
        FOR(k, N) {
            FOR(i, N) {
                FOR(j, N) {
                    Distance[i][j] = min(Distance[i][j], Distance[i][k] + Distance[k][j]);
                } 
            }
        }
        FOR(i, N) {
            Maximum[i] = 0;
            FOR(j, N) {
                if(Maximum[i] < Distance[i][j]) Maximum[i] = Distance[i][j];
            }
        }
        int Result = INF;
        int Person;
        FOR(i, N) {
            if(Result > Maximum[i]) {
                Result = Maximum[i];
                Person = i;
            }
        }
        if(Result == INF)       puts("disjoint");
        else printf("%d %d\n", Person + 1, Result);
    }      
    
    return 0;
}

