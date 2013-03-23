//============================================================================
// File        : 280 - Vertex.cpp
// Author      : AHMED HANI IBRAHIM
// Copyright   : AHani
// Version     : UVa - Accepted - 0.292
// Created on August 15, 2012, 3:15 AM
//============================================================================

#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include<string>
#include<iostream>
#include<vector>
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

int NumberOfVertex , First , Second;
int Distance[Max][Max] , Counter;

int main(int argc, char** argv) {
//    freopen("Trojan.txt", "r", stdin);
    
    while ( scanf("%d" , &NumberOfVertex) != EOF){
        if ( NumberOfVertex == 0 )
            break;
        
        memset(Distance , -1 , sizeof(Distance));
        
        while ((scanf("%d" ,&First ) ) && First != 0 )
        while ((scanf("%d" , &Second) ) && Second != 0 )
              Distance[First][Second] = 1;

        FOR1e(k , NumberOfVertex){
            FOR1e(i , NumberOfVertex){
                FOR1e(j , NumberOfVertex){
                    Distance[i][j] = max( Distance[i][j] , min(Distance[i][k] , Distance[k][j]) );
                }
            }
        }
        
        scanf("%d" , &Counter);

        while ( Counter-- ) {

            scanf("%d" , &First);

            vector<int> Result;

            FOR1e(Second , NumberOfVertex) 
                    if (Distance[First][Second] == -1)  
                        Result.push_back(Second);

            printf("%d" , Result.size());

            FOR(i, Result.size()) 
            printf(" %d" ,Result[i] ) ;

            printf("\n");

        }
    }
    
    

    return 0;
}

