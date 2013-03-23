//============================================================================
// File        : 10685 - Nature.cpp
// Author      : AHMED HANI IBRAHIM
// Copyright   : AHani
// Version     : UVa - Accepted - 0.532
// Created on August 29, 2012, 12:51 AM
//============================================================================

#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include<string>
#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#define Max 200 + 5
#define INF 1000000000
//#define INT_MAX 2147483647
#define FOR(i , N) for( int i = 0 ; i < N ; i++ )
#define FOR1e(i , N) for( int i = 1 ; i <= N ; i++ )
#define FORe(i , N) for(int i = 0 ; i <= N ; i++ )
#define FOR1(i , N) for(int i = 1 ; i < N ; i++ )

using namespace std;

int NumberOfCreatures , NumberOfRelations , MaxSize;
vector<int> Parents;
vector<int> Size;
map<string , int> Container;
string First , Second , All;

int FindSet(int i){
    return Parents[i] == i ? i : (Parents[i] = FindSet(Parents[i]));
}

bool Equal(int X , int Y){
    return FindSet(X) == FindSet(Y);
//    return false;
}

void Joint(int X , int Y){
    if ( !Equal(X , Y) )
        Size[FindSet(Y)] += Size[FindSet(X)];
     Parents[FindSet(X)] = FindSet(Y);
}

int main(int argc, char** argv) {
//    freopen("Trojan.txt", "r", stdin);
    
    while ( scanf("%d %d" , &NumberOfCreatures , &NumberOfRelations) , NumberOfCreatures|NumberOfRelations ){
        
        Parents.assign(NumberOfCreatures , 0);
        Size.assign(NumberOfCreatures , 1);
        
        FOR(i , NumberOfCreatures){
            Parents[i] = i;
        }
        
        Container.clear();
        
        FOR(i , NumberOfCreatures){
            cin >> All;
            Container[All] = i;
        }
        
        FOR(i , NumberOfRelations){
            cin >> First >> Second;
            Joint(Container[First] , Container[Second]);
        }
        
        MaxSize = Size[0];
        
        for ( int i = 1 ; i <= Parents.size() - 1 ; i++ ){
            MaxSize = Size[i] > MaxSize ? Size[i] : MaxSize;
        }
        printf("%d\n" , MaxSize);
    }

    return 0;
}

