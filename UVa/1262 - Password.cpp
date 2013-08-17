//============================================================================
// File        : 1262 - Password.cpp
// Author      : AHMED HANI IBRAHIM
// Copyright   : AHani
// Version     : UVa - Accepted - 0.275
// Created on August 17, 2013, 9:19 AM
//============================================================================

#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <set>
#define Max 100 + 5
#define INF 1000000000
//#define INT_MAX 2147483647
#define FOR(i, N) for( int i = 0 ; i < N ; i++ )
#define FOR1e(i, N) for( int i = 1 ; i <= N ; i++ )
#define FORe(i, N) for(int i = 0 ; i <= N ; i++ )
#define FOR1(i, N) for(int i = 1 ; i < N ; i++ )

using namespace std;

int TestCases;
int Queries;
char Grid1[Max][Max];
char Grid2[Max][Max];
bool Here[Max][Max];
set<string> Passwords;
vector<char> All[Max];

inline void Solve(int Columns, string Passw) {
    if(Columns == 5) {
        Passwords.insert(Passw);
        return;
    }
    FOR(i, All[Columns].size()) {
        Solve(Columns + 1, Passw + All[Columns][i]);
    }
}

int main(int argc, char** argv) {
    freopen("Trojan.txt", "r", stdin);
    scanf("%d", &TestCases);
    while(TestCases-- > 0) {
        Passwords.clear();
        FOR(i, Max) All[i].clear();
        memset(Here, false, sizeof(Here));
        scanf("%d", &Queries);
        
        FOR(i, 6) scanf("%s", Grid1[i]);
        FOR(j, 5) FOR(i, 6) Here[j][Grid1[i][j]] = true;
        FOR(i, 6) scanf("%s", Grid2[i]);
        
        FOR(j, 5) FOR(i, 6) if(Here[j][Grid2[i][j]]) All[j].push_back(Grid2[i][j]);
        
        Solve(NULL, "");
        if(Queries > Passwords.size()) {
            puts("NO");
            continue;
        }
        vector<string> Result;
        for(set<string>::iterator it = Passwords.begin(); it != Passwords.end(); it++) {
            Result.push_back(*it);
        }
        puts(Result[Queries - 1].c_str());
        
    }
    
    return 0;
}

