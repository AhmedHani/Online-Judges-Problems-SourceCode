//============================================================================
// File        : 10637 - Coprimes.cpp
// Author      : AHMED HANI IBRAHIM
// Copyright   : AHani
// Version     : UVa - Accepted - 2.792
// Created on October 5, 2012, 11:03 PM
//============================================================================

//#include <cstdlib>
#include <stdio.h>
#include <string.h>
//#include <string>
//#include <iostream>
//#include <map>
//#include <algorithm>
//#include <functional>
#define Max 30 + 5
//#define INF 1000000000
//#define INT_MAX 2147483647
#define FOR(i, N) for( int i = 0 ; i < N ; i++ )
#define FOR1e(i, N) for( int i = 1 ; i <= N ; i++ )
#define FORe(i, N) for(int i = 0 ; i <= N ; i++ )
#define FOR1(i, N) for(int i = 1 ; i < N ; i++ )

//using namespace std;

int TestCases;
int Target, Indexs;
int Partitions[Max];

int GCD(int First, int Second){
    return Second == 0 ? First : GCD(Second, First % Second);
}

bool Valid(int Index, int Number){
    FOR(i, Index){
        if(GCD(Partitions[i], Number) != 1)
            return false;
    }
    return true;
}

void Solve(int Index, int All, int Old){
    if(Index == Indexs && All == 0){
        FOR(i, Indexs - 1)      printf("%d ", Partitions[i]);
        printf("%d\n", Partitions[Indexs - 1]);
    } else {
        if(Index > Indexs || All < 0)   return;
        for(int i = Old; i <= All; i++){
            if(Valid(Index, i)){
                Partitions[Index] = i;
                Solve(Index + 1, All - i, i);
                Partitions[Index] = 0;
            }
        }
            
    }
}

int main(int argc, char** argv) {
//    freopen("Trojan.txt", "r", stdin);
    int Cases = 1;
    scanf("%d", &TestCases);
    
    while(TestCases--) {
        scanf("%d %d", &Target, &Indexs);
        memset(Partitions, NULL, sizeof(Partitions));
        printf("Case %d:\n", Cases++);
        Solve(0, Target, 1);
        
    }

    return 0;
}

