//============================================================================
// File        : 10397 - Connect the Campus.cpp
// Author      : AHMED HANI IBRAHIM
// Copyright   : AHani
// Version     : UVa - Accepted - 0.224
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
#define Max 1000 + 5
#define INF 1000000000
//#define INT_MAX 2147483647
#define FOR(i, N) for( int i = 0 ; i < N ; i++ )
#define FOR1e(i, N) for( int i = 1 ; i <= N ; i++ )
#define FORe(i, N) for(int i = 0 ; i <= N ; i++ )
#define FOR1(i, N) for(int i = 1 ; i < N ; i++ )

using namespace std;

typedef struct All {
    int First, Second;
    double Cost;
}E;

class UnionFind {
public:
    int Parent[Max];
    int Size;
public:
    void Intialize(int N) {
        memset(Parent, 0, sizeof(Parent));
        for(int i = 1; i <= N; i++)      Parent[i] = i;
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
        Parent[FindSet(X)] = FindSet(Y);
    }
    int GetSize() {
        return Size;
    }
};

int Cmp(const void* X, const void* Y) {
    if((*(E*)X).Cost < (*(E*)Y).Cost)   return -1;
    else return 1;
}

int NumberOfBuildings, First, Second, Cables;
double X[Max], Y[Max];
E Edges[Max];

int main(int argc, char** argv) {
    freopen("Trojan.txt", "r", stdin);
    while(scanf("%d", &NumberOfBuildings) == 1) {
        int Index = 0;
        FOR1e(i, NumberOfBuildings)       scanf("%lf %lf", &X[i], &Y[i]);
        for(int i = 1; i <= NumberOfBuildings; i++) {
            for(int j = i + 1; j <= NumberOfBuildings; j++) {
                Edges[Index].First = i;
                Edges[Index].Second = j;
                Edges[Index].Cost = hypot(X[i] - X[j], Y[i] - Y[j]);
                Index++;
            }
        }
        int Joints = 0;
        UnionFind X;
        X.Intialize(NumberOfBuildings);
        scanf("%d", &Cables);
        while(Cables--) {
            scanf("%d %d", &First, &Second);
            if(!X.IsEqual(First, Second)) {
                Joints++;
                X.Union(First, Second);
            }
        }
        qsort(Edges, Index, sizeof(E), &Cmp);
        double Result = 0;
        for(int i = 0; i < Index && Joints < NumberOfBuildings - 1; i++) {
            if(!X.IsEqual(Edges[i].First, Edges[i].Second)) {
                Result += Edges[i].Cost;
                X.Union(Edges[i].First, Edges[i].Second);
                Joints++;
            }
        }
        printf("%.2lf\n", Result);
    }

    return 0;
}

