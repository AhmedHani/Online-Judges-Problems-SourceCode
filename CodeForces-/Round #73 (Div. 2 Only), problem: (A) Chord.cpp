//============================================================================
// File        : main.cpp
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
#define Max 50 + 5
#define INF 1000000000
#define LLU unsigned long long
//#define INT_MAX 2147483647
#define FOR(i, N) for( int i = 0 ; i < N ; i++ )
#define FOR1e(i, N) for( int i = 1 ; i <= N ; i++ )
#define FORe(i, N) for(int i = 0 ; i <= N ; i++ )
#define FOR1(i, N) for(int i = 1 ; i < N ; i++ )

using namespace std;

string All[12] = {"C","C#","D","D#","E","F","F#","G","G#","A","B","H"};
int L[3];
string Line[3];

bool Check() {
    if(L[1] - L[0] == 4 && L[2] - L[1] == 3) {        puts("major"); return true;  }
    else if(L[1] - L[0] == 3 && L[2] - L[1] == 4) {   puts("minor"); return true;  }
    return false;
}

int main(int argc, char** argv) {
    //freopen("Trojan.txt", "r", stdin);
    FOR(i, 3) {
        cin >> Line[i];
        FOR(j, 12) {
            if(Line[i] == All[j])       L[i] = j;
        }
    }
    sort(L, L + 3);
    FOR(i, 3) {
        if(Check())     return 0;
        L[0] += 12;
        sort(L, L + 3);
    }
    puts("strange");
    
    return 0;
}
