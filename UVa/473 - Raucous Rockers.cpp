//============================================================================
// File        : main.cpp
// Author      : AHMED HANI IBRAHIM
// Copyright   : AHani
// Version     : 
// Created on October 5, 2012, 3:36 PM
//============================================================================

#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>
#include <map>
#include <algorithm>
#include <functional>
#define Max 800 
#define Maxx 100 
#define INF 1000000000
//#define INT_MAX 2147483647
#define FOR(i, N) for( int i = 0 ; i < N ; i++ )
#define FOR1e(i, N) for( int i = 1 ; i <= N ; i++ )
#define FORe(i, N) for(int i = 0 ; i <= N ; i++ )
#define FOR1(i, N) for(int i = 1 ; i < N ; i++ )

using namespace std;

int TestCases;
int NumberOfSongs, MaxiT, NumberOfDisks;
int Tracks[Max];
int DPMemo[Max][Maxx][Maxx];
char C;

int Solve(int Index, int Time, int Disks){
    if(Index > NumberOfSongs)           return 0;
    if(DPMemo[Index][Time][Disks] != -1)        return DPMemo[Index][Time][Disks];
    
    if(Time < Tracks[Index]) {
        if(Disks > NULL)    
            return DPMemo[Index][Time][Disks] = max(Solve(Index + 1, MaxiT - Tracks[Index], Disks - 1) + 1, Solve(Index + 1, Time, Disks));
        else
            return DPMemo[Index][Time][Disks] = Solve(Index + 1, Time, Disks);
    } else {
        if(Disks > NULL)
            return DPMemo[Index][Time][Disks] = max(Solve(Index + 1, Time - Tracks[Index], Disks) + 1, max(Solve(Index + 1, MaxiT - Tracks[Index], Disks - 1) + 1, Solve(Index + 1, Time, Disks)));
        else
            return DPMemo[Index][Time][Disks] = max(Solve(Index + 1, Time - Tracks[Index], Disks) + 1, Solve(Index + 1, Time, Disks));
    }
}

int main(int argc, char** argv) {
//    freopen("Trojan.txt", "r", stdin);
    scanf("%d", &TestCases);
    while(TestCases--){
        scanf("%d %d %d", &NumberOfSongs, &MaxiT, &NumberOfDisks);
      
        for(int i=1;i<=NumberOfSongs;scanf("%d%c",&Tracks[i++],&C))
        memset(DPMemo, -1, sizeof(DPMemo));
        printf("%d\n", Solve(1, NULL, NumberOfDisks));
        if(TestCases)   puts("");
    }

    return 0;
}

