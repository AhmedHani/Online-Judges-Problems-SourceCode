//============================================================================
// File        : 11463 - Commandos.cpp
// Author      : AHMED HANI IBRAHIM
// Copyright   : AHani
// Version     : UVA - Accepted - 0.040
// Created on August 8, 2012, 10:38 PM
//============================================================================

#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include<iostream>
#include<algorithm>
#include<functional>
#define Max 100 + 1
#define INF 1000000000
#define INT_MAX 2147483647
#define FOR(i , NumberOfBuildings) for( int i = 0 ; i < NumberOfBuildings ; i++ )

using namespace std;

int TestCases , NumberOfBuildings , NumberOfRoads;
int U , V;
int Distance[Max][Max];

int main(int argc, char** argv) {
    freopen("Trojan.txt", "r", stdin);
    int Case = 1;
    scanf("%d" , &TestCases);
    
    while ( TestCases -- ){
        
        scanf("%d %d" , &NumberOfBuildings , &NumberOfRoads);
        
        FOR(i , NumberOfBuildings)
            FOR(j , NumberOfBuildings)
                Distance[i][j] = 10000;
//        memset(Distance , 10000 , sizeof(Distance));
        
        FOR(i , NumberOfRoads){
            scanf("%d %d" , &U , &V);
            Distance[U][V] = 1;
            Distance[V][U] = 1;
        }
       FOR(i , NumberOfBuildings)
           Distance[i][i] = 0;
       
       FOR(k , NumberOfBuildings)
           FOR(i , NumberOfBuildings)
               FOR(j , NumberOfBuildings)
                      Distance[i][j] = min(Distance[i][j] , Distance[i][k] + Distance[k][j]);
           
       scanf("%d %d" , &U , &V);
       int Answer = 0;
       FOR(i , NumberOfBuildings){
           if ( Distance[U][i] + Distance[i][V] > Answer )
               Answer = Distance[U][i] + Distance[i][V];
       }
    
       printf("Case %d: %d\n" , Case++ ,Answer);
    
    }
return 0;
}
