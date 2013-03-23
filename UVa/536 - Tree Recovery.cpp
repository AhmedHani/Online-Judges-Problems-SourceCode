//============================================================================
// File        : 536 - Tree Recovery.cpp
// Author      : AHMED HANI IBRAHIM
// Copyright   : AHani
// Version     : UVa - Accepted - 0.008
// Created on September 20, 2012, 5:02 PM
//============================================================================

//#include <cstdlib>
#include <stdio.h>
#include <string.h>
//#include <string>
//#include <iostream>
//#include <map>
//#include <algorithm>
//#include <functional>
#define Max 200 + 5
//#define INF 1000000000
////#define INT_MAX 2147483647
//#define FOR(i, N) for( int i = 0 ; i < N ; i++ )
//#define FOR1e(i, N) for( int i = 1 ; i <= N ; i++ )
//#define FORe(i, N) for(int i = 0 ; i <= N ; i++ )
//#define FOR1(i, N) for(int i = 1 ; i < N ; i++ )
//
//using namespace std;

char PreOrder[Max];
char InOrder[Max];
int Length;

void Recovery(int i, int j, int ii, int jj){
    char Target = PreOrder[i];
    int RootPos;
    
    if ( i == j ){printf("%c", Target);   return;}
    
    for ( int k = ii; k <= jj; k++ ){
        if( InOrder[k] == Target ){
            RootPos = k;
            break;
        }
    }
    int Post = i + RootPos - ii;
    if (RootPos - 1 >= ii)
        Recovery(i + 1, Post, ii, RootPos - 1);
    if (jj >= RootPos + 1)
        Recovery(Post + 1, j, RootPos + 1, jj);
    printf("%c", Target);
    
}


int main(int argc, char** argv) {
//    freopen("Trojan.txt", "r", stdin);
    
    while ( scanf("%s %s", PreOrder, InOrder) == 2){
        Length = strlen(PreOrder) - 1;
        Recovery(NULL, Length, NULL, Length);
        puts("");
        
    }
    

    return 0;
}

