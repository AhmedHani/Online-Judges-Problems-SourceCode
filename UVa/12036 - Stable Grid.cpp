//============================================================================
// File        : 12036 - Stable Grid.cpp
// Author      : AHMED HANI IBRAHIM
// Copyright   : AHani
// Version     : UVa - Accepted - 0.044
// Created on February 20, 2013, 10:15 PM
//============================================================================

#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>
#include <map>
#include <algorithm>
#include <functional>
#define Max 200 + 5
#define INF 1000000000
//#define INT_MAX 2147483647
#define FOR(i, N) for( int i = 0 ; i < N ; i++ )
#define FOR1e(i, N) for( int i = 1 ; i <= N ; i++ )
#define FORe(i, N) for(int i = 0 ; i <= N ; i++ )
#define FOR1(i, N) for(int i = 1 ; i < N ; i++ )

using namespace std;

int Size, Number;
int TestCases;
int Frequencey[Max];
bool Check;

int main(int argc, char** argv) {
    //freopen("Trojan.txt", "r", stdin);
    int Cases = 1;
    scanf("%d", &TestCases);
    while(TestCases--) {
        memset(Frequencey, NULL, sizeof(Frequencey));
        scanf("%d", &Size);
        FOR(i, Size) {
            FOR(j, Size) {
                scanf("%d", &Number);
                Frequencey[Number]++;
            }
        }
        Check = true;
        FOR(i, 101)     if(Frequencey[i] > Size)        Check = false;
        printf("Case %d: ", Cases++);
        puts(Check ? "yes" : "no");
        
    }
             
    return 0;
}

