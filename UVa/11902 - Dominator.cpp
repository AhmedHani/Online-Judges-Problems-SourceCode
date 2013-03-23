//============================================================================
// File        : 11902 - Dominator.cpp
// Author      : AHMED HANI IBRAHIM
// Copyright   : AHani
// Version     : UVa - Accepted - 0.056
// Created on November 8, 2012, 12:29 AM
//============================================================================

#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#define Max 100 + 5
#define INF 1000000000
//#define INT_MAX 2147483647
#define FOR(i, N) for( int i = 0 ; i < N ; i++ )
#define FOR1e(i, N) for( int i = 1 ; i <= N ; i++ )
#define FORe(i, N) for(int i = 0 ; i <= N ; i++ )
#define FOR1(i, N) for(int i = 1 ; i < N ; i++ )

using namespace std;

//enum Traversal {TRUE, FALSE};
int TestCases;
int NumberOfNodes, X;
int AdjList[Max][Max];
bool FirstVisited[Max];
bool SecondVisited[Max];
int Array[Max];

void RootDFS(int Start) {
    int Tmp;
    FirstVisited[Start] = true;
    FOR(i, Array[Start]) {
        Tmp = AdjList[Start][i];
        if(FirstVisited[Tmp] == NULL)
            RootDFS(Tmp);
    }
}

void DFS(int Start, int End) {
    int Tmp;
    if(Start == End)    return;
    SecondVisited[Start] = true;
    FOR(i, Array[Start]) {
        Tmp = AdjList[Start][i];
        if(Tmp != End && SecondVisited[Tmp] == NULL)
            DFS(Tmp, End);
    }
}

void OutputFormat() {
    printf("+");
    FOR(i, NumberOfNodes * 2 - 1) {
        printf("-");
    }
    puts("+");
}

int main(int argc, char** argv) {
   //freopen("Trojan.txt", "r", stdin);
    int Cases = 1;
    scanf("%d", &TestCases);
    
    while(TestCases--) {
        scanf("%d", &NumberOfNodes);
        
        memset(Array, NULL, sizeof(Array));
     //   memset(AdjList, NULL, sizeof(AdjList));
        FOR(i, NumberOfNodes) {
            FOR(j, NumberOfNodes) {
                scanf("%d", &X);
                if(X)   AdjList[i][Array[i]++] = j;
            }
        }
        memset(FirstVisited, false, sizeof(FirstVisited));
        RootDFS(0);
        printf("Case %d:\n", Cases++);
        
        FOR(i, NumberOfNodes) {
            memset(SecondVisited, false, sizeof(SecondVisited));
            OutputFormat();
            printf("|");
            DFS(0, i);
            FOR(j, NumberOfNodes) {
                if(FirstVisited[j] == true && SecondVisited[j] == NULL)
                    printf("Y|");
                else
                    printf("N|");
            }
            puts("");
        }
        OutputFormat();
    }

    return 0;
}

