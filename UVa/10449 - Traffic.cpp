//============================================================================
// File        : 10449 - Traffic.cpp
// Author      : AHMED HANI IBRAHIM
// Copyright   : AHani
// Version     : UVa - Accepted - 0.032
// Created on April 11, 2013, 2:33 AM
//============================================================================

#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>
#include <map>
#include <algorithm>
#include <functional>
#define Max 200 + 5
#define INF 1000000000
//#define INT_MAX 2147483647
#define FOR(i, N) for( int i = 0 ; i < N ; i++ )
#define FOR1e(i, N) for( int i = 1 ; i <= N ; i++ )
#define FORe(i, N) for(int i = 0 ; i <= N ; i++ )
#define FOR1(i, N) for(int i = 1 ; i < N ; i++ )

using namespace std;

int NumberOfJunction;
int Junctions[Max];
int Roads, First, Second;
bool Connected[Max][Max];
int Distance[Max][Max];
int Queries, Node;
int Cost[Max];

int main(int argc, char** argv) {
   // freopen("Trojan.txt", "r", stdin);
    int Cases = 1;
    while(scanf("%d", &NumberOfJunction) == 1) {
        memset(Junctions, NULL, sizeof(Junctions));
        memset(Connected, false, sizeof(Connected));
        //memset(Distance, NULL, sizeof(Distance));
        memset(Cost, NULL, sizeof(Cost));
        FOR1e(i, NumberOfJunction)      scanf("%d", &Junctions[i]);
        FOR1e(i, NumberOfJunction) FOR1e(j, NumberOfJunction)  Distance[i][j] = INF;
        FOR1e(i, NumberOfJunction)      Distance[i][i] = NULL, Connected[i][i] = false;
        
        scanf("%d", &Roads);
        FOR(i, Roads) {
            scanf("%d %d", &First, &Second);
            Distance[First][Second] = (Junctions[Second] - Junctions[First]) * 
                    (Junctions[Second] - Junctions[First]) * 
                    (Junctions[Second] - Junctions[First]);
            Connected[First][Second] = true;
        }
        // Floyed
        FOR1e(k, NumberOfJunction) {
            FOR1e(i, NumberOfJunction) {
                if(Connected[i][k])
                FOR1e(j, NumberOfJunction) {
                    if(Connected[k][j]) {
                        Connected[i][j] = true;
                        Distance[i][j] = min(Distance[i][j], Distance[i][k] + Distance[k][j]);
                        if(Distance[i][j] < -INF)   Distance[i][j] = INF;
                    }
                }
            }
        }
        FOR1e(i, NumberOfJunction) {
            Cost[i] = Distance[1][i];
            if(!Connected[1][i]) {
                Cost[i] = -1;
                continue;
            }
            FOR1e(j, NumberOfJunction) {
                if(Connected[1][j] && Connected[j][i] && Distance[j][j] < NULL) {
                    Cost[i] = -1;
                    break;
                }
            }
        }
        printf("Set #%d\n", Cases++);
        
        scanf("%d", &Queries);
        while(Queries--) scanf("%d", &Node), printf(Cost[Node] < 3 ? "?\n" : "%d\n", Cost[Node]);
        
    }

    return 0;
}

