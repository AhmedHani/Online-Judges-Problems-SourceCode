//============================================================================
// File        : 247 - Calling Circles.cpp
// Author      : AHMED HANI IBRAHIM
// Copyright   : AHani
// Version     : 
// Created on May 21, 2013, 5:16 PM
//============================================================================

#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>
#include <map>
#include <algorithm>
#include <functional>
#include <list>
#include <sstream>
#include <set>
#include <vector>
#include <stack>
#define Max 200 + 5
#define INF 1000000000
//#define INT_MAX 2147483647
#define FOR(i, N) for( int i = 0 ; i < N ; i++ )
#define FOR1e(i, N) for( int i = 1 ; i <= N ; i++ )
#define FORe(i, N) for(int i = 0 ; i <= N ; i++ )
#define FOR1(i, N) for(int i = 1 ; i < N ; i++ )

using namespace std;

vector<int> NumberOfDFS;
vector<int> LowLink;
vector<bool> Visited;
vector<vector<pair<int, int> > > AdjList;
vector<int> Stack;
map<int, string> ToText;
map<string, int> ToValue;
char First[Max], Second[Max];
string From, To;
int DFSCount, SCC;

void Tarjan(int Source) {
    NumberOfDFS[Source] = LowLink[Source] = DFSCount++;
    Visited[Source] = true;
    Stack.push_back(Source);
    FOR(i, AdjList[Source].size()) {
        pair<int, int> V = AdjList[Source][i];
        if(NumberOfDFS[V.first] == -1) Tarjan(V.first);
        if(Visited[V.first] == true)   LowLink[Source] = min(LowLink[Source], LowLink[V.first]);
    }
    if(NumberOfDFS[Source] == LowLink[Source]) {
        SCC++;
        int V;
        while(true) {
            V = Stack.back();
            Stack.pop_back();
            Visited[V] = false;
            if(Source == V)break;
            printf("%s, ", ToText[V].c_str());
        }
        printf("%s\n", ToText[V].c_str());
    }
}

int NumberOfPeople, Connections;
int Index;

int main(int argc, char** argv) {
   // freopen("Trojan.txt", "r", stdin);
    int Cases = 0;
    while(scanf("%d %d", &NumberOfPeople, &Connections) == 2, NumberOfPeople|Connections) {
        Cases++;
        Index = 0;
        if(Cases > 1)   puts("");
        AdjList.assign(NumberOfPeople, vector<pair<int, int> >());
        ToText.clear();
        ToValue.clear();
        while(Connections--) {
            scanf("%s %s", First, Second);
            From = string(First);
            To = string(Second);
            if(ToValue.find(From) == ToValue.end()) {
                ToValue[From] = Index;
                ToText[Index++] = From;
            }
            if(ToValue.find(To) == ToValue.end()) {
                ToValue[To] = Index;
                ToText[Index++] = To;
            }
            AdjList[ToValue[From]].push_back(make_pair(ToValue[To], 1));
        }
        NumberOfDFS.assign(NumberOfPeople, -1);
        LowLink.assign(NumberOfPeople, 0);
        Visited.assign(NumberOfPeople, false);
        Stack.clear();
        printf("Calling circles for data set %d:\n", Cases);
        FOR(i, NumberOfPeople) if(NumberOfDFS[i] == -1) Tarjan(i);
    }
    
    return 0;
}

