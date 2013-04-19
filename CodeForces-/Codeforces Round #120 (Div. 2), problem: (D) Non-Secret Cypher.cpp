//============================================================================
// File        : Codeforces Round #120 (Div. 2), problem: (D) Non-Secret Cypher.cpp
// Author      : AHMED HANI IBRAHIM
// Copyright   : AHani
// Version     : CF - Accepted
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
#define Max 4000000 + 5
#define INF 1000000000
//#define INT_MAX 2147483647
#define FOR(i, N) for( long long i = 0 ; i < N ; i++ )
#define FOR1e(i, N) for( long long i = 1 ; i <= N ; i++ )
#define FORe(i, N) for(long long i = 0 ; i <= N ; i++ )
#define FOR1(i, N) for(long long i = 1 ; i < N ; i++ )

using namespace std;

map<long long, long long> Map;
long long Answer;
int Arr[Max];
int NumberOfElements, Target;

int main(int argc, char** argv) {
    //freopen("Trojan.txt","r",stdin);
    while(cin >> NumberOfElements >> Target) {
        Map.clear();
        Answer = 0LL;
        FOR(i, NumberOfElements)        scanf("%d", &Arr[i]);
        int j = 0;
        
        FOR(i, NumberOfElements) {
            Map[Arr[i]]++;
            if(Map[Arr[i]] == Target) {
                do {
                    Answer += NumberOfElements - i;
                    Map[Arr[j]]--;
                    j++;
                } while(Arr[i] != Arr[j - 1]);
            }
        }
        cout << Answer << endl;
    }   
    
    return 0;
}
