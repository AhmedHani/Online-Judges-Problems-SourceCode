//============================================================================
// File        : 985 - Round and Round Maze.cpp
// Author      : AHMED HANI IBRAHIM
// Copyright   : AHani
// Version     : UVa - Accepted - 0.144
// Created on August 17, 2013, 2:19 PM
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
#define Max 500 + 5
#define MaxDirection 4
#define INF 1000000000
//#define INT_MAX 2147483647
#define FOR(i, N) for( int i = 0 ; i < N ; i++ )
#define FOR1e(i, N) for( int i = 1 ; i <= N ; i++ )
#define FORe(i, N) for(int i = 0 ; i <= N ; i++ )
#define FOR1(i, N) for(int i = 1 ; i < N ; i++ )

using namespace std;

class Node {
public:
    int First;
    int Second;
    int Third;
    Node(int First, int Second, int Third) {
        this->First = First;
        this->Second = Second;
        this->Third = Third;
    }
};

int Rows, Columns;
vector<int> Maze[Max][Max];
bool Visited[MaxDirection][Max][Max];
int Distance[MaxDirection][Max][Max];
int Directions[4][2] = {
    {-1, 0}, 
    {0, 1},
    {1, 0},
    {0, -1}
};
enum Sympol {NORTH, EAST, SOUTH, WEST};
char Input[Max];

int main(int argc, char** argv) {
    //freopen("Trojan.txt", "r", stdin);
    while(scanf("%d %d", &Rows, &Columns) == 2) {
        memset(Visited, false, sizeof(Visited));
        int Result = -1;
        FOR(i, Rows) FOR(j, Columns) FOR(k, 4) Distance[k][i][j] = INF, Maze[i][j].clear();
        
        gets(Input);
        FOR(i, Rows) {
            FOR(j, Columns) {
                if(i == Rows - 1 && j == Columns - 1) break;
                gets(Input);
                for(int ii = 0; Input[ii]; ii++) {
                    if(Input[ii] == 'N') Maze[i][j].push_back(NORTH);
                    else if(Input[ii] == 'E') Maze[i][j].push_back(EAST);
                    else if(Input[ii] == 'S') Maze[i][j].push_back(SOUTH);
                    else if(Input[ii] == 'W') Maze[i][j].push_back(WEST);
                }
            }
        }
        Distance[0][0][0] = 0;
        queue<Node> Q;
        Q.push(Node(0, 0, 0));
        while(!Q.empty()) {
            Node Current = Q.front();
            Q.pop();
            int Tmp = Distance[Current.First][Current.Second][Current.Third];
            Visited[Current.First][Current.Second][Current.Third] = false;
            if(Current.Second == Rows - 1 && Current.Third == Columns - 1) {
                Result = Tmp;
                break;
            }
            int Oreintation = Tmp % 4;
            FOR(i, Maze[Current.Second][Current.Third].size()) {
                int Nodec = Maze[Current.Second][Current.Third][i];
                int NewDirection = (Nodec + Oreintation) % 4;
                int NewFirst = (Current.First + 1) % 4;
                int NewSecond = Current.Second + Directions[NewDirection][0];
                int NewThird = Current.Third + Directions[NewDirection][1];
                if(NewSecond >= NULL && NewSecond < Rows && NewThird >= NULL && NewThird < Columns) {
                    if(Tmp + 1 < Distance[NewFirst][NewSecond][NewThird]) {
                        Distance[NewFirst][NewSecond][NewThird] = Tmp + 1;
                        if(!Visited[NewFirst][NewSecond][NewThird]) {
                            Visited[NewFirst][NewSecond][NewThird] = true;
                            Q.push(Node(NewFirst, NewSecond, NewThird));
                        }
                    }
                }
            }
        }
        printf(Result == -1 ? "no path to exit\n" : "%d\n", Result);
    }
    
    return 0;
}

