//============================================================================
// File        : 1209 - Wordfish.cpp
// Author      : AHMED HANI IBRAHIM
// Copyright   : AHani
// Version     : UVa - Accepted - 0.008
// Created on April 16, 2013, 15:43 PM
//============================================================================

#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <functional>
#include <math.h>
#include <list>
#define Max 100
#define INF 1000000000
//#define INT_MAX 2147483647
#define FOR(i, N) for( int i = 0 ; i < N ; i++ )
#define FOR1e(i, N) for( int i = 1 ; i <= N ; i++ )
#define FORe(i, N) for(int i = 0 ; i <= N ; i++ )
#define FOR1(i, N) for(int i = 1 ; i < N ; i++ )

using namespace std;

char First[Max];
char Second[Max];
char All[Max][Max];
int Minimum, Maximum, Index, MinAbs;

int main(int argc, char** argv) {
    //freopen("Trojan.txt","r",stdin);
    while(gets(First)) {
        strcpy(Second, First);
        strcpy(All[11], First);
        int i = 10;
        while(i >= 0) {
            prev_permutation(First, First + strlen(First));
            strcpy(All[i], First);
            i--;
        }
        i = 12;
        while(i <= 21) {
            next_permutation(Second, Second + strlen(First));
            strcpy(All[i], Second);
            i++;
        }
        Index = 1;
        //Minimum = INF;
        MinAbs = Maximum = 0;
        FOR1e(i, 21) {
            Minimum = INF;
            FOR(j, strlen(First) - 1) {
                Minimum = min(Minimum, abs(All[i][j] - All[i][j + 1]));
            }
            if(Minimum > Maximum && Minimum != INF) Maximum = Minimum, Index = i, MinAbs = Minimum;
            
        }
        printf("%s%d\n", All[Index], MinAbs);
    }
    
    return 0;
}

