//============================================================================
// File        : 10369 - Arctic Network.cpp
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
    double Cost;
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
int Stallites, Roads, First, Second;
int X[Max], Y[Max];
E Edges[Max];

int main(int argc, char** argv) {
    //freopen("Trojan.txt", "r", stdin);
    scanf("%d", &TestCases);
    while(TestCases--) {
        scanf("%d %d", &Stallites, &Roads);
        int Index = 0;
        FOR(i, Roads)       scanf("%d %d", &X[i], &Y[i]);
        for(int i = 0; i < Roads; i++) {
            for(int j = i + 1; j < Roads; j++) {
                Edges[Index].First = i;
                Edges[Index].Second = j;
                Edges[Index].Cost = hypot(X[i] - X[j], Y[i] - Y[j]);
                Index++;
            }
        }
        //int Joints = 0;
        UnionFind X;
        X.Intialize(Roads);
        //scanf("%d", &Cables);
        
        qsort(Edges, Index, sizeof(E), &Cmp);
        double Result = 0;
        int Joints = 0;
        for(int i = 0; i < Index && Joints < Roads - Stallites; i++) {
            if(!X.IsEqual(Edges[i].First, Edges[i].Second)) {
                X.Union(Edges[i].First, Edges[i].Second);
                if(Edges[i].Cost > Result)      Result = Edges[i].Cost;
                Joints++;
            }
        }
        printf("%.2lf\n", Result);
    }

    return 0;
}

