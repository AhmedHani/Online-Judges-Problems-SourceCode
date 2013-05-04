//============================================================================
// File        : 12455 - Bars.cpp
// Author      : AHMED HANI IBRAHIM
// Copyright   : AHani
// Version     : UVa - Accepted - 0.016
// Created on MAy 04, 2013, 04:50 PM
//============================================================================

#include <cstdlib>
#include <stdio.h>
//#include <string.h>
//#include <string>
//#include <iostream>
//#include <queue>
//#include <algorithm>
//#include <vector>
//#include <set>
#include <bitset>
//#include <iomanip>
//#include <map>
#define Max 100050 + 5
#define INF 1000000000
//#define INT_MAX 2147483647
#define FOR(i, N) for( int i = 0 ; i < N ; i++ )
#define FOR1e(i, N) for( int i = 1 ; i <= N ; i++ )
#define FORe(i, N) for(int i = 0 ; i <= N ; i++ )
#define FOR1(i, N) for(int i = 1 ; i < N ; i++ )

using namespace std;

int TestCases;
int Target;
int NumberOfBars, Sum;
int* Bars;
bool Can;

int main(int argc, char** argv) {
    //freopen("Trojan.txt", "r", stdin);
    scanf("%d", &TestCases);
    while(TestCases-- > 0) {
        scanf("%d\n", &Target);
        scanf("%d", &NumberOfBars);
        Can = false;
        Bars = new int[NumberOfBars + 1];
        FOR(i, NumberOfBars)    scanf("%d", &Bars[i]);
        
        FOR(i, (1 << NumberOfBars)) {
            Sum = NULL;
            FOR(j, NumberOfBars)        if(i & (1 << j))        Sum += Bars[j];
            if(Sum == Target) {
                Can = true;
                break;
            }
        }
        puts(Can ? "YES" : "NO");
        delete[] Bars;
    }
    
    return 0;
}

