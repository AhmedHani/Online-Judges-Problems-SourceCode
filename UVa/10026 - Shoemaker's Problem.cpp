//============================================================================
// File        : 10026 - Shoemaker's Problem.cpp
// Author      : AHMED HANI IBRAHIM
// Copyright   : AHani
// Version     : UVa - Accepted - 0.008
// Created on September 28, 2012, 5:46 PM
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

using namespace std;

int TestCases, NumberOfJobs, Time, Fine;
vector<pair<double, int> > Container;

bool Compare(const pair<double,int> &X, const pair<double,int> &Y) {
    if (X.first == Y.first)     return X.second < Y.second;
    return X.first > Y.first;
}

int main(int argc, char** argv) {
//    freopen("Trojan.txt", "r", stdin);
 
    scanf("%d", &TestCases);
    while(TestCases--){
        Container.clear();
        scanf("%d", &NumberOfJobs);
        
        FOR(i, NumberOfJobs){
            scanf("%d %d", &Time, &Fine);
            Container.push_back(make_pair(Fine * 1.0 / Time, i + 1));
        }
        sort(Container.begin(), Container.end(), Compare);
        
        FOR(i, Container.size()){
            if(i > NULL)        printf(" ");
            printf("%d", Container[i].second);
        }
        puts("");
        
        if(TestCases)   puts("");
    }

    return 0;
}

