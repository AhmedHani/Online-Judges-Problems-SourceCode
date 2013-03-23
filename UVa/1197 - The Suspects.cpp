//============================================================================
// File        : 1197 - The Suspects.cpp
// Author      : AHMED HANI IBRAHIM
// Copyright   : AHani
// Version     : UVa - Accepeted - 0.020
// Created on August 18, 2012, 9:01 AM
//============================================================================

#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include<string>
//#include<iostream>
#include<vector>
#define MaxStudents 30000 + 5
#define MaxGroups 500 + 5
#define INF 1000000000
//#define INT_MAX 2147483647
#define FOR(i , N) for( int i = 0 ; i < N ; i++ )
#define FOR1e(i , N) for( int i = 1 ; i <= N ; i++ )
#define FORe(i , N) for(int i = 0 ; i <= N ; i++ )
#define FOR1(i , N) for(int i = 1 ; i < N ; i++ )

using namespace std;

int NumberOfStudents , NumberOfGroups ;
bool VectorOfGroup[MaxGroups] , VectorOfStudents[MaxStudents];
vector<int> Group[MaxGroups];
vector<int> Students[MaxStudents];
int Counter , Members , Value1 , Value2;


int DFS( int N ){
    
    int Sum = 1;
    VectorOfStudents[N] = true;
    
    FOR(i , Students[N].size()){
        Value1 = Students[N][i];
        VectorOfGroup[Value1] = true;
        
        FOR(j , Group[Value1].size()){
            Value2 = Group[Value1][j];
            if ( VectorOfStudents[Value2] == true)
                continue;
            
            Sum += DFS(Value2);
        }
    }
    
    return Sum;
}


int main(int argc, char** argv) {
    freopen("Trojan.txt", "r", stdin);
    
    while ( scanf("%d %d" , &NumberOfStudents , &NumberOfGroups) ){
        if ( NumberOfStudents == 0 && NumberOfGroups == 0)
            break;
        
        memset(Group , false , sizeof(Group));
        memset(Students , false , sizeof(Students));
        memset(VectorOfGroup , false , sizeof(VectorOfGroup));
        memset(VectorOfStudents , false , sizeof(VectorOfStudents));
        
        FOR(i , NumberOfGroups){
            scanf("%d" , &Counter); 
            
            while( Counter -- ){
                
                scanf("%d" , &Members);
                Group[i].push_back(Members);
                Students[Members].push_back(i);
            }
        }
        
        printf("%d\n" , DFS(0));
        
    }

    return 0;
}

