//============================================================================
// File        : 10453 - Make Palindrome.cpp
// Author      : AHMED HANI IBRAHIM
// Copyright   : AHani
// Version     : UVa - Accepetd - 1.425
// Created on September 17, 2012, 8:03 PM
//============================================================================

#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>
#include <map>
#include <algorithm>
#include <functional>
#define Max 1000 + 1
#define INF 1000000000
//#define INT_MAX 2147483647
#define FOR(i, N) for( int i = 0 ; i < N ; i++ )
#define FOR1e(i, N) for( int i = 1 ; i <= N ; i++ )
#define FORe(i, N) for(int i = 0 ; i <= N ; i++ )
#define FOR1(i, N) for(int i = 1 ; i < N ; i++ )

using namespace std;

string Input;
string LCS, Reverse;
int DPMemo[Max][Max];
int Length;

int Solve(int First, int Second){
    if ( First >= Second )       return 0;
    if ( DPMemo[First][Second] != -1 )  return DPMemo[First][Second];
    if ( Input[First] == Input[Second] )        return DPMemo[First][Second] = Solve(First + 1, Second - 1);
    else        return DPMemo[First][Second] = min(Solve(First, Second - 1), Solve(First + 1, Second)) + 1;
    
}

void BackTrack(int First, int Second){
    if ( First >= Second){
        if ( First == Second )  LCS += Input[First];    
        return;
    }
    if ( Input[First] == Input[Second] ){
        LCS += Input[First];
        Reverse.insert(NULL, 1, Input[Second]);
        BackTrack(First + 1, Second - 1);
    }else{
        if ( 1 + Solve(First, Second - 1) < 1 + Solve(First + 1, Second) ){
            LCS += Input[Second];
            Reverse.insert(NULL, 1, Input[Second]);
            BackTrack(First, Second - 1);
        }else{
            LCS += Input[First];
            Reverse.insert(NULL, 1, Input[First]);
            BackTrack(First + 1, Second);
        }
    }
}

int main(int argc, char** argv) {
//    freopen("Trojan.txt", "r", stdin);
    
    while ( getline(cin, Input) ){
        Length = Input.length();
        memset(DPMemo, -1, sizeof(DPMemo));
        printf("%d ", Solve(NULL, Length - 1));
        LCS = "";
        Reverse = "";
        BackTrack(NULL, Length - 1);
        cout << LCS << Reverse << endl;
        
    }
    

    return 0;
}

