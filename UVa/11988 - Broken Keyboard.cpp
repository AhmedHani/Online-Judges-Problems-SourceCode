//============================================================================
// File        : 11988 - Broken Keyboard.cpp
// Author      : AHMED HANI IBRAHIM
// Copyright   : AHani
// Version     : UVa - Accepted - 0.300
// Created on August 27, 2012, 11:21 PM
//============================================================================

#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include<string>
#include<iostream>
#include<deque>
#include<algorithm>
//#include<functional>
#define Max 100000 + 5
#define INF 1000000000
//#define INT_MAX 2147483647
#define FOR(i , N) for( int i = 0 ; i < N ; i++ )
#define FOR1e(i , N) for( int i = 1 ; i <= N ; i++ )
#define FORe(i , N) for(int i = 0 ; i <= N ; i++ )
#define FOR1(i , N) for(int i = 1 ; i < N ; i++ )

using namespace std;

char Input[Max] , Char;
bool Home;
string CurrentPosition;
deque<string> Container;

int main(int argc, char** argv) {
//    freopen("Trojan.txt", "r", stdin);
    
    while ( gets(Input) ){
        Home = false;
        Container.clear();
        CurrentPosition.clear();
        
        for ( int i = 0 ; Char = Input[i] ; ++i ){
            
            switch(Char){
                case '[':
                    if ( Home )
                        Container.push_back(CurrentPosition);
                    else
                        Container.push_front(CurrentPosition);                    
                    Home = true;
                    CurrentPosition = "";
                    break;
                    
                case ']':
                    if ( Home && CurrentPosition != "" ){
                        Container.push_back(CurrentPosition);
                        CurrentPosition = "";
                    }
                    Home = false;
                    break;
                    
                default:
                    CurrentPosition.push_back(Char);
                    break;
            }
        }
        
        if ( CurrentPosition != "" ){
            if ( Home )
                Container.push_back(CurrentPosition);
            else
                Container.push_front(CurrentPosition);
        }
        
         while( !Container.empty() ) {
            printf("%s", Container.back().c_str());
            Container.pop_back();
        }
        printf("\n");
    }

    return 0;
}

