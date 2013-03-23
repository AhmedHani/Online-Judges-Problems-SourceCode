//============================================================================
// File        : main.cpp
// Author      : AHMED HANI IBRAHIM
// Copyright   : AHani
// Version     : 
// Created on March 14, 2013, 9:19 AM
//============================================================================

#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>
#include <map>
#include <algorithm>
#include <functional>
#include <vector>
#include <map>
#include <queue>
#define Max 600
#define INF 1000000000
//#define INT_MAX 2147483647
#define FOR(i, N) for( int i = 0 ; i < N ; i++ )
#define FOR1e(i, N) for( int i = 1 ; i <= N ; i++ )
#define FORe(i, N) for(int i = 0 ; i <= N ; i++ )
#define FOR1(i, N) for(int i = 1 ; i < N ; i++ )

using namespace std;

int TestCases;
int NumberOfCorridors;
int ExistingCorridors;
int Matrix[Max][Max];
int Parent[Max];
int Visited[Max];
int Capacity[Max][Max];
int Tmp, End;
int Source;

int MaxFlow() {
    memset(Parent, -1, sizeof(Parent));
    memset(Visited, false, sizeof(Visited));
    Parent[Source] = -1;
    queue<int> Q;
    Q.push(Source);
    Visited[Source] = true;
    //bool Flag = false;
    while(!Q.empty()) {
        int Front = Q.front();
        Q.pop();
        for(int i = 1; i <= NumberOfCorridors; i++) {
            if(!Visited[i] && Capacity[Front][i] > 0) {
                Q.push(i);
                Visited[i] = true;
                Parent[i] = Front;
                if(i == End)    break;
            }
        }
    }
    int V = End;
    int Max_Flow = INF;
    while(Parent[V] != -1) {
        Max_Flow = min(Max_Flow, Capacity[Parent[V]][V]);
        V = Parent[V];
    }
    V = End;
    while(Parent[V] != -1) {
        Capacity[Parent[V]][V] -= Max_Flow;
        Capacity[V][Parent[V]] += Max_Flow;
        V = Parent[V];
    }
    return Max_Flow == INF ? 0 : Max_Flow;
  
}

int main(int argc, char** argv) {
  //  freopen("Trojan.txt", "r", stdin);
    scanf("%d", &TestCases);
    while(TestCases--) {
        memset(Capacity, 0, sizeof(Capacity));
        scanf("%d", &NumberOfCorridors);
        FOR1(i, NumberOfCorridors) {
            scanf("%d", &ExistingCorridors);
            FOR(j, ExistingCorridors) {
                scanf("%d", &Tmp);
                if(i == 1 || Tmp == NumberOfCorridors)  Capacity[i][Tmp] = 1;
                else                                    Capacity[i][Tmp] = INF;
            }
        }
        Source = 1;
        End = NumberOfCorridors;
        int Result = 0;
        while(true) {
            int A = MaxFlow();
            if(A == 0)break;
            Result += A;
        }
        printf("%d\n", Result);
    }
    
    return 0;
}

