//============================================================================
// File        : 10842 - Traffic Flow.cpp
// Author      : AHMED HANI IBRAHIM
// Copyright   : AHani
// Version     : UVa - Accepted - 0.188
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
#define Max 200000 + 5
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
    return -((E*)X)->Cost+((E*)Y)->Cost;
}

int TestCases;
int Intersections, Roads;
int First, Second, Cost;
int Result;
E Edges[Max];

int main(int argc, char** argv) {
    //freopen("Trojan.txt", "r", stdin);
    int Cases = 1;
    scanf("%d", &TestCases);
    while(TestCases--) {
        Result = INF;
        UnionFind X;
        scanf("%d %d", &Intersections, &Roads);
        FOR(i, Roads)   scanf("%d %d %d", &Edges[i].First, &Edges[i].Second, &Edges[i].Cost);
        X.Intialize(Intersections);
        qsort(Edges, Roads, sizeof(E), &Cmp);
        for(int i = 0; i < Roads && X.GetSize() > 0; i++) {
            if(!X.IsEqual(Edges[i].First, Edges[i].Second)) {
                X.Union(Edges[i].First, Edges[i].Second);
                if(Edges[i].Cost < Result)      Result = Edges[i].Cost;
            }
        }
        printf("Case #%d: %d\n", Cases++, Result);
    }

    return 0;
}

