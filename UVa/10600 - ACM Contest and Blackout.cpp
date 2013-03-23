//============================================================================
// File        : 10600 - ACM Contest and Blackout.cpp
// Author      : AHMED HANI IBRAHIM
// Copyright   : AHani
// Version     : UVa - Accepted - 0.016
// Created on March 11, 2013, 07:15 PM
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
#define Max 30000 + 5
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
int Neighbors, Connections, First, Second, Cost;
int X[Max], Y[Max];
E Edges[Max];
vector<int> Marked;
int Index;
//UnionFind X;

int Kruskal(int Ignored, int Index) {
    UnionFind X;
    int Rsult = 0;
    X.Intialize(Neighbors);
    for(int i = 0; i < Index && X.GetSize() > 1; i++) {
        if(Ignored == i)        continue;
        if(!X.IsEqual(Edges[i].First, Edges[i].Second)) {
            Rsult += Edges[i].Cost;
            X.Union(Edges[i].First, Edges[i].Second);
        }
    }
    return X.GetSize() > 1 ? INF : Rsult;
}

int main(int argc, char** argv) {
    //freopen("Trojan.txt", "r", stdin);
    scanf("%d", &TestCases);
    int Cases = 1;
    while(TestCases--) {
        scanf("%d %d", &Neighbors, &Connections);
        Marked.clear();
        Index = 0;
        while(Connections--) {
            scanf("%d %d %d", &First, &Second, &Cost);
            First--, Second--;
            Edges[Index].First = First;
            Edges[Index].Second = Second;
            Edges[Index].Cost = Cost;
            Index++;
        }
        
        int Joints = 0;
        int Best = 0;
        int SecondBest = INF;
        UnionFind X;
        X.Intialize(Neighbors);
       
        qsort(Edges, Index, sizeof(E), &Cmp);
        for(int i = 0; i < Index && Joints < Neighbors - 1; i++) {
            if(!X.IsEqual(Edges[i].First, Edges[i].Second)) {
                Best += Edges[i].Cost;
                X.Union(Edges[i].First, Edges[i].Second);
                Joints++;
                Marked.push_back(i);
            }
        }
        
        FOR(i, Marked.size()) {
            SecondBest = min(SecondBest, Kruskal(Marked[i], Index));
        }
        
        printf("%d %d\n", Best, SecondBest);
    }

    return 0;
}

