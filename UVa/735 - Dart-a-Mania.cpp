//============================================================================
// File        : 735 - Dart-a-Mania.cpp
// Author      : AHMED HANI IBRAHIM
// Copyright   : AHani
// Version     : UVa - Accepted - 0.685
// Created on May 04, 2013, 06:31 PM
//============================================================================

#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <set>
#include <bitset>
#include <iomanip>
#include <map>
#define Max 60 + 5
#define INF 1000000000
//#define INT_MAX 2147483647
#define FOR(i, N) for( int i = 0 ; i < N ; i++ )
#define FOR1e(i, N) for( int i = 1 ; i <= N ; i++ )
#define FORe(i, N) for(int i = 0 ; i <= N ; i++ )
#define FOR1(i, N) for(int i = 1 ; i < N ; i++ )

using namespace std;

set<int> Regions;
bool Visited[Max][Max][Max];
int Score, Combinations, Permutations;
vector<int> Values;

int main(int argc, char** argv) {
    //freopen("Trojan.txt", "r", stdin);
    FORe(i, 20) Regions.insert(i), Regions.insert(i * 2), Regions.insert(i * 3);
    Regions.insert(50);
    for(set<int>::iterator it = Regions.begin(); it != Regions.end(); it++) {
        Values.push_back(*it);
    }
    while(scanf("%d", &Score) == 1) {
        Combinations = Permutations = NULL;
        if(Score <= NULL) {
            puts("END OF OUTPUT");
            break;
        }
        memset(Visited, false, sizeof(Visited));
        
        FOR(i, Values.size()) {
            FOR(j, Values.size()) {
                FOR(k, Values.size()) {
                    if(Values[i] + Values[j] + Values[k] == Score) {
                        Permutations++;
                        if(!Visited[Values[i]][Values[j]][Values[k]]) {
                            Visited[Values[i]][Values[j]][Values[k]] = Visited[Values[i]][Values[k]][Values[j]] = true;
                            Visited[Values[j]][Values[i]][Values[k]] = Visited[Values[j]][Values[k]][Values[i]] = true;
                            Visited[Values[k]][Values[i]][Values[j]] = Visited[Values[k]][Values[j]][Values[i]] = true;
                            Combinations++;
                        }
                    }
                }
            }
        }
        if(!Permutations && !Combinations)      printf("THE SCORE OF %d CANNOT BE MADE WITH THREE DARTS.\n", Score);
        else {
            printf("NUMBER OF COMBINATIONS THAT SCORES %d IS %d.\n", Score, Combinations);
            printf("NUMBER OF PERMUTATIONS THAT SCORES %d IS %d.\n", Score, Permutations);
        }
        puts("**********************************************************************");
    }
    
    return 0;
}

