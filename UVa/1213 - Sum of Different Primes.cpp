//============================================================================
// File        : 1213 - Sum of Different Primes.cpp
// Author      : AHMED HANI IBRAHIM
// Copyright   : AHani
// Version     : UVa - Accepted - 0.160
// Created on September 13, 2012, 10:37 PM
//============================================================================

//#include <cstdlib>
#include <stdio.h>
#include <string.h>
//#include <string>
//#include <iostream>
//#include <map>
//#include <algorithm>
//#include <functional>
#define MaxS 1120 + 5
#define MaxN 14 + 5
#define MaxPN 187 
//#define INF 1000000000
//#define INT_MAX 2147483647
//#define FOR(i, N) for( int i = 0 ; i < N ; i++ )
//#define FOR1e(i, N) for( int i = 1 ; i <= N ; i++ )
//#define FORe(i, N) for(int i = 0 ; i <= N ; i++ )
//#define FOR1(i, N) for(int i = 1 ; i < N ; i++ )

//using namespace std;

int Target, NumberOfPrimes, Index;
unsigned int DPMemo[MaxS][MaxPN][MaxN];
int Primes[MaxS];
int PrimeNumbers[MaxPN];

void Seive(){
    for ( int i = 2; i * i < MaxS; i++ ){
        if ( !Primes[i] )
            for( int j = i *i; j < MaxS; j += i )
                Primes[j] = 1;
    }
}

unsigned int Solve(int Value, int Index, int Used){
    if ( Value == NULL && Used == NULL )        return 1;
    if ( Value < NULL || Index >= MaxPN || Used == NULL )       return 0;
    if ( DPMemo[Value][Index][Used] != -1 )     return DPMemo[Value][Index][Used];
    
    return DPMemo[Value][Index][Used] = Solve(Value, Index + 1, Used) + Solve(Value - PrimeNumbers[Index], Index + 1, Used - 1);
}

int main(int argc, char** argv) {
    freopen("Trojan.txt", "r", stdin);
    memset(DPMemo, -1, sizeof(DPMemo));
    memset(Primes, NULL, sizeof(Primes));
    Primes[0] = Primes[1] = 1;
    
    Seive();
    
    Index = NULL;
    
    for ( int i = 2; i < MaxS; i++ )
        if ( !Primes[i] )       PrimeNumbers[Index++] = i;
    
    while ( scanf("%d %d", &Target, &NumberOfPrimes), Target|NumberOfPrimes ){
        printf("%u\n", Solve(Target, NULL, NumberOfPrimes) );
    }
    
    

    return 0;
}

