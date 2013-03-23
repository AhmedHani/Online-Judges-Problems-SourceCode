//============================================================================
// File        : 10285 - Longest Run on a Sn.cpp
// Author      : AHMED HANI IBRAHIM
// Copyright   : AHani
// Version     : UVa - Accepted - 0.020
// Created on August 24, 2012, 10:27 PM
//============================================================================

#include <cstdlib>
#include <stdio.h>
#include <string.h>
//#include<string>
//#include<iostream>
//#include<map>
#include<algorithm>
//#include<functional>
#define Max 200 + 5
#define INF 1000000000
//#define INT_MAX 2147483647
#define FOR(i , N) for( int i = 0 ; i < N ; i++ )
#define FOR1e(i , N) for( int i = 1 ; i <= N ; i++ )
#define FORe(i , N) for(int i = 0 ; i <= N ; i++ )
#define FOR1(i , N) for(int i = 1 ; i < N ; i++ )

using namespace std;

char Area[Max];
int Rows , Column;
int Result[Max][Max] , Grid[Max][Max];
int TestCases;

int DFS(int R , int C){
    int North = 0;
    int South = 0;
    int East = 0;
    int West = 0;
    
    if ( R != 0 && Grid[R - 1][C] < Grid[R][C] )  North = DFS(R - 1 , C) + 1;
    if ( R != Rows - 1 && Grid[R + 1][C] < Grid[R][C] ) South = DFS(R + 1 , C) + 1;
    if ( C != 0 && Grid[R][C - 1] < Grid[R][C] )  West = DFS(R , C - 1) + 1;
    if ( C != Column - 1 && Grid[R][C + 1] < Grid[R][C] ) East = DFS(R , C + 1) + 1;
    return Result[R][C] = max(North , max(South , max(East , West)));
}

int main(int argc, char** argv) {
//    freopen("Trojan.txt", "r", stdin);
    
    scanf("%d" , &TestCases);
    
    while ( TestCases-- ){
        memset(Result , -1 , sizeof(Result));
        
        scanf("%s %d %d" , &Area , &Rows , &Column);
        
        FOR(i , Rows){
            FOR(j , Column){
                scanf("%d" , &Grid[i][j]);
            }
        }
        
        int MaxLength = -INF;
        int Length;
        
        FOR(i , Rows){
            FOR(j , Column){
                Length = DFS(i , j);
                if ( Length > MaxLength )
                    MaxLength = Length;
            }
        }
        
        printf ("%s: %d\n", Area, MaxLength + 1);

    }
    return 0;
}

