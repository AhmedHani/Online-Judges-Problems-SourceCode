//============================================================================
// File        : 558 - Wormholes.cpp
// Author      : AHMED HANI IBRAHIM
// Copyright   : AHani
// Version     : UVa - Accepted - 0.036
// Created on August 11, 2012, 5:30 AM
//============================================================================

#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include<iostream>
#include<algorithm>
#include<functional>
#define Max 2000 + 10
#define INF 1000000000
//#define INT_MAX 2147483647
#define FOR(i , NumberOfWormHoles) for( int i = 0 ; i < NumberOfWormHoles ; i++ )
#define FORi(i , NumberOfStarSystem) for( int i = 0 ; i <= NumberOfStarSystem ; i++ )

using namespace std;

struct Universe{
    int First;
    int Second;
    int Years;
} WormHoles[Max];

int TestCase , NumberOfStarSystem , NumberOfWormHoles;
int Distance[Max];

int main(int argc, char** argv) {
    freopen("Trojan.txt", "r", stdin);
    
    scanf("%d" , &TestCase);
    while ( TestCase -- ){
        scanf("%d %d" , &NumberOfStarSystem , &NumberOfWormHoles);
        
        FOR(i , NumberOfWormHoles){
            scanf("%d %d %d" , &WormHoles[i].First , &WormHoles[i].Second , &WormHoles[i].Years);
        }
        
        FORi(i , NumberOfStarSystem){
            Distance[i] = INF;
        }
        Distance[0] = 0;
        
        FOR(i , NumberOfStarSystem-1 ){
            FOR(j , NumberOfWormHoles){
                Distance[WormHoles[j].Second] = min ( Distance[WormHoles[j].Second] , Distance[WormHoles[j].First] + WormHoles[j].Years );    
            }
            
        }
                
        bool Check = false;
        
        FOR(j , NumberOfWormHoles){
            if (Distance[WormHoles[j].First] + WormHoles[j].Years < Distance[WormHoles[j].Second])
                Check = true;
            
        }
        
        if (Check)
            printf("possible\n");
        else
            printf("not possible\n");
        
        
    }
    

    return 0;
}

