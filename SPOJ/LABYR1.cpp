//============================================================================
// File        : main.cpp
// Author      : AHMED HANI IBRAHIM
// Copyright   : AHani
// Version     : 
// Created on February 20, 2013, 10:15 PM
//============================================================================

#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <queue>
#define Max 10000 + 5
#define MOD 1000000007
#define INF 1000000000
#define P pair<int, int>
//#define INT_MAX 2147483647
#define FOR(i, N) for( int i = 0 ; i < N ; i++ )
#define FOR1e(i, N) for( int i = 1 ; i <= N ; i++ )
#define FORe(i, N) for(int i = 0 ; i <= N ; i++ )
#define FOR1(i, N) for(int i = 1 ; i < N ; i++ )

using namespace std;

int TestCases;
int Rows, Columns;
int Maxi, MaxLength;
char Grid[Max][Max];
P Current;

void FloodFill(int R, int C, int Counter) {
    if(Grid[R][C] != '.' || R < 0 || R >= Rows || C < 0 || C >= Columns)        return;
    Grid[R][C] = '#';
    FloodFill(R + 1, C, Counter + 1);
    FloodFill(R - 1, C, Counter + 1);
    FloodFill(R, C + 1, Counter + 1);
    FloodFill(R, C - 1, Counter + 1);
    Grid[R][C] = '.';
    if(Counter > Maxi)  Maxi = Counter, Current.first = R, Current.second = C;
    
}

int main(int argc, char** argv) {
    //freopen("Trojan.txt", "r", stdin);
    scanf("%d", &TestCases);
    while(TestCases--) {
        scanf("%d %d", &Columns, &Rows);
        FOR(i, Rows)    scanf("%s", Grid[i]);
        Current.first = Current.second = NULL;
        FOR(i, Rows) {
            FOR(j, Columns) {
                if(Grid[i][j] == '.') {
                    Current.first = i;
                    Current.second = j;
                    break;
                }
            }
        }
        //bool OK = true;
        MaxLength = NULL;
        if(Grid[Current.first][Current.second] != '.')  return 0;
        while(true) {
                Maxi = NULL;
                FloodFill(Current.first, Current.second, NULL);
                if(Maxi <= MaxLength)   break;
                else    MaxLength = Maxi;
            }
        
        printf("Maximum rope length is %d.\n", MaxLength);
    }
             
    return 0;
}

