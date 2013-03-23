//============================================================================
// File        : main.cpp
// Author      : AHMED HANI IBRAHIM
// Copyright   : AHani
// Version     : 
// Created on January 25, 2013, 7:44 PM
//============================================================================

#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>
#include <queue>
#include <algorithm>
#include <functional>
#define Max 100000 + 5
#define INF 1000000000
//#define INT_MAX 2147483647
#define FOR(i, N) for( int i = 0 ; i < N ; i++ )
#define FOR1e(i, N) for( int i = 1 ; i <= N ; i++ )
#define FORe(i, N) for(int i = 0 ; i <= N ; i++ )
#define FOR1(i, N) for(int i = 1 ; i < N ; i++ )

using namespace std;

int Number;
int Arr[Max];
bool First, Second, Ok;

int main () {
   // freopen("Trojan.txt", "r", stdin);
        scanf("%d", &Number) ;
        FOR(i, Number)  scanf("%d", &Arr[i]);
        for(int i = 0; i < Number - 1; i++) {
            if(Arr[i] == Arr[i + 1])    continue;
            First = Second = Ok = false;
            swap(Arr[i], Arr[i + 1]);
            for(int j = 0; j < Number - 1; j++) {
                if(Arr[j] < Arr[j + 1]) First = true;
                if(Arr[j] > Arr[j + 1]) Second = true;
                if(First && Second)     break;
            }
            if(First && Second) {
                printf("%d %d", i + 1, i + 1 + 1);
                return 0;
            }
            swap(Arr[i], Arr[i + 1]);
        }
        puts("-1");
    
    
    return 0;
 
}
