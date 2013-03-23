//============================================================================
// File        : 11629 - Ballot evaluation.cpp
// Author      : AHMED HANI IBRAHIM
// Copyright   : AHani
// Version     : UVa - Accepted - 0.068
// Created on January 30, 2013, 21:44 PM
//============================================================================

#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>
#include <map>
#include <algorithm>
#include <functional>
#define Max 30 + 5
#define INF 1000000000
//#define INT_MAX 2147483647
#define FOR(i, N) for( int i = 0 ; i < N ; i++ )
#define FOR1e(i, N) for( int i = 1 ; i <= N ; i++ )
#define FORe(i, N) for(int i = 0 ; i <= N ; i++ )
#define FOR1(i, N) for(int i = 1 ; i < N ; i++ )

using namespace std;

char Name[Max];
int First, Second;
int Integer, Frac, Value;
int Sum;
//bool Result;
char Operator[Max];
map<string, int> Map;

int main(int argc, char** argv) {
   // freopen("Trojan.txt", "r", stdin);
    int Cases = 1;
    while(scanf("%d %d", &First, &Second) == 2) {
        Map.clear();
        FOR(i, First) {
            scanf("%s %d.%d", Name, &Integer, &Frac);
            Map[Name] = Integer * 10 + Frac;
        }
        FOR(i, Second) {
            Sum = 0;
            bool Result;
            while(true) {
                scanf("%s %s", Name, Operator);
                Sum += Map[Name];
                if(*Operator == '+')    continue;
                scanf("%d", &Value);
                Value = Value * 10;
                if(*Operator == '>') {
                    if(*(Operator + 1) == '=')  Result = (Sum >= Value);
                    else                        Result = (Sum > Value);
                } else if(*Operator == '<') {
                    if(*(Operator + 1) == '=')  Result = (Sum <= Value);
                    else                        Result = (Sum < Value);
                } else                          Result = (Sum == Value);
                
                if(Result)      printf("Guess #%d was correct.\n", Cases++);
                else            printf("Guess #%d was incorrect.\n", Cases++);
                break;
            }
        }
    }
    
    return 0;
}

