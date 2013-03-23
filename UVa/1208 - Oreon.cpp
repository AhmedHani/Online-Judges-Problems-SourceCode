//============================================================================
// File        : 1208 - Oreon.cpp
// Author      : AHMED HANI IBRAHIM
// Copyright   : AHani
// Version     : UVa - Accepted - 0.008
// Created on March 9, 2013, 9:19 PM
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
#define Max 10000 + 5
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
    if(((E*)X)->Cost < ((E*)Y)->Cost) return -1;
    if(((E*)X)->Cost > ((E*)Y)->Cost) return 1;
    if(((E*)X)->Cost == ((E*)Y)->Cost) return 0;
}

int TestCases;
int Nodes, Roads;
int First, Second, Cost;
int Result;
E Edges[Max];

int main(int argc, char** argv) {
    //freopen("Trojan.txt", "r", stdin);
    int Cases = 1;
    scanf("%d", &TestCases);
    while(TestCases--) {
        scanf("%d\n", &Nodes);
        UnionFind X;
        int Index = 0;
        FOR(i, Nodes) {
            FOR(j, Nodes) {
                scanf("%d, ", &Cost);
                if(Cost) Edges[Index].First = i, Edges[Index].Second = j, Edges[Index].Cost = Cost, ++Index;        
            }
        }
        X.Intialize(Nodes);
        qsort(Edges, Index, sizeof(E), &Cmp);
        printf("Case %d:\n", Cases++);

        for(int i = 0; i < Index && X.GetSize(); i++) {
            if(!X.IsEqual(Edges[i].First, Edges[i].Second)) {
                int A = min(Edges[i].First, Edges[i].Second);
                int B = max(Edges[i].First, Edges[i].Second);
                printf("%c-%c %d\n", A + 'A', B + 'A', Edges[i].Cost);
                X.Union(Edges[i].First, Edges[i].Second);
                //Result = max(Result, Edges[i].Cost);
//                Joints++;
            }
        }
        
        
    }

    return 0;
}

