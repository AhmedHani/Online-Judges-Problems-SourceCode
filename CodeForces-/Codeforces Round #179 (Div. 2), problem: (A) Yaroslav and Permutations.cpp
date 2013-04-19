//============================================================================
// File        : Codeforces Round #179 (Div. 2), problem: (A) Yaroslav and Permutations.cpp
// Author      : AHMED HANI IBRAHIM
// Copyright   : AHani
// Version     : CF - Accepted
// Created on April 11, 2013, 2:33 AM
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
//#define INT_MAX 2147483647
#define FOR(i, N) for( int i = 0 ; i < N ; i++ )
#define FOR1e(i, N) for( int i = 1 ; i <= N ; i++ )
#define FORe(i, N) for(int i = 0 ; i <= N ; i++ )
#define FOR1(i, N) for(int i = 1 ; i < N ; i++ )

using namespace std;

int NumberOfElements;
int Elements[Max];
int Frequency[Max];
bool OK;
int Size;

int main(int argc, char** argv) {
    //freopen("Trojan.txt", "r", stdin);
    while(scanf("%d", &NumberOfElements) == 1) {
        OK = true;
        memset(Elements, NULL, sizeof(Elements));
        memset(Frequency, NULL, sizeof(Frequency));
        Size = NULL;
        if(NumberOfElements == 1) {
            puts("YES");
            return 0;
        }
        FOR(i, NumberOfElements)        scanf("%d", &Elements[i]), Frequency[Elements[i]]++;
            if(NumberOfElements % 2 == NULL) {
                Size = NumberOfElements / 2;
            } else {
                Size = (NumberOfElements + 1) / 2;
            }
            FOR(i, Max) {
                if(Frequency[i] > Size) {
                    OK = false;
                    break;
                }
            }
            if(!OK)puts("NO");
            else puts("YES");
    } 
        
    return 0;
}
