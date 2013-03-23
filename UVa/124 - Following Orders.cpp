//============================================================================
// File        : 124 - Following Orders.cpp
// Author      : AHMED HANI IBRAHIM
// Copyright   : AHani
// Version     : UVa - Accepted - 0.008
// Created on September 14, 2012, 11:12 PM
//============================================================================

#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>
#include <map>
#include <algorithm>
#include <sstream>
#define Max 27
#define INF 1000000000
//#define INT_MAX 2147483647
#define FOR(i, N) for( int i = 0 ; i < N ; i++ )
#define FOR1e(i, N) for( int i = 1 ; i <= N ; i++ )
#define FORe(i, N) for(int i = 0 ; i <= N ; i++ )
#define FOR1(i, N) for(int i = 1 ; i < N ; i++ )

using namespace std;

int OutcomingEdge[Max], Vertics;
bool Visited[Max][Max];
bool NotVisted[Max];
bool Line;
char Result[Max], First, Second;
string Input, Constraints;


void DFS(int Start, int End){
    if ( Start == End ) printf("%s\n", Result);
    else{
        FOR(i, 26){
            if ( NotVisted[i] && !OutcomingEdge[i] ){
                NotVisted[i] = false;
            FOR(j, 26){
                if ( Visited[i][j] && NotVisted[j] )
                    OutcomingEdge[j]--;
            }
            Result[Start] = i + 'a';
            DFS(Start + 1, End);
            NotVisted[i] = true;
            FOR(j, 26){
                if ( Visited[i][j] && NotVisted[j] )
                    OutcomingEdge[j]++;
            }
        }
    }
}
}

int main(int argc, char** argv) {
    freopen("Trojan.txt", "r", stdin);
    Line = false;
    
    while ( getline(cin, Input)  ){
        if (Line)      printf("\n");
        Line = true;
        memset(OutcomingEdge, NULL, sizeof(OutcomingEdge));
        memset(NotVisted, false, sizeof(NotVisted));
        memset(Visited, false, sizeof(Visited));
        Vertics = NULL;
        
        FOR(i, Input.length()){
            if ( Input[i] >= 'a' && Input[i] <= 'z' && !NotVisted[Input[i] - 'a'] ){
                NotVisted[Input[i] - 'a'] = true;
            Vertics++;
            }
        }
        getline(cin, Constraints);
        stringstream sin(Constraints);
        
        while ( sin >> First >> Second ){
            Visited[First - 'a'][Second - 'a'] = true;
            ++OutcomingEdge[Second - 'a'];
        }
//        int Start = NULL;
        
        DFS(NULL, Vertics);

        
    }
    

    return 0;
}

