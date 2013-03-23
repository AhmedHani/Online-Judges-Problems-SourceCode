//============================================================================
// File        : 567 - Risk.cpp
// Author      : AHMED HANI IBRAHIM
// Copyright   : AHani
// Version     : UVa - Accepted - 0.112
// Created on August 17, 2012, 10:08 AM
//============================================================================

#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include<string>
#include<iostream>
#include<map>
#include<algorithm>
#include<functional>
#define Max 20 + 5
#define MaxCountries 19
#define INF 1000000000
//#define INT_MAX 2147483647
#define FOR(i , N) for( int i = 0 ; i < N ; i++ )
#define FOR1e(i , N) for( int i = 1 ; i <= N ; i++ )
#define FORe(i , N) for(int i = 0 ; i <= N ; i++ )
#define FOR1(i , N) for(int i = 1 ; i < N ; i++ )

using namespace std;

int NumberOfCountries;
int First , Second;
int Distance[Max][Max];

int main(int argc, char** argv) {
//    freopen("Trojan.txt", "r", stdin);
    int Cases = 1;
    
    while ( scanf("%d" , &NumberOfCountries) != EOF ){
        
        FOR(i , Max){
            FOR(j , Max)
                Distance[i][j] = INF;
            Distance[i][i] = 1;
        }
        
        FOR(i , MaxCountries){
            if ( i )
                scanf("%d" , &NumberOfCountries);
            First = i + 1;
            
            FOR(j , NumberOfCountries){
                scanf("%d" , &Second);
                Distance[First][Second] = Distance[Second][First] = 1;
            }
        }
        
        FOR(k , Max){
            FOR(i , Max){
                FOR(j , Max){
                    Distance[i][j] = min(Distance[i][j] , Distance[i][k] + Distance[k][j] );
                }
            }
        }
        
        scanf("%d" , &NumberOfCountries);
        printf("Test Set #%d\n" , Cases++);
        
        FOR(i , NumberOfCountries){
            scanf("%d %d" , &First , &Second);
            printf("%2d to %2d: %d\n" , First , Second ,Distance[First][Second]);
        }
        
        printf("\n");
        
        
        
    }

    return 0;
}

