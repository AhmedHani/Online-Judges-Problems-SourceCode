//============================================================================
// File        : 10009 - All Roads Lead Where?.cpp
// Author      : AHMED HANI IBRAHIM
// Copyright   : AHani
// Version     : UVa - Accepted - 0.008
// Created on November 21, 2012, 5:33 AM
//============================================================================

#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>
#include <map>
#include <algorithm>
#include <functional>
#define Max 26 + 5
#define INF 1000000000
//#define INT_MAX 2147483647
#define FOR(i, N) for( int i = 0 ; i < N ; i++ )
#define FOR1e(i, N) for( int i = 1 ; i <= N ; i++ )
#define FORe(i, N) for(int i = 0 ; i <= N ; i++ )
#define FOR1(i, N) for(int i = 1 ; i < N ; i++ )

using namespace std;

int TestCases, NumberOfRoads, NumberOfQueries;
int Distance[Max][Max];
int Previous[Max][Max];
string First, Second;

string Solve(int First, int Second) {
    if(Previous[First][Second] == -1) {
        return string(1, First + 'A') + string(1, Second + 'A');
    } else {
        return Solve(First, Previous[First][Second]) + (Solve(Previous[First][Second], Second).substr(1));
    }
}

int main(int argc, char** argv) {
   //freopen("Trojan.txt", "r", stdin);
    bool Line = false;
    scanf("%d", &TestCases);
    
    while(TestCases--) {
        if(Line) puts(""); Line = true;
        memset(Distance, 0xffffff, sizeof(Distance));
        memset(Previous, 0xffffff, sizeof(Previous));
        scanf("%d %d", &NumberOfRoads, &NumberOfQueries);
        while(NumberOfRoads--) {
            cin >> First >> Second;
            Distance[First[0] - 'A'][Second[0] - 'A'] = 1;
            Distance[Second[0] - 'A'][First[0] - 'A'] = 1;
        }
        
        // Floyed
        FOR(k, Max) {
            FOR(i, Max) {
                FOR(j, Max) {
                    if(Distance[i][k] > NULL && Distance[k][j] > NULL) {
                        if(Distance[i][j] == -1 || Distance[i][k] + Distance[k][j] < Distance[i][j]) {
                            Distance[i][j] = Distance[i][k] + Distance[k][j];
                            Previous[i][j] = k;
                        }
                    }
                }
            }
        }
        while(NumberOfQueries--) {
            cin >> First >> Second;
            cout << Solve(First[0] - 'A', Second[0] - 'A') << endl;
        }
        
        
    }

    return 0;
}

