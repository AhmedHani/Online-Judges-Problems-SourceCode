//============================================================================
// File        : main.cpp
// Author      : AHMED HANI IBRAHIM
// Copyright   : AHani
// Version     : 
// Created on February 3, 2013, 10:07 AM
//============================================================================

#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>
#include <map>
#include <algorithm>
#include <functional>
#define Max 20000 + 5
#define INF 1000000000
//#define INT_MAX 2147483647
#define FOR(i, N) for( int i = 0 ; i < N ; i++ )
#define FOR1e(i, N) for( int i = 1 ; i <= N ; i++ )
#define FORe(i, N) for(int i = 0 ; i <= N ; i++ )
#define FOR1(i, N) for(int i = 1 ; i < N ; i++ )

using namespace std;

int N, M, Counter[Max];
string S[Max];

int main(int argc, char** argv) {
   // freopen("Trojan.txt", "r", stdin);

	while(cin>> N >> M){
		
		if(N == 0) break;

		FOR(i, N) cin >> S[i];
		sort(S, S + N);

		int Pos = 0;
		fill(Counter, Counter + N, 0);

		while(Pos < N){
			int tmp = Pos;
			while(Pos < N && S[Pos] == S[Tmp]) ++Pos;
			++Counter[Pos - Tmp - 1];
		}

		FOR(i, N) cout << Counter[i] << endl;
	}

    return 0;
}

