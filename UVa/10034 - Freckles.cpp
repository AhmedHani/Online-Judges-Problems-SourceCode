//============================================================================
// File        : 10034 - Freckles.cpp
// Author      : AHMED HANI IBRAHIM
// Copyright   : AHani
// Version     : UVa - Accepetd - 0.016
// Created on September 19, 2012, 8:32 PM
//============================================================================

#include <cstdlib>
#include <stdio.h>
//#include <string.h>
//#include <string>
//#include <iostream>
#include <cmath>
#include <algorithm>
#include <functional>
#define Max 10000
#define INF 1000000000
//#define INT_MAX 2147483647
#define FOR(i, N) for( int i = 0 ; i < N ; i++ )
#define FOR1e(i, N) for( int i = 1 ; i <= N ; i++ )
#define FORe(i, N) for(int i = 0 ; i <= N ; i++ )
#define FOR1(i, N) for(int i = 1 ; i < N ; i++ )

using namespace std;

int TestCases, NumberOfFreckles;
int Parents[Max];
double Vertex[Max][2];
double Result;

typedef struct Edges{
    int First;
    int Second;
    double Distance;
}E;

int FindSet(int i){
    return Parents[i] == i ? i : (Parents[i] = FindSet(Parents[i]));
}

int Equal(int X , int Y){
    return FindSet(X) == FindSet(Y);
}

void Joint(int X , int Y){
        Parents[FindSet(X)] = FindSet(Y);
}

double Calculation(double X1, double Y1, double X2, double Y2){
    return sqrt((X1 - X2) * (X1 - X2) + (Y1 - Y2) * (Y1 - Y2));
}

bool Compare(Edges X, Edges Y){
    if(X.Distance < Y.Distance)   return true;
    else        return false;
}


int main(int argc, char** argv) {
    freopen("Trojan.txt", "r", stdin);
    E AllEdges[Max];
    scanf("%d", &TestCases);
    while ( TestCases-- ){
        int Index = NULL;
        scanf("%d", &NumberOfFreckles);
        
        FOR(i, NumberOfFreckles){
            scanf("%lf %lf", Vertex[i], Vertex[i] + 1);
        }
        for (int i = 0; i < NumberOfFreckles; i++)
            for (int j = i + 1; j < NumberOfFreckles; j++){
                AllEdges[Index].First    = i;
                AllEdges[Index].Second   = j;
                AllEdges[Index].Distance = Calculation(Vertex[i][0], Vertex[i][1], Vertex[j][0], Vertex[j][1]);
                Index++;
            }
        sort(AllEdges, AllEdges + Index, Compare);
        Result = NULL;
        
        FOR(i, NumberOfFreckles)        Parents[i] = i;
        int Done = NULL;
        
        for ( int i = 0; i < Index && Done < NumberOfFreckles - 1; i++ ){
            if ( !Equal(AllEdges[i].First, AllEdges[i].Second) ){
                Result += AllEdges[i].Distance;
                Joint(AllEdges[i].First, AllEdges[i].Second);
                Done++;
            }
        }
        printf("%.2lf\n", Result);
        if ( TestCases )        puts("");
    }

    return 0;
}

