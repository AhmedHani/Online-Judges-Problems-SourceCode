//============================================================================
// File        : 10171.cpp
// Author      : AHMED HANI IBRAHIM
// Copyright   : AHani
// Version     : UVA - Accepted - 0.008
// Created on August 9, 2012, 8:57 AM
//============================================================================

#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include<iostream>
#include<algorithm>
#include<functional>
#define Max 26
#define INF 1000000000
//#define INT_MAX 2147483647
#define FOR(i , Case) for(int i = 0; i < Case; i++)

using namespace std;

struct Result {
    int Energy;
    int Distance;
    Result() : Distance(INF) {}
};

int Case ,IntialEnergy;
char First, Second, X, Y;
int DistanceY[Max][Max] , DistanceM[Max][Max];

int main(int argc, char** argv) {
     //freopen("Trojan.txt", "r", stdin);
     
      while(scanf("%d" , &Case) == 1, Case) {
          FOR(i, Max) FOR(j, Max) DistanceY[i][j] = INF, DistanceM[i][j] = INF;
       
          FOR(i, Case) {
              scanf("%s %s %s %s %d" , &First , &Second , &X , &Y , &IntialEnergy);
              if (First == 'Y'){
                  if (Second == 'U')
                      DistanceY[X - 'A'][Y - 'A'] = IntialEnergy; 
                  else if(Second == 'B') {
                      DistanceY [X - 'A'][Y - 'A'] = IntialEnergy;
                      DistanceY [Y - 'A'][X - 'A'] = IntialEnergy;
                  }
              } else if (First == 'M') {
                  if (Second == 'U')
                      DistanceM[X - 'A'][Y - 'A'] = IntialEnergy;
                  else if (Second == 'B') {
                      DistanceM [X - 'A'][Y - 'A'] = IntialEnergy;
                      DistanceM [Y - 'A'][X - 'A'] = IntialEnergy;
                  }
              }
          }
          
          FOR(i, Max) DistanceY[i][i] = 0, DistanceM[i][i] = 0;
          
          FOR(k, Max){
              FOR(i, Max){
                  FOR(j, Max){
                      DistanceY[i][j] = min(DistanceY[i][j], DistanceY[i][k] + DistanceY[k][j]);  
                      DistanceM[i][j] = min(DistanceM[i][j], DistanceM[i][k] + DistanceM[k][j]);
                  }
              }
          }
          scanf("%s %s" , &First , &Second);
          int YY = First - 'A';
          int MM = Second - 'A';
          Result Answer; 
          FOR(i , Max) {
              if(DistanceY[YY][i] == INF || DistanceM[MM][i] == INF) continue;
              if(DistanceY[YY][i] +  DistanceM[MM][i] < Answer.Distance) {
                      Answer.Energy = i;
                      Answer.Distance = DistanceY[YY][i] +  DistanceM[MM][i];
              }
          }
          if (Answer.Distance == INF) printf("You will never meet.\n");
          else {
              printf("%d" , Answer.Distance);
              FOR(i, Max)  if(DistanceY[YY][i] +  DistanceM[MM][i] == Answer.Distance) printf(" %c" , char(i + 'A'));
                  puts("");
          }
      }
    return 0;
}
    
