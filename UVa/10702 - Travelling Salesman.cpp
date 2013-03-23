//============================================================================
// File        : 10702 - Travelling Salesman.cpp
// Author      : AHMED HANI IBRAHIM
// Copyright   : AHani
// Version     : UVa - Accepted - 0.140
// Created on February 20, 2013, 09:12 AM
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
#define Max 1000 + 5
#define MOD 1000000007
#define INF 1000000000
#define P pair<int, int>
//#define INT_MAX 2147483647
#define FOR(i, N) for( int i = 0 ; i < N ; i++ )
#define FOR1e(i, N) for( int i = 1 ; i <= N ; i++ )
#define FORe(i, N) for(int i = 0 ; i <= N ; i++ )
#define FOR1(i, N) for(int i = 1 ; i < N ; i++ )

using namespace std;

int NumberOfCities, StartingCity, Endings, Intermidiates;
int Cost, CityEnd;
bool CityEndings[100 + 5];
int DPMemo[100 + 5][1000 + 5];
int Graph[100 + 5][100 + 5];
//int Tmp, Sum;

int Solve(int Source, int Inter) {
    int Tmp = -INF;
    int Sum = -INF;
    if(DPMemo[Source][Inter] != -1)     return DPMemo[Source][Inter];
    if(Inter == 1) {
        FOR(i, NumberOfCities) {
            if(CityEndings[i]) {
                if(Tmp < Graph[Source][i]) {
                    Tmp = Graph[Source][i];
                }
            }
        }
        DPMemo[Source][Inter] = Tmp;
        return Tmp;
    }
    FOR(i, NumberOfCities) {
        Tmp = Solve(i, Inter - 1);
        if(Sum < Tmp + Graph[Source][i])
            Sum = Tmp + Graph[Source][i];
    }
    DPMemo[Source][Inter] = Sum;
    return Sum;
}

int main(int argc, char** argv) {
    //freopen("Trojan.txt", "r", stdin);
    scanf("%d %d %d %d", &NumberOfCities, &StartingCity, &Endings, &Intermidiates);
    while(NumberOfCities || StartingCity || Endings || Intermidiates) {
        //if(!NumberOfCities && !StartingCity && !Endings && !Intermidiates)      break;
        memset(DPMemo, -1, sizeof(DPMemo));
        memset(CityEndings, false, sizeof(CityEndings));
        FOR(i, NumberOfCities)  FOR(j, NumberOfCities)  scanf("%d", &Graph[i][j]);
        FOR(i, Endings)    scanf("%d", &CityEnd), CityEndings[CityEnd - 1] = true;
        cout << Solve(StartingCity - 1, Intermidiates) << endl;
        scanf("%d %d %d %d", &NumberOfCities, &StartingCity, &Endings, &Intermidiates);
    }
    
    return 0;
}

