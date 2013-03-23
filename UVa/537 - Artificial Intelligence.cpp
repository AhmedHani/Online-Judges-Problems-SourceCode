//============================================================================
// File        : 537 - Artificial Intelligence?.cpp
// Author      : AHMED HANI IBRAHIM
// Copyright   : AHani
// Version     : UVa - Accepted - 0.016
// Created on December 15, 2012, 10:57 PM
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

int TestCases, Index;
double P, U, I;
char First, Second, Unit;
char *Pointer;
char Input[Max];
char Equations[Max][Max];

int main(int argc, char** argv) {
    //freopen("Trojan.txt", "r", stdin);
    int Cases = 1;
    scanf("%d", &TestCases);
    getchar();
    while(TestCases--) {
        gets(Input);
        Index = NULL;
        Pointer = strtok(Input, " AVW");
        while(Pointer != NULL) {
            if(strchr(Pointer, '='))    strcpy(Equations[Index++], Pointer);
            Pointer = strtok(NULL, " ");
        }
        printf ("Problem #%d\n", Cases++);
        P = U = I = -INF;
        FOR(i, 2) {
            if(Equations[i][0] == 'P') {
                sscanf(Equations[i], "%c %c %lf %c", &First, &Second, &P, &Unit);
                if(Unit == 'm')     P /= 1000;
                if(Unit == 'k')     P *= 1000;
                if(Unit == 'M')     P *= 1000000;
            }
            if(Equations[i][0] == 'U') {
                sscanf(Equations[i], "%c %c %lf %c", &First, &Second, &U, &Unit);
                if(Unit == 'm')     U /= 1000;
                if(Unit == 'k')     U *= 1000;
                if(Unit == 'M')     U *= 1000000;
            }
            if(Equations[i][0] == 'I') {
                sscanf(Equations[i], "%c %c %lf %c", &First, &Second, &I, &Unit);
                if(Unit == 'm')     I /= 1000;
                if(Unit == 'k')     I *= 1000;
                if(Unit == 'M')     I *= 1000000;
            }
        }
        if(U == NULL) {
            P = NULL;
            U = 1;
        }
        if(I == NULL) {
            P = NULL;
            I = 1;
        }
        if(I == -INF)           printf ("I=%.2lfA\n", P / U);
        if(U == -INF)           printf ("U=%.2lfV\n", P / I);
        if(P == -INF)           printf ("P=%.2lfW\n", I * U);
        
        puts("");
        
    }

    return 0;
}

