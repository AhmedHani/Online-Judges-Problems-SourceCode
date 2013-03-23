//============================================================================
// File        : 11151 - Longest Palindrome.cpp
// Author      : AHMED HANI IBRAHIM
// Copyright   : AHani
// Version     : UVa - Accepted - 0.112
// Created on September 14, 2012, 4:40 PM
//============================================================================

//#include <cstdlib>
#include <stdio.h>
#include <string.h>
//#include <string>
//#include <iostream>
//#include <map>
#include <algorithm>
//#include <functional>
#define Max 1000 + 5
#define INF 1000000000
//#define INT_MAX 2147483647
#define FOR(i, N) for( int i = 0 ; i < N ; i++ )
#define FOR1e(i, N) for( int i = 1 ; i <= N ; i++ )
#define FORe(i, N) for(int i = 0 ; i <= N ; i++ )
#define FOR1(i, N) for(int i = 1 ; i < N ; i++ )

using namespace std;

int TestCases, Length;
char Text[Max];
int DPMemo[Max][Max];

int Solve(int i, int j){
    if ( i > j )        return 0;
    if ( i == j )        return DPMemo[i][j] = 1;
    if ( DPMemo[i][j] != -1 )   return DPMemo[i][j];
    if ( Text[i] == Text[j] )     return DPMemo[i][j] = 2 + Solve(i + 1, j - 1);  
    
    return DPMemo[i][j] = max(Solve(i + 1, j), Solve(i, j - 1));
    
}


int main(int argc, char** argv) {
//    freopen("Trojan.txt", "r", stdin);
    
    scanf("%d", &TestCases);
    getchar();
    while ( TestCases-- ){
        gets(Text); 
        Length = strlen(Text);
        memset(DPMemo, -1, sizeof(DPMemo));
        
        printf("%d\n", Solve(NULL, Length - 1));
    }

    return 0;
}

