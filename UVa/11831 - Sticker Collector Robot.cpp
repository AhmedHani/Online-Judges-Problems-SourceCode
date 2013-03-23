//============================================================================
// File        : 11831 - Sticker Collector Robot.cpp
// Author      : AHMED HANI IBRAHIM
// Copyright   : AHani
// Version     : UVa - Accepted - 0.144
// Created on September 19, 2012, 2:40 PM
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

int N, M, Instructions;
char Order;
char Grid[Max][Max];
enum Directions { NORTH, SOUTH, EAST, WEST };
struct Robot{
    int Rows;
    int Columns;
    Directions Dir;
};

Directions Converter(char Dir){
    switch(Dir){
        case 'N':
            return NORTH;
        case 'S':
            return SOUTH;
        case 'L':
            return EAST;
        case 'O':
            return WEST;
    }
}
Directions Right(Directions Dir){
    switch (Dir){
        case NORTH:
            return EAST;
        case SOUTH:
            return WEST;
        case EAST:
            return SOUTH;
        case WEST:
            return NORTH;
    }
}
Directions Left(Directions Dir){
     switch (Dir){
        case NORTH:
            return WEST;
        case SOUTH:
            return EAST;
        case EAST:
            return NORTH;
        case WEST:
            return SOUTH;
    }
}

int Forward(Robot &R, int Ro, int Col){
    int Result = NULL;
    switch(R.Dir){
        case NORTH:
            if ( R.Rows > NULL && Grid[R.Rows - 1][R.Columns] != '#' ){
                R.Rows--;
            }break;
        case SOUTH:
            if ( R.Rows + 1 < Ro && Grid[R.Rows + 1][R.Columns] != '#' ){
                R.Rows++;
            }break;
        case EAST:
            if ( R.Columns + 1 < Col && Grid[R.Rows][R.Columns + 1] != '#' ){
                R.Columns++;
            }break;
        case WEST:
            if ( R.Columns > NULL && Grid[R.Rows][R.Columns - 1] != '#' ){
                R.Columns--;
            }break;
    }
    if ( Grid[R.Rows][R.Columns] == '*' ){
        Grid[R.Rows][R.Columns] = '.';
        Result = 1;
    }
    return Result;
}


int main(int argc, char** argv) {
    freopen("Trojan.txt", "r", stdin);
    
    while ( scanf("%d %d %d", &N, &M, &Instructions) ){
        if ( N == NULL && M == NULL && Instructions == NULL )   break;
        Robot R;
        int Result = NULL;
        
        FOR(i, N){
            FOR(j, M){
                cin >> Grid[i][j];
                if ( Grid[i][j] == 'N' || Grid[i][j] == 'S' || Grid[i][j] == 'L' || Grid[i][j] == 'O' ){
                    R.Rows     = i;
                    R.Columns  = j;
                    R.Dir      = Converter(Grid[i][j]);
                    Grid[i][j] = '.';
                }
            }
        }
        
        while ( Instructions-- ){
            cin >> Order;
            switch(Order){
                case 'F':
                    Result += Forward(R, N, M);
                    break;
                case 'E':
                    R.Dir  = Left(R.Dir);
                    break;
                case 'D':
                    R.Dir  = Right(R.Dir);
                    break;
            }
            
        }
        printf("%d\n", Result);
    }

    return 0;
}

