//============================================================================
// File        : 11414 - Dream.cpp
// Author      : AHMED HANI IBRAHIM
// Copyright   : AHani
// Version     : UVa - Accepted - 0.032
// Created on August 26, 2012, 9:38 PM
//============================================================================

#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include<string>
#include<iostream>
#include<map>
#include<algorithm>
#include<functional>
#define Max 10000 + 5
#define INF 1000000000
//#define INT_MAX 2147483647
#define FOR(i , N) for( int i = 0 ; i < N ; i++ )
#define FOR1e(i , N) for( int i = 1 ; i <= N ; i++ )
#define FORe(i , N) for(int i = 0 ; i <= N ; i++ )
#define FOR1(i , N) for(int i = 1 ; i < N ; i++ )

using namespace std;

int NumberOfInputs , TestCases;
int Inputs[Max];
int main() {
    freopen("Trojan.txt" , "r" , stdin);
    scanf("%d" , &TestCases);
    
  while (TestCases -- ) {
      scanf("%d" , &NumberOfInputs);
 
      FOR1e(i , NumberOfInputs){
           scanf("%d", &Inputs[i]);
      }
 
    sort(Inputs + 1, Inputs + NumberOfInputs + 1, greater<int>());
 
    int sum = 0;
    for (int i = 1; i <= NumberOfInputs; i++)
      sum += Inputs[i];
 
    if (sum % 2 != 0 || Inputs[1] >= NumberOfInputs) {
      printf("No\n");
      continue;
    }
 
    bool ok = true;
    FOR1e(k , NumberOfInputs) {
      sum = 0;
      for (int i = 1; i <= k; i++)
        sum += Inputs[i];
 
      int tmp = 0;
      for (int i = k + 1; i <= NumberOfInputs; i++)
        tmp = tmp + min(Inputs[i], k);
 
      tmp += k * (k - 1);
 
      if (sum > tmp) {
        ok = false;
        break;
      }
    }
 
    if (ok)
      printf("Yes\n");
    else
   printf("No\n");
  }
 
  return 0;
}
