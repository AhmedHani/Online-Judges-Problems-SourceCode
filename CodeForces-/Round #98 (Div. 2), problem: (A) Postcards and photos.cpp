//============================================================================
// File        : 11350.cpp
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
#define Max 100 + 5
#define INF 1000000000
#define LLU unsigned long long
//#define INT_MAX 2147483647
#define FOR(i, N) for( int i = 0 ; i < N ; i++ )
#define FOR1e(i, N) for( int i = 1 ; i <= N ; i++ )
#define FORe(i, N) for(int i = 0 ; i <= N ; i++ )
#define FOR1(i, N) for(int i = 1 ; i < N ; i++ )

using namespace std;

char Line[Max];
char *Ptr;
int Counter;

int main(int argc, char** argv) {
   // freopen("Trojan.txt", "r", stdin);
    gets(Line);
    for(Ptr = Line; *Ptr; Ptr++) {
        Counter++;
        for(int i = 4; i && *(Ptr + 1) == *Ptr; ++Ptr, i--);
    }
    printf("%d\n", Counter);
    
    return 0;
}
