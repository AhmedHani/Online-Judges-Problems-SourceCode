//============================================================================
// File        : 11015 - 05-2 Rendezvous.cpp
// Author      : AHMED HANI IBRAHIM
// Copyright   : AHani
// Version     : UVa - Accepted - 0.012
// Created on August 14, 2012, 9:35 PM
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

struct Team{
    char Names[Max];
    int ID;
} Friends[Max];

int NumberOfFriends , NumberOfRoads;
int First , Second , Cost;
int Distance[Max][Max];
int Target;
int Sum;
int Tmp;

int main(int argc, char** argv) {
    freopen("Trojan.txt", "r", stdin);
    int Cases = 1;
    
    while ( scanf("%d %d" , &NumberOfFriends , &NumberOfRoads) ){
        if ( NumberOfFriends == 0 && NumberOfRoads == 0)
            break;
        
        int Counter = 0;
        
        FOR(i , NumberOfFriends){
            scanf("%s" , Friends[i].Names);
            Friends[i].ID = Counter++;
        }
        
        FOR(i , NumberOfFriends){
            FOR(j , NumberOfFriends)
            Distance[i][j] = INF;
            Distance[i][i] = 0;
        }
        
        FOR(i , NumberOfRoads){
            scanf("%d %d %d" , &First , &Second , &Cost);
            Distance[First - 1][Second - 1] = Distance[Second - 1][First - 1] = Cost;
//            Distance[First][Second] = Distance[Second][First] = Cost;
        }
        
        FOR(k , NumberOfFriends){
            FOR(i , NumberOfFriends){
                FOR(j , NumberOfFriends){
                    Distance[i][j] = min(Distance[i][j] , Distance[i][k] + Distance[k][j]);
                }
            }
        }
        
        Target = -INF;
        Sum = INF;
        Tmp;
        
        FOR(i , NumberOfFriends){
            Tmp = 0;
            
            FOR(j , NumberOfFriends){
                Tmp += Distance[i][j];
            }
            
            if ( Tmp < Sum ){
                Sum = Tmp;
                Target = i;
            }
        }
        
        printf("Case #%d : %s\n", Cases++, Friends[Target].Names);
        
        
    }
    

    return 0;
}

