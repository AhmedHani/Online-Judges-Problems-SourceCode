//============================================================================
// File        : 10608 - Friends.cpp
// Author      : AHMED HANI IBRAHIM
// Copyright   : AHani
// Version     : UVa - Accepted - 0.032
// Created on August 28, 2012, 9:48 PM
//============================================================================

#include <cstdlib>
#include <stdio.h>
//#include <string.h>
//#include<string>
//#include<iostream>
//#include<map>
#include<algorithm>
//#include<functional>
#define Max 30000 + 5
//#define INF 1000000000
//#define INT_MAX 2147483647
#define FOR(i , N) for( int i = 0 ; i < N ; i++ )
//#define FOR1e(i , N) for( int i = 1 ; i <= N ; i++ )
//#define FORe(i , N) for(int i = 0 ; i <= N ; i++ )
//#define FOR1(i , N) for(int i = 1 ; i < N ; i++ )

using namespace std;

int TestCases , NumberOfPeople , NumberOfPairs , First , Second;
int Parents[Max] , Counter[Max];

int FindSet(int i){
    return Parents[i] == i ? i: (Parents[i] = FindSet(Parents[i]));
}

bool Equal(int X , int Y){
    return FindSet(X) == FindSet(Y);
    return false;
}

int Joint(int X , int Y){
//    if ( !Equal(X , Y) )
    return Parents[FindSet(X)] = FindSet(Y);
}

int main(int argc, char** argv) {
//    freopen("Trojan.txt", "r", stdin);
    
    scanf("%d" , &TestCases);
    
    while ( TestCases -- ){
        scanf("%d %d" , &NumberOfPeople , &NumberOfPairs);
        
        FOR(i , NumberOfPeople){
            Parents[i] = i;
            Counter[i] = 0;
        }
        
        while ( NumberOfPairs-- ){
            scanf("%d %d" , &First , &Second);
            Joint(First , Second);
        }
        
        FOR(i , NumberOfPeople){
            
            Counter[FindSet(i)]++;
        }
        
        NumberOfPairs = 1;
        
        FOR(i , NumberOfPeople){
            NumberOfPairs = max(NumberOfPairs , Counter[i]);
        }
        printf("%d\n" , NumberOfPairs);
    }

    return 0;
}

