//============================================================================
// File        : 459 - Graph Connectivity.cpp
// Author      : AHMED HANI IBRAHIM
// Copyright   : AHani
// Version     : UVa - Accepted - 0.008
// Created on August 28, 2012, 6:58 AM
//============================================================================

#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include<ctype.h>
//#include<iostream>
//#include<map>
//#include<algorithm>
//#include<functional>
#define Max 200 + 5
#define INF 1000000000
//#define INT_MAX 2147483647
#define FOR(i , N) for( int i = 0 ; i < N ; i++ )
//#define FOR1e(i , N) for( int i = 1 ; i <= N ; i++ )
//#define FORe(i , N) for(int i = 0 ; i <= N ; i++ )
//#define FOR1(i , N) for(int i = 1 ; i < N ; i++ )

//using namespace std;

int Parents[Max];
int TestCases , IntialJoint;
char MaximumVertex;
char FirstSecond[Max];

int FindSet(int i){
    return (Parents[i] == i) ? i : (Parents[i] = FindSet(Parents[i]));
    printf("%d" , FindSet(0));
}

bool Equal(int X , int Y ){
    return FindSet(X) == FindSet(Y);
    return false;
}

void Joint(int X , int Y){
    if ( !Equal(X , Y) )
        IntialJoint--;
    Parents[FindSet(X)] = FindSet(Y);
}

int main(int argc, char** argv) {
    freopen("Trojan.txt", "r", stdin);
    
    scanf("%d" , &TestCases);
    
    while ( TestCases-- ){
        scanf("%s" , &MaximumVertex);
        
        FOR(i , (MaximumVertex - 'A' + 1)){
            Parents[i] = i;
            IntialJoint = MaximumVertex - 'A' + 1;
        }
        getchar();
        
        while ( gets(FirstSecond) && strlen(FirstSecond) > 0 ){
            Joint(FirstSecond[0] - 'A' , FirstSecond[1] - 'A');
        }
        
        printf("%d\n" , IntialJoint);
        
        if ( TestCases )
            printf("\n");
    }

    return 0;
}

