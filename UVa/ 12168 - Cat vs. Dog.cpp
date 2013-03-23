//============================================================================
// File        : Cat vs. Dog.cpp
// Author      : AHMED HANI IBRAHIM
// Copyright   : AHani
// Version     : Live Archive
// Created on March 14, 2013, 9:19 AM
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
#include <stack>
#define Max 600
#define INF 1000000000
//#define INT_MAX 2147483647
#define FOR(i, N) for( int i = 0 ; i < N ; i++ )
#define FOR1e(i, N) for( int i = 1 ; i <= N ; i++ )
#define FORe(i, N) for(int i = 0 ; i <= N ; i++ )
#define FOR1(i, N) for(int i = 1 ; i < N ; i++ )

using namespace std;

int Matrix[Max][Max];
bool Visited[Max];
int TestCases;
int Cats, Dogs, Voters;
char CFirst, CSecond;
int NFirst, NSecond;
int Blue[Max], Red[Max];
bool DFS(int V, int Size);
int Matching(int C, int D) {
    int Counter = 0;
    memset(Red, -1, sizeof(Red));
    FOR(i, C) {
        memset(Visited, false, sizeof(Visited));
        if(DFS(i, D))   Counter++;
    }
    return Counter;
}

bool DFS(int V, int Size) {
    FOR(i, Size) {
        if(Matrix[V][i] && !Visited[i]) {
            Visited[i] = true;
            if(Red[i] == -1 || DFS(Red[i], Size)) {
                Red[i] = V;
                return true;
            }
        }
    }
    return false;
}

int main(int argc, char** argv) {
    //freopen("Trojan.txt", "r", stdin);
    scanf("%d", &TestCases);
    while(TestCases--) {
        memset(Matrix, 0, sizeof(Matrix));
        vector<int> LeftCats, RightCats, LeftDogs, RightDogs;
        scanf("%d %d %d", &Cats, &Dogs, &Voters);
        FOR(i, Voters) {
            cin >> CFirst >> NFirst >> CSecond >> NSecond;
            if(CFirst == 'C')   LeftCats.push_back(NFirst), RightDogs.push_back(NSecond);
            else                RightCats.push_back(NSecond), LeftDogs.push_back(NFirst);
        }
        FOR(i, LeftCats.size()) {
            FOR(j, LeftDogs.size()) {
                if(LeftCats[i] == RightCats[j]) Matrix[i][j] = 1;
                if(LeftDogs[j] == RightDogs[i]) Matrix[i][j] = 1;
            }
        }
         printf("%d\n",Voters - Matching(LeftCats.size(), LeftDogs.size()));
    }
    
    return 0;
}

