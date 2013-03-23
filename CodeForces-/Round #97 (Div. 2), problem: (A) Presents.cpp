//============================================================================
// File        : main.cpp
// Author      : AHMED HANI IBRAHIM
// Copyright   : AHani
// Version     : 
// Created on December 18, 2012, 10:47 PM
//============================================================================

#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#define Max 1000 + 5
#define INF 1000000000
#define LLU unsigned long long
//#define INT_MAX 2147483647
#define FOR(i, N) for( int i = 0 ; i < N ; i++ )
#define FOR1e(i, N) for( int i = 1 ; i <= N ; i++ )
#define FORe(i, N) for(int i = 0 ; i <= N ; i++ )
#define FOR1(i, N) for(int i = 1 ; i < N ; i++ )

using namespace std;

int Friends;
int Num;
int Arr[Max];

int main(int argc, char** argv) {
   // freopen("Trojan.txt", "r", stdin);
    scanf("%d", &Friends);
    FOR1e(i, Friends)   scanf("%d", &Num), Arr[Num] = i;
    FOR1e(i, Friends)   printf("%d ", Arr[i]);
    
}
