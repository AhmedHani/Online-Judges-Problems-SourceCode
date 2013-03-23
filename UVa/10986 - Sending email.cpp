//============================================================================
// File        : 10986 - Sending email.cpp
// Author      : AHMED HANI IBRAHIM
// Copyright   : AHani
// Version     : UVa - Accepted - 0.400
// Created on February 28, 2013, 10:15 PM
//============================================================================

#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <queue>
#define Max 50000 + 5
#define MOD 1000000007
#define INF 1000000000
#define P pair<int, int>
//#define INT_MAX 2147483647
#define FOR(i, N) for( int i = 0 ; i < N ; i++ )
#define FOR1e(i, N) for( int i = 1 ; i <= N ; i++ )
#define FORe(i, N) for(int i = 0 ; i <= N ; i++ )
#define FOR1(i, N) for(int i = 1 ; i < N ; i++ )

using namespace std;

//class Comp {
//public:
//    bool operator() (const P &a, const P &b) {
//        return a.second > b.second;
//    }
//};

int TestCases;
int Servers, Cables;
int Source, End;
int First, Second, Cost;
int Distance[Max];
priority_queue<P, vector<P>, greater<P> > PQ;
vector<P> AdjList[Max];

int main(int argc, char** argv) {
    freopen("Trojan.txt", "r", stdin);
    int Cases = 1;
    scanf("%d", &TestCases);
    while(TestCases--) {
        scanf("%d %d %d %d", &Servers, &Cables, &Source, &End);
        FOR(i, Max)     AdjList[i].clear();
        while(Cables--) {
            scanf("%d %d %d", &First, &Second, &Cost);
            AdjList[First].push_back(make_pair(Second, Cost));
            AdjList[Second].push_back(make_pair(First, Cost));
        }
        FOR(i, Max)     Distance[i] = INF;
        Distance[Source] = 0;
        PQ.push(make_pair(Source, 0));
        // Dijkstra
        while(!PQ.empty()) {
            P Front = PQ.top();
            PQ.pop();
            int U = Front.first;  
            FOR(i, AdjList[U].size()) {
                P V = AdjList[U][i];
                if(Distance[U] + V.second < Distance[V.first]) {
                    Distance[V.first] = Distance[U] + V.second;
                    PQ.push(make_pair(V.first, Distance[V.first]));
                }
            }
        }
        printf("Case #%d: ", Cases++);
        bool Answer = Distance[End] != INF;
        if(Answer)      printf("%d\n", Distance[End]);
        else    puts("unreachable");
    }
    
    return 0;
}

