//============================================================================
// File        : 10557 - XYZZY.cpp
// Author      : AHMED HANI IBRAHIM
// Copyright   : AHani
// Version     : UVa - Accepted - 0.392
// Created on October 6, 2012, 4:47 PM
//============================================================================

//#include <cstdlib>
#include <stdio.h>
//#include <string.h>
//#include <string>
//#include <iostream>
//#include <map>
//#include <algorithm>
//#include <functional>
#define Max 10000 + 5
#define INF 1000000000
//#define INT_MAX 2147483647
#define FOR(i, N) for( int i = 0 ; i < N ; i++ )
#define FOR1e(i, N) for( int i = 1 ; i <= N ; i++ )
//#define FORe(i, N) for(int i = 0 ; i <= N ; i++ )
//#define FOR1(i, N) for(int i = 1 ; i < N ; i++ )

//using namespace std;

int NumberOfRooms, Counter, Connections, v;
int Energy;
struct Nodes { int ChangeSign; int Energy; } Nodes[Max];
struct UV { int U; int V; } Array[Max];

void BellManFord() {
    for(int i = 2; i <= NumberOfRooms; i++)
        Nodes[i].Energy = INF;
    Nodes[1].Energy = -100;
    FOR1e(i, Max){
      FOR(j, Counter){
          int U = Array[j].U;
          int V = Array[j].V;
          if(Nodes[U].Energy >= NULL)     continue;
          if(Nodes[U].Energy + Nodes[V].ChangeSign < Nodes[V].Energy)
              Nodes[V].Energy = Nodes[U].Energy + Nodes[V].ChangeSign;
           if(Nodes[NumberOfRooms].Energy < INF)
              return;
        }
    }
}

int main(int argc, char** argv) {
//    freopen("Trojan.txt", "r", stdin);
    
    while(scanf("%d", &NumberOfRooms) == 1 && NumberOfRooms != -1) {
        Counter = 0;
        FOR1e(i, NumberOfRooms) {
            scanf("%d", &Energy);
            Nodes[i].ChangeSign = -Energy;
            scanf("%d", &Connections);
            while(Connections--){
                scanf("%d", &v);
                Array[Counter].U = i;
                Array[Counter++].V = v;
            }
        }
        Nodes[1].ChangeSign = NULL;
        Nodes[NumberOfRooms].ChangeSign = NULL;
        BellManFord();
        
        if(Nodes[NumberOfRooms].Energy < INF)   puts("winnable");
        else                                    puts("hopeless");
        
        
        
        
    }

    return 0;
}

