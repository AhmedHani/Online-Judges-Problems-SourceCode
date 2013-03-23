//============================================================================
// File        : 12356 - Army Buddies.cpp
// Author      : AHMED HANI IBRAHIM
// Copyright   : AHani
// Version     : UVa - Accepted - 0.168
// Created on August 26, 2012, 4:49 PM
//============================================================================

//#include <cstdlib>
#include <stdio.h>
//#include <string.h>
//#include<string>
//#include<iostream>
//#include<map>
//#include<algorithm>
//#include<functional>
#define Max 100000 + 5
#define INF 1000000000
//#define INT_MAX 2147483647
#define FOR(i , N) for( int i = 0 ; i < N ; i++ )
#define FOR1e(i , N) for( int i = 1 ; i <= N ; i++ )
//#define FORe(i , N) for(int i = 0 ; i <= N ; i++ )
//#define FOR1(i , N) for(int i = 1 ; i < N ; i++ )

//using namespace std;

int NumberOfSoldiers , NumberOfReports;
int RightMost[Max] , LeftMost[Max];
int First , Second;

int main(int argc, char** argv) {
//    freopen("Trojan.txt", "r", stdin);
    
    while ( scanf("%d %d" , &NumberOfSoldiers , &NumberOfReports) && NumberOfReports + NumberOfSoldiers != NULL){
//        if ( NumberOfSoldiers + NumberOfSoldiers == 0 )
//            break;
        LeftMost[NULL] = RightMost[NULL] = NULL;
        
        FOR1e(i , NumberOfSoldiers){
            LeftMost[i] = i - 1;
            RightMost[i] = i + 1;
        }
        RightMost[NumberOfSoldiers] = NULL;
        
        FOR(i , NumberOfReports){
            scanf("%d %d" , &First , &Second);
            if ( LeftMost[First] == NULL )
                printf("* ");
            else
                printf("%d " , LeftMost[First]);
            if ( RightMost[Second] == NULL )
                puts("*");
            else
                printf("%d\n" , RightMost[Second]);
            
            LeftMost[RightMost[Second]] = LeftMost[First];
            RightMost[LeftMost[First]] = RightMost[Second];
        }
        
        puts("-");
       
    }

    return 0;
}

