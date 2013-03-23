//============================================================================
// File        : 10803 - Thunder Mountain.cpp
// Author      : AHMED HANI IBRAHIM
// Copyright   : AHani
// Version     : UVa - Accepted - 0.052
// Created on August 11, 2012, 8:37 AM
//============================================================================

#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include<iostream>
#include<algorithm>
#include<functional>
#include<cmath>
#define Max 1010
#define INF 1000000000
//#define INT_MAX 2147483647
#define FOR(i , NumberOfTowns) for( int i = 0 ; i < NumberOfTowns ; i++ )

using namespace std;

double Calculation(int x1 , int y1  , int x2 , int y2 ){
       return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));

}
int TestCases , NumberOfTowns;
int XCoordinate[Max] , YCoordinate[Max];
double Distance[Max][Max];

int main(int argc, char** argv) {
    freopen("Trojan.txt", "r", stdin);
    int Cases = 1;
    
    scanf("%d" , &TestCases);
    while ( TestCases -- ){
        scanf("%d" , &NumberOfTowns);
        
        FOR(i , NumberOfTowns)
            scanf("%d %d" , &XCoordinate[i] , &YCoordinate[i] );
        
        FOR(i , NumberOfTowns)
            FOR(j , NumberOfTowns){
                Distance[i][j] = Calculation(XCoordinate[i] , YCoordinate[i] , XCoordinate[j] , YCoordinate[j]);
            if ( Distance[i][j] > 10 )
                Distance[i][j] = INF;
        }
        
        FOR(k , NumberOfTowns){
            FOR(i , NumberOfTowns){
                FOR(j , NumberOfTowns){
                    Distance[i][j] = min (Distance[i][j] , Distance[i][k] + Distance[k][j]);
                }
            }
        }
        double Answer = 0;
        FOR(i , NumberOfTowns)
            FOR(j , NumberOfTowns)
            Answer = max(Answer , Distance[i][j]);
        
         printf("Case #%d:\n", Cases++);
         if ( Answer < INF )
             printf("%.4lf\n\n", Answer);
         else
             printf("Send Kurdy\n\n");
        
    }
    
    return 0;
}

