//============================================================================
// File        : 10080 - Gopher II.cpp
// Author      : AHMED HANI IBRAHIM
// Copyright   : AHani
// Version     : UVa - Accepted - 0.016
// Created on December 8, 2012, 10:55 PM
//============================================================================

#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>
#include <map>
#include <vector>
#include <cmath>
#define Max 200 + 5
#define INF 1000000000
//#define INT_MAX 2147483647
#define FOR(i, N) for( int i = 0 ; i < N ; i++ )
#define FOR1e(i, N) for( int i = 1 ; i <= N ; i++ )
#define FORe(i, N) for(int i = 0 ; i <= N ; i++ )
#define FOR1(i, N) for(int i = 1 ; i < N ; i++ )

using namespace std;

int NumberOfGophers, NumberOfHoles, Seconds, Velocity;
int NewA[Max], NewB[Max], Size[Max];
vector<int> Graph[Max];
int Matched;
double GCoordinates[Max][2], HCoordinates[Max][2];
bool Visited[Max];

double Calculation(double X1, double Y1, double X2, double Y2) {
    return sqrt((X1 - X2) * (X1 - X2) + (Y1 - Y2) * (Y1 - Y2));
}

bool Solve(int Source) {
    int B;
    FOR(i, Graph[Source].size()) {
        B = Graph[Source][i];
        if(!Visited[B]) {
            Visited[B] = true;
            if(NewB[B] == false || DFS(NewB[B])) {
                NewA[Source] = B;
                NewB[B]      = Source;
                return true;
            }
        }
    }
    return false;
}

int main(int argc, char** argv) {
   // freopen("Trojan.txt", "r", stdin);
    while(scanf("%d %d %d %d", &NumberOfGophers, &NumberOfHoles, &Seconds, &Velocity) == 4) {
        memset(NewA, NULL, sizeof(NewA));
        memset(NewB, NULL, sizeof(NewB));
        FORe(i, NumberOfGophers) Graph[i].clear();
        
        FOR1e(i, NumberOfGophers) scanf("%lf %lf", &GCoordinates[i][0], &GCoordinates[i][1]);
        FOR1e(i, NumberOfHoles)           scanf("%lf %lf", &HCoordinates[i][0], &HCoordinates[i][1]);
        
        FOR1e(i, NumberOfGophers) {
            FOR1e(j, NumberOfHoles) {
                if((Calculation(GCoordinates[i][0], GCoordinates[i][1], HCoordinates[j][0], HCoordinates[j][1])) / Velocity <= Seconds)
                    Graph[j].push_back(i);  
            } 
        }
        Matched = NULL;
        FOR1e(i, NumberOfGophers) {
            if(!NewA[i]) {
                memset(Visited, false, sizeof(Visited));
                if(Solve(i))      Matched++;
            }
        }
        int Result = NumberOfGophers - Matched;
        printf("%d\n", Result);
        
        
    }

    return 0;
}

