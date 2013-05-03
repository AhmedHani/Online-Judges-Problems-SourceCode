//============================================================================
// File        : 
// Author      : AHMED HANI IBRAHIM
// Copyright   : AHani
// Version     : 
// Created on April 27, 2012, 7:31 PM
//============================================================================

#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <set>
#include <bitset>
#include <iomanip>
#include <map>
#define Max 50001 + 5
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

map<string, int> Map;

int Transform(char *C) {
    if(Map.find(C) != Map.end())        return Map[C];
    else                                return Map[C] = Map.size();
}

int TestCases;
int Cities, Connections;
E Edges[Max];
char First[Max], Second[Max];
int Cost, Index, Result;
 
int main(int argc, char** argv) {
   // freopen("Trojan.txt", "r", stdin);
    scanf("%d", &TestCases);
    while(TestCases-- > 0) {
        scanf("%d\n%d", &Cities, &Connections);
        UnionFind X;
        Index = Result = NULL;
        Map.clear();
        FOR(i, Connections) {
            scanf("%s %s %d", First, Second, &Cost);
            Edges[Index].First = Transform(First);
            Edges[Index].Second = Transform(Second);
            Edges[Index].Cost = Cost;
            Index++;
        }
        X.Intialize(Connections);
        qsort(Edges, Index, sizeof(E), &Cmp);
        for(int i = 0; i < Index && X.GetSize() > 0; i++) {
            if(!X.IsEqual(Edges[i].First, Edges[i].Second)) {
                X.Union(Edges[i].First, Edges[i].Second);
                Result += Edges[i].Cost;
            }
        }
        printf("%d\n", Result);
        if(TestCases)   puts("");
    }
    

    return 0;
}

