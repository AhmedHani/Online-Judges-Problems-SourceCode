//============================================================================
// File        : 10903 - Rock-Paper-Scissors Tournament.cpp
// Author      : AHMED HANI IBRAHIM
// Copyright   : AHani
// Version     : UVa - Accepted - 1.076
// Created on September 13, 2012, 1:43 AM
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

enum All {WIN, LOSE, DRAW};
int NumberOfPlayers, Games, TotalGames;
int Player1, Player2;
string Player1Turn, Player2Turn;
int Win[Max], Lose[Max];
bool Line;

int Solve(string First, string Second){
    if ( First == "paper" ){
        if ( Second == "rock")  return WIN;
        else if ( Second == "scissors") return LOSE;
        return DRAW;
    }
    if ( First == "scissors" ){
        if ( Second == "paper")  return WIN;
        else if ( Second == "rock") return LOSE;
        return DRAW;
    }
    if ( First == "rock" ){
        if ( Second == "scissors")  return WIN;
        else if ( Second == "paper") return LOSE;
        return DRAW;
    }
    
}

int main(int argc, char** argv) {
//    freopen("Trojan.txt", "r", stdin);
    Line = false;
    
    while ( scanf("%d", &NumberOfPlayers) , NumberOfPlayers ){
        memset(Win, NULL, sizeof(Win));
        memset(Lose, NULL, sizeof(Lose));
        if ( Line )     printf("\n");   Line = true;
        
        scanf("%d", &Games);
        TotalGames = Games * (NumberOfPlayers * (NumberOfPlayers - 1) / 2);
        
        FOR(i, TotalGames){
            cin >> Player1 >> Player1Turn >> Player2 >> Player2Turn;
            
            switch( Solve(Player1Turn, Player2Turn) ){
                case WIN:
                    Win[Player1]++;
                    Lose[Player2]++;
                    break;
                case LOSE:
                    Win[Player2]++;
                    Lose[Player1]++;
                    break;
                case DRAW:
                    break;
            }
            
        }
        FOR1e(i, NumberOfPlayers){
            if ( Win[i] + Lose[i] == 0 )        printf("-\n");
            else        printf("%.3f\n", (double)Win[i]/(double)(Win[i]+Lose[i]) );
        }
        
    }
    

    return 0;
}

