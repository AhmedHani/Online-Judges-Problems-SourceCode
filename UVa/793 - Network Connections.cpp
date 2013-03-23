//============================================================================
// File        : 793 - Network Connections.cpp
// Author      : AHMED HANI IBRAHIM
// Copyright   : AHani
// Version     : UVa - Accepted - 0.256
// Created on August 28, 2012, 5:30 AM
//============================================================================

#include <ctype.h>
#include <stdio.h>
//#include <string.h>
//#include<string>
//#include<iostream>
//#include<map>
//#include<algorithm>
//#include<functional>
#define Max 1000000
//#define INF 1000000000
//#define INT_MAX 2147483647
#define FOR(i , N) for( int i = 0 ; i < N ; i++ )
////#define FOR1e(i , N) for( int i = 1 ; i <= N ; i++ )
//#define FORe(i , N) for(int i = 0 ; i <= N ; i++ )
//#define FOR1(i , N) for(int i = 1 ; i < N ; i++ )

//using namespace std;

int TestCases , NumberOfComputers , SuccessfulCounter , UnSuccessfulCounter;
int First , Second;
int Parents[Max];
char Order;
//bool Line;

int FindSet(int i){
    return (Parents[i] == i) ? i : (Parents[i] = FindSet(Parents[i]));
}

bool Equal(int X , int Y ){
    return FindSet(X) == FindSet(Y);
    return false;
}

void Joint(int X , int Y){
    Parents[FindSet(X)] = FindSet(Y);
}

int main(int argc, char** argv) {
//    freopen("Trojan.txt", "r", stdin);
    
    scanf("%d" , &TestCases);
    bool Line = false;
    
    while ( TestCases -- ){
        
        FOR(i , Max){
            Parents[i] = i;
        }
        
        scanf("%d" , &NumberOfComputers);
        getchar();
        SuccessfulCounter = NULL;
        UnSuccessfulCounter = NULL;
        
        while ( (Order = getchar() ) && isalpha(Order) ){
            scanf("%d %d" , &First , &Second);
            getchar();
            
            if ( Order == 'c' ){
                Joint(First , Second);
            }
            else{
                if (Equal(First , Second))
                    SuccessfulCounter++;
                else
                    UnSuccessfulCounter++;
            }
        }
        
        if (Line)
            printf("\n");
        Line = true;
        printf ("%d,%d\n", SuccessfulCounter, UnSuccessfulCounter);

    }
    

    return 0;
}

