//============================================================================
// File        : 10910 - Marks Distribution.cpp
// Author      : AHMED HANI IBRAHIM
// Copyright   : AHani
// Version     : UVa - Accepted - 0,192
// Created on September 12, 2012, 8:44 PM
//============================================================================

//#include <cstdlib>
#include <stdio.h>
#include <string.h>
//#include <string>
//#include <iostream>
//#include <map>
//#include <algorithm>
//#include <functional>
#define Max 75 + 5
#define INF 1000000000
//#define INT_MAX 2147483647
//#define FOR(i, N) for( int i = 0 ; i < N ; i++ )
#define FOR1e(i, N) for( int i = 1 ; i <= N ; i++ )
//#define FORe(i, N) for(int i = 0 ; i <= N ; i++ )
//#define FOR1(i, N) for(int i = 1 ; i < N ; i++ )

//using namespace std;

int TestCases, NumberOfSubjects, TotalMarks, Pass;
int DPMemo[Max][Max];
int High;

unsigned int Solve(int i, int j){
    unsigned int Result = NULL;
    if ( j == NumberOfSubjects && i == TotalMarks )      return 1;
    if ( j >= NumberOfSubjects || i > TotalMarks ) return 0;
    if ( DPMemo[i][j] != -1 )   return DPMemo[i][j];
    
    for ( int ii = Pass; ii <= High; ii++){
        Result += Solve(i + ii, j + 1);
    }
    return DPMemo[i][j] = Result;
    
}

int main(int argc, char** argv) {
//    freopen("Trojan.txt", "r", stdin);
    scanf("%d", &TestCases);
    
    while ( TestCases-- ){
        scanf("%d %d %d", &NumberOfSubjects, &TotalMarks, &Pass);
        memset(DPMemo, -1, sizeof(DPMemo));
        High = TotalMarks - Pass * NumberOfSubjects + Pass;
        printf("%d\n",Solve(0,0));

    }

    return 0;
}

