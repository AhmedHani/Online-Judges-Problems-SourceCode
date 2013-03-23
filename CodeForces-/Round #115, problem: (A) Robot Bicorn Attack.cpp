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

string Line;
string SFirst, SSecond, SThird;
int First, Second, Third;
int Result;

bool Check(const string &s) {
    if(s.length() == 1) return true;
    if(s[0] == '0' || s.length() > 9)   return false;
    return atoi(s.c_str()) <= 1000000;
}

int main(int argc, char** argv) {
   // freopen("Trojan.txt", "r", stdin);
    Result = -1;
    cin >> Line;
    for(int i = 1; i < Line.length(); i++) {
        for(int j = i + 1; j < Line.length(); j++) {
            SFirst  = Line.substr(NULL, i);
            SSecond = Line.substr(i, j - i);
            SThird  = Line.substr(j);
            
            if(Check(SFirst) && Check(SSecond) && Check(SThird))
                Result = max(Result, atoi(SFirst.c_str()) + atoi(SSecond.c_str()) + atoi(SThird.c_str()));
        }
    }
    printf("%d\n", Result);
            
    return 0;
}
