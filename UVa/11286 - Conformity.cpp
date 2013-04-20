//============================================================================
// File        : 11286 - Conformity.cpp
// Author      : AHMED HANI IBRAHIM
// Copyright   : AHani
// Version     : UVa - Accepted - 0.220
// Created on April 20, 2013, 04:33 AM
//============================================================================

#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <functional>
#include <math.h>
#include <map>
#define Max 100000  + 5
#define INF 1000000000
//#define INT_MAX 2147483647
#define FOR(i, N) for( int i = 0 ; i < N ; i++ )
#define FOR1e(i, N) for( int i = 1 ; i <= N ; i++ )
#define FORe(i, N) for(int i = 0 ; i <= N ; i++ )
#define FOR1(i, N) for(int i = 1 ; i < N ; i++ )

using namespace std;

int NumberOfFrosh;
int Course;
map<vector<int>, int> Map;
int Counter, Maximum;

int main(int argc, char** argv) {
    //freopen("Trojan.txt","r",stdin);
    while(scanf("%d", &NumberOfFrosh) == 1, NumberOfFrosh) {
        Map.clear();
       // Courses.clear();
        Counter = 0;
        Maximum = 1;
        while(NumberOfFrosh--) {
            vector<int> Courses(5);
            FORe(i, 4)  cin >> Courses[i];
            sort(Courses.begin(), Courses.end());
            ++Map[Courses];
            Maximum = max(Maximum, Map[Courses]);
        }
        for(map<vector<int>, int>::iterator it = Map.begin(); it != Map.end(); it++) {
            if(Maximum == (*it).second) Counter += (*it).second;
        }
        printf("%d\n", Counter);
    }
    return 0;
}

