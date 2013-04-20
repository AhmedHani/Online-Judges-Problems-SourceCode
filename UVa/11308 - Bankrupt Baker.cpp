//============================================================================
// File        : 11308 - Bankrupt Baker.cpp
// Author      : AHMED HANI IBRAHIM
// Copyright   : AHani
// Version     : UVa - Accepted - 0.316
// Created on April 20, 2013, 03:12 AM
//============================================================================

#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <functional>
#include <math.h>
#include <map>
#define Max 100000  + 5
#define INF 1000000000
//#define INT_MAX 2147483647
#define FOR(i, N) for( int i = 0 ; i < N ; i++ )
#define FOR1e(i, N) for( int i = 1 ; i <= N ; i++ )
#define FORe(i, N) for(int i = 0 ; i <= N ; i++ )
#define FOR1(i, N) for(int i = 1 ; i < N ; i++ )

using namespace std;

int TestCases;
int Budget, Queries, Cost, NumberOfRec, NumberOfRequr, X;
string Title, Ingredeint, Recipce, Requr;
map<string, int> Price;
vector<pair<int, string> > Result;

int main(int argc, char** argv) {
   //freopen("Trojan.txt","r",stdin);
    cin >> TestCases;
    cin.ignore();
    while(TestCases--) {
        Price.clear();
        Result.clear();
        getline(cin, Title);
        FOR(i, Title.length()) Title[i] = toupper(Title[i]);
        cout << Title << endl;
        
        cin >> Queries >> NumberOfRec >> Budget;
        cin.ignore();
        FOR(i, Queries) {
            cin >> Ingredeint >> Cost;
            cin.ignore();
            Price[Ingredeint] = Cost;
        }
        FOR(i, NumberOfRec) {
            getline(cin, Recipce);
            cin >> NumberOfRequr;
            Cost = 0;
            FOR(i, NumberOfRequr) {
                cin >> Requr >> X;
                cin.ignore();
                Cost += Price[Requr] * X;
            }
            if(Cost <= Budget)  Result.push_back(make_pair(Cost, Recipce));
        }
        if(Result.empty())      puts("Too expensive!");
        else {
            sort(Result.begin(), Result.end());
            FOR(i, Result.size())       cout << Result[i].second << endl;
        }
        puts("");
    }
         
    
    return 0;
}

