//============================================================================
// File        : 11631 - Dark roads.cpp
// Author      : AHMED HANI IBRAHIM
// Copyright   : AHani
// Version     : UVa - Accepted - 0.394
// Created on August 28, 2012, 8:41 PM
//============================================================================

#include <cstdlib>
#include <stdio.h>
#include <string.h>
//#include<string>
//#include<iostream>
//#include<map>
#include<algorithm>
#include<functional>
#define Max 200000 + 5
//#define INF 1000000000
//#define INT_MAX 2147483647
#define FOR(i , N) for( int i = 0 ; i < N ; i++ )
//#define FOR1e(i , N) for( int i = 1 ; i <= N ; i++ )
//#define FORe(i , N) for(int i = 0 ; i <= N ; i++ )
//#define FOR1(i , N) for(int i = 1 ; i < N ; i++ )

using namespace std;

int NumberRoads , NumberOfRoads , TotalDistance , IntialJoint;
int Parents[Max] , Size[Max];

struct Node{
    int First;
    int Second;
    int Distance;
} Collection[Max];

int FindSet(int i){
    return (Parents[i] == i) ? i : (Parents[i] = FindSet(Parents[i]));
    printf("%d" , FindSet(0));
}

bool Equal(int X , int Y ){
    return FindSet(X) == FindSet(Y);
    return false;
}

void Joint(int X , int Y){
//    if ( !Equal(X , Y) )
//        IntialJoint--;
    Parents[FindSet(X)] = FindSet(Y);
}

bool Compare(Node X , Node Y){
    if ( X.Distance < Y.Distance )
        return true;
    return false;
}

int main(int argc, char** argv) {
//    freopen("Trojan.txt", "r", stdin);
    
    while ( scanf("%d %d" , &NumberRoads , &NumberOfRoads) , NumberRoads|NumberOfRoads ){
        TotalDistance = NULL;
        
        FOR(i , NumberOfRoads){
            Parents[i] = i;
            Size[i] = 1;
            scanf("%d %d %d" , &Collection[i].First , &Collection[i].Second , &Collection[i].Distance);
            TotalDistance += Collection[i].Distance;
        }
        
        Parents[NumberOfRoads] = NumberOfRoads;
        Size[NumberOfRoads] = 1;
        
        IntialJoint = NumberRoads - 1;
        int Counter = NULL;
        
        sort(Collection , Collection + NumberOfRoads , Compare);
        
        for ( int i = 0 ; i < NumberOfRoads && IntialJoint ; i++ ){
            int CFirst = FindSet(Collection[i].First);
            int CSecond = FindSet(Collection[i].Second);
            if ( !Equal(CFirst , CSecond) ){
                if ( Size[CFirst] > Size[CSecond] )
                    swap(CFirst , CSecond);
                
                Size[CSecond] += Size[CFirst];
                Joint(CFirst , CSecond);
                Counter += Collection[i].Distance;
                IntialJoint--;
                
            }
        }
        printf("%d\n", TotalDistance - Counter);
    }
    

    return 0;
}

