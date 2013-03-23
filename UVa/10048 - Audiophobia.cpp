//============================================================================
// File        : 10048 - Audiophobia.cpp
// Author      : AHMED HANI IBRAHIM
// Copyright   : AHani
// Version     : UVa - Accepted - 0.020
// Created on August 11, 2012, 11:09 PM
//============================================================================

#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include<iostream>
#include<algorithm>
#include<functional>
#define Max 100 + 10
#define INF 1000000000
//#define INT_MAX 2147483647
#define FOR(i , N) for( int i = 1 ; i <= N ; i++ )
#define FORi(i , N) for( int i = 0 ; i < N ; i++ )
#define FORe(i , N) for( int i = 0 ; i <= N ; i++ )

using namespace std;

int NumberOfCrossings , NumberOfStreets , NumberOfQuaries;
int First , Second , Dicebles;
int Distance[Max][Max];

int main(int argc, char** argv) {
//    freopen("Trojan.txt", "r", stdin);
    
    int Cases = 1;
    bool line = false;
    
    while ( scanf("%d %d %d" , &NumberOfCrossings , &NumberOfStreets , &NumberOfQuaries ) ){
        if (NumberOfCrossings == 0 && NumberOfStreets == 0 && NumberOfQuaries == 0)
            break;
        FORe(i , NumberOfCrossings){
            FORe(j , NumberOfCrossings){
                Distance[i][j] = INF;
            }
        }
       
        
        FORi(i , NumberOfStreets){
            scanf("%d %d %d" , &First , &Second , &Dicebles);
            Distance[First][Second] = Distance[Second][First] = Dicebles;
        }
        
        FOR(k , NumberOfCrossings){
            FOR(i , NumberOfCrossings){
                FOR(j , NumberOfCrossings)
                    Distance[i][j] = Distance[j][i] = min( Distance[i][j] , max(Distance[i][k] , Distance[k][j]) );
                
            }
        }
        if ( line )
            printf("\n");
        line = true;
        printf ("Case #%d\n", Cases++);
        
        FORi(i , NumberOfQuaries){
            scanf("%d %d" , &First , &Second);
            
            if ( Distance[First][Second] < INF )
                printf("%d\n" , Distance[First][Second] );
            else
                printf("no path\n");
                 
           
        }
        
    }
    
    return 0;
}

