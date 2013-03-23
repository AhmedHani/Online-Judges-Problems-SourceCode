//============================================================================
// File        : 10660 - Citizen attention offices.cpp
// Author      : AHMED HANI IBRAHIM
// Copyright   : AHani
// Version     : UVa - Accepted - 0.100
// Created on February 22, 2013, 12:12 PM
//============================================================================

#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#define Max 10 + 5
#define MaxArea 25
#define INF 1000000000
//#define INT_MAX 2147483647
#define FOR(i, N) for( int i = 0 ; i < N ; i++ )
#define FOR1e(i, N) for( int i = 1 ; i <= N ; i++ )
#define FORe(i, N) for(int i = 0 ; i <= N ; i++ )
#define FOR1(i, N) for(int i = 1 ; i < N ; i++ )

using namespace std;
typedef pair<int, int> P; 

int TestCases, Size;
int X, Y;
int Map[Max][Max];
int Population, Minimum;
int I, II, III, IV, V;
vector<pair<int, pair<int, int> > > Distance;
pair<int, int> Office[] = { 
    P(0, 0), P(0, 1), P(0, 2), P(0, 3), P(0, 4), P(1, 0), P(1, 1), P(1, 2), P(1, 3), P(1, 4), 
    P(2, 0), P(2, 1), P(2, 2), P(2, 3), P(2, 4), P(3, 0), P(3, 1), P(3, 2), P(3, 3), P(3, 4), 
    P(4, 0), P(4, 1), P(4, 2), P(4, 3), P(4, 4)
};

int Calculate(int First, int Second, int Third, int Fourth, int Fivth) {
    int Result = NULL;
    int I, II, III, IV, V;
    for(vector<pair<int, pair<int, int> > >:: iterator it = Distance.begin(); it != Distance.end(); it++) {
        I   = it->first * (abs(it->second.first - Office[First].first) + abs(it->second.second - Office[First].second));
        II  = it->first * (abs(it->second.first - Office[Second].first) + abs(it->second.second - Office[Second].second));
        III = it->first * (abs(it->second.first - Office[Third].first) + abs(it->second.second - Office[Third].second));
        IV  = it->first * (abs(it->second.first - Office[Fourth].first) + abs(it->second.second - Office[Fourth].second));
        V   = it->first * (abs(it->second.first - Office[Fivth].first) + abs(it->second.second - Office[Fivth].second));
        Result += min(min(I, II), min(min(IV, V), III));
    }
    return Result;
}

void Solve() {
    int Temp;
    Minimum = INF;
    for(int First = 0; First < MaxArea; First++) {
        for(int Second = First + 1; Second < MaxArea; Second++) {
            for(int Third = Second + 1; Third < MaxArea; Third++) {
                for(int Fourth = Third + 1; Fourth < MaxArea; Fourth++) {
                    for(int Fivth = Fourth + 1; Fivth < MaxArea; Fivth++) {
                        Temp = Calculate(First, Second, Third, Fourth, Fivth);
                        if(Temp < Minimum) {
                            I = First;
                            II = Second;
                            III = Third;
                            IV = Fourth;
                            V = Fivth;
                            Minimum = Temp;
                        }
                    }
                }
            }
        }
    }
}

int main(int argc, char** argv) {
    //freopen("Trojan.txt", "r", stdin);
    scanf("%d", &TestCases);
    while(TestCases--) {
        memset(Map, NULL, sizeof(Map));
        Distance.clear();
        scanf("%d", &Size);
        FOR(i, Size) {
            scanf("%d %d %d", &X, &Y, &Population);
            Map[X][Y] = Population;
            Distance.push_back(make_pair(Population, P(X, Y)));
        }
        Solve();
        printf("%d %d %d %d %d\n", I, II, III, IV, V);
        
    }
             
    return 0;
}

