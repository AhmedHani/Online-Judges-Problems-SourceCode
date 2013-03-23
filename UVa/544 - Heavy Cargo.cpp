//============================================================================
// File        : 544 - Heavy Cargo.cpp
// Author      : AHMED HANI IBRAHIM
// Copyright   : AHani
// Version     : UVa - Accepted - 0.048
// Created on August 12, 2012, 6:15 AM
//============================================================================

#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include<string>
#include<iostream>
#include<map>
#include<algorithm>
#include<functional>
#define Max 200 + 5
#define INF 1000000000
//#define INT_MAX 2147483647
#define FOR(i , N) for( int i = 0 ; i < N ; i++ )
#define FOR1e(i , N) for( int i = 1 ; i <= N ; i++ )
#define FORe(i , N) for(int i = 0 ; i <= N ; i++ )
#define FOR1(i , N) for(int i = 1 ; i < N ; i++ )

using namespace std;

int NumberOfCities , NumberOfRoads , WeightLimits;
map<string , int> IndexCity;
string First , Second;
int Distanc[Max][Max];

int main(int argc, char** argv) {
//    freopen("Trojan.txt", "r", stdin);
    
    int Cases = 1;
    
    while ( scanf("%d %d" , &NumberOfCities , &NumberOfRoads) == 2 ){
        if ( NumberOfCities == 0 && NumberOfRoads == 0 )
            break;
        
        int Index = 0;
        
        memset(Distanc , -1 , sizeof(Distanc));
        
        FOR(i , Max){
            Distanc[i][i] = 0;
        }
        
        FOR(i , NumberOfRoads){
            cin >> First >> Second ;
            scanf("%d" , &WeightLimits);
            
            if ( !IndexCity[First] )
                IndexCity[First] = ++Index;
            if ( !IndexCity[Second] )
                IndexCity[Second] = ++Index;
            
            Distanc[IndexCity[First]][IndexCity[Second]] = Distanc[IndexCity[Second]][IndexCity[First]] = WeightLimits;
        }
        
        FOR1e(k , NumberOfCities){
            FOR1e(i , NumberOfCities){
                FOR1e(j , NumberOfCities){
                    Distanc[i][j] = Distanc[j][i] = max( Distanc[i][j] , min(Distanc[i][k] , Distanc[k][j]) );
                }
            }
        }
//        
//        string Start , End;
        cin >> First >> Second;
        
        printf ("Scenario #%d\n", Cases++);
        printf ("%d tons\n\n", Distanc[IndexCity [First]] [IndexCity [Second]] );
        
        
    }

    return 0;
}

