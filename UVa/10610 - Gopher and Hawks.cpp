//============================================================================
// File        : 10610 - Gopher and Hawks
// Author      : AHMED HANI IBRAHIM
// Copyright   : AHani
// Version     : UVa - Accepted
// Created on August 8, 2013, 7:31 PM
//============================================================================

#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <set>
#include <bitset>
#include <queue>
#include <map>
#include <math.h>
#define Max 1000 + 5
#define INF 1000000000
//#define INT_MAX 2147483647
#define FOR(i, N) for( int i = 0 ; i < N ; i++ )
#define FOR1e(i, N) for( int i = 1 ; i <= N ; i++ )
#define FORe(i, N) for(int i = 0 ; i <= N ; i++ )
#define FOR1(i, N) for(int i = 1 ; i < N ; i++ )

using namespace std;

int GoverSpeed, Minuits;
char Buffer[Max];
int Index;
int Distance[Max];
double XCoord[Max], YCoord[Max];

int main(int argc, char** argv) {
  //freopen("Trojan.txt", "r", stdin);
	while(scanf("%d %d", &GoverSpeed, &Minuits) == 2) {
		if(GoverSpeed == NULL && Minuits == NULL) break;
		int Len = GoverSpeed * Minuits * 60;
		int Index = 2;
		scanf("%lf %lf", &XCoord[0], &YCoord[0]);
		scanf("%lf %lf", &XCoord[1], &YCoord[1]);
		getchar();
		while(gets(Buffer)) {
			if(strcmp(Buffer, " ") == 0 || strcmp(Buffer, "") == 0) break;
			sscanf(Buffer, "%lf %lf", &XCoord[Index], &YCoord[Index]);
			Index++;
		}
		queue<int> Q;
		memset(Distance, NULL, sizeof(Distance));
		Distance[0] = 1;
		Q.push(0);
		while(!Q.empty()) {
			int Current = Q.front();
			Q.pop();
			FOR(i, Index) {
				if(hypot(XCoord[i] - XCoord[Current], YCoord[i] - YCoord[Current]) < Len) {
					if(!Distance[i]) {
						Distance[i] = Distance[Current] + 1;
						Q.push(i);
					}
				}
			}
			if(Distance[1]) break;
		}
		if(Distance[1]) printf("Yes, visiting %d other holes.\n", Distance[1] - 2);
	    else puts("No.");
	}


	return 0;
}
