//============================================================================
// File        : 11228 - Transportation system..cpp
// Author      : AHMED HANI IBRAHIM
// Copyright   : AHani
// Version     : UVa - Accepted - 0.380
// Created on March 12, 2013, 06:12 AM
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
#define Max 5000
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

bool Comp(const E &a, const E &b)
{
    return a.Cost < b.Cost;
}

int TestCases;
int Cities, State, First, Second;
int X[Max], Y[Max];
vector<E> V;

int main(int argc, char** argv) {
   // freopen("Trojan.txt", "r", stdin);
    int Cases = 1;
    scanf("%d", &TestCases);
    while(TestCases--) {
        V.clear();
        scanf("%d %d", &Cities, &State);
        int Index = 0;
        FOR(i, Cities)       scanf("%d %d", &X[i], &Y[i]);
        for(int i = 0; i < Cities; i++) {
            for(int j = i + 1; j < Cities; j++) {
                V.push_back(E());
                V[Index].First = i;
                V[Index].Second = j;
                V[Index].Cost = hypot(X[i] - X[j], Y[i] - Y[j]);
                Index++;
            }
        }
     
        UnionFind X;
        X.Intialize(Cities);
        int StatesCounter = 1;
        double Roads = 0;
        double RailRoads = 0;
        sort(V.begin(), V.end(), Comp);
   
        for(int i = 0; i < V.size() && X.GetSize() > 0; i++) {
            if(!X.IsEqual(V[i].First, V[i].Second)) {
                X.Union(V[i].First, V[i].Second);
                if(V[i].Cost > State)       RailRoads += V[i].Cost, StatesCounter++;
                else                            Roads += V[i].Cost;  
            }
        }
        printf("Case #%d: %d %.lf %.lf\n", Cases++, StatesCounter, Roads ,RailRoads);
    }

    return 0;
}

