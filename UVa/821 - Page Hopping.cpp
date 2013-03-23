//============================================================================
// File        : 821 - Page Hopping.cpp
// Author      : AHMED HANI IBRAHIM
// Copyright   : AHani
// Version     : UVa - Accepted - 1.920
// Created on August 13, 2012, 8:18 AM
//============================================================================

#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include<string>
#include<map>
#include<algorithm>
#include<functional>
#define Max 250
#define INF 1000000000
//#define INT_MAX 2147483647
#define FOR(i , N) for( int i = 0 ; i < N ; i++ )
#define FOR1e(i , N) for( int i = 1 ; i <= N ; i++ )
#define FORe(i , N) for(int i = 0 ; i <= N ; i++ )
#define FOR1(i , N) for(int i = 1 ; i < N ; i++ )

using namespace std;

int First , Second , Sum , PairsCounter ;
int Distance[Max][Max];

int main(int argc, char** argv) {
    freopen("Trojan.txt", "r", stdin);
    int Cases = 1;
    
    while ( scanf("%d %d" , &First , &Second) ){
        if ( First == 0 && Second == 0 )
            break;
        
        FOR1e(i , Max){
            FOR1e(j , Max)
                Distance[i][j] = INF;
            Distance[i][i] = 0;
        }
        
        Distance[First][Second] = 1;
        
        while ( scanf("%d %d" , &First , &Second ) ){
            if( First == 0 && Second == 0 )
                break;
            Distance[First][Second] = 1;
        }
       
        FOR1e(k , Max){
            FOR1e(i , Max){
                FOR1e(j , Max){
                    Distance[i][j] = min(Distance[i][j] , Distance[i][k] + Distance[k][j] );
                }
            }
        }
        
        Sum = 0;
        PairsCounter = 0;
        
        FOR1e(i , Max){
            FOR1e(j , Max){
                
                if ( Distance[i][j] == INF || i == j )
                    continue;
                PairsCounter++;
                Sum += Distance[i][j];
                
            }
        }
        printf("Case %d: average length between pages = %.03lf clicks\n" , Cases++ ,double(Sum*1.0 / PairsCounter) );
       

    }
    
    

    return 0;
}

