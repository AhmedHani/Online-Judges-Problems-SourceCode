//============================================================================
// File        : 222 - Budget Travel.cpp
// Author      : AHMED HANI IBRAHIM
// Copyright   : AHani
// Version     : UVa - Accepted - 0.044
// Created on April 21, 2013, 12:53 PM
//============================================================================

#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <functional>
#include <math.h>
#include <map>
#define Max 100000  + 5
#define INF 1000000000
//#define INT_MAX 2147483647
#define FOR(i, N) for( int i = 0 ; i < N ; i++ )
#define FOR1e(i, N) for( int i = 1 ; i <= N ; i++ )
#define FORe(i, N) for(int i = 0 ; i <= N ; i++ )
#define FOR1(i, N) for(int i = 1 ; i < N ; i++ )

using namespace std;

double Distance;
double GallonCapacity, MilesPerGallon, Cost, NumberOfStations;
double StartDistance, Price;
pair<double, double> Stations[Max];
double Result;

void Solve(int Station, double Price, double Gasolin) {
    if(Station == NumberOfStations - 1) {
        double Temp = (Distance - Stations[Station].first) / MilesPerGallon;
        if(Gasolin < Temp) {
            Price = Price + (GallonCapacity - Gasolin) * Stations[Station].second + 200.0;
            Gasolin = GallonCapacity;
        }
        Result = min(Result, Price);
    } else {
        double Temp = (Stations[Station + 1].first - Stations[Station].first) / MilesPerGallon;
        if(Gasolin < Temp) {
            Price = Price + (GallonCapacity - Gasolin) * Stations[Station].second + 200.0;
            Solve(Station + 1, Price, GallonCapacity - Temp);
        } else if(Gasolin > GallonCapacity / 2.0 && Gasolin >= Temp) {
            Solve(Station + 1, Price, Gasolin - Temp);
        } else {
            Solve(Station + 1, Price, Gasolin - Temp);
            Price = Price + (GallonCapacity - Gasolin) * Stations[Station].second + 200.0;
            Solve(Station + 1, Price, GallonCapacity - Temp);
        }
    }
}

int main(int argc, char** argv) {
    //freopen("Trojan.txt","r",stdin);
    int Cases = 1;
    while(scanf("%lf", &Distance) == 1, Distance >= NULL) {
        memset(Stations, NULL, sizeof(Stations));
        scanf("%lf %lf %lf %lf", &GallonCapacity, &MilesPerGallon, &Cost, &NumberOfStations);
        FOR(i, NumberOfStations) {
            scanf("%lf %lf", &StartDistance, &Price);
            Stations[i].first = StartDistance;
            Stations[i].second = Price;
        }
        Result = INF;
        printf("Data Set #%d\n", Cases++);
        Solve(0, Cost * 100.0, GallonCapacity - Stations[0].first / MilesPerGallon);
        printf("minimum cost = $%.2lf\n", Result / 100.0);
    }
    
    return 0;
}

