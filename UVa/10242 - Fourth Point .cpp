//============================================================================
// File        : 10242 - Fourth Point !!.cpp
// Author      : AHMED HANI IBRAHIM
// Copyright   : AHani
// Version     : UVa - Accepted - 0.008
// Created on February 5, 2013, 7:44 AM
//============================================================================

#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#define Max 200 + 5
#define INF 1000000000
//#define INT_MAX 2147483647
#define FOR(i, N) for( int i = 0 ; i < N ; i++ )
#define FOR1e(i, N) for( int i = 1 ; i <= N ; i++ )
#define FORe(i, N) for(int i = 0 ; i <= N ; i++ )
#define FOR1(i, N) for(int i = 1 ; i < N ; i++ )
#define BLUE 1
#define RED 2
using namespace std;

double X1, Y1, X2, Y2, X3, Y3, X4, Y4;
double X, Y;

int main(int argc, char** argv) {
    freopen("Trojan.txt", "r", stdin);
    while(scanf("%lf %lf %lf %lf %lf %lf %lf %lf", &X1, &Y1, &X2, &Y2, &X3, &Y3, &X4, &Y4) == 8) {
        
        if(X1 == X3 && Y1 == Y3) {
            X = X2 + X4 - X3;
            Y = Y2 + Y4 - Y3;
        } else if(X1 == X4 && Y1 == Y4) {
            X = X2 + X3 - X4;
            Y = Y2 + Y3 - Y4;
        } else if(X2 == X3 && Y2 == Y3) {
            X = X1 + X4 - X3;
            Y = Y1 + Y4 - Y3;
        } else {
            X = X1 + X3 - X4;
            Y = Y1 + Y3 - Y4;
        }
        printf("%.3f %.3f\n", X, Y);
    }
   
    return 0;
}

