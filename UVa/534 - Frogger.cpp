//============================================================================
// File        : 534 - Frogger.cpp
// Author      : AHMED HANI IBRAHIM
// Copyright   : AHani
// Version     : UVa - Accepted - 0.064
// Created on August 10, 2012, 4:42 AM
//============================================================================

#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<functional>
#define Max 200 + 5
#define INF 1000000000
//#define INT_MAX 2147483647
#define FOR(i , Stones) for( int i = 0 ; i < Stones ; i++ )

using namespace std;

double Calculation(int x1 , int y1  , int x2 , int y2 ){
       return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));

}

int Stones;
double Distance[Max][Max];
int Nodes[1000][1000];


int main(int argc, char** argv) {
    freopen("Trojan.txt", "r", stdin);
    int Cases = 1;
    
    while ( scanf("%d" , &Stones) && Stones ){
        
        FOR(i , Stones){
            scanf("%d %d" , Nodes[i] , Nodes[i]+1);
        }
        FOR(i , Stones){
            FOR(j , Stones)
            Distance[i][j] = INF;
            Distance[i][i] = 0;
        }
        
        FOR(i , Stones)
            for (int j = i + 1 ; j < Stones ; j++ )
                Distance[i][j] = Distance[j][i] = Calculation(Nodes[i][0] , Nodes[i][1] , Nodes[j][0] , Nodes[j][1]);
        
        FOR(k , Stones)
            FOR(i , Stones)
                FOR(j , Stones)
                    Distance[i][j] = min( Distance[i][j] , max(Distance[i][k] , Distance[k][j]) );
               
         printf("Scenario #%d\n",Cases++);
         printf("Frog Distance = %.3lf\n\n",Distance[0][1]);

        
    }
    return 0;
    
    
    
}

