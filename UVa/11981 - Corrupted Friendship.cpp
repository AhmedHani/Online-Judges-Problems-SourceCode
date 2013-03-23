//============================================================================
// File        : 11981 - Corrupted Friendship.cpp
// Author      : AHMED HANI IBRAHIM
// Copyright   : AHani
// Version     : UVa - Accepted - 0.488
// Created on August 26, 2012, 6:34 PM
//============================================================================

#include <cstdlib>
#include <stdio.h>
#include <string.h>
//#include<string>
//#include<iostream>
#include<vector>
#include<queue>
//#include<algorithm>
//#include<functional>
#define Max 1000000 + 5
//#define INF 1000000000
//#define INT_MAX 2147483647
#define FOR(i , N) for( int i = 0 ; i < N ; i++ )
#define FOR1e(i , N) for( int i = 1 ; i <= N ; i++ )
#define FORe(i , N) for(int i = 0 ; i <= N ; i++ )
#define FOR1(i , N) for(int i = 1 ; i < N ; i++ )

using namespace std;

bool BVisited[Max];
int CurrentEdge[Max] , SenderFriends[Max] , RecievedFriends[Max];
vector<int> AdjList[Max];
queue<int> Container;
int TestCases ,NumberOfFriends , First , Second;
long long Pair;

int main(int argc, char** argv) {
    freopen("Trojan.txt", "r", stdin);
    int Cases = 1;
    
    scanf("%d" , &TestCases);
    
    while ( TestCases -- ){
        scanf("%d" , &NumberOfFriends);

        memsetAdjList, false , sizeofAdjList
        memset(CurrentEdge , NULL , sizeof(CurrentEdge));
        memset(RecievedFriends , NULL , sizeof(RecievedFriends));
        memset(BVisited , false , sizeof(BVisited));
        
        
        SenderFriends[1] = NULL;
        
        FOR1(i , NumberOfFriends){
            scanf("%d %d" , &First , &Second);
            CurrentEdge[First]++;
            AdjList[First].push_back(Second);
            AdjList[Second].push_back(First);
        }
        
        Container.empty();
        Container.push(1);
        BVisited[1] = true;
        
        while ( !Container.empty() ){
            int QF = Container.front();
            Container.pop();
            
            FOR(i , AdjList[QF].size()){
                if ( !BVisited[AdjList[QF][i]] ){
                    SenderFriends[AdjList[QF][i]] = SenderFriends[QF] + 1;
                    Container.push(AdjList[QF][i]);
                    BVisited[AdjList[QF][i]] = true;
                }
            }
        }
        
        memset(BVisited , false , sizeof(BVisited));
        
        FOR1e(i , NumberOfFriends){
            if ( CurrentEdge[i] == NULL )
                Container.push(i);
        }
        
        while ( !Container.empty() ){
            int QF = Container.front();
            Container.pop();
            BVisited[QF] = true;
            
            FOR(i , AdjList[QF].size()){
                if ( !BVisited[AdjList[QF][i]] ){
                    RecievedFriends[AdjList[QF][i]] += RecievedFriends[QF] + 1;
                    CurrentEdge[AdjList[QF][i]]--;
                    
                    if (CurrentEdge[AdjList[QF][i]] == 0 )
                        Container.push(AdjList[QF][i]);
                }
            }
        }
        Pair = 0;
        
        FOR1e(i , NumberOfFriends){
            Pair += (NumberOfFriends - (SenderFriends[i] + RecievedFriends[i] + 1));
        }
        
        printf ("Case %d: %d ", Cases++ , NumberOfFriends - 1);
        printf("%lld\n" , Pair / 2);

        
    }

    return 0;
}

