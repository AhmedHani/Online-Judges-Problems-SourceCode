//============================================================================
// File        : 341 - Non-Stop Travel.cpp
// Author      : AHMED HANI IBRAHIM
// Copyright   : AHani
// Version     : UVa - Accepted - 0.056
// Created on August 17, 2012, 10:08 AM
//============================================================================

#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include<string>
#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
#define Max 200
#define INF 1000000000
//#define INT_MAX 2147483647
#define FOR(i , N) for( int i = 0 ; i < N ; i++ )
#define FOR1e(i , N) for( int i = 1 ; i <= N ; i++ )
#define FORe(i , N) for(int i = 0 ; i <= N ; i++ )
#define FOR1(i , N) for(int i = 1 ; i < N ; i++ )

using namespace std;

int NumberOfIntersections , NumberOfStreets;
int Second , First;
int Distance[Max][Max] , Path[Max][Max];
vector<int> path;

void pathprint(int i, int j) {
  if (i != j)
    pathprint(i, Path[i][j]);
  path.push_back(j);
}

int main(int argc, char** argv) {
//    freopen("Trojan.txt", "r", stdin);
    int Cases = 1;
    
    while ( scanf("%d" ,&NumberOfIntersections )  ){
        if ( NumberOfIntersections == 0 )
            break;
        
        FOR(i , Max){
            FOR(j , Max){
                Distance[i][j] = INF;
                Path[i][j] = i;
            }
        }
        
        FOR(i , Max){
            Distance[i][i] = 0;
        }
        
        FOR(i , NumberOfIntersections){
            scanf("%d" , &NumberOfStreets);
            
            while ( NumberOfStreets -- ){
                scanf("%d %d" , &First , &Second);
                Distance[i + 1] [ First ] = Second;
            }
        }
        
        
        
        FOR1e(k , NumberOfIntersections){
            FOR1e(i , NumberOfIntersections){
                FOR1e(j , NumberOfIntersections){
                    
                    if ( Distance[i][j] > Distance[i][k] + Distance[k][j] ){
                        Distance[i][j] = Distance[i][k] + Distance[k][j];
                        Path[i][j] = Path[k][j];
                        
                    }
                }
            }
        }
        
        scanf("%d %d" , &First , &Second);
        
        path.clear();
        pathprint(First , Second);
        
        printf("Case %d: Path =" , Cases++);
        
        FOR(i , path.size()){
            printf(" %d" , path[i]);
        }
        
        printf("; %d second delay\n" , Distance[First][Second]);
        
      
    }
   

    return 0;
}

