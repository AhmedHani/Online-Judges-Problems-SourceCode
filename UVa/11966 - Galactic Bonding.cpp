//============================================================================
// File        : 11966 - Galactic Bonding.cpp
// Author      : AHMED HANI IBRAHIM
// Copyright   : AHani
// Version     : UVa - Accepted - 0.052
// Created on August 31, 2012, 11:15 PM
//============================================================================

//#include <cstdlib>
#include <stdio.h>
//#include <string.h>
//#include<string>
//#include<iostream>
#include<cmath>
//#include<algorithm>
//#include<functional>
#define Max 1000 + 5
#define INF 1000000000
//#define INT_MAX 2147483647
#define FOR(i , N) for( int i = 0 ; i < N ; i++ )
#define FOR1e(i , N) for( int i = 1 ; i <= N ; i++ )
#define FORe(i , N) for(int i = 0 ; i <= N ; i++ )
#define FOR1(i , N) for(int i = 1 ; i < N ; i++ )

//using namespace std;

int TestCases ,NumberOfStars , NumberOfDisJoints;
double XCoordinate[Max] , YCoordinate[Max];
int Parents[Max];
double RealDistance;

int FindSet(int i){
    return Parents[i] == i ? i : (Parents[i] = FindSet(Parents[i]));
}

bool Equal(int X , int Y){
    return FindSet(X) == FindSet(Y);
    return false;
}

int Joint(int X , int Y){
    if ( !Equal(X , Y) )
        NumberOfDisJoints--;
    return Parents[FindSet(X)] = FindSet(Y);
}

 double Calculation(int X, int Y) {
    return sqrt (pow(XCoordinate[X] - XCoordinate[Y] , 2) + pow(YCoordinate[X] - YCoordinate[Y] , 2));
}

int main(int argc, char** argv) {
//    freopen("Trojan.txt", "r", stdin);
    int Cases = 1;
    
    scanf("%d" , &TestCases);
    
    while ( TestCases-- ){
        scanf("%d %lf" , &NumberOfStars , &RealDistance);
        FOR(i , NumberOfStars){
            Parents[i] = i;
        }
        
        NumberOfDisJoints = NumberOfStars;
        FOR(i , NumberOfStars){
            scanf("%lf %lf " , &XCoordinate[i] , &YCoordinate[i]);
            FOR(j , i)
                if (Calculation(i , j) <= RealDistance)
                    Joint(i , j);
        }
        printf("Case %d: %d\n" , Cases++ , NumberOfDisJoints);
    }
    

    return 0;
}

