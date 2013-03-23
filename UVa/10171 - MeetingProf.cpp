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
#define INT_MAX 2147483647
#define FOR(i , Case) for( int i = 0 ; i < Case ; i++ )

using namespace std;

struct Result{
    int Energy ;
    int Distance ;
    Result() : Distance(INF){}
   
};

int Case ,IntialEnergy;
char First, Second, X, Y;
int DistinationY[Max][Max] , DistinationM[Max][Max];

int main(int argc, char** argv) {
//    freopen("Trojan.txt", "r", stdin);
    
      while ( scanf("%d" , &Case)){
          if ( Case == 0 )
              break;
          
         
          FOR(i , Max){
              FOR(j , Max){
                  DistinationY[i][j] = INF;
                  DistinationM[i][j] = INF;
              }
          }
          
          
          FOR(i , Case){
              scanf("%s %s %s %s %d" , &First , &Second , &X , &Y , &IntialEnergy);
              
                      
              if (First == 'Y' ){
                  if ( Second == 'U')
                      DistinationY[ X - 'A'][ Y - 'A'] = IntialEnergy;
                  
                  else if ( Second == 'B'){
                      DistinationY [ X - 'A' ][ Y - 'A' ] = IntialEnergy;
                      DistinationY [ Y - 'A' ][ X - 'A' ] = IntialEnergy;
                  }
              }
          
          
          else if ( First == 'M' ){
                  if ( Second == 'U')
                      DistinationM[ X - 'A'][ Y - 'A'] = IntialEnergy;
                  
                  else if ( Second == 'B'){
                      DistinationM [ X - 'A' ][ Y - 'A' ] = IntialEnergy;
                      DistinationM [ Y - 'A' ][ X - 'A' ] = IntialEnergy;
                  }
              }
          }
          
          FOR(i , Max){
              DistinationY[i][i] = 0;
              DistinationM[i][i] = 0;
          }
          
          
          FOR(k , Max){
              FOR(i , Max){
                  FOR(j , Max){
                      DistinationY[i][j] = min( DistinationY[i][j] ,DistinationY[i][k] + DistinationY[k][j] );  
                      DistinationM[i][j] = min( DistinationM[i][j] ,DistinationM[i][k] + DistinationM[k][j] );
                  }
              }
          }
            
              scanf("%s %s" , &First , &Second);
              
              int YY = First - 'A';
              int MM = Second - 'A';
              Result Answer;
              
              FOR(i , Max){
                  if ( DistinationY[YY][i] == INF ||  DistinationM[MM][i] == INF )
                      continue;
                  
                  if ( DistinationY[YY][i] +  DistinationM[MM][i] < Answer.Distance){
                      Answer.Energy = i;
                      Answer.Distance = DistinationY[YY][i] +  DistinationM[MM][i];
                  }
              }
              
              if ( Answer.Distance == INF )
                  printf("You will never meet.\n");
              
              else{
                  printf("%d" , Answer.Distance);
                  FOR(i , Max){
                      if (DistinationY[YY][i] +  DistinationM[MM][i] == Answer.Distance)
                          printf(" %c" , char(i+'A'));
                  
                  }
                  printf("\n");
              }
              
      }
      
    return 0;
}
             
