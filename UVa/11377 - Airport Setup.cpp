//============================================================================
// File        : 11377 - Airport Setup.cpp
// Author      : AHMED HANI IBRAHIM
// Copyright   : AHani
// Version     : UVa - Accepted - 0.052
// Created on August 25, 2012, 6:02 AM
//============================================================================

#include <cstdlib>
#include <stdio.h>
#include <string.h>
//#include<string>
//#include<iostream>
//#include<map>
#include<vector>
#include<queue>
//#include<algorithm>
//#include<functional>
#define Max 20000 + 5
#define INF 1000000000
//#define INT_MAX 2147483647
#define FOR(i , N) for( int i = 0 ; i < N ; i++ )
#define FOR1e(i , N) for( int i = 1 ; i <= N ; i++ )
#define FORe(i , N) for(int i = 0 ; i <= N ; i++ )
#define FOR1(i , N) for(int i = 1 ; i < N ; i++ )

using namespace std;

int TestCases , NumberOfCities , NumberOfCompaniesSetup , NCitiesAirPort , CitiesAirPort , Demands , First , Second;
bool HasAirport[Max];
vector<int> Distance[Max];
queue<int> Container;
int Setup[Max];

int main(int argc, char** argv) {
//    freopen("Trojan.txt", "r", stdin);
    int Cases = 1;
    scanf("%d" , &TestCases);
    
    while( TestCases-- ){
        memset(HasAirport , false , sizeof(HasAirport));
        FOR(i , Max){
            Distance[i].clear();
        }
        
        scanf("%d %d %d" , &NumberOfCities , &NumberOfCompaniesSetup , &NCitiesAirPort);
        FOR(i , NCitiesAirPort){
            scanf("%d" , &CitiesAirPort);
            HasAirport[CitiesAirPort] = true;
        }
        
        FOR(i , NumberOfCompaniesSetup){
            scanf("%d %d" , &First , &Second);
            Distance[First].push_back(Second);
            Distance[Second].push_back(First);
        }
        Container.empty();
        scanf("%d" , &Demands);
        printf ("Case %d:\n", Cases++);
        
        while ( Demands-- ){
            scanf("%d %d" , &First , &Second);
            
            if ( First == Second)       { printf("0\n"); continue; }
            
            FOR(i , Max){
                Setup[i] = INF;
            }
            Container.push(First);
            
            Setup[First] = HasAirport[First] ? 0 : 1;
            
            while ( !Container.empty() ){
                int P = Container.front(); Container.pop();
                
                FOR(i , Distance[P].size()){
                    int Tmp = HasAirport [Distance [P] [i]] ? Setup [P] : Setup [P] + 1;
                    if ( Setup[Distance[P][i]] > Tmp ){
                        Setup[Distance[P][i]] = Tmp;
                        Container.push(Distance[P][i]);
                    }
                }
            }
            if ( Setup[Second] == INF )
            printf("-1\n");
        else
            printf("%d\n" , Setup[Second]); 
        }
        
        printf("\n");
    }
    

    return 0;
}

