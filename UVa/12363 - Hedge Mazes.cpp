//============================================================================
// File        : 12363 - Hedge Mazes.cpp
// Author      : AHMED HANI IBRAHIM
// Copyright   : AHani
// Version     : UVa - Accepted - 0.132 - Rank (19)
// Created on August 24, 2012, 3:01 AM
//============================================================================

#include <cstdlib>
#include <stdio.h>
#include <string.h>
//#include<string>
//#include<iostream>
#include<vector>
#include<algorithm>
//#include<functional>
#include<stack>
#define Max 10048
#define INF 1000000000
//#define INT_MAX 2147483647
#define FOR(i , N) for( int i = 0 ; i < N ; i++ )
#define FOR1e(i , N) for( int i = 1 ; i <= N ; i++ )
#define FORe(i , N) for(int i = 0 ; i <= N ; i++ )
#define FOR1(i , N) for(int i = 1 ; i < N ; i++ )
#define P pair<int,int>

using namespace std;

int NumberOfRooms , NumberOfCorridors , NumberOfQuaries;
int First , Second , Counter;
vector<int> Distance[Max];
stack<P> Results;
int Start[Max] ,End[Max] , Path[Max]; 

int Root(int A){
    return Path[A] == A ? A : Path[A] = Root(Path[A]);
}

bool Find(int First , int Second){
    Path[First = Root(First)] = Second = Root(Second);
    return First != Second;
}

void DFS(int U , int V = -1){
    End[U] = Start[U] = Counter++;
    
    FOR(i , Distance[U].size()){
        if ( Start[Distance[U][i]] == -1 ){
            Results.push(make_pair(U , Distance[U][i]));
            DFS(Distance[U][i] , U);
            
            End[U] = min(End[U] , End[Distance[U][i]]);
            
            if ( End[Distance[U][i]] == Start[Distance[U][i]]){
                Find(U , Distance[U][i]);
            }
            
        }  
        else if ( Distance[U][i] != V ){
                if (Start[Distance[U][i]] < Start[U])
                    Results.push(make_pair(U , Distance[U][i]));
                End[U] = min(End[U] , Start[Distance[U][i]]);
            }
        }
    }


int main(int argc, char** argv) {
//    freopen("Trojan.txt", "r", stdin);
    
    while ( scanf("%d %d %d" , &NumberOfRooms , &NumberOfCorridors , &NumberOfQuaries) == 3 && NumberOfRooms){
        FOR(i , NumberOfRooms){
            Distance[i].clear();
            Path[i] = i;
        }
        
        FOR(i , NumberOfCorridors){
            scanf("%d %d" , &First , &Second);
            --First; --Second;
            Distance[First].push_back(Second); Distance[Second].push_back(First);
        }
        
        memset(Start , -1 , sizeof(Start));
        FOR(i , NumberOfRooms){
            if ( Start[i] == -1 ) Counter = 0 , DFS(i);
        }
        FOR(i , NumberOfQuaries){
            scanf("%d %d" , &First , &Second);
            
             puts(Root(--First) == Root(--Second) ? "Y" : "N");
            
        }
        puts("-");
    }

    return 0;
}

