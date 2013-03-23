//============================================================================
// File        : 168 - Theseus and the Minotaur.cpp
// Author      : AHMED HANI IBRAHIM
// Copyright   : AHani
// Version     : UVa - Accepted - 0.464
// Created on August 22, 2012, 3:58 AM
//============================================================================

#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include<string>
#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
#define Max 300
#define INF 1000000000
//#define INT_MAX 2147483647
#define FOR(i , N) for( int i = 0 ; i < N ; i++ )
#define FOR1e(i , N) for( int i = 1 ; i <= N ; i++ )
#define FORe(i , N) for(int i = 0 ; i <= N ; i++ )
#define FOR1(i , N) for(int i = 1 ; i < N ; i++ )

using namespace std;

int K ;
string Input;
char Theseus , Minotaur;
vector<int> NodesMaze[Max];
bool Visited[Max];


int DFS(int Mino , int Thes , int Step , vector<int>NodesMaze[Max] , int k){
    
    Step = ( Step + 1 ) % k ;
    if ( Step == 0  )
        Visited[Mino] = true;
    
    FOR(i , NodesMaze[Mino].size()){
        if ( !Visited[NodesMaze[Mino][i]] && NodesMaze[Mino][i] != Thes ){
            if ( Visited[Mino] )
                printf("%c " , char(Mino));
            
            return DFS(NodesMaze[Mino][i] , Mino , Step , NodesMaze , k);
        }
    }
    printf("/%c\n" , char(Mino));
    
}


int main(int argc, char** argv) {
    freopen("Trojan.txt", "r", stdin);
    
    while ( cin >> Input && Input != "#" ){
        
        memset(Visited , false , sizeof(Visited));
        
        FOR(i , Max){
            NodesMaze[i].clear();
        }
        
//        scanf("%c %c" , Minotaur , Theseus); cin >>  K;
        cin >> Minotaur >> Theseus >> K;
        
        int Part = 0 ;
        int All[Max];
        
        FOR(i , Input.length()){
            if ( Input[i] == '.')
                break;
            if ( Input[i] == ':' || Input[i] == ';' ){
                if ( Input[i] == ':' )
                    Part = 1;
                else
                    Part = NULL;
                
            }
            else{
                All[Part] = Input[i];
                if ( Part == 1 )
                    NodesMaze[All[0]].push_back(All[1]);
            }
          
        }
        
        DFS(Minotaur, Theseus , NULL , NodesMaze , K);
        
    }

    return 0;
}

