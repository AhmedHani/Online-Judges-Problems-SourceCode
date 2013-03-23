//============================================================================
// File        : 423 - MPI Maelstrom.cpp
// Author      : AHMED HANI IBRAHIM
// Copyright   : AHani
// Version     : UVa - Accepted - 0.024
// Created on August 23, 2012, 1:44 AM
//============================================================================

#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include<string>
#include<iostream>
#include<map>
#include<algorithm>
#include<functional>
#define Max 200 + 5
#define INF 1000000000
//#define INT_MAX 2147483647
#define FOR(i , N) for( int i = 0 ; i < N ; i++ )
#define FOR2e(i , N) for( int i = 2 ; i <= N ; i++ )
#define FOR1e(i , N) for(int i = 1 ; i <= N ; i++ )
#define FOR1(i , N) for(int i = 1 ; i < N ; i++ )

using namespace std;

int NumberOfProcessors , Converted;
string Input;
int Distance[Max][Max];

int Conversion(string &s) {
  int Result = 0;

  for (int i = 0; i < s.size(); i++) {
    Result = Result * 10 + int(s[i] - '0');
  }

  return Result;
}

int main(int argc, char** argv) {
    freopen("Trojan.txt", "r", stdin);
    
    scanf("%d" , &NumberOfProcessors);
    
    FOR(i , Max){
        FOR(j , Max){
            Distance[i][j] = INF;
        }
    }
    
    FOR2e(i , NumberOfProcessors){
        FOR1(j , i){
            cin >> Input;
            
            if ( Input == "x" )
                continue;
            
            Converted = Conversion(Input);
            Distance[i][j] = Distance[j][i] = Converted;
        }
    }
    
    FOR(i , Max){
        Distance[i][i] = 0;
    }
    
    FOR1e(k , NumberOfProcessors){
        FOR1(i , NumberOfProcessors){
            FOR1e(j , NumberOfProcessors){
                Distance[i][j] = min(Distance[i][j] , Distance[i][k] + Distance[j][k]);
            }
        }
    }
    
    int Output = 0;
    
    FOR1e(j , NumberOfProcessors){
        Output = max(Output , Distance[1][j]);
    }
    
    printf("%d\n" , Output);

    return 0;
}

