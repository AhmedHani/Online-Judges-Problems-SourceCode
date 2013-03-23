//============================================================================
// File        : 334 - Identifying Concurrent Events.cpp
// Author      : AHMED HANI IBRAHIM
// Copyright   : AHani
// Version     : UVa - Accepted - 0.008
// Created on August 15, 2012, 6:15 AM
//============================================================================

#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include<string>
#include<iostream>
#include<map>
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

int NumberOfComputations , NumberOfEvents;
int GDynamicPro[Max][Max];
string Event;
string MessageFrom , MessageTo;
int Index , Choosen , Counter;
string Answer;


int main(int argc, char** argv) {
//    freopen("Trojan.txt", "r", stdin);
    
    int Cases = 1;
    
    while ( scanf("%d" , &NumberOfComputations) ){
        if ( NumberOfComputations == 0)
            break;
        
        map<string , int> EventsArrange;
        vector<string> EventsContainer;
        
        memset(GDynamicPro , -1 , sizeof(GDynamicPro));
        
        Index = 0;
        
        FOR(i , NumberOfComputations){
            scanf("%d" , &NumberOfEvents);
            Choosen = Index;
            
            FOR(j , NumberOfEvents){
                cin >> Event;
                EventsArrange[Event] = Index++;
                EventsContainer.push_back(Event);
            }
            
            for ( int k = Choosen ; k < Index - 1 ; k++ ){
                GDynamicPro[k][k + 1] = INF;
            }
        }
        
        scanf("%d" , &NumberOfEvents);
        
        FOR(i , NumberOfEvents){
            cin >> MessageFrom >> MessageTo;
            GDynamicPro[ EventsArrange[MessageFrom] ][ EventsArrange[MessageTo] ] = INF;
        }
        
        FOR(k , Index){
            FOR(i , Index){
                FOR(j , Index){
                    GDynamicPro[i][j] = max(GDynamicPro[i][j] , min(GDynamicPro[i][k] , GDynamicPro[k][j]));
                }
            }
        }
        
        Answer = "";
        Counter = 0;
        
        FOR(i , Index)
        for ( int j = i + 1 ; j < Index ; j++ ){
            
            if ( GDynamicPro[i][j] == -1 && GDynamicPro[j][i] == -1){
                Counter++;
                
                if ( Counter <= 2 )
                   Answer += "(" + EventsContainer[i] + "," + EventsContainer[j] + ") ";

            }
            
        }
        
        if ( Counter ){
            printf("Case %d, %d concurrent events:\n" , Cases++ , Counter);
            cout << Answer << endl;
        }
        else
            printf("Case %d, no concurrent events.\n" , Cases++);
    }

    return 0;
}

