//============================================================================
// File        : 11747 - Heavy Cycle Edges.cpp
// Author      : AHMED HANI IBRAHIM
// Copyright   : AHani
// Version     : UVa - Accepted - 0.012
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
#include <math.h>
#include <vector>
#define Max 25000 + 5
#define INF 1000000000
//#define INT_MAX 2147483647
#define FOR(i, N) for( int i = 0 ; i < N ; i++ )
#define FOR1e(i, N) for( int i = 1 ; i <= N ; i++ )
#define FORe(i, N) for(int i = 0 ; i <= N ; i++ )
#define FOR1(i, N) for(int i = 1 ; i < N ; i++ )

using namespace std;

typedef struct All {
    int First, Second;
    int Cost;
}E;

class UnionFind {
public:
    int Parent[Max];
    int Size;
public:
    void Intialize(int N) {
        //memset(Parent, 0, sizeof(Parent));
        for(int i = 0; i < N; i++)      Parent[i] = i;
        Size = N;
    }
    int FindSet(int Index) {
        return Parent[Index] == Index ? Index : (Parent[Index] = FindSet(Parent[Index]));
    }
    bool IsEqual(int X, int Y) {
        return FindSet(X) == FindSet(Y);
        return false;
    }
    void Union(int X, int Y) {
        if(!IsEqual(X, Y))
            Parent[FindSet(X)] = FindSet(Y), Size--;
    }
    int GetSize() {
        return Size;
    }
};

int Cmp(const void* X, const void* Y) {
    if (((E*)X)->Cost < ((E*)Y)->Cost) return -1;
    if (((E*)X)->Cost > ((E*)Y)->Cost) return 1;
    if (((E*)X)->Cost == ((E*)Y)->Cost) return 0;
}

int TestCases;
int Nodes, Roads;
int First, Second, Cost;
int Result;
vector<int> Heavy;
E Edges[Max];

int main(int argc, char** argv) {
   freopen("Trojan.txt", "r", stdin);
    int Cases = 1;
    while(scanf("%d %d", &Nodes, &Roads) == 2, Nodes|Roads) {
        //Result = INF;
        UnionFind X;
        //memset(Flag, false, sizeof(Flag));
        bool Flag[Max];
        FOR(i, Roads)   Flag[i] = false;
        Heavy.clear();
        FOR(i, Roads)   scanf("%d %d %d", &Edges[i].First, &Edges[i].Second, &Edges[i].Cost);
        X.Intialize(Nodes);
        qsort(Edges, Roads, sizeof(E), &Cmp);
        for(int i = 0; i < Roads && X.GetSize() > 0; i++) {
            if(!X.IsEqual(Edges[i].First, Edges[i].Second)) {
                X.Union(Edges[i].First, Edges[i].Second);
                Flag[i] = true;
            }
        }
        FOR(i, Roads)   if(!Flag[i])    Heavy.push_back(Edges[i].Cost);
        if(Heavy.empty()) {       puts("forest"); }
        else {
            FOR(i, Heavy.size()) {
                if(i)   printf(" %d", Heavy[i]);
                else    printf("%d", Heavy[i]);
            }
            puts("");
        }
    }

    return 0;
}

