//============================================================================
// File        : 11489 - Integer Game.cpp
// Author      : AHMED HANI IBRAHIM
// Copyright   : AHani
// Version     : UVa - Accepted - 0.008
// Created on October 28, 2012, 2:36 PM
//============================================================================

//#include <cstdlib>
#include <stdio.h>
#include <string.h>
//#include <string>
//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <functional>
#define Max 1000 + 5
#define INF 1000000000
//#define INT_MAX 2147483647
#define FOR(i, N) for( int i = 0 ; i < N ; i++ )
#define FOR1e(i, N) for( int i = 1 ; i <= N ; i++ )
#define FORe(i, N) for(int i = 0 ; i <= N ; i++ )
#define FOR1(i, N) for(int i = 1 ; i < N ; i++ )

//using namespace std;

char Input[Max];
int Index, TestCases;
int AllwedMove[Max];
int Container[Max];
int Answer, Sum;
int Winner[] = {'T', 'S'};

int main(int argc, char** argv) {
   freopen("Trojan.txt", "r", stdin);
   int Cases = 1;
   scanf("%d", &TestCases);
   while(TestCases--) {
       scanf("%s", Input);
       memset(Container, NULL, sizeof(Container));
       Answer = NULL;
       Sum    = NULL;
       printf("Case %d: ", Cases++) ;
       for(Index = NULL; Input[Index]; Index++) {
           Container[Input[Index] - '0']++;
           Sum += (Input[Index] - '0');
       }
       AllwedMove[0] = Container[3] + Container[6] + Container[9];
       AllwedMove[1] = Container[1] + Container[4] + Container[7];
       AllwedMove[2] = Container[2] + Container[5] + Container[8];
       
       if(AllwedMove[Sum % 3]) {
           Answer = 1;
           AllwedMove[Sum % 3]--;
       }
       if(Answer)       Answer += AllwedMove[0];
       if(Index - Answer == 1)  Answer++;
       printf("%c\n", Winner[Answer & 1]);
   }
    

    return 0;
}


