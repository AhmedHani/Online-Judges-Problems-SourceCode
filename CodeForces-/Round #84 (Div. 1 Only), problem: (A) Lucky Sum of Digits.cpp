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
#include <functional>
#define Max 50 + 5
#define INF 1000000000
//#define INT_MAX 2147483647
#define FOR(i, N) for( int i = 0 ; i < N ; i++ )
#define FOR1e(i, N) for( int i = 1 ; i <= N ; i++ )
#define FORe(i, N) for(int i = 0 ; i <= N ; i++ )
#define FOR1(i, N) for(int i = 1 ; i < N ; i++ )

using namespace std;

int Number;
bool Flag;

int main(int argc, char** argv) {
   // freopen("Trojan.txt", "r", stdin);
    Flag = false;
    while(scanf("%d", &Number) == 1) {
        for(int i = 0; i <= Number / 4; i++) {
            int DigOf4 = 4 * i;
            if((Number - DigOf4) % 7 == NULL) {
                Flag = true;
                for(int j = 0; j < i; j++) {
                    printf("4");
                }
                for(int j = 0; j < ((Number - DigOf4) / 7); j++) {
                    printf("7");
                }
                break;
            }
        }
        if(!Flag)       printf("-1\n");
    }
    
    
    return 0;
}
