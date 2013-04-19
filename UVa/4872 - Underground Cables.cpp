//============================================================================
// File        : 4872 - Underground Cables.cpp
// Author      : AHMED HANI IBRAHIM
// Copyright   : AHani
// Version     : Live Archive - Accepted
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
#include <math.h>
#define Max 499500 + 5
#define P pair<int, double>
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
    All(){}
    
    bool operator < (All X)const{
        return Cost < X.Cost;
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

int N;
int X[Max];
int Y[Max];
int Index;
E Edges[Max];

int main(int argc, char** argv) {
  // freopen("Trojan.txt","r",stdin);
   while(true) {
       scanf("%d", &N);
       if(N == 0)break;
       UnionFind XX;
       FOR(i, N)        scanf("%d %d", &X[i], &Y[i]);
       Index = 0;
       
       for(int i = 0; i < N; i++) {
           for(int j = i + 1; j < N; j++) {
               Edges[Index].First = i;
               Edges[Index].Second = j;
               Edges[Index].Cost = (X[i] - X[j]) * (X[i] - X[j]) + (Y[i] - Y[j]) * (Y[i] - Y[j]);
               Index++;
           }
       }
       XX.Intialize(N);
      // qsort(Edges, Index, sizeof(E), &Cmp);
       sort(Edges, Edges + Index);
       double Result = 0;;
       //int Joints = 0;
       for(int i = 0, Joints = 0; i < Index && Joints < N - 1; i++) {
           if(!XX.IsEqual(Edges[i].First, Edges[i].Second)) {
               XX.Union(Edges[i].First, Edges[i].Second);
               Result += sqrt(Edges[i].Cost);
               Joints++;
           }
       }
       printf("%.2f\n",Result);
   }
   
    
      
    
    return 0;
}

