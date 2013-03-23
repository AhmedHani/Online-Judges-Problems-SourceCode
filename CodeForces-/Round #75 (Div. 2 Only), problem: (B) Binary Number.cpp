//============================================================================
// File        : BinarySearchTree.cpp
// Author      : AHMED HANI IBRAHIM
// Copyright   : AHani
// Version     : 
// Created on December 18, 2012, 10:47 PM
//============================================================================

#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#define Max 1000000 + 5
#define INF 1000000000
//#define INT_MAX 2147483647
#define FOR(i, N) for( int i = 0 ; i < N ; i++ )
#define FOR1e(i, N) for( int i = 1 ; i <= N ; i++ )
#define FORe(i, N) for(int i = 0 ; i <= N ; i++ )
#define FOR1(i, N) for(int i = 1 ; i < N ; i++ )

using namespace std;

char Number[Max];
bool Flag;
int Result;

int main(int argc, char** argv) {
   // freopen("Trojan.txt", "r", stdin);
    gets(Number);
    Flag = Result = 0;
    int i;
    for(i = strlen(Number) - 1; i >= 1; i--) {
        if(Flag == false && Number[i] == '0')   Result++;
        else if(Flag == false && Number[i] == '1')   Result += 2, Flag = true;
        else if(Flag == true && Number[i] == '1')    Result++;
        else if(Flag == true && Number[i] == '0')    Result += 2, Flag = true;
    }
    if(Flag == true && Number[i] == '1')        Result++;
    printf("%d\n", Result);

    return 0;
}
