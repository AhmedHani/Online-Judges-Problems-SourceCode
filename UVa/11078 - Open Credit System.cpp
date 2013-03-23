//============================================================================
// File        : 11078 - Open Credit System.cpp
// Author      : AHMED HANI IBRAHIM
// Copyright   : AHani
// Version     : UVa - Accepted - 0.104
// Created on September 9, 2012, 2:42 PM
//============================================================================

//#include <cstdlib>
#include <stdio.h>
//#include <string.h>
//#include <string>
//#include <iostream>
//#include <map>
#include <algorithm>
//#include <functional>
//#define Max 10 + 5
#define INF 1000000000
//#define INT_MAX 2147483647
#define FOR(i, N) for( int i = 0 ; i < N ; i++ )
//#define FOR1e(i, N) for( int i = 1 ; i <= N ; i++ )
//#define FORe(i, N) for(int i = 0 ; i <= N ; i++ )
//#define FOR1(i, N) for(int i = 1 ; i < N ; i++ )

using namespace std;

int TestCases, NumberOfStudents;
int Score;
int Best, Result;

int main(int argc, char** argv) {
//    freopen("Trojan.txt", "r", stdin);
    
    scanf("%d", &TestCases);
    while ( TestCases-- ){
        Best = -INF;
        Result = -INF;
        
        scanf("%d", &NumberOfStudents);
        FOR(i, NumberOfStudents){
            scanf("%d", &Score);
            Result = max(Result, Best - Score);
            Best = max(Best, Score);
        }
        printf("%d\n", Result);
        
    }
      

    return 0;
}

