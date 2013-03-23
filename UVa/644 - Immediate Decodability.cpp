//============================================================================
// File        : 644 - Immediate Decodability.cpp
// Author      : AHMED HANI IBRAHIM
// Copyright   : AHani
// Version     : UVa - Accepted - 0.100
// Created on September 8, 2012, 2:19 PM
//============================================================================

#include <cstdlib>
#include <stdio.h>
//#include <string.h>
#include <string>
#include <iostream>
#include <vector>
//#include <algorithm>
#include <cmath>
#define Max 200 + 5
//#define INF 1000000000
//#define INT_MAX 2147483647
#define FOR(i, N) for( int i = 0 ; i < N ; i++ )
#define FOR1e(i, N) for( int i = 1 ; i <= N ; i++ )
#define FORe(i, N) for(int i = 0 ; i <= N ; i++ )
#define FOR1(i, N) for(int i = 1 ; i < N ; i++ )

using namespace std;

string Input;
vector<string> Container;

int main(int argc, char** argv) {
    freopen("Trojan.txt", "r", stdin);
    int Cases = 1;
    bool End = false;
    
    while ( true ){
        Container.clear();
        bool Decodable = true;
        
        while ( cin >> Input ){
            if(cin.eof()){
        End=true;
	      break;
            }
   
            if ( Input[0] == '9' )
                break;
            Container.push_back(Input);
        }
        if ( End )
            break;
        
        FOR(i, Container.size()){
            FOR(j, Container.size()){
                if ( i != j ){
                    if ( Container[j].find(Container[i]) == 0)
                        Decodable = false;
                }
            }
        }
        
        if ( Decodable )
            printf("Set %d is immediately decodable\n", Cases++);
        else
            printf("Set %d is not immediately decodable\n", Cases++);
    }
    
   
    

    return 0;
}

