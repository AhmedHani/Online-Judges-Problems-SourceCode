//============================================================================
// File        : 231 - Testing the CATCHER.cpp
// Author      : AHMED HANI IBRAHIM
// Copyright   : AHani
// Version     : UVa - Accepted - 0.008
// Created on September 7, 2012, 9:14 PM
//============================================================================

#include <cstdlib>
#include <stdio.h>
#include <string.h>
//#include <string>
//#include <iostream>
#include <vector>
#include <algorithm>
//#include <functional>
//#define Max 200 + 5
//#define INF 1000000000
//#define INT_MAX 2147483647
#define FOR(i, N) for( int i = 0 ; i < N ; i++ )
//#define FOR1e(i, N) for( int i = 1 ; i <= N ; i++ )
//#define FORe(i, N) for(int i = 0 ; i <= N ; i++ )
//#define FOR1(i, N) for(int i = 1 ; i < N ; i++ )

using namespace std;

int N, Maximum;
vector<int> Container;


int main(int argc, char** argv) {
//    freopen("Trojan.txt", "r", stdin);
    int Cases = NULL;
    
    while ( scanf("%d", &N) && N != -1){
        if ( Cases )
            printf("\n");
        Container.clear();
        Container.push_back(N);
        
        while ( scanf("%d", &N) && N != -1)
            Container.push_back(N);
        Maximum = 1;
        int Size[Container.size()];
        
        FOR(i, Container.size()){
            Size[i] = 1;
            FOR(j, i){
                if ( Container[j] >= Container[i] )
                    Size[i] = max(Size[i], Size[j] + 1);
            }
            Maximum = max(Maximum, Size[i]);
        }
        printf("Test #%d:\n", ++Cases);
        printf("  maximum possible interceptions: %d\n", Maximum);

        
    }

    return 0;
}

