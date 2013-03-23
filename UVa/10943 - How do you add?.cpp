//============================================================================
// File        : 10943 - How do you add?.cpp
// Author      : AHMED HANI IBRAHIM
// Copyright   : AHani
// Version     : UVa - Accepted - 0.394
// Created on August 31, 2012, 6:05 PM
//============================================================================

//#include <cstdlib>
#include <stdio.h>
#include <string.h>
//#include<string>
//#include<iostream>
//#include<map>
//#include<algorithm>
//#include<functional>
#define Max 200 + 5
//#define INF 1000000000
//#define INT_MAX 2147483647
//#define FOR(i , N) for( int i = 0 ; i < N ; i++ )
//#define FOR1e(i , N) for( int i = 1 ; i <= N ; i++ )
#define FORe(i , N) for(int i = 0 ; i <= N ; i++ )
//#define FOR1(i , N) for(int i = 1 ; i < N ; i++ )

//using namespace std;

int Number , NumberOfPairs;
int DP[Max][Max];

int Solution(int N , int K){
    unsigned long long Result = NULL;
    
    if ( K == 1)
        return 1;
    if ( DP[N][K] != NULL)
        return DP[N][K];
    
    FORe(i , N){
        DP[N - i][K - 1] = Solution(N - i , K - 1);
        Result += DP[N - i][K - 1];
    }
    
    return Result % 1000000;
}

int main(int argc, char** argv) {
//    freopen("Trojan.txt", "r", stdin);
    
    while(scanf("%d %d" , &Number , &NumberOfPairs) , Number|NumberOfPairs){
        memset(DP , NULL , sizeof(DP));
        printf("%d\n" , Solution(Number , NumberOfPairs));
    }

    return 0;
}

