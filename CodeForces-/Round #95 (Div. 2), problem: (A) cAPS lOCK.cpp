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
#define Max 100 + 100
#define INF 1000000000
//#define INT_MAX 2147483647
#define FOR(i, N) for( int i = 0 ; i < N ; i++ )
#define FOR1e(i, N) for( int i = 1 ; i <= N ; i++ )
#define FORe(i, N) for(int i = 0 ; i <= N ; i++ )
#define FOR1(i, N) for(int i = 1 ; i < N ; i++ )

using namespace std;

char Line[Max];
int Length;

bool AllUpper(char *C, int Length) {
    FOR(i, Length)      
            if(islower(C[i]))       return false;
    
    return true;
}

bool Solve(char *C, int Length) {
    if(AllUpper(C, Length))     return true;
    if(AllUpper(C + 1, Length - 1) && islower(C[0]))    return true;
    return false;
}

int main(int argc, char** argv) {
    //freopen("Trojan.txt", "r", stdin);
    while(gets(Line)){
    Length = strlen(Line);
    
    if(Solve(Line, Length)) {
        FOR(i, Length) 
            Line[i] = isupper(Line[i]) ? tolower(Line[i]) : toupper(Line[i]);
    }
    puts(Line);}
    
            
    return 0;
}
