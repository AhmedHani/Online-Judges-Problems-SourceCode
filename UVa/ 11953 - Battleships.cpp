//============================================================================
// File        : main.cpp
// Author      : AHMED HANI IBRAHIM
// Copyright   : AHani
// Version     : 
// 
//============================================================================

#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>
#include <map>
#include <algorithm>
#include <queue>
#define Max 600 + 5
#define INF 1000000000
//#define INT_MAX 2147483647
#define FOR(i, N) for( int i = 0 ; i < N ; i++ )
#define FOR1e(i, N) for( int i = 1 ; i <= N ; i++ )
#define FORe(i, N) for(int i = 0 ; i <= N ; i++ )
#define FOR1(i, N) for(int i = 1 ; i < N ; i++ )

using namespace std;

char Field[Max][Max];
int TestCases, N;

void FloodFill(int X, int Y){
  Field[X][Y] = '.';

  if (Field[X + 1][Y] == 'x' || Field[X + 1][Y] == '@')     FloodFill(X + 1, Y);
  if (Field[X][Y + 1] == 'x' || Field[X][Y + 1] == '@')     FloodFill(X, Y + 1);
  if (Field[X - 1][Y] == 'x' || Field[X - 1][Y] == '@')     FloodFill(X - 1, Y);
  if (Field[X][Y - 1] == 'x' || Field[X][Y - 1] == '@')     FloodFill(X, Y - 1);
}

int main() {
    freopen("Trojan.txt", "r", stdin);
    int Cases = 1;
    scanf("%d", &TestCases);

    while(TestCases--) {
    scanf("%d", &N);
    FOR1e(i, N) FOR1e(j, N)  cin >> Field[i][j];
    int Result = 0;

    FOR1e(i, N) {
      FOR1e(j, N) {
        if (Field[i][j] == 'x') {
          Result++;
          FloodFill(i, j);
        }
      }
    }

    cout << "Case " << Cases++ << ": " << Result << endl;
  }

  return 0;
}
