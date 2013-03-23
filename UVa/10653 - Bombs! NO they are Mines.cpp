//============================================================================
// File        : 10653 - Bombs! NO they are Mines!!.cpp
// Author      : AHMED HANI IBRAHIM
// Copyright   : AHani
// Version     : UVa - Accepted - 0.532
// Created on February 8, 2013, 04:44 PM
//============================================================================

#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#define Max 1000 + 5
#define INF 1000000000
//#define INT_MAX 2147483647
#define FOR(i, N) for( int i = 0 ; i < N ; i++ )
#define FOR1e(i, N) for( int i = 1 ; i <= N ; i++ )
#define FORe(i, N) for(int i = 0 ; i <= N ; i++ )
#define FOR1(i, N) for(int i = 1 ; i < N ; i++ )
#define BLUE 1
#define RED 2
using namespace std;

int Rows, Columns, R, RowNumber, ColNumber, NumberOfBooms;
bool Grid[Max][Max];
bool Visited[Max][Max];
struct All { int First, Second, Step;   All(int First, int Second, int Step): First(First), Second(Second), Step(Step){} };
All Start(0, 0, 0);
All End(0, 0, 0);

int BFS() {
    queue<All> Q;
    Q.push(Start);
    while(!Q.empty()) {
        All Front = Q.front();
        Q.pop();
        if((Front.First < NULL) || (Front.First >= Rows) || (Front.Second < NULL) || (Front.Second >= Columns)) continue;
        if((Visited[Front.First][Front.Second]) || Grid[Front.First][Front.Second])     continue;
        Visited[Front.First][Front.Second] = true;
        if((Front.First == End.First) && (Front.Second == End.Second))  return Front.Step;
        Q.push(All(Front.First, Front.Second - 1, Front.Step + 1));
        Q.push(All(Front.First, Front.Second + 1, Front.Step + 1));
        Q.push(All(Front.First + 1, Front.Second, Front.Step + 1));
        Q.push(All(Front.First - 1, Front.Second, Front.Step + 1));
    }
    return 0;
}

int main(int argc, char** argv) {
    //freopen("Trojan.txt", "r", stdin);
    while(scanf("%d %d", &Rows, &Columns) == 2, Rows|Columns) {
        memset(Grid, false, sizeof(Grid));
        memset(Visited, false, sizeof(Visited));
        scanf("%d", &R);
        FOR(i, R) {
            scanf("%d %d", &RowNumber, &NumberOfBooms);
            FOR(j, NumberOfBooms) {
                scanf("%d", &ColNumber);
                Grid[RowNumber][ColNumber] = true;
            }
        }
        Start = End = All(0, 0, 0);
        scanf("%d %d", &Start.First, &Start.Second);
        scanf("%d %d", &End.First, &End.Second);
        printf("%d\n", BFS());
    }
         
   
    return 0;
}



