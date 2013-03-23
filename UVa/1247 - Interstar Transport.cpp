//============================================================================
// File        : 1247 - Interstar Transport.cpp
// Author      : AHMED HANI IBRAHIM
// Copyright   : AHani
// Version     : UVa - Accepted - 0.008
// Created on August 23, 2012, 4:37 AM
//============================================================================

#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include<string>
//#include<iostream>
#include<vector>
#include<queue>
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

int NumberOfPlants , ITransport ,IFirst , ISecond, Cost , Quaries , IStart , IEnd;
char First , Second;
int Matrix[Max][Max] , Distance[Max] , Route[Max];

void Dijkstra( int Start , int End ){
    FOR(i , Max){
        Distance[i] = INF;
        Route[i] = INF;
    }
    Distance[Start] = 0;
    
    priority_queue<pair<int,int> , vector<pair<int,int> > , greater<pair<int,int> > > Q;
    
    Q.push(pair<int,int>(NULL , Start));
    
    while(Q.size()){
      pair<int,int> p = Q.top();
      Q.pop();

      FOR(i , Max){

   if(Distance[i] > Distance[p.second] + Matrix[p.second][i]){
	    Distance[i] = Distance[p.second] + Matrix[p.second][i];
	    Q.push(pair<int,int>(Distance[i],i));
	    Route[i] = p.second;
            
	 }
      }
   }
}


int main(int argc, char** argv) {
    freopen("Trojan.txt", "r", stdin);
    
    FOR(i , Max){
        FOR(j , Max){
            Matrix[i][j] = INF;
        }
    }
    
    scanf("%d %d" , &NumberOfPlants , &ITransport);
    
    FOR(i , ITransport){
        scanf("%s %s %d" , &First , &Second ,  &Cost);
        IFirst = First - 'A'; ISecond = Second - 'A';
        Matrix[IFirst][ISecond] = Matrix[ISecond][IFirst] = Cost;
    }
    
    scanf("%d" , &Quaries);
    
    FOR(i , Quaries){
        scanf("%s %s" , &First , &Second); ;
        IStart = First - 'A'; IEnd = Second - 'A';
        
        Dijkstra(IStart , IEnd);
        vector<char>AllResults;
        int Current = IEnd;
        
        while (true){
            AllResults.push_back(Current + 'A');
            Current = Route[Current];
            if ( Current == INF )
                break;
        }
        
        reverse(AllResults.begin() , AllResults.end());
        
        FOR(j , AllResults.size()){
            if (j)
                printf(" ");
            printf("%c" , AllResults[j]);
            
        }
        printf("\n");
    }

    return 0;
}
