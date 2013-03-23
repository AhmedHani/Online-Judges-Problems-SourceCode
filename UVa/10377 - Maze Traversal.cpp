//============================================================================
// File        : 10377 - Maze Traversal.cpp
// Author      : AHMED HANI IBRAHIM
// Copyright   : AHani
// Version     : UVa - Accepted - 0.008
// Created on September 19, 2012, 4:33 PM
//============================================================================

#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>
#include <map>
#include <algorithm>
#include <functional>
#define Max 200 + 5
#define INF 1000000000
//#define INT_MAX 2147483647
#define FOR(i, N) for( int i = 0 ; i < N ; i++ )
#define FOR1e(i, N) for( int i = 1 ; i <= N ; i++ )
#define FORe(i, N) for(int i = 0 ; i <= N ; i++ )
#define FOR1(i, N) for(int i = 1 ; i < N ; i++ )

using namespace std;

int TestCases;
int Rows, Columns, X, Y;
char Start, Order;
char Grid[Max][Max];

int main(int argc, char** argv) {
//    freopen("Trojan.txt", "r", stdin);
    scanf("%d", &TestCases);
    
    while ( TestCases-- ){
        scanf("%d %d\n", &Rows, &Columns);
        
        for ( int i = 0; i < Rows; i++ )        gets(Grid[i]);
        scanf("%d %d", &X, &Y);
//        X--;    Y--;
        Start = 'N';
        while(scanf("%c", &Order), Order != 'Q'){
            if ( Order == 'R' ){
                if ( Start == 'N' )     Start = 'E';
                else if ( Start == 'E' )        Start = 'S';
                else if ( Start == 'S' )        Start = 'W';
                else if ( Start == 'W' )        Start = 'N';
            }
            else if ( Order == 'L' ){
                if ( Start == 'N' )     Start = 'W';
                else if ( Start == 'E' )        Start = 'N';
                else if ( Start == 'S' )        Start = 'E';
                else if ( Start == 'W' )        Start = 'S';
            }
            else if ( Order == 'F' ){
                if ( Start == 'N' && X - 1 >= NULL && X - 1 < Rows && Y >= NULL && Y < Columns && Grid[X - 1][Y] != '*')    X--;
                else if ( Start == 'E' && X >= NULL && X < Rows && Y + 1 >= NULL && Y + 1 < Columns && Grid[X][Y + 1] != '*' )      Y++;
                else if ( Start == 'S' && X + 1 >= NULL && X + 1 < Rows && Y >= NULL && Y < Columns && Grid[X + 1][Y] != '*' )      X++;
                else if ( Start == 'W' && X >= NULL && X < Rows && Y - 1 >= NULL && Y - 1 < Columns && Grid[X][Y - 1] != '*' )      Y--;
            }
        }
        printf("%d %d %c\n", X + 1, Y + 1, Start);
        if ( TestCases )        puts("");
        
    }

    return 0;
}

