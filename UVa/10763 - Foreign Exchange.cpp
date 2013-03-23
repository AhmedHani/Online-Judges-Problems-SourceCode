//============================================================================
// File        : 10763 - Foreign Exchange.cpp
// Author      : AHMED HANI IBRAHIM
// Copyright   : AHani
// Version     : UVa - Accepted - 0.172
// Created on September 15, 2012, 6:16 PM
//============================================================================

#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <string>
//#include <iostream>
#include <vector>
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

int Relations, First, Second;
vector<int> Container1;
vector<int> Container2;
bool Check;

int main(int argc, char** argv) {
//    freopen("Trojan.txt", "r", stdin);
    
    while ( scanf("%d", &Relations) && Relations ){
        Container1.clear();
        Container2.clear();
        Check = true;
        
        FOR1e(i, Relations){
            scanf("%d %d", &First, &Second);
            Container1.push_back(First);
            Container2.push_back(Second);
        }
        sort(Container1.begin(), Container1.end());
        sort(Container2.begin(), Container2.end());
        
        
        FOR(i, Relations){
            if ( Container1[i] != Container2[i] ){  Check = false;       break; }    
        }
        
        if ( !Check )   printf("NO\n");
        else            printf("YES\n");
    }
   
    return 0;
}

