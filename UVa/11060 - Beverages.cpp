//============================================================================
// File        : 11060 - Beverages.cpp
// Author      : AHMED HANI IBRAHIM
// Copyright   : AHani
// Version     : UVa - Accepted - 0.016
// Created on September 14, 2012, 9:38 PM
//============================================================================

#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>
#include <map>
#include <algorithm>
#include <functional>
#define Max 200 + 5
#define INF 1000000000
//#define INT_MAX 2147483647
#define FOR(i, N) for( int i = 0 ; i < N ; i++ )
#define FOR1e(i, N) for( int i = 1 ; i <= N ; i++ )
#define FORe(i, N) for(int i = 0 ; i <= N ; i++ )
#define FOR1(i, N) for(int i = 1 ; i < N ; i++ )

using namespace std;

int NumberOfItems, Relations;
int IncomingEdges[Max];
bool Visited[Max][Max];
bool VisSolution[Max];
bool OK;
string WordContainer[Max];
string Item, First, Second;
map<string, int> InEdges;

int main(int argc, char** argv) {
    freopen("Trojan.txt", "r", stdin);
    int Cases = 1;
    
    while ( scanf("%d", &NumberOfItems) != EOF ){
        memset(IncomingEdges, NULL, sizeof(IncomingEdges));
        memset(Visited, false, sizeof(Visited));
        memset(VisSolution, false, sizeof(VisSolution));
        InEdges.clear();
        
        FOR(i, NumberOfItems){
            cin >> Item;
            InEdges[Item] = i;
            WordContainer[i] = Item;
        }
        
        scanf("%d", &Relations);
        
        FOR(i, Relations){
            cin >> First >> Second;
            if ( !Visited[InEdges[First]][InEdges[Second]] ){
                Visited[InEdges[First]][InEdges[Second]] = true;
                IncomingEdges[InEdges[Second]]++;
            }
        }
        printf("Case #%d: Dilbert should drink beverages in this order:", Cases++);
        OK = false;
        
        while (!OK){
            OK = true;
            
            FOR(i, NumberOfItems)
                if ( !VisSolution[i] && !IncomingEdges[i] ){
                    OK = false;
                    VisSolution[i] = true;
                    
                    cout << " " << WordContainer[i];
                    FOR(j, NumberOfItems){
                        if ( Visited[i][j] )    IncomingEdges[j]--;
                    }
                    break;
                }
            
        }
        printf(".\n\n");

    }

    return 0;
}

