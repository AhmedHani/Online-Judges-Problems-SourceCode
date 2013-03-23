//============================================================================
// File        : 11710 - Expensive subway.cpp
// Author      : AHMED HANI IBRAHIM
// Copyright   : AHani
// Version     : UVa - Accepted - 1.584
// Created on September 19, 2012, 9:50 PM
//============================================================================

#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>
#include <map>
#include <algorithm>
#include <functional>
#define Max 450
#define INF 1000000000
//#define INT_MAX 2147483647
#define FOR(i, N) for( int i = 0 ; i < N ; i++ )
#define FOR1e(i, N) for( int i = 1 ; i <= N ; i++ )
#define FORe(i, N) for(int i = 0 ; i <= N ; i++ )
#define FOR1(i, N) for(int i = 1 ; i < N ; i++ )

using namespace std;

int NodesStations, Connections, Cost;
int Parents[Max];
string All, Start, End, From;
map<string, int> Container;

struct Edges{
    int First;
    int Second;
    double Distance;
}E[79800 + 10];

int FindSet(int i){
    return Parents[i] == i ? i : (Parents[i] = FindSet(Parents[i]));
}

int Equal(int X , int Y){
    return FindSet(X) == FindSet(Y);
}

void Joint(int X , int Y){
        Parents[FindSet(X)] = FindSet(Y);
}



bool Compare(Edges X, Edges Y){
    if(X.Distance < Y.Distance)   return true;
    else        return false;
}

int main(int argc, char** argv) {
//    freopen("Trojan.txt", "r", stdin);
    
    while ( scanf("%d %d", &NodesStations, &Connections), NodesStations|Connections){
        Container.clear();
        FOR(i, Max)     Parents[i] = i;
        int Index = 0;
        
        FOR(i, NodesStations){
            cin >> All;
            Container[All] = Index;
            Index++;
        }
        int Indx = NULL;
        
        FOR(i, Connections){
            cin >> Start >> End >> Cost;
            E[Indx].First    = Container[Start];
            E[Indx].Second   = Container[End];
            E[Indx].Distance = Cost;
            Indx++;
        }
        cin >> From;
        
        sort(E, E + Indx, Compare);
        
        int Selected   = NodesStations - 1;
        int Result     = NULL;
        
        for ( int i = 0; i < Indx && Selected; i++ ){
            if ( !Equal(E[i].First, E[i].Second) ){
                Joint(E[i].First, E[i].Second);
                Selected--;
                Result += E[i].Distance;
               
            }
        }
        if ( Selected ) printf("Impossible\n");
        else    printf("%d\n", Result);
        
    }

    return 0;
}

