//============================================================================
// File        : main.cpp
// Author      : AHMED HANI IBRAHIM
// Copyright   : AHani
// Version     : 
// Created on March 20, 2013, 7:13 PM
//============================================================================

#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>
#include <map>
#include <algorithm>
#include <queue>
#define Max 600 + 5
#define INF 1000000000
//#define INT_MAX 2147483647
#define FOR(i, N) for( int i = 0 ; i < N ; i++ )
#define FOR1e(i, N) for( int i = 1 ; i <= N ; i++ )
#define FORe(i, N) for(int i = 0 ; i <= N ; i++ )
#define FOR1(i, N) for(int i = 1 ; i < N ; i++ )

using namespace std;

int TestCases, Marriages;
int Man, Woman;
int Prefered[Max][Max];
int WomanToMan[Max][Max];
int ManToWoman[Max][Max];
int El_7ag[Max];
int El_7aga[Max];

int main(int argc, char** argv) {
    //freopen("Trojan.txt", "r", stdin);
    scanf("%d", &TestCases);
    while(TestCases--) {
        scanf("%d", &Marriages);
        queue<int> Q;
        
        FOR(i, Marriages) {
            scanf("%d", &Woman);
            FOR(j, Marriages) {
                 cin >> WomanToMan[Woman - 1][j];
                 --WomanToMan[Woman - 1][j];
                 Prefered[Woman - 1][WomanToMan[Woman - 1][j]] = j;
             }
        }
        FOR(i, Marriages) {
            scanf("%d", &Man);
            FOR(j, Marriages) {
                cin >> ManToWoman[Man - 1][j];
                --ManToWoman[Man - 1][j];
            }
        }
        memset(El_7ag, -1, sizeof(El_7ag));
        memset(El_7aga, -1, sizeof(El_7aga));
        
        FOR(i, Marriages)       Q.push(i);
        while(!Q.empty()) {
              int CuurentMan = Q.front();
              Q.pop();
              FOR(i, Marriages) {
                  int CurrentWoman = ManToWoman[CuurentMan][i];
                  if(El_7aga[CurrentWoman] == -1) {
                      El_7aga[CurrentWoman] = CuurentMan;
                      El_7ag[CuurentMan] = CurrentWoman;
                      break;
                 } else if(Prefered[CurrentWoman][CuurentMan] < Prefered[CurrentWoman][El_7aga[CurrentWoman]]) {
                      Q.push(El_7aga[CurrentWoman]);
                      El_7ag[CuurentMan] = CurrentWoman;
                      El_7aga[CurrentWoman] = CuurentMan;
                      break;
                    }
                }
            }
        FOR(i, Marriages)  printf("%d %d\n", i + 1, El_7ag[i] + 1);
    }

    return 0;
}

