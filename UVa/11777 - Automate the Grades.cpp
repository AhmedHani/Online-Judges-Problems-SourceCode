//============================================================================
// File        : main.cpp
// Author      : AHMED HANI IBRAHIM
// Copyright   : AHani
// Version     : 
// Created on March 20, 2013, 7:13 PM
//============================================================================
 
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>
#include <map>
#include <algorithm>
#include <deque>
#define Max 600 + 5
#define INF 1000000000
//#define INT_MAX 2147483647
#define FOR(i, N) for( int i = 0 ; i < N ; i++ )
#define FOR1e(i, N) for( int i = 1 ; i <= N ; i++ )
#define FORe(i, N) for(int i = 0 ; i <= N ; i++ )
#define FOR1(i, N) for(int i = 1 ; i < N ; i++ )
 
using namespace std;

int mark[7];
int TestCases;
 
int main(int argc, char** argv) {
    freopen("Trojan.txt", "r", stdin);
    scanf("%d", &TestCases);
    int Cases = 1;

    while(TestCases--) {
        FOR(i, 7)       scanf("%d", &mark[i]);
        sort (mark + 4, mark + 7);
        double Sum = 0;

        FOR(i, 4)   Sum += mark[i];

        sum += ((mark[5] + mark[6]) / 2.0);
        cout << "Case " << Cases++ << ": ";

        if ( sum >= 90 )        cout<<"A";
        else if ( sum >= 80 )   cout<<"B";
        else if ( sum >= 70 )   cout<<"C";
        else if ( sum >= 60 )   cout<<"D";
        else                    cout<<"F";
        puts("");
    }
    return 0;
}
