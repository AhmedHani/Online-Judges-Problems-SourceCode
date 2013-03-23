//============================================================================
// File        : 10099 - The Tourist Guide.cpp
// Author      : AHMED HANI IBRAHIM
// Copyright   : AHani
// Version     : UVA - Accepted - 0.024
// Created on August 10, 2012, 2:38 AM
//============================================================================

#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include<iostream>
#include<algorithm>
#include<functional>
#include<cmath>
#define Max 200 + 5
#define INF 1000000000
#define INT_MAX 2147483647
#define FOR(i , NumberOfCities) for( int i = 1 ; i <= NumberOfCities ; i++ )

using namespace std;

int Distance[Max][Max];
int NumberOfCities , NumberOfRoad;
int FirstCity , SecondCity , NumberOfPassengers;

int main(int argc, char** argv) {
    freopen("Trojan.txt", "r", stdin);
    int Cases = 0;
    while ( scanf("%d %d" , &NumberOfCities , &NumberOfRoad ) ){
        if (NumberOfCities == 0 && NumberOfRoad == 0)
            break;
        
        FOR(i , NumberOfCities)
            FOR(j , NumberOfCities)    
                  Distance[i][j] = 0;
        
          
             
        FOR(i , NumberOfRoad){
            scanf("%d %d %d" , &FirstCity , &SecondCity , &NumberOfPassengers);
            Distance[SecondCity][FirstCity] = Distance[FirstCity][SecondCity] = NumberOfPassengers ;
            
        }
        
        scanf("%d %d %d" , &FirstCity , &SecondCity , &NumberOfPassengers);
        
        FOR(k , NumberOfCities)
            FOR(i , NumberOfCities)
                FOR(j , NumberOfCities)
                    Distance[i][j] = max(Distance[i][j] , min(Distance[i][k] ,Distance[k][j] ) );
        
        if ( FirstCity == SecondCity ){
             printf ("Scenario #%d\n", ++Cases);

            printf ("Minimum Number of Trips = 1\n\n");

            continue;

        }
    
        int OverAll = NumberOfPassengers / (Distance[FirstCity][SecondCity] - 1 );
        if ( NumberOfPassengers > OverAll * (Distance[FirstCity][SecondCity] - 1))
            OverAll++;
        printf ("Scenario #%d\n", ++Cases);
        printf("Minimum Number of Trips = %d\n\n" , OverAll);
       
    }
    
return 0;
}
