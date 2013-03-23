//============================================================================
// File        : 11683 - Laser Sculpture.cpp
// Author      : AHMED HANI IBRAHIM
// Copyright   : AHani
// Version     : UVa - Accepted - 0.020
// Created on August 26, 2012, 3:49 AM
//============================================================================

#include <cstdlib>
#include <stdio.h>
//#include <string.h>
//#include<string>
//#include<iostream>
#include<stack>
//#include<algorithm>
//#include<functional>
//#define Max 200 + 5
//#define INF 1000000000
//#define INT_MAX 2147483647
#define FOR(i , N) for( int i = 0 ; i < N ; i++ )
#define FOR1e(i , N) for( int i = 1 ; i <= N ; i++ )
#define FORe(i , N) for(int i = 0 ; i <= N ; i++ )
#define FOR1(i , N) for(int i = 1 ; i < N ; i++ )

using namespace std;

int Height , Length , High , Result;
stack<int> Container;

int main(int argc, char** argv) {
    freopen("Trojan.txt", "r", stdin);
    
    while ( scanf("%d %d" , &Height , &Length) ){
        if ( Height == 0 || Length == 0) break;
        Container.empty();
        
        Result = 0;
        scanf("%d" , &High);
        Container.push(High);
        
        FOR1(i , Length){
            scanf("%d" , &High);
            if ( High > Container.top() )
                Result += High - Container.top();
            Container.push(High);
        }
        
        Result += Height - Container.top();
        printf("%d\n" , Result);
        
    }

    return 0;
}

