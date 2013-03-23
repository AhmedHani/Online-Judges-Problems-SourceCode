//============================================================================
// File        : 10152 - ShellSort.cpp
// Author      : AHMED HANI IBRAHIM
// Copyright   : AHani
// Version     : UVa - Accepted - 0.852
// Created on October 24, 2012, 3:03 PM
//============================================================================

#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <queue>
#define Max 200 + 5
#define INF 1000000000
//#define INT_MAX 2147483647
#define FOR(i, N) for( int i = 0 ; i < N ; i++ )
#define FOR1e(i, N) for( int i = 1 ; i <= N ; i++ )
#define FORe(i, N) for(int i = 0 ; i <= N ; i++ )
#define FOR1(i, N) for(int i = 1 ; i < N ; i++ )

using namespace std;

int TestCases;
int NumberOfTurtels;
string Line;
string li;
map <string, bool> Token;

int main(int argc, char** argv) {
   // freopen("Trojan.txt", "r", stdin);
    scanf("%d", &TestCases);
    while(TestCases--) {
        scanf("%d", &NumberOfTurtels);
        cin.ignore();
        vector <string> First;
        vector <string> Second;
        
        FOR(i, NumberOfTurtels) {
            getline(cin, Line);
            First.push_back(Line);
        }
        FOR(i, NumberOfTurtels) {
            getline(cin, Line);
            Second.push_back(Line);
        }
        vector <string>::iterator itf = First.end() - 1;
        vector <string>::iterator its = Second.end() - 1;
        Token.clear();
        vector <string> Result;
        
        while(its != Second.begin() - 1) {
            if(*its == *itf) {
                its--;
                itf--;
            } else {
                if(Token[*its] == true) {
                    while(itf != First.begin()) {
                        Token[*itf] = true;
                        First.erase(itf);
                        itf--;
                    }
                    Token[First[0]] = true;
                    
                    while(its != Second.begin()) {
                        Result.push_back(*its);
                        its--;
                    }
                    Result.push_back(Second[0]);
                    break;
                } else {
                    while(*itf != *its) {
                        Token[*itf] = true;
                        First.erase(itf);
                        itf--;
                    }
                }
                its--;
            }
        }
        FOR(i, Result.size())   cout << Result[i] << endl;
        puts("");
        
    }

    return 0;
}
