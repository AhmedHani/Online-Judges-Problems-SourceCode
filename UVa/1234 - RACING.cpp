//============================================================================
// File        : 1234 - RACING.cpp
// Author      : AHMED HANI IBRAHIM
// Copyright   : AHani
// Version     : UVa - Accepted - 0.124
// Created on April 20, 2013, 01:22 AM
//============================================================================

#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <functional>
#include <math.h>
#define Max 100000  + 5
#define P pair<int, double>
#define INF 1000000000
//#define INT_MAX 2147483647
#define FOR(i, N) for( int i = 0 ; i < N ; i++ )
#define FOR1e(i, N) for( int i = 1 ; i <= N ; i++ )
#define FORe(i, N) for(int i = 0 ; i <= N ; i++ )
#define FOR1(i, N) for(int i = 1 ; i < N ; i++ )

using namespace std;

typedef struct All {
    int First, Second, Cost;
    bool operator < (const All &e) const {
        return Cost > e.Cost;
    }
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
    if(((E*)X)->Cost < ((E*)Y)->Cost) return -1;
    if(((E*)X)->Cost > ((E*)Y)->Cost) return 1;
    if(((E*)X)->Cost == ((E*)Y)->Cost) return 0;
}

int TestCases;
int NumberOfJunctions, NumberOfRoads;
int First, Second, Cost;
E Edges[Max];
int Index;

int main(int argc, char** argv) {
   //freopen("Trojan.txt","r",stdin);
    scanf("%d", &TestCases);
    while(TestCases--) {
        UnionFind X;
        Index = 0;
        scanf("%d %d", &NumberOfJunctions, &NumberOfRoads);
        FOR(i, NumberOfRoads) {
            scanf("%d %d %d", &First, &Second, &Cost);
            Edges[Index].First = First - 1;
            Edges[Index].Second = Second - 1;
            Edges[Index].Cost = Cost;
            Index++;
        }
        X.Intialize(NumberOfJunctions);
        sort(Edges, Edges + Index);
        int Result = 0;
        FOR(i, NumberOfRoads)   Result += Edges[i].Cost;
        
        for(int i = 0; i < Index && X.GetSize() > 0; i++) {
            if(!X.IsEqual(Edges[i].First, Edges[i].Second)) {
                X.Union(Edges[i].First, Edges[i].Second);
                Result -= Edges[i].Cost;
            }
        }
        printf("%d\n", Result);
    }       
    
    return 0;
}

