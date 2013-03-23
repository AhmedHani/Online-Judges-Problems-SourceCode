//============================================================================
// File        : 10987 - Antifloyd.cpp
// Author      : AHMED HANI IBRAHIM
// Copyright   : AHani
// Version     : UVa - Accepted - 0.068
// Created on February 17, 2013, 10:45 PM
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

int TestCases;
int NumberOfComputers;
int NumberOfCables;
int Distance[Max][Max];
bool Connected[Max][Max];

bool Check() {
    FOR(k, NumberOfComputers) {
        FOR(i, NumberOfComputers) {
            FOR(j, NumberOfComputers) {
                if(Distance[i][k] + Distance[k][j] < Distance[i][j])
                    return true;
            }
        }
    }
    NumberOfCables = NULL;
    FOR(i, NumberOfComputers) {
        FOR(j, i) {
            Connected[i][j] = Connected[j][i] = true;
            FOR(k, NumberOfComputers) {
                if(k != i && k != j && Distance[i][k] + Distance[k][j] == Distance[i][j])
                    Connected[i][j] = Connected[j][i] = false;
            }
            NumberOfCables += Connected[i][j];
        }
    }
    printf("%d\n", NumberOfCables);
    for(int i = 0; i < NumberOfComputers; i++) {
        for(int j = i + 1; j < NumberOfComputers; j++) {
            if(Connected[i][j])
                printf("%d %d %d\n", i + 1, j + 1, Distance[i][j]);
        }
    }
    return false;
}

int main(int argc, char** argv) {
    freopen("Trojan.txt", "r", stdin);
    int Cases = 1;
    scanf("%d", &TestCases);
    while(TestCases--) {
        scanf("%d", &NumberOfComputers);
        printf("Case #%d:\n", Cases++);
        FOR(i, NumberOfComputers) {
            FOR(j, i) {
                scanf("%d", &Distance[i][j]);
                Distance[j][i] = Distance[i][j];
            }
            Distance[i][i] = NULL;
        }
        if(Check())     puts("Need better measurements.");
        puts("");
    }

    return 0;
}

