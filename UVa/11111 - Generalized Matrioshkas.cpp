//============================================================================
// File        : 11111 - Generalized Matrioshkas.cpp
// Author      : AHMED HANI IBRAHIM
// Copyright   : AHani
// Version     : UVa - Accepted - 0.068
// Created on January 30, 2013, 21:44 PM
//============================================================================

#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>
#include <sstream>
#include <stack>
#include <vector>
#include <algorithm>
#include <cmath>
#define Max 30 + 5
#define INF 1000000000
//#define INT_MAX 2147483647
#define FOR(i, N) for( int i = 0 ; i < N ; i++ )
#define FOR1e(i, N) for( int i = 1 ; i <= N ; i++ )
#define FORe(i, N) for(int i = 0 ; i <= N ; i++ )
#define FOR1(i, N) for(int i = 1 ; i < N ; i++ )

using namespace std;

string Line;
bool Result;

int main(int argc, char** argv) {
  // freopen("Trojan.txt", "r", stdin);
    
    while(getline(cin, Line)) {
        stringstream Sin;
        stack<int> Original;
        stack<int> Copy;
        Sin.clear();
        Sin.str(Line);
        int Numbers;
        Result = true;
        
        while(!Sin.eof()) {
            Sin >> Numbers;
            if(Copy.empty()) {
                Copy.push(abs(Numbers));
                Original.push(abs(Numbers));
            } else {
                if(Numbers < NULL) {
                    Copy.top() -= abs(Numbers);
                    if(Copy.top() <= NULL) {
                        Result = false;
                        break;
                    }
                    Copy.push(abs(Numbers));
                    Original.push(abs(Numbers));
                } else {
                    if(Numbers != Original.top()) {
                        Result = false;
                        break;
                    }
                    Original.pop();
                    Copy.pop();
                }
            }
        }
        if(!Original.empty())   Result = false;
        puts(Result ? ":-) Matrioshka!" : ":-( Try again.");
    }
    
    return 0;
}

