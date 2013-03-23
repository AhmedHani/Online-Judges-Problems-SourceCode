//============================================================================
// File        : 11733 - Airports.cpp
// Author      : AHMED HANI IBRAHIM
// Copyright   : AHani
// Version     : UVa - Accepted - 0.100
// Created on September 19, 2012, 11:07 PM
//============================================================================

#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>
#include <map>
#include <algorithm>
#include <functional>
#define Max 1000 + 5
#define INF 1000000000
//#define INT_MAX 2147483647
#define FOR(i, N) for( int i = 0 ; i < N ; i++ )
#define FOR1e(i, N) for( int i = 1 ; i <= N ; i++ )
#define FORe(i, N) for(int i = 0 ; i <= N ; i++ )
#define FOR1(i, N) for(int i = 1 ; i < N ; i++ )

using namespace std;

int TestCases;
int NumberOfLocations, Connections, TotalCost;
int Parents[Max];

 typedef struct Edges{
    int First;
    int Second;
    double Distance;
}E;


int FindSet(int i){
    return Parents[i] == i ? i : (Parents[i] = FindSet(Parents[i]));
}

int Equal(int X , int Y){
    return FindSet(X) == FindSet(Y);
}

void Joint(int X , int Y){
        Parents[FindSet(X)] = FindSet(Y);
}
int cmp(const void*a,const void*b)

{

    return ((E*)a)->Distance-((E*)b)->Distance;

}

int main(int argc, char** argv) {
    freopen("Trojan.txt", "r", stdin);
    E List[Max];
    int Cases = 1;
    scanf("%d", &TestCases);
    
    while ( TestCases-- ){
        scanf("%d %d %d", &NumberOfLocations, &Connections, &TotalCost);
        
        FOR(i, Connections){
            scanf("%d %d %d", &List[i].First, &List[i].Second, &List[i].Distance);
        }
        qsort(List,Connections,sizeof(E),&cmp);
        FOR(i, NumberOfLocations)       Parents[i] = i;
        
        int Answer = NULL;      int Airports = NULL;    int Selected = NULL;
        
        for ( int i = 0; i < Connections && Selected < NumberOfLocations - 1 && List[i].Distance < TotalCost; i++ ){
            if ( !Equal(List[i].Second, List[i].First) ){
                Answer += List[i].Distance;
                Joint(List[i].Second, List[i].First);
                Selected++;
            }
        }
        FOR1e(i, NumberOfLocations){
            Answer += TotalCost * (Parents[i] == i);
            Airports += (Parents[i] == i);
        }
        printf("Case #%d: %d %d\n", Cases++, Answer ,Airports);
    }

    return 0;
}

