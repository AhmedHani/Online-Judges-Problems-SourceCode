//============================================================================
// File        : 10583 - Ubiquitous Religions.cpp
// Author      : AHMED HANI IBRAHIM
// Copyright   : AHani
// Version     : UVa - Accepted - 0.148
// Created on August 28, 2012, 2:09 AM
//============================================================================

//#include <cstdlib>
#include <stdio.h>
//#include <string.h>
//#include<string>
//#include<iostream>
//#include<map>
//#include<algorithm>
//#include<functional>
#define Max 50000 + 5
//#define INF 1000000000
//#define INT_MAX 2147483647
#define FOR(i , N) for( int i = 0 ; i < N ; i++ )
//#define FOR1e(i , N) for( int i = 1 ; i <= N ; i++ )
//#define FORe(i , N) for(int i = 0 ; i <= N ; i++ )
//#define FOR1(i , N) for(int i = 1 ; i < N ; i++ )

//using namespace std;

int Parents[Max] , IntialDisJoint;
int First , Second;
int AllStudents , NumberOfPairs;

int FindSet(int i){
    return Parents[i] == i ? i : (Parents[i] = FindSet(Parents[i]));
}

bool Equal(int X , int Y ){
    return FindSet(X) == FindSet(Y);
    return false;
}

void Joint(int X , int Y){
    if ( !Equal(X , Y) )
        IntialDisJoint--;
    Parents[FindSet(X)] = FindSet(Y);
}

int main(int argc, char** argv) {
    freopen("Trojan.txt", "r", stdin);
    int Cases = 1;
    
    while ( scanf("%d %d" , &AllStudents , &NumberOfPairs) , AllStudents|NumberOfPairs ){
        
        FOR(i , AllStudents){
            Parents[i] = i;
        }
          IntialDisJoint = AllStudents;
          
          FOR(i , NumberOfPairs){
              scanf("%d %d" , &First , &Second);
              Joint(First , Second);
          }
          printf("Case %d: %d\n", Cases++, IntialDisJoint);
    }

    return 0;
}

