//============================================================================
// File        : 10337 - Flight Planner.cpp
// Author      : AHMED HANI IBRAHIM
// Copyright   : AHani
// Version     : UVa - Accepted - 0.008
// Created on September 7, 2012, 6:39 PM
//============================================================================

//#include <cstdlib>
#include <stdio.h>
#include <string.h>
//#include <string>
//#include <iostream>
//#include <map>
#include <algorithm>
//#include <functional>
#define MaxWS 10 
#define Max 1000 + 5
#define INF 1000000000
//#define INT_MAX 2147483647
#define FOR(i, N) for( int i = 0 ; i < N ; i++ )
//#define FOR1e(i, N) for( int i = 1 ; i <= N ; i++ )
//#define FORe(i, N) for(int i = 0 ; i <= N ; i++ )
#define FORg(i, N) for(int i = N ; i >= 0 ; i-- )

using namespace std;

int TestCases, Target;
int Grid[MaxWS][Max], Cost[MaxWS][Max];

unsigned int Solve(int Altitude, int Distance, int Targ){
    int Climb, Remain, Down;
    
    if ( Distance == Targ && !Altitude) return 0;
    if ( Distance == Targ || Altitude < 0 || Altitude > 9 )     return INF;
    if ( Cost[Altitude][Distance] != -1 )       return Cost[Altitude][Distance];
    
    if ( Altitude == NULL ){
        if ( Distance == Targ - 1)
            return Cost[Altitude][Distance] = 30 - Grid[Altitude][Distance] + Solve(Altitude, Distance + 1, Targ);
        else{
            Climb = 60 - Grid[Altitude][Distance] + Solve(Altitude + 1, Distance + 1, Targ);
            Remain = 30 - Grid[Altitude][Distance] + Solve(Altitude, Distance + 1, Targ);
            return Cost[Altitude][Distance] = min(Climb, Remain);
        }
    }else{
        Climb = 60 - Grid[Altitude][Distance] + Solve(Altitude + 1, Distance + 1, Targ);
        Remain = 30 - Grid[Altitude][Distance] + Solve(Altitude, Distance + 1, Targ);
        Down = 20 - Grid[Altitude][Distance] + Solve(Altitude - 1, Distance + 1, Targ);
        return Cost[Altitude][Distance] = min(min(Climb, Remain), Down);
    }
}

int main(int argc, char** argv) {
//    freopen("Trojan.txt", "r", stdin);
    
    scanf("%d", &TestCases);
    
    while ( TestCases-- ){
        scanf("%d", &Target);
        Target /= 100;
        
        FORg(i, 9)
            FOR(j, Target){
            scanf("%d",&Grid[i][j]);
        }
        memset(Cost, -1, sizeof(Cost));
        printf("%u\n\n", Solve(NULL, NULL, Target));
    }

    return 0;
}

