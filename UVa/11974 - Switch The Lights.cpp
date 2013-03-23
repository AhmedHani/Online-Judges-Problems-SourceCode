//============================================================================
// File        : 11974 - Switch The Lights.cpp
// Author      : AHMED HANI IBRAHIM
// Copyright   : AHani
// Version     : UVa - Accepted - 4.096
// Created on March 4, 2013, 3:55 PM
//============================================================================

#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>
#include <queue>
#include <bitset>
#include <vector>
#include <map>
#define Max 100
#define INF 1000000000
int dx[] = {-1, 1, 0, 0, 0, 0};
int dy[] = {0, 0, -1, 1, 0, 0};
int dz[] = {0, 0, 0, 0, -1, 1};
//#define INT_MAX 2147483647
#define P pair<bitset<15>, int>
#define FOR(i, N) for( int i = 0 ; i < N ; i++ )
#define FOR1e(i, N) for( int i = 1 ; i <= N ; i++ )
#define FORe(i, N) for(int i = 0 ; i <= N ; i++ )
#define FOR1(i, N) for(int i = 1 ; i < N ; i++ )

using namespace std;

int TestCases;
int Lamp, Switch, Bit;

int BFS(vector<int> Switches[Max]) {
    map<unsigned long, bool> Visited;
    bitset<15> Lamps;
    queue<P> Q;
    P Node;
    FOR(i, Lamp)        Lamps.flip(i);
    Node.first = Lamps;
    Node.second = 0;
    Q.push(Node);
    Visited[Lamps.to_ulong()] = true;
    while(!Q.empty()) {
        Node = Q.front();
        Q.pop();
        if(Node.first.to_ulong() == 0) return Node.second;
        FOR(i, Switch) {
            bitset<15> Curr = Node.first;
            FOR(j, Switches[i].size()) {
                Curr.flip(Switches[i][j]);
            }
            if(!Visited[Curr.to_ulong()]) {
                Visited[Curr.to_ulong()] = true;
                Q.push(make_pair(Curr, Node.second + 1));
            }
        }
    }
    return -1;
}

int main(int argc, char** argv) {
   // freopen("Trojan.txt", "r", stdin);
    int Cases = 1;
    scanf("%d", &TestCases);
    while(TestCases--) {
        vector<int> Switches[Max];
        scanf("%d %d", &Lamp, &Switch);
        FOR(i, Switch) {
            FOR(j, Lamp) {
                scanf("%d", &Bit);
                if(Bit) Switches[i].push_back(j);
            }
        }
        int Res = BFS(Switches);
        printf("Case %d: ", Cases++);
        if(Res == -1)   puts("IMPOSSIBLE");
        else            printf("%d\n", Res);
    }

    return 0;
}

