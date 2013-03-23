//============================================================================
// File        : 1056 - Degrees of Separation.cpp
// Author      : AHMED HANI IBRAHIM
// Copyright   : AHani
// Version     : UVa - Accepted - 0.020
// Created on August 20, 2012, 8:15 AM
//============================================================================

#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include<string>
#include<iostream>
#include<map>
#include<algorithm>
#include<functional>
#define Max 50 + 5
#define INF 1000000000
//#define INT_MAX 2147483647
#define FOR(i , N) for( int i = 0 ; i < N ; i++ )
#define FOR1e(i , N) for( int i = 1 ; i <= N ; i++ )
#define FORe(i , N) for(int i = 0 ; i <= N ; i++ )
#define FOR1(i , N) for(int i = 1 ; i < N ; i++ )

using namespace std;

int NumberOfPeople , NumberOfNetwork;
string First , Second;
int Distance[Max][Max];

int main(int argc, char** argv) {
    freopen("Trojan.txt", "r", stdin);
    int Cases = 1;
    
    while ( scanf("%d %d" , &NumberOfPeople , &NumberOfNetwork) , NumberOfPeople|NumberOfNetwork){
        
        map<string , int> Members;
        int Index = 0;
        
        FOR(i , NumberOfPeople){
            FOR(j , NumberOfPeople)
            Distance[i][j] = INF;
            Distance[i][i] = NULL;
        }
        
           while ( NumberOfNetwork -- ){
            cin >> First >> Second;
            
            if ( !Members[First] )
                Members[First] = Index++;
            if ( !Members[Second] )
                Members[Second] = Index++;
            
            Distance[Members[First]][Members[Second]] = Distance[Members[Second]][Members[First]] = 1;
            
        }
        
        FOR(k , NumberOfPeople){
            FOR(i , NumberOfPeople){
                FOR(j , NumberOfPeople){
                    Distance[i][j] = min( Distance[i][j] , Distance[i][k] + Distance[k][j] ); 
                }
            }
        }
        
        int Output = NULL;
        
        FOR(i , NumberOfPeople){
            FOR(j , NumberOfPeople){
                if ( Distance[i][j] == INF ){
                    Output = -INF;
                    i = NumberOfPeople;
                    break;
                }
                
                Output = max ( Output , Distance[i][j] );
            }
        }
        
        printf("Network %d: " , Cases++);
        
        if ( Output == -INF )
            printf("DISCONNECTED\n");
        else
            printf("%d\n" , Output);
        
        printf("\n");
        
    }

    return 0;
}

