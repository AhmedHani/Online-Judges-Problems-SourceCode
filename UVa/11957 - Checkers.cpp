//============================================================================
// File        : 11957 - Checkers.cpp
// Author      : AHMED HANI IBRAHIM
// Copyright   : AHani
// Version     : UVa - Accepted - 0.016
// Created on August 21, 2012, 12:09 AM
//============================================================================

#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include<string>
//#include<iostream>
//#include<map>
//#include<algorithm>
//#include<functional>
#define Max 200 + 5
#define INF 1000000000
//#define INT_MAX 2147483647
#define FOR(i , N) for( int i = 0 ; i < N ; i++ )
#define FOR1e(i , N) for( int i = 1 ; i <= N ; i++ )
#define FORe(i , N) for(int i = 0 ; i <= N ; i++ )
#define FOR1(i , N) for(int i = 1 ; i < N ; i++ )

//using namespace std;

char Board[Max][Max];
int Path[Max][Max];
int TestCases , BoardSize;

void AllMovements( int Row , int Column ){
    Path[Row][Column] = Path[Row][Column] % 1000007;
    
    if ( Row + 1 < BoardSize && Column + 1 < BoardSize)
        if ( Board[Row + 1][Column + 1] != 'B' )
            Path[Row + 1][Column + 1] = (Path[Row + 1][Column + 1] + Path[Row][Column]) % 1000007;
    
        else 
            if ( Row + 2 < BoardSize && Column + 2 < BoardSize )
                if ( Board[Row + 2][Column + 2] != 'B' )
                    Path[Row + 2][Column + 2] = (Path[Row + 2][Column + 2] + Path[Row][Column]) % 1000007;
    
    
    if ( Row + 1 < BoardSize && Column - 1 >= 0 )
        if ( Board[Row + 1][Column - 1] != 'B' )
            Path[Row + 1][Column - 1] = (Path[Row + 1][Column - 1] + Path[Row][Column]) % 1000007;
    
        else
            if ( Row + 2 < BoardSize && Column - 2 >= 0 )
                if ( Board[Row + 2][Column - 2] != 'B' )
                    Path[Row + 2][Column - 2] = (Path[Row + 2][Column - 2] + Path[Row][Column]) % 1000007;
    
        
    
}


int main(int argc, char** argv) {
//    freopen("Trojan.txt", "r", stdin);
    int Cases = 1;
    
    scanf("%d" , &TestCases);
    
    while ( TestCases -- ){
       memset(Path , 0 , sizeof(Path));
       
       scanf("%d" , &BoardSize);
       
       FOR(i , BoardSize){
           scanf("%s" , Board[i]);
       }
       
       FOR(i , BoardSize){
           if ( Board[0][i] != 'B' )
               Path[0][i] = 1;
       }
       
       FOR(i , BoardSize){
           FOR(j , BoardSize){
               AllMovements(i , j);
           }
       }
        
       FOR(i , BoardSize){
           FOR(j , BoardSize){
               if ( Board[i][j] == 'W' )
                   printf("Case %d: %d\n" , Cases++ , (Path[i][j] % 1000007));
           }
       }
        
        
    }
    return 0;
}
    

    

