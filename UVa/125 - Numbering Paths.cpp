//============================================================================
// File        : 125 - Numbering Paths.cpp
// Author      : AHMED HANI IBRAHIM
// Copyright   : AHani
// Version     : UVa - Accepted - 0.008
// Created on August 13, 2012, 4:56 AM
//============================================================================

#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include<string>
#include<iostream>
#include<map>
#include<algorithm>
#include<functional>
#define Max 30 + 1
#define INF 1000000000
//#define INT_MAX 2147483647
#define FOR(i , N) for( int i = 0 ; i < N ; i++ )
#define FOR1e(i , N) for( int i = 1 ; i <= N ; i++ )
#define FORe(i , N) for(int i = 0 ; i <= N ; i++ )
#define FOR1(i , N) for(int i = 1 ; i < N ; i++ )

using namespace std;

int NumberOfStreets , FirstIntersection , SecondIntersection;
int MatrixConstruction;
int MatrixDP[Max][Max];

int main(int argc, char** argv) {
//    freopen("Trojan.txt", "r", stdin);
    int Cases = 0;
    
    while ( scanf("%d" , &NumberOfStreets ) != EOF ){
        
        MatrixConstruction = 0;
        memset(MatrixDP , 0 , sizeof(MatrixDP));
        
        FOR1e(i , NumberOfStreets){
            scanf("%d %d" , &FirstIntersection , &SecondIntersection);
            MatrixDP[FirstIntersection][SecondIntersection] = 1;
            MatrixConstruction = max (MatrixConstruction , max(FirstIntersection , SecondIntersection ));
        }
        MatrixConstruction++;
        
        FOR(k , MatrixConstruction){
            FOR(i , MatrixConstruction){
                FOR(j , MatrixConstruction){
                    MatrixDP[i][j] += MatrixDP[i][k] * MatrixDP[k][j];
//                    if (MatrixDP[i][j] < MatrixDP[i][k] + MatrixDP[k][j])
//                        MatrixDP[i][j] += MatrixDP[i][k] * MatrixDP[k][j];
////                    MatrixDP[i][j] = max (MatrixDP[i][j] , MatrixDP[i][k] * MatrixDP[k][j]);
                }
            }
        }
        
        FOR(k , MatrixConstruction)
            if ( MatrixDP[k][k]  )
                FOR(i , MatrixConstruction)
                    FOR(j , MatrixConstruction)
                        if( MatrixDP[i][k] && MatrixDP[k][j] )
                            MatrixDP[i][j] = -1;
        
        printf("matrix for city %d\n", Cases++);
        
        FOR(i , MatrixConstruction){
           FOR(j , MatrixConstruction){
               
               if ( j )
                   printf(" ");
               printf("%d" , MatrixDP[i][j] );
               
           }
           printf("\n");
        }
    }
    

    return 0;
}

