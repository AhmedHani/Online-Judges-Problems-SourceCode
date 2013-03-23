//============================================================================
// File        : 10739 - String to Palindrome.cpp
// Author      : AHMED HANI IBRAHIM
// Copyright   : AHani
// Version     : UVa - Accepted - 0.042
// Created on September 4, 2012, 11:18 AM
//============================================================================

//#include <cstdlib>
#include <stdio.h>
#include <string.h>
//#include<string>
//#include<iostream>
//#include<vector>
//#include<algorithm>
//#include<cmath>
#define Max 1000 + 5
#define INF 1000000000
//#define INT_MAX 2147483647
#define FOR(i , N) for( int i = 0 ; i < N ; i++ )
#define FOR1e(i , N) for( int i = 1 ; i <= N ; i++ )
#define FORe(i , N) for(int i = 0 ; i <= N ; i++ )
#define FOR1(i , N) for(int i = 1 ; i < N ; i++ )

//using namespace std;

int TestCases;
char String[Max];
int CostDP[Max][Max];

int Solve(int Index , int Length){
    int Result;
    
    if ( Index >= Length )      return 0;
    if ( CostDP[Index][Length] )        return CostDP[Index][Length];
    if ( String[Index] == String[Length] )      CostDP[Index][Length] = Solve(Index + 1 , Length - 1);
    else{
        CostDP[Index][Length] = Solve(Index , Length - 1) + 1;
        Result = Solve(Index + 1 , Length) + 1;
        if ( Result < CostDP[Index][Length] )   CostDP[Index][Length] = Result;
        Result = Solve(Index + 1 , Length - 1) + 1;
        if ( Result < CostDP[Index][Length] )   CostDP[Index][Length] = Result;
    }
    return CostDP[Index][Length];
}



int main(int argc, char** argv) {
//    freopen("Trojan.txt", "r", stdin);
    int Cases = 1;
    
    scanf("%d" , &TestCases);
    getchar();
    
    while ( TestCases-- ){
        scanf("%s" , String);
        printf("Case %d: " ,Cases++ );

        int Length = strlen(String) - 1;
        printf("%d\n", Solve(NULL , Length));
        
        if (TestCases)  memset(CostDP , NULL , sizeof(CostDP));
        
        
    }
    

    return 0;
}

