//============================================================================
// File        : main.cpp
// Author      : AHMED HANI IBRAHIM
// Copyright   : AHani
// Version     : 
// Created on December 2, 2012, 4:05 PM
//============================================================================

#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define Max 100 + 5
#define INF 1000000000
//#define INT_MAX 2147483647
#define FOR(i, N) for( int i = 0 ; i < N ; i++ )
#define FOR1e(i, N) for( int i = 1 ; i <= N ; i++ )
#define FORe(i, N) for(int i = 0 ; i <= N ; i++ )
#define FOR1(i, N) for(int i = 1 ; i < N ; i++ )

using namespace std;

int Number;
int Soldiers[Max];
int High, Low;
int H, L;

int main(int argc, char** argv) {
   // freopen("Trojan.txt", "r", stdin);
    scanf("%d", &Number);
    
    High = -INF;
    Low  = INF;
    FOR1e(i, Number) {
        scanf("%d", &Soldiers[i]);
        if(Soldiers[i] > High) {
            High = Soldiers[i];
            H = i;
        }
        if(Soldiers[i] <= Low) {
            Low = Soldiers[i];
            L = i;
        }
    }
    printf("%d\n", H < L ? (H - 1 + Number - L) : (H - 1 + Number - L - 1));
    
    
    
}
