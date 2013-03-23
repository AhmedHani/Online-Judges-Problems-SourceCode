//============================================================================
// File        : 10276 - Hanoi Tower Troubles Again!.cpp
// Author      : AHMED HANI IBRAHIM
// Copyright   : AHani
// Version     : UVa - Accepted - 0.012
// Created on November 7, 2012, 12:07 AM
//============================================================================

#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <string>
#include <cmath>
#include <stack>
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

int TestCases, Number, SQRTSUM;
bool Taken;

int main(int argc, char** argv) {
   // freopen("Trojan.txt", "r", stdin);
    int i;
    scanf("%d", &TestCases);
    while(TestCases--) {
        scanf("%d", &Number);
        stack<int> Container[Max];
        for(i = 1;; i++) { 
            Taken = false;
            FOR(j, Number) 
                if(!Container[j].empty()) {
                    SQRTSUM = sqrt(Container[j].top() + i);
                    if((Container[j].top() + i) == (SQRTSUM * SQRTSUM)) {
                        Container[j].push(i);
                        Taken = true;
                        break;
                    }
                } else {
                    Container[j].push(i);
                    Taken = true;
                    break;
                }
                if(!Taken)      break;
            
        }
        
        printf("%d\n", i - 1);
    }

    return 0;
}


