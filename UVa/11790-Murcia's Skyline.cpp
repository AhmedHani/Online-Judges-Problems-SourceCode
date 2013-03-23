//============================================================================
// File        : 11790-Murcia's Skyline.cpp
// Author      : AHMED HANI IBRAHIM
// Copyright   : AHani
// Version     : UVa - Accepted - 0.112
// Created on September 2, 2012, 9:47 AM
//============================================================================

#include <cstdlib>
#include <stdio.h>
//#include <string.h>
//#include<string>
//#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
#define Max 200 + 5
//#define INF 1000000000
//#define INT_MAX 2147483647
#define FOR(i , N) for( int i = 0 ; i < N ; i++ )
//#define FOR1e(i , N) for( int i = 1 ; i <= N ; i++ )
//#define FORe(i , N) for(int i = 0 ; i <= N ; i++ )
//#define FOR1(i , N) for(int i = 1 ; i < N ; i++ )

using namespace std;

int TestCases , NumberOfBuildings;
int LDS , LIS;

int Solve(vector<int> H , vector<int> W){
    int Sum[H.size()];
    
    FOR(i , H.size()){
        Sum[i] = W[i];
        
        FOR(j , i){
            if ( H[i] < H[j] )
                Sum[i] = max(Sum[i] , Sum[j] + W[i]);
        }
    }
    return *max_element(Sum , Sum + H.size());
    
}

int main(int argc, char** argv) {
//    freopen("Trojan.txt", "r", stdin);
    int Cases = 1;
    scanf("%d" , &TestCases);
    
    while ( TestCases-- ){
        scanf("%d" , &NumberOfBuildings);
        vector<int> Width(NumberOfBuildings);
        vector<int> Height(NumberOfBuildings);
        
        FOR(i , NumberOfBuildings){
            scanf("%d" , &Height[i]);
        }
        FOR(i , NumberOfBuildings){
            scanf("%d" , &Width[i]);
        }
        
        LDS = Solve(Height , Width);
        reverse(Height.begin(), Height.end()), reverse(Width.begin(), Width.end());
        LIS = Solve(Height , Width);
        
      if (LIS >= LDS)  
          printf("Case %d. Increasing (%d). Decreasing (%d).\n", Cases++, LIS, LDS);
      else           
          printf("Case %d. Decreasing (%d). Increasing (%d).\n", Cases++, LDS, LIS);
        
    }
    
    return 0;
}

