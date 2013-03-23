//============================================================================
// File        : 10816 - Travel in Desert.cpp
// Author      : AHMED HANI IBRAHIM
// Copyright   : AHani
// Version     : UVa - Accepted - 0.132
// Created on August 12, 2012, 10:56 PM
//============================================================================

#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include<iostream>
#include<algorithm>
#define MaxMatrix 500
#define Max 10000 + 5
#define INF 1000000000
//#define INT_MAX 2147483647
#define FOR(i , N) for( int i = 0 ; i < N ; i++ )
#define FOR1e(i , N) for( int i = 1 ; i <= N ; i++ )
#define FORe(i , N) for(int i = 0 ; i <= N ; i++ )
#define FOR1(i , N) for(int i = 1 ; i < N ; i++ )

using namespace std;

int NumberOfOasis , NumberOfPaths;
int First , Second;
int X[Max] , Y[Max];
double Distance[Max] , Temperature[Max] , Floyed[MaxMatrix][MaxMatrix] ;
int Answer[MaxMatrix][MaxMatrix];


void Print(int a , int b , int c ){
    
    if ( !Answer[a][b] ){
        if ( c == -1 )
            printf("%d " , a);
        printf("%d" , b);
        
        if ( b != Second )
            printf(" ");
        
    }
    else{
        Print(a , Answer[a][b] , c );
        Print(Answer[a][b] , b , INF );
    }
    
}


int main(int argc, char** argv) {
    freopen("Trojan.txt", "r", stdin);
    
    while ( scanf("%d %d" , &NumberOfOasis , &NumberOfPaths) == 2 ){
        
        scanf("%d %d" , &First , &Second);
        
        FOR1e(i , NumberOfOasis){
            FOR1e(j , NumberOfOasis){
                Floyed[i][j] = INF;
            }
        }
        
        FOR(i , NumberOfPaths){
            scanf("%d %d %lf %lf" , &X[i] , &Y[i] , &Temperature[i] , &Distance[i] );
            
            Floyed[ X[i] ][ Y[i] ] = min( Floyed[ X[i] ][ Y[i] ] , Temperature[i] );
            Floyed[ Y[i] ][ X[i] ] = min( Floyed[ Y[i] ][ X[i] ] , Temperature[i] );
        }
        
        FOR1e(k , NumberOfOasis){
            FOR1e(i , NumberOfOasis){
                FOR1e(j , NumberOfOasis){
                    Floyed[i][j] = min ( Floyed[i][j] , max(Floyed[i][k] , Floyed[k][j]) );
                }
            }
        }
        
       double MinimumTemperature = Floyed[First][Second];
        
        FOR1e(i , NumberOfOasis)
              FOR1e(j , NumberOfOasis){
            Floyed[i][j] = INF;
            Answer[i][j] = 0;
        }
        
        FOR(i , NumberOfPaths){
            if ( Temperature[i] <= MinimumTemperature ){
                Floyed[ X[i] ][ Y[i] ] = min( Floyed[ X[i] ][ Y[i] ] , Distance[i] );
                Floyed[ Y[i] ][ X[i] ] = min( Floyed[ Y[i] ][ X[i] ] , Distance[i] );
            }   
        }
        
        FOR1e(k , NumberOfOasis)
            FOR1e(i , NumberOfOasis)
                FOR1e(j , NumberOfOasis)
                   if (Floyed[i][k] + Floyed[k][j] < Floyed[i][j]  ) {
                       Floyed[i][j] = Floyed[i][k] + Floyed[k][j];
                       Answer[i][j] = k;
                        
                }
        
        Print(First , Second , -1);
        printf("\n");
        printf("%.1lf %.1lf\n", Floyed[First][Second], MinimumTemperature);

    }

    return 0;
}

