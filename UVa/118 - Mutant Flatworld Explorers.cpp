//============================================================================
// File        : 118 - Mutant Flatworld Explorers.cpp
// Author      : AHMED HANI IBRAHIM
// Copyright   : AHani
// Version     : UVa - Accepted - 0.008
// Created on August 23, 2012, 9:42 PM
//============================================================================

#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include<string>
//#include<iostream>
#include<map>
#include<algorithm>
#include<functional>
#define Max 200 + 5
#define INF 1000000000
//#define INT_MAX 2147483647
#define FOR(i , N) for( int i = 0 ; i < N ; i++ )
#define FOR1e(i , N) for( int i = 1 ; i <= N ; i++ )
#define FORe(i , N) for(int i = 0 ; i <= N ; i++ )
#define FOR1(i , N) for(int i = 1 ; i < N ; i++ )

using namespace std;

int Row , Column , XCurrent , YCurrent;
char Orientation;
char Order[Max];
bool Flag[Max][Max];
bool Check;

void Solution(char C){
    if ( Orientation == 'N' && C == 'R' )
        Orientation = 'E';
    else if ( Orientation == 'N' && C == 'L')
        Orientation = 'W';
    
    else if ( Orientation == 'S' && C == 'R' )
        Orientation = 'W';
    else if ( Orientation == 'S' && C == 'L' )
        Orientation = 'E';
    
    else if ( Orientation == 'E' && C == 'R' )
        Orientation = 'S';
    else if ( Orientation == 'E' && C == 'L' )
        Orientation = 'N';
    
    else if ( Orientation == 'W' && C == 'R' )
        Orientation = 'N';
    else if ( Orientation == 'W' && C == 'L' )
        Orientation = 'S';
    
    if ( C == 'F' ){
        switch( Orientation ){
            case 'N':
                if ( Row == YCurrent && Flag[XCurrent][YCurrent] == true )
                    break;
                else if ( Row == YCurrent && Flag[XCurrent][YCurrent] == false ){
                    Flag[XCurrent][YCurrent] = true;
                    printf("%d %d %c LOST\n" , XCurrent , YCurrent , Orientation);
                    Check = true;
                    break;
                }
                YCurrent++;
                break;
                
            case 'S':
                if ( YCurrent == 0 && Flag[XCurrent][YCurrent] == true )
                    break;
                else if ( YCurrent == 0 && Flag[XCurrent][YCurrent] == false ){
                    Flag[XCurrent][YCurrent] = true;
                    printf("%d %d %c LOST\n" , XCurrent , YCurrent , Orientation);
                    Check = true;
                    break;
                }
                YCurrent--;
                break;
                
            case 'E':
                 if ( Column == XCurrent && Flag[XCurrent][YCurrent] == true )
                    break;
                else if ( Column == XCurrent && Flag[XCurrent][YCurrent] == false ){
                    Flag[XCurrent][YCurrent] = true;
                    printf("%d %d %c LOST\n" , XCurrent , YCurrent , Orientation);
                    Check = true;
                    break;
                }
                 XCurrent++;
                 break;
                 
            case 'W':
                 if ( XCurrent == 0 && Flag[XCurrent][YCurrent] == true )
                    break;
                else if ( XCurrent == 0 && Flag[XCurrent][YCurrent] == false ){
                    Flag[XCurrent][YCurrent] = true;
                    printf("%d %d %c LOST\n" , XCurrent , YCurrent , Orientation);
                    Check = true;
                    break;
                }
                 XCurrent--;
                 
        }
    }
}

int main(int argc, char** argv) {
//    freopen("Trojan.txt", "r", stdin);
    
    memset(Flag , false , sizeof(Flag));
    
    scanf("%d %d" , &Column , &Row);
    
    while ( scanf("%d %d %c" , &XCurrent , &YCurrent , &Orientation) != EOF){
        scanf("%s" , Order);
        
        Check = false;
        
        for( int i = 0 ; Order[i] && !Check ; i++ ){
            Solution(Order[i]);
        }
        
        if ( !Check )
            printf("%d %d %c\n" , XCurrent , YCurrent , Orientation);
    }

    return 0;
}

