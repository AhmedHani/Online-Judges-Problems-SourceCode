//============================================================================
// File        : 200 - Rare Order.cpp
// Author      : AHMED HANI IBRAHIM
// Copyright   : AHani
// Version     : UVa - Accepted - 0.144
// Created on March 6, 2013, 9:19 PM
//============================================================================

#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>
#include <map>
#include <algorithm>
#include <functional>
#include <vector>
#include <map>
#define Max 5000
#define INF 1000000000
//#define INT_MAX 2147483647
#define FOR(i, N) for( int i = 0 ; i < N ; i++ )
#define FOR1e(i, N) for( int i = 1 ; i <= N ; i++ )
#define FORe(i, N) for(int i = 0 ; i <= N ; i++ )
#define FOR1(i, N) for(int i = 1 ; i < N ; i++ )

using namespace std;

vector<char> V;
map<char, bool> Visited;
string Input[Max];

int main(int argc, char** argv) {
    //freopen("Trojan.txt", "r", stdin);
    int Index = 0;
    Visited.clear();
    while(cin >> Input[Index++]) if(Input[Index - 1] == "#")     break;
    FOR(i, 20) {
        FOR(j, Index - 1) {
            if(i < Input[j].size()) {
                if(!Visited[Input[j][i]]) {
                    cout << Input[j][i];
                    Visited[Input[j][i]] = true;
                }
            }
        }
    }
    puts("");
    return 0;
}

