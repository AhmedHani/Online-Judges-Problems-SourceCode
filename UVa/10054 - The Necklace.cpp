//============================================================================
// File        : 10054 - The Necklace.cpp
// Author      : AHMED HANI IBRAHIM
// Copyright   : AHani
// Version     : UVa - Accepted - 0.276
// Created on October 6, 2012, 10:32 PM
//============================================================================

#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>
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

int TestCases, First, Second, NumberOfBeads, MaxColors;
int Container[Max];
int Matrix[Max][Max];
bool OK;

void SolveDFS(int C){
    FOR1e(i, MaxColors){
        if(Matrix[C][i] > NULL){
            Matrix[C][i]--;
            Matrix[i][C]--;
            SolveDFS(i);
            printf("%d %d\n", i, C);
        }
    }
}

int main(int argc, char** argv) {
//    freopen("Trojan.txt", "r", stdin);
    int Cases = 1;
    bool Line = false;
    scanf("%d", &TestCases);
    
    while(TestCases--){
        if(Line)        puts("");
        Line = true;
        
        scanf("%d", &NumberOfBeads);
        memset(Container, NULL, sizeof(Container));
        memset(Matrix, NULL, sizeof(Matrix));
        
        OK = false;
        MaxColors = NULL;
        FOR(i, NumberOfBeads){
            scanf("%d %d", &First, &Second);
            Container[First]++;
            Container[Second]++;
            Matrix[First][Second]++;
            Matrix[Second][First]++;
            
            if(First > MaxColors)       MaxColors = First;
            if(Second > MaxColors)      MaxColors = Second;
        }
        
        printf("Case #%d\n", Cases++);
        
        FOR1e(i, MaxColors){
            if(Container[i] % 2) {
                OK = true;
                break;
            }
        }
       
        if(OK)          puts("some beads may be lost");
        else            SolveDFS(MaxColors);
        
    }

    return 0;
}

