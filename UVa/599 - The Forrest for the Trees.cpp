//============================================================================
// File        : 599 - The Forrest for the Trees.cpp
// Author      : AHMED HANI IBRAHIM
// Copyright   : AHani
// Version     : UVa - Accepted - 0.100
// Created on August 28, 2012, 11:00 PM
//============================================================================

#include <cstdlib>
#include <stdio.h>
//#include <string.h>
//#include<string>
//#include<iostream>
//#include<map>
//#include<algorithm>
//#include<functional>
#define Max 26
//#define INF 1000000000
//#define INT_MAX 2147483647
#define FOR(i , N) for( int i = 0 ; i < N ; i++ )
//#define FOR1e(i , N) for( int i = 1 ; i <= N ; i++ )
//#define FORe(i , N) for(int i = 0 ; i <= N ; i++ )
//#define FOR1(i , N) for(int i = 1 ; i < N ; i++ )

//using namespace std;

int TestCases , TreesCount , ACorns;
char Tree[Max + 100] , Letters[Max + 100];
int Parents[Max] , Counter[Max];

int FindSet(int i){
    return Parents[i] == i ? i : (Parents[i] = FindSet(Parents[i]));
}

bool Equal(int X , int Y){
    return Parents[X] == Parents[Y];
    return false;
}

int Joint(int X , int Y){
    return Parents[FindSet(X)] = FindSet(Y);
}

int main(int argc, char** argv) {
//    freopen("Trojan.txt", "r", stdin);
    
    
    scanf("%d" , &TestCases);
    getchar();
    
    while ( TestCases -- ){
        FOR(i , Max){
            Parents[i] = i;
            Counter[i] = 0;
        }
        
        while ( gets(Tree) && Tree[0] != '*' ){
            Joint(Tree[1] - 'A' , Tree[3] - 'A');
        }
        
        gets(Letters);
        
        for ( int i = 0 ; Letters[i] ; i++ ){
            if ( Letters[i] != ',' )
                Counter[FindSet(Letters[i] - 'A')]++;
        }
        
        TreesCount = NULL;
        ACorns = NULL;
        
        FOR(i , Max){
            if ( Counter[i] > 1 )
                TreesCount++;
            else if (Counter[i] == 1)
                ACorns++;
        }
        
        printf("There are %d tree(s) and %d acorn(s).\n",TreesCount,ACorns);

    }

    return 0;
}

