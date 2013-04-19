//============================================================================
// File        : 1119 - Project File Dependencies.cpp
// Author      : AHMED HANI IBRAHIM
// Copyright   : AHani
// Version     : UVa - Accepted - 0.008
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
#include <map>
#define Max 200 + 5
#define INF 1000000000
//#define INT_MAX 2147483647
#define FOR(i, N) for( int i = 0 ; i < N ; i++ )
#define FOR1e(i, N) for( int i = 1 ; i <= N ; i++ )
#define FORe(i, N) for(int i = 0 ; i <= N ; i++ )
#define FOR1(i, N) for(int i = 1 ; i < N ; i++ )

using namespace std;

int TestCases;
int NumberOfTasks, Rules;
int Task, Count, Dep;
int Tmp;
int Order[Max];
vector<int> AdjList[Max];
bool Visited[Max];

inline void DFS(int Source, int &Index) {
    Visited[Source] = true;
    FOR(i, AdjList[Source].size()) {
        if(!Visited[AdjList[Source][i]]) {
            DFS(AdjList[Source][i], Index);
        }
    }
    Order[Index--] = Source;
}

int main(int argc, char** argv) {
   //freopen("Trojan.txt","r",stdin);
    //scanf("%d", &TestCases);
    while(scanf("%d %d", &NumberOfTasks, &Rules) == 2) {
        //if(TestCases)   puts("");
        FOR(i, Max)     AdjList[i].clear();
        memset(Visited, false, sizeof(Visited));
        memset(Order, NULL, sizeof(Order));
        
     //   scanf("%d %d", &NumberOfTasks, &Rules);
        FOR(i, Rules) {
            scanf("%d %d", &Task, &Count);
            Task--;
            FOR(j, Count) {
                scanf("%d", &Tmp);
                Tmp--;
                AdjList[Tmp].push_back(Task);
            }
        }
        FOR(i, NumberOfTasks)   sort(AdjList[i].begin(), AdjList[i].end(), greater<int>());
        int Index = NumberOfTasks - 1;
        for(int i = NumberOfTasks - 1; i >= NULL; i--) {
            if(!Visited[i]) {
               DFS(i, Index); 
            }
        }
        FOR(i, NumberOfTasks) {
            printf("%d%c", Order[i] + 1, i == NumberOfTasks - 1 ? '\n' : ' ');
        }
        //printf("%d", Order[NumberOfTasks - 1] + 1);
       // if(TestCases)   puts("");
    }
      
    
    return 0;
}

