//============================================================================
// File        : 11039 - Building designing.cpp
// Author      : AHMED HANI IBRAHIM
// Copyright   : AHani
// Version     : 
// Created on February 4, 2013, 7:44 AM
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

int TestCases;
int NumberOfFloors, Floor;
int Counter, Previous;
vector<pair<int, int> > Floors;

bool Comp(const pair<int,int> &X, const pair<int,int> &Y) {
  return X.first > Y.first;
}

int main(int argc, char** argv) {
   // freopen("Trojan.txt", "r", stdin);
    scanf("%d", &TestCases);
    while(TestCases--) {
        Floors.clear();
        scanf("%d", &NumberOfFloors);
        FOR(i, NumberOfFloors) {
            scanf("%d", &Floor);
            if(Floor < 0)       Floors.push_back(make_pair(-Floor, RED));
            else                Floors.push_back(make_pair(Floor, BLUE));
        }
        sort(Floors.begin(), Floors.end(), Comp);
        Previous = Floors[0].second;
        Counter = 1;
        FOR(i, Floors.size()) {
            if(Floors[i].second != Previous) {
                ++Counter;
            Previous = Floors[i].second;
            }
        }
        printf("%d\n", Counter);
    }

    return 0;
}

