//============================================================================
// File        : 10626 - Buying Coke.cpp
// Author      : AHMED HANI IBRAHIM
// Copyright   : AHani
// Version     : UVa - Accepted - 1.896
// Created on October 4, 2012, 11:45 PM
//============================================================================

#include <cstdlib>
#include <stdio.h>
#include <string.h>
//#include <string>
//#include <iostream>
//#include <map>
#include <algorithm>
#include <functional>
#define Max1  700 + 1
#define Max5  700 + 1
#define Max10 50  + 5
#define INF 1000000000
//#define INT_MAX 2147483647
#define FOR(i, N) for( int i = 0 ; i < N ; i++ )
#define FOR1e(i, N) for( int i = 1 ; i <= N ; i++ )
#define FORe(i, N) for(int i = 0 ; i <= N ; i++ )
#define FOR1(i, N) for(int i = 1 ; i < N ; i++ )

using namespace std;

int TestCases;
int NumberOfCokes, N1, N5, N10;
int DPMemo[Max1][Max5][Max10];

int Solve(int Cokes, int First, int Second, int Third) {
    if(Cokes == NULL)   return 0;
    if(DPMemo[First][Second][Third] != -1)      return DPMemo[First][Second][Third];
    
    int Minimum = INF;
    if(First >= 8)  	Minimum = min(Minimum, Solve(Cokes - 1, First - 8, Second, Third) + 8);
    if(Second >= 2)		Minimum = min(Minimum, Solve(Cokes - 1, First + 2, Second - 2, Third) + 2);
    if(Third >= 1)		Minimum = min(Minimum, Solve(Cokes - 1, First + 2, Second, Third - 1) + 1);
    if(First >= 3 && Third >= 1)	Minimum = min(Minimum, Solve(Cokes - 1, First - 3, Second + 1, Third -1) + 4);
    if(Second >= 1 && First >= 3)	Minimum = min(Minimum, Solve(Cokes - 1, First - 3, Second - 1, Third) + 4);
    return DPMemo[First][Second][Third] = Minimum;
}

int main(int argc, char** argv) {
//    freopen("Trojan.txt", "r", stdin);
    
    scanf("%d", &TestCases);
    while(TestCases--) {
        scanf("%d %d %d %d", &NumberOfCokes, &N1, &N5, &N10);
        memset(DPMemo, -1, sizeof(DPMemo));
        printf("%d\n", Solve(NumberOfCokes, N1, N5, N10));   
    }

    return 0;
}

