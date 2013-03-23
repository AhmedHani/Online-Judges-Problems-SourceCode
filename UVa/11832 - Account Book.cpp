//============================================================================
// File        : 11832 - Account Book.cpp
// Author      : AHMED HANI IBRAHIM
// Copyright   : AHani
// Version     : UVa - Accepted - 1.912
// Created on September 8, 2012, 11:59 PM
//============================================================================

//#include <cstdlib>
#include <stdio.h>
#include <string.h>
//#include <string>
//#include <iostream>
//#include <map>
#include <algorithm>
//#include <functional>
#define MaxSe 40 + 1
#define MaxSum 80000 + 5
//#define Remain 40000
//#define INF 1000000000
//#define INT_MAX 2147483647
#define FOR(i, N) for( int i = 0 ; i < N ; i++ )
//#define FOR1e(i, N) for( int i = 1 ; i <= N ; i++ )
//#define FORe(i, N) for(int i = 0 ; i <= N ; i++ )
//#define FOR1(i, N) for(int i = 1 ; i < N ; i++ )

using namespace std;

int NumberOfTransaction, CashFlow;
int Sequence[MaxSe];
int Positive[MaxSe][MaxSum];
int Negative[MaxSe][MaxSum];
bool BPositive[MaxSe];
bool BNegative[MaxSe];

int Solve( int Index, int Sum, int CashF ){
    if ( Index == NumberOfTransaction )
        return Sum == CashF;
    int &NeGative = Negative[Index][Sum];
    int &PoSitive = Positive[Index][Sum];
    if ( NeGative != -1 && PoSitive != -1 )
        return NeGative || PoSitive;
    NeGative = NULL;
    PoSitive = NULL;
    
    if ( Sum + Sequence[Index] < MaxSum )
        PoSitive |= Solve(Index + 1, Sum + Sequence[Index], CashF);
    if ( Sum - Sequence[Index]  < MaxSum )
        NeGative |= Solve(Index + 1, Sum - Sequence[Index], CashF);
    if (NeGative)     BNegative[Index] = true;
    if (PoSitive)     BPositive[Index] = true;
    
    return NeGative || PoSitive;
    
}

int main(int argc, char** argv) {
    freopen("Trojan.txt", "r", stdin);
    
    while ( scanf("%d %d", &NumberOfTransaction, &CashFlow), NumberOfTransaction|CashFlow ){
        FOR(i, NumberOfTransaction){
            scanf("%d", &Sequence[i]);
        }
        memset(BPositive, false, sizeof(BPositive));
        memset(BNegative, false, sizeof(BNegative));
        memset(Positive, -1, sizeof(Positive));
        memset(Negative, -1, sizeof(Negative));
        
        if ( !Solve(NULL, NULL, CashFlow) ){
            puts("*");
        }else{
            FOR(i, NumberOfTransaction){
                if ( BNegative[i] && BPositive[i] )
                    printf("?");
                else if (BPositive[i])
                    printf("+");
                else if (BNegative[i])
                    printf("-");
            }
            puts("");
        }
            
        
        
    }

    return 0;
}

