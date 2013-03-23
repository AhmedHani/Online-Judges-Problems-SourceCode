//============================================================================
// File        : 10246 - Asterix and Obelix.cpp
// Author      : AHMED HANI IBRAHIM
// Copyright   : AHani
// Version     : UVa - Accepted - 0.040
// Created on August 14, 2012, 5:56 AM
//============================================================================

#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include<string>
#include<iostream>
#include<map>
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

int NumberOfCities , NumberOfRoads , NumberOfQuaries;
int FeastCost[Max];
int First , Second , RoadCost;
int Feast[Max][Max] , Distance[Max][Max];
int Collection;

int main(int argc, char** argv) {
//    freopen("Trojan.txt", "r", stdin);
    int Cases = 1;
    
    while ( scanf("%d %d %d" , &NumberOfCities , &NumberOfRoads , &NumberOfQuaries) != EOF  ){
        if ( NumberOfCities == 0 && NumberOfRoads == 0 && NumberOfQuaries == 0 )
            break;
        
        FOR(i , Max){
            FOR(j , Max){
                Distance[i][j] = INF;
            Distance[i][i] = 0;   
            }
        }
//        FOR(i , Max)
//             Distance[i][i] = 0;   
        
        FeastCost[0] = 0;
        FOR1(i , NumberOfCities+1){
            scanf("%d" , &FeastCost[i]);
        }
        
        
        FOR(i , NumberOfRoads){
            scanf("%d %d %d" , &First , &Second , &RoadCost);
            Distance[First][Second] = Distance[Second][First] = RoadCost;
        }
        
        FORe(i , NumberOfCities){
            FORe(j , NumberOfCities){
                
                if ( FeastCost[i] > FeastCost[j] )
                    Feast[i][j] = Feast[j][i] = FeastCost[i];
                else
                    Feast[i][j] = Feast[j][i] = FeastCost[j];
                
            }
            
        }
        
        FOR1e(k , NumberOfCities){
            FOR1e(i , NumberOfCities){
                FOR1e(j , NumberOfCities){
                    
                    if ( Feast[i][k] > Feast[k][j] )
                        Collection = Feast[i][k];
                    else
                        Collection = Feast[k][j];
                    
                    if ( Collection + Distance[i][k] + Distance[k][j] < Distance[i][j] + Feast[i][j] ){
                        Distance[i][j] = Distance[i][k] + Distance[k][j];
                        Feast[i][j] = Collection;
                        
                        
                    }
                        
                }
            }
        }
           FOR1e(k , NumberOfCities){
            FOR1e(i , NumberOfCities){
                FOR1e(j , NumberOfCities){
                    
                    if ( Feast[i][k] > Feast[k][j] )
                        Collection = Feast[i][k];
                    else
                        Collection = Feast[k][j];
                    
                    if ( Collection + Distance[i][k] + Distance[k][j] < Distance[i][j] + Feast[i][j] ){
                        Distance[i][j] = Distance[i][k] + Distance[k][j];
                        Feast[i][j] = Collection;
                    }
                        
                }
            }
        }
        
        if ( Cases > 1)
            printf("\n");
        printf("Case #%d\n" , Cases++);
        
        FOR(i , NumberOfQuaries){
            scanf("%d %d" , &First , &Second);
            
            if ( Distance[First][Second] >= INF )
               printf("-1\n");
             
            else
                printf("%d\n" , Distance[First][Second] + Feast[First][Second]);
            
        }
        
//        printf("\n");
        
    }
    

    return 0;
}

