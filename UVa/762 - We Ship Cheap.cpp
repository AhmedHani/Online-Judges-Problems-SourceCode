//============================================================================
// File        : 762 - We Ship Cheap.cpp
// Author      : AHMED HANI IBRAHIM
// Copyright   : AHani
// Version     : UVa - Accepted - 1.408
// Created on August 17, 2012, 1:00 AM
//============================================================================

#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include<string>
#include<iostream>
#include<map>
#include<algorithm>
#include<functional>
#define Max 1000
#define INF 1000000000
//#define INT_MAX 2147483647
#define FOR(i , N) for( int i = 0 ; i < N ; i++ )
#define FOR1e(i , N) for( int i = 1 ; i <= N ; i++ )
#define FORe(i , N) for(int i = 0 ; i <= N ; i++ )
#define FOR1(i , N) for(int i = 1 ; i < N ; i++ )

using namespace std;

int NumberOfLinks , Index;
int Intial[Max][Max] , Distance[Max][Max];
string First , Second;
map<string , int> CitiesArrangement;
map<int , string> CitiesReversed;
bool line = true;

void path(int i,int j)
{
    if(Intial[i][j]==-1)
        cout << CitiesReversed[i] << " " << CitiesReversed[j] <<endl;
    else
    {
        path(i,Intial[i][j]);
        path(Intial[i][j],j);
    }
}

int main(int argc, char** argv) {
//    freopen("Trojan.txt", "r", stdin);
    
    
    while ( scanf("%d" , &NumberOfLinks) != EOF ){
        
        CitiesArrangement.clear();
        CitiesReversed.clear();
        
        FOR(i , Max){
            FOR(j , Max)
                Distance[i][j] = INF;
            Distance[i][i] = 0;
        }
        
        FOR(i , Max){
            FOR(j , Max){
                Intial[i][j] = -1;
            }
        }
        
        Index = 1;
        
        FOR(i , NumberOfLinks){
            cin >> First >> Second;
            
            if ( CitiesArrangement[First] == false){
                CitiesReversed[Index] = First;
                CitiesArrangement[First] = Index++;
            }
            
            if ( CitiesArrangement[Second] == false ){
                CitiesReversed[Index] = Second;
                CitiesArrangement[Second] = Index++;
            }
            
            Distance[ CitiesArrangement[First] ][ CitiesArrangement[Second] ] = 1;
            Distance[ CitiesArrangement[Second] ][ CitiesArrangement[First] ] = 1;
        }
        
        cin >> First >> Second;
        
        if ( CitiesArrangement[First] == false ){
            CitiesReversed[Index] = First;
            CitiesArrangement[First] = Index++;
        }
        
        if ( CitiesArrangement[Second] == false ){
            CitiesReversed[Index] = Second;
            CitiesArrangement[Second] = Index++;
        }
        
        FOR(k , Index){
            FOR(i , Index){
                FOR(j , Index){
                     if(  Distance[i][k] + Distance[k][j] < Distance[i][j]  ){
                        Distance[i][j] = Distance[i][k] + Distance[k][j];
                        Intial[i][j] = k;
                     }
                }
            }
        }
        
        if ( line == true )
            line = false;
        else
            printf("\n");
        
        if ( Distance[CitiesArrangement[First]][CitiesArrangement[Second]] == INF )printf("No route\n");
        else    path(CitiesArrangement[First] , CitiesArrangement[Second]);
            
        
    }

    return 0;
}

