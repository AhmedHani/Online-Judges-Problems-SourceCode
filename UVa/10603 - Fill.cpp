//============================================================================
// File        : 10603 - Fill.cpp
// Author      : AHMED HANI IBRAHIM
// Copyright   : AHani
// Version     : UVa - Accepted - 0.008
// Created on October 31, 2012, 10:39 PM
//============================================================================

#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>
#include <queue>
#include <algorithm>
#include <functional>
#define Max 200 + 5
#define MaxJ 3
#define INF 1000000000
//#define INT_MAX 2147483647
#define FOR(i, N) for( int i = 0 ; i < N ; i++ )
#define FOR1e(i, N) for( int i = 1 ; i <= N ; i++ )
#define FORe(i, N) for(int i = 0 ; i <= N ; i++ )
#define FOR1(i, N) for(int i = 1 ; i < N ; i++ )

using namespace std;

int TestCases;
int Liters;
int Jugs[MaxJ];
bool Visited[Max][Max];
int MinimumFill, ClosestLiters;
struct Node{ int All[MaxJ]; int Filled; };

void BFS() {
    Node Front = {NULL, NULL, Jugs[2], NULL};
    queue<Node> Q;
    Q.push(Front);
    Visited[0][0] = true;
    ClosestLiters = NULL;
    MinimumFill = NULL;
    
    while(!Q.empty()) {
        Node Current = Q.front();
        Q.pop();
        int Fill;
        
        for(int i = 2; i >= 0; i--) {
            if(Current.All[i] == Liters) {
                if(ClosestLiters == Liters && Current.Filled < MinimumFill)
                    MinimumFill = Current.Filled;
                else if(ClosestLiters != Liters) {
                    ClosestLiters = Liters;
                    MinimumFill = Current.Filled;
                }
            }
            else if((Current.All[i] > ClosestLiters && Current.All[i] < Liters) || (Current.All[i] == Liters && Current.Filled < MinimumFill)) {
                ClosestLiters = Current.All[i];
                MinimumFill = Current.Filled;
            }
            for(int j = 2; j >= 0; j--)
                if(i != j) {
                    if(Current.All[i] < Jugs[j] - Current.All[j])
                        Fill = Current.All[i];
                    else
                        Fill = Jugs[j] - Current.All[j];
                    Node Tmp = Current;
                    Tmp.All[i] = Tmp.All[i] - Fill;
                    Tmp.All[j] = Tmp.All[j] + Fill;
                    Tmp.Filled = Tmp.Filled + Fill;
                    
                    if(!Visited[Tmp.All[0]][Tmp.All[1]]) {
                        Q.push(Tmp);
                        Visited[Tmp.All[0]][Tmp.All[1]] = true;
                    }
                }
        }
    }
}
int main(int argc, char** argv) {
    //freopen("Trojan.txt", "r", stdin);
    scanf("%d", &TestCases);
    while(TestCases--) {
        FOR(i, MaxJ)    scanf("%d", &Jugs[i]);
        scanf("%d", &Liters);
        memset(Visited, false, sizeof(Visited));
        BFS();
        printf("%d %d\n", MinimumFill, ClosestLiters);
        
        
    }

    return 0;
}

