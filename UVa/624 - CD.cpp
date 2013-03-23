//============================================================================
// File        : 624 - CD.cpp
// Author      : AHMED HANI IBRAHIM
// Copyright   : AHani
// Version     : UVa - Accepted - 0.052
// Created on August 13, 2012, 11:29 PM
//============================================================================

#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include<string>
#include<iostream>
#include<vector>
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


int LimitedMinitus , NumberOfTracks;
int Tracks[Max] , RequiredCD[Max] , CD[Max];
int RequiredDuration , Duration ;
int Space , Sum;


void MaximumDuaration(int Duarationn , int Index){
    int Diff = Duarationn - Tracks[Index];
    
    if (Index == NumberOfTracks || Diff < 0){
        if (Duarationn < Space ){
            Space = Duarationn;
            RequiredDuration = Duration;
            
            FOR(i , Duration)
                RequiredCD[i] = CD[i];
            
        }
    }
    else{
//        Duration++;
        
        CD[Duration++] = Tracks[Index];
        for ( int i = Index + 1 ; i <= NumberOfTracks ; i++ )
            MaximumDuaration(Diff , i);
        
        Duration--;
    }
    
}


int main(int argc, char** argv) {
    freopen("Trojan.txt", "r", stdin);
    
       while (scanf("%d %d", &LimitedMinitus , &NumberOfTracks)!=EOF ){
           if (LimitedMinitus == 0 && NumberOfTracks == 0)
               break;
           
           FOR(i , NumberOfTracks){
               scanf("%d" , &Tracks[i]);
           }
           
           Duration = 0;
           Space = LimitedMinitus;
           Sum = 0;
           
           FOR(i , NumberOfTracks){
               MaximumDuaration(LimitedMinitus , i);
           }
           
           FOR(i , RequiredDuration){
               Sum += RequiredCD[i];
               
               printf("%d " , RequiredCD[i]);
           }
           
           printf("sum:%d\n", Sum);

    }
    

    return 0;
}

