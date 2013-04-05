//============================================================================
// File        : 11045 - My T-shirt suits me.cpp
// Author      : AHMED HANI IBRAHIM
// Copyright   : AHani
// Version     : UVa - Accepted - 0.016
// Created on April 5, 2013, 11:30 PM
//============================================================================

#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
#define Max 200 + 5
#define INF 1000000000
//#define INT_MAX 2147483647
#define FOR(i, N) for( int i = 0 ; i < N ; i++ )
#define FOR1e(i, N) for( int i = 1 ; i <= N ; i++ )
#define FORe(i, N) for(int i = 0 ; i <= N ; i++ )
#define FOR1(i, N) for(int i = 1 ; i < N ; i++ )

using namespace std;

int TestCases;
int T_Shirts, Voulnters;
bool OK;
int Available[Max];
struct Vol {
    char First[Max];
    char Second[Max];
} Volunter[Max];

int Shirt(char *C) {
    if(strcmp(C, "S") == 0)       return 0;
    if(strcmp(C, "M") == 0)       return 1;
    if(strcmp(C, "L") == 0)       return 2;
    if(strcmp(C, "XL") == 0)      return 3;
    if(strcmp(C, "XXL") == 0)     return 4;
    if(strcmp(C, "XS") == 0)      return 5;
}

inline void Solve(int Index) {
    if(Index == Voulnters) { 
        OK = true;
        return;
    }
    if(OK == true) return;
    int T_shirt_for_first = Shirt(Volunter[Index].First);
    int T_shirt_for_second = Shirt(Volunter[Index].Second);
    if(Available[T_shirt_for_first]) {
        Available[T_shirt_for_first]--;
        Solve(Index + 1);
        Available[T_shirt_for_first]++;
    }
    if(Available[T_shirt_for_second]) {
        Available[T_shirt_for_second]--;
        Solve(Index + 1);
        Available[T_shirt_for_second]++;
    }
}

int main(int argc, char** argv) {
    freopen("Trojan.txt", "r", stdin);
    scanf("%d", &TestCases);
    while(TestCases--) {
        memset(Available, NULL, sizeof(Available));
        scanf("%d %d", &T_Shirts, &Voulnters);
        FOR(i, Voulnters)     scanf("%s %s", Volunter[i].First, Volunter[i].Second);
        FOR(i, 30)      Available[i] = T_Shirts / 6;
        OK = false;
        Solve(0);
        puts(OK  ? "YES" : "NO");
    }
    
    return 0;
}
