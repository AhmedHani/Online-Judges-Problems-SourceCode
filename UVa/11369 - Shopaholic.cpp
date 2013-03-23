//============================================================================
// File        : 11369 - Shopaholic.cpp
// Author      : AHMED HANI IBRAHIM
// Copyright   : AHani
// Version     : UVa - Accepted - 0.048
// Created on September 28, 2012, 4:26 PM
//============================================================================

//#include <cstdlib>
#include <stdio.h>
//#include <string.h>
//#include <string>
//#include <iostream>
//#include <map>
#include <algorithm>
#include <functional>
#define Max 20005
#define INF 1000000000
//#define INT_MAX 2147483647
#define FOR(i, N) for( int i = 0 ; i < N ; i++ )
#define FOR1e(i, N) for( int i = 1 ; i <= N ; i++ )
#define FORe(i, N) for(int i = 0 ; i <= N ; i++ )
#define FOR1(i, N) for(int i = 1 ; i < N ; i++ )

using namespace std;

int TestCases;
int Seqence[Max];
int NumberOfItems;
int Sum;

int main(int argc, char** argv) {
//    freopen("Trojan.txt", "r", stdin);
    
    scanf("%d", &TestCases);
    while(TestCases--){
        scanf("%d", &NumberOfItems);
        FOR(i, NumberOfItems)   scanf("%d", &Seqence[i]);
        sort(Seqence, Seqence + NumberOfItems, greater<int>());
        
        Sum = NULL;
        for(int i = 2; i < NumberOfItems; i += 3)
            Sum += Seqence[i];
        printf("%d\n",Sum);
    }

    return 0;
}

