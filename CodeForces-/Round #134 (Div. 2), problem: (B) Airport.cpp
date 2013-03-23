//============================================================================
// File        : BinarySearchTree.cpp
// Author      : AHMED HANI IBRAHIM
// Copyright   : AHani
// Version     : 
// Created on December 18, 2012, 10:47 PM
//============================================================================

#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#define Max 500 + 5
#define INF 1000000000
//#define INT_MAX 2147483647
#define FOR(i, N) for( int i = 0 ; i < N ; i++ )
#define FOR1e(i, N) for( int i = 1 ; i <= N ; i++ )
#define FORe(i, N) for(int i = 0 ; i <= N ; i++ )
#define FOR1(i, N) for(int i = 1 ; i < N ; i++ )

using namespace std;

int NumberOfPassengers, Planes;
int EmptySeats;
int Maximum, Minimum;
//int Maxi[Max], Mini[Max];
vector<int> Maxi, Mini;

int main(int argc, char** argv) {
    //freopen("Trojan.txt", "r", stdin);
    while(scanf("%d %d", &NumberOfPassengers, &Planes) == 2) {
        Maxi.clear();
        Mini.clear();
        Maximum = Minimum = NULL;
        FOR(i, Planes) {
            scanf("%d", &EmptySeats);
            Maxi.push_back(EmptySeats);
            Mini.push_back(EmptySeats);
        }
        FOR(i, NumberOfPassengers) {
            sort(Maxi.begin(), Maxi.end());
            Minimum += Maxi[0];
            Maxi[0]--;
            if(!Maxi[0])        Maxi.erase(Maxi.begin());
            sort(Mini.begin(), Mini.end(), greater<int>());
            Maximum += Mini[0];
            Mini[0]--;
            if(!Mini[0])        Mini.erase(Mini.begin());
        }
        printf("%d %d", Maximum, Minimum);
    }

    return 0;
}
