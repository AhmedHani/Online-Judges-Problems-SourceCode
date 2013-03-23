//============================================================================
// File        : 10227 - Forests.cpp
// Author      : AHMED HANI IBRAHIM
// Copyright   : AHani
// Version     : UVa - Accepted - 0.008
// Created on August 31, 2012, 7:49 PM
//============================================================================

//#include <cstdlib>
#include <stdio.h>
#include <string.h>
//#include<string>
//#include<iostream>
//#include<map>
//#include<algorithm>
//#include<functional>
#define Max 200 + 5
//#define INF 1000000000
//#define INT_MAX 2147483647
#define FOR(i , N) for( int i = 0 ; i < N ; i++ )
#define FOR1e(i , N) for( int i = 1 ; i <= N ; i++ )
#define FORe(i ,ii, N) for(int i = ii ; i < (N) ; i++ )
#define FOR1(i ,ii, N) for(int i = ii ; i < N ; i++ )

//using namespace std;

int TestCases , NumberOfPeople , NumberOfTrees;
int Parents[Max] , NumberOfDisjoints;
int Seen[Max][Max];
char Garbage[Max];
int First , Second;

int FindSet(int i){
    return Parents[i] == i ? i : (Parents[i] = FindSet(Parents[i]));
}

bool Equal(int X , int Y){
    return FindSet(X) == FindSet(Y);
    return false;
}

int Joint(int X , int Y){
    if ( !Equal(X , Y) )
        NumberOfDisjoints--;
    return Parents[FindSet(X)] = FindSet(Y);
}
bool Same(int X, int Y) {
    FOR(i , NumberOfTrees){
        if (Seen[X][i] != Seen[Y][i])
            return false;  
    }
       return true;
}

int main(int argc, char** argv) {
//   freopen("Trojan.txt", "r", stdin);
    gets(Garbage);
    sscanf(Garbage , "%d" , &TestCases);
    gets(Garbage);
    while ( TestCases-- ){
        memset(Seen , NULL , sizeof(Seen));
        gets(Garbage);
        sscanf(Garbage , "%d %d" , &NumberOfPeople , &NumberOfTrees);
        while ( gets(Garbage) && sscanf(Garbage , "%d %d" , &First , &Second) == 2 ){
            --First;--Second;
            Seen[First][Second] = 1;
        }
         FOR(i , NumberOfPeople){
            Parents[i] = i;
        }
        NumberOfDisjoints = NumberOfPeople;
        
        FOR1(i , 0 , NumberOfPeople - 1){
            FORe(j , i + 1 , NumberOfPeople){
                if ( Same(i , j))
                    Joint(i , j);
            }
        }
        
        printf("%d\n" , NumberOfDisjoints);
        if ( TestCases )
            printf("\n");
    } 
    
    return 0;
}

