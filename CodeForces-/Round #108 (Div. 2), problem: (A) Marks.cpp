//============================================================================
// File        : main.cpp
// Author      : AHMED HANI IBRAHIM
// Copyright   : AHani
// Version     : 
// Created on December 2, 2012, 4:05 PM
//============================================================================

#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#define Max 1000 + 5
#define INF 1000000000
//#define INT_MAX 2147483647
#define FOR(i, N) for( int i = 0 ; i < N ; i++ )
#define FOR1e(i, N) for( int i = 1 ; i <= N ; i++ )
#define FORe(i, N) for(int i = 0 ; i <= N ; i++ )
#define FOR1(i, N) for(int i = 1 ; i < N ; i++ )

using namespace std;

int NumberOfStudents;
int NumberOfSubjects;
int Result;
int Subjects[Max];
string Input[Max];
bool Check;

int main(int argc, char** argv) {
  //  freopen("Trojan.txt", "r", stdin);
    scanf("%d %d", &NumberOfStudents, &NumberOfSubjects);
    Result = NULL;
    FOR(i, NumberOfStudents)    cin >> Input[i];
    FOR(i, NumberOfStudents)    FOR(j, NumberOfSubjects)        if(Subjects[j] < Input[i][j] - '0') Subjects[j] = Input[i][j] - '0';
    
    FOR(i, NumberOfStudents) {
        Check = false;
        FOR(j, NumberOfSubjects) {
            if(Input[i][j] - '0' >= Subjects[j])       Check = true;
        }
        if(Check)      Result++;
    }
            
    printf("%d\n", Result);
    
    
    return 0;
}
