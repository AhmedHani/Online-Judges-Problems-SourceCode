//============================================================================
// File        : 10259 - Hippity Hopscotch.cpp
// Author      : AHMED HANI IBRAHIM
// Copyright   : AHani
// Version     : UVa - Accepted - 0.084
// Created on August 24, 2012, 12:47 AM
//============================================================================

#include <cstdlib>
#include <stdio.h>
#include <string.h>
//#include<string>
//#include<iostream>
//#include<map>
#include<algorithm>
//#include<functional>
#define Max 100 + 5
#define INF 1000000000
//#define INT_MAX 2147483647
#define FOR(i , N) for( int i = 0 ; i < N ; i++ )
#define FOR1e(i , N) for( int i = 1 ; i <= N ; i++ )
#define FORe(i , N) for(int i = 0 ; i <= N ; i++ )
#define FOR1(i , N) for(int i = 1 ; i < N ; i++ )

using namespace std;

int TestCases , K  , N;
int Grid[Max][Max] , Result[Max][Max];

int Solution ( int Row , int Column , int Current ){
    if ( Row < NULL || Row >= N || Column < NULL || Column >= N || Grid[Row][Column] <= Current )
        return 0;
    if ( Result[Row][Column] >= NULL )
        return Result[Row][Column];
    
    int MaxPenies = NULL;
    
    FOR1e(i , K){
        MaxPenies = max(MaxPenies, Solution( Row + i , Column , Grid[Row][Column]) + Grid[Row][Column]);
        MaxPenies = max(MaxPenies, Solution( Row - i , Column , Grid[Row][Column]) + Grid[Row][Column]);
        MaxPenies = max(MaxPenies, Solution( Row , Column + i , Grid[Row][Column]) + Grid[Row][Column]);
        MaxPenies = max(MaxPenies, Solution( Row , Column - i , Grid[Row][Column]) + Grid[Row][Column]);
    }
    
    return Result[Row][Column] = MaxPenies;
}

int main(int argc, char** argv) {
    freopen("Trojan.txt", "r", stdin);
    
    scanf("%d" , &TestCases);
    
    while ( TestCases -- ){
        scanf("%d %d" , &N , &K);
        memset(Result , -1, sizeof(Result));
        
        FOR(i , N){
            FOR(j , N){
                scanf("%d" , &Grid[i][j]);
            }
        }
        
        printf("%d\n" , Solution(NULL , NULL , NULL));
        
        if ( TestCases )
            printf("\n");
    }

    return 0;
}

