//============================================================================
// File        : main.cpp
// Author      : AHMED HANI IBRAHIM
// Copyright   : AHani
// Version     : 
// Created on February 5, 2013, 7:44 AM
//============================================================================

#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#define Max 200 + 5
#define INF 1000000000
//#define INT_MAX 2147483647
#define FOR(i, N) for( int i = 0 ; i < N ; i++ )
#define FOR1e(i, N) for( int i = 1 ; i <= N ; i++ )
#define FORe(i, N) for(int i = 0 ; i <= N ; i++ )
#define FOR1(i, N) for(int i = 1 ; i < N ; i++ )
#define BLUE 1
#define RED 2
using namespace std;

int NumberOfStreets, NumberOfInters;
double Distance[Max][Max];
int First, Second;
double Cost;

int main(int argc, char** argv) {
       // freopen("Trojan.txt", "r", stdin);
    while(scanf("%d", &NumberOfInters) == 1, NumberOfInters) {
        memset(Distance, NULL, sizeof(Distance));
        scanf("%d", &NumberOfStreets);
        FOR(i, NumberOfStreets) {
            scanf("%d %d %lf", &First, &Second, &Cost);
            Distance[First][Second] = Distance[Second][First] = Cost / 100.0;
        }
        FOR1e(k, NumberOfInters) {
            FOR1e(i, NumberOfInters) {
                FOR1e(j, NumberOfInters) {
                    Distance[i][j] = max(Distance[i][j], Distance[i][k] * Distance[k][j]);
                }
            }
        }
        printf("%.6lf percent\n", Distance[1][NumberOfInters] * 100.0 + 1e-10);
        
    }

    return 0;
}

