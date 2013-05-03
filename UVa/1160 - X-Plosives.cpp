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
#define Max 100050 + 5
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
        for(int i = 1; i < N + 1; i++)      Parent[i] = i;
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

int First, Second, Counter;

int main(int argc, char** argv) {
    freopen("Trojan.txt", "r", stdin);
    while(scanf("%d", &First) == 1) {
        Counter = 0;
        UnionFind X;
        X.Intialize(Max - 1);
        while(First != -1) {
            scanf("%d", &Second);
            if(X.IsEqual(First, Second)) Counter++;
            else                          X.Union(First, Second);
            scanf("%d", &First);
        }
        printf("%d\n", Counter);
    }
    
    return 0;
}

