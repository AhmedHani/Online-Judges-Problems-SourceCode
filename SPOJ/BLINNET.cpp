//============================================================================
// File        : BLINNET.cpp
// Author      : AHMED HANI IBRAHIM
// Copyright   : AHani
// Version     : SPOJ - Accepted
// Created on April 15, 2013, 13:43 PM
//============================================================================

#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <functional>
#include <map>
#define Max 200 + 5
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
int NumberOfCities, Connections;
char Name[Max];
int Second, Cost;
E Edges[Max];

int main(int argc, char** argv) {
   freopen("Trojan.txt","r",stdin);
    scanf("%d", &TestCases);
    while(TestCases-- > 0) {
        UnionFind X;
    //    Edges.clear();
        int Index = 0;
        scanf("%d", &NumberOfCities);
        FOR(i, NumberOfCities) {
            scanf("%s%d", Name, &Connections);
            while(Connections--) {
                scanf("%d %d", &Second, &Cost);
                if(Second > i) {
                    Edges[Index].First = i;
                    Edges[Index].Second = Second;
                    Edges[Index].Cost = Cost;
                    Index++;
                }
            }
        }
        X.Intialize(NumberOfCities);
        qsort(Edges, NumberOfCities, sizeof(E), &Cmp);
        int Result = NULL;
        for(int i = 0; i < Index && X.GetSize() > 0; i++) {
            if(!X.IsEqual(Edges[i].First, Edges[i].Second)) {
                X.Union(Edges[i].First, Edges[i].Second);
                Result += Edges[i].Cost;
            }
        }
        printf("%d\n", Result);
    }
      
    
    return 0;
}

