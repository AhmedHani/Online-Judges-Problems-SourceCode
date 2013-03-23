//============================================================================
// File        : 571 - Jugs.cpp
// Author      : AHMED HANI IBRAHIM
// Copyright   : AHani
// Version     : UVa - Accepted - 0.012
// Created on March 4, 2013, 3:55 PM
//============================================================================

#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>
#include <queue>
#include <bitset>
#include <vector>
#include <map>
#define Max 100
#define INF 1000000000
int dx[] = {-1, 1, 0, 0, 0, 0};
int dy[] = {0, 0, -1, 1, 0, 0};
int dz[] = {0, 0, 0, 0, -1, 1};
//#define INT_MAX 2147483647
#define P pair<bitset<15>, int>
#define FOR(i, N) for( int i = 0 ; i < N ; i++ )
#define FOR1e(i, N) for( int i = 1 ; i <= N ; i++ )
#define FORe(i, N) for(int i = 0 ; i <= N ; i++ )
#define FOR1(i, N) for(int i = 1 ; i < N ; i++ )

using namespace std;

int CapacityA, CapacityB, Final;
int First, Second;

int main(int argc, char** argv) {
  // freopen("Trojan.txt", "r", stdin);
    while(scanf("%d %d %d", &CapacityA, &CapacityB, &Final) == 3) {
        First = Second = 0;
        while(Second != Final) {
        if(!First)      First = CapacityA, puts("fill A");
        else {
            if(First + Second <= CapacityB) Second += First, First = 0, puts("pour A B");
            else {
                First = First - (CapacityB - Second);
                puts("pour A B");
                Second = 0;
                puts("empty B");
            }
        }
        }
        puts("success");
    }

    return 0;
}

