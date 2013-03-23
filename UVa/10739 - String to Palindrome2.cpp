//============================================================================
// File        : 10739 - String to Palindrome.cpp
// Author      : AHMED HANI IBRAHIM
// Copyright   : AHani
// Version     : 
// Created on January 30, 2013, 12:26 AM
//============================================================================

#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>
#include <map>
#include <algorithm>
#include <functional>
#define Max 1000 + 5
#define INF 1000000000
//#define INT_MAX 2147483647
#define FOR(i, N) for( int i = 0 ; i < N ; i++ )
#define FOR1e(i, N) for( int i = 1 ; i <= N ; i++ )
#define FORe(i, N) for(int i = 0 ; i <= N ; i++ )
#define FOR1(i, N) for(int i = 1 ; i < N ; i++ )

using namespace std;

int TestCases;
int DP[Max][Max];
string Line;

int Solve(int Start, int End) {
    int CurrentCounter;
    if(Start >= End)    return 0;
    if(DP[Start][End] != -1)    return DP[Start][End];
    if(Line[Start] == Line[End])       DP[Start][End] = Solve(Start + 1, End - 1);
    else {
        DP[Start][End] = 1 + Solve(Start, End - 1);
        CurrentCounter = 1 + Solve(Start + 1, End);
        //DP[Start][End] = min(DP[Start][End], Current);
        if(CurrentCounter < DP[Start][End])    DP[Start][End] = CurrentCounter;
        CurrentCounter = 1 + Solve(Start + 1, End - 1);
        if(CurrentCounter < DP[Start][End])    DP[Start][End] = CurrentCounter;
    }
    return DP[Start][End];
}

int main(int argc, char** argv) {
   // freopen("Trojan.txt", "r", stdin);
    int Cases = 1;
    scanf("%d", &TestCases);
    while(TestCases--) {
        cin >> Line;
        memset(DP, -1, sizeof(DP));
        int Length = Line.size() - 1;
        printf("Case %d: %d\n", Cases++,  Solve(0, Length));
    }

    return 0;
}

