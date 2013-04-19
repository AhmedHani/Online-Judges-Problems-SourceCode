//============================================================================
// File        : Codeforces Round #113 (Div. 2), problem: (D) Shoe Store.cpp
// Author      : AHMED HANI IBRAHIM
// Copyright   : AHani
// Version     : CF - Accepted 
// Created on April 5, 2013, 11:30 PM
//============================================================================

#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#define Max 100000 + 5
#define INF 1000000000
//#define INT_MAX 2147483647
#define FOR(i, N) for( int i = 0 ; i < N ; i++ )
#define FOR1e(i, N) for( int i = 1 ; i <= N ; i++ )
#define FORe(i, N) for(int i = 0 ; i <= N ; i++ )
#define FOR1(i, N) for(int i = 1 ; i < N ; i++ )

using namespace std;

int NumberOfPairs;
struct Node { 
    int Cost, Size, Index;
    bool operator < (const Node& First) const {
        return Cost > First.Cost;
    }
} Shoes[Max];

int Match[Max];
int Matched[Max];
vector<int> AdjList[Max];
map<int, int> Size;
int NumberOfcustomres;
int Money, CoustmerSize;
long long Result;

bool DFS(int Source) {
    for(vector<int>::iterator it = AdjList[Source].begin(); it != AdjList[Source].end(); it++) {
        if(Match[*it] == Source)      continue;
        if(Match[*it] == -1 || DFS(Match[*it])) {
            Match[*it] = Source;
            Matched[Source] = *it;
            return true;
        }
    }
    return false;
}

int main(int argc, char** argv) {
    //freopen("Trojan.txt", "r", stdin);
    while(cin >> NumberOfPairs) {
        memset(Match, -1, sizeof(Match));
        memset(Matched, -1, sizeof(Matched));
        Size.clear();
        FOR(i, Max)     AdjList[i].clear();
        
        FOR(i, NumberOfPairs) cin >> Shoes[i].Cost >> Shoes[i].Size, Shoes[i].Index = i;
        sort(Shoes, Shoes + NumberOfPairs);
        FOR(i, NumberOfPairs)   Size[Shoes[i].Size] = i;
        
        cin >> NumberOfcustomres;
        FOR(i, NumberOfcustomres) {
            cin >> Money >> CoustmerSize;
            if(Size.count(CoustmerSize) && Shoes[Size[CoustmerSize]].Cost <= Money) {
                AdjList[Size[CoustmerSize]].push_back(i);
            }
            if(Size.count(CoustmerSize + 1) && Shoes[Size[CoustmerSize + 1]].Cost <= Money) {
                AdjList[Size[CoustmerSize + 1]].push_back(i);
            }
        }
        Result = 0;
        int Counter = 0;
        FOR(i, NumberOfPairs)   if(DFS(i))      Result += Shoes[i].Cost, Counter++;
        cout << Result << "\n" << Counter << "\n";
        FOR(i, NumberOfPairs)   if(Matched[i] != -1 && Match[Matched[i]] == i)  cout << Matched[i] + 1 << " " << Shoes[i].Index + 1 << endl;
        
    }
    
    return 0;
}
