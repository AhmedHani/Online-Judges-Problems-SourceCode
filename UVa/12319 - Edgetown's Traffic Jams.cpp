//============================================================================
// File        : 12319 - Edgetown's Traffic Jams.cpp
// Author      : AHMED HANI IBRAHIM
// Copyright   : AHani
// Version     : UVa - Accepted - 0.439
// Created on August 22, 2013, 9:19 AM
//============================================================================

#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <queue>
#define Max 500 + 5
#define MaxDirection 4
#define INF 1000000000
//#define INT_MAX 2147483647
#define FOR(i, N) for( int i = 0 ; i < N ; i++ )
#define FOR1e(i, N) for( int i = 1 ; i <= N ; i++ )
#define FORe(i, N) for(int i = 0 ; i <= N ; i++ )
#define FOR1(i, N) for(int i = 1 ; i < N ; i++ )

using namespace std;

int NumberOfInersection;
char Buffer[Max + Max + Max];
int FirstMatrix[Max][Max];
int SecondMatrix[Max][Max];
int A, B;
bool OK;

int main(int argc, char** argv) {
    
    while(scanf("%d\n", &NumberOfInersection) == 1, NumberOfInersection) {
        //FOR(i, NumberOfInersection) FOR(j, NumberOfInersection) FirstMatrix[i][j] = SecondMatrix[i][j] = INF;
        memset(FirstMatrix, 63, sizeof(FirstMatrix));
        memset(SecondMatrix, 63, sizeof(SecondMatrix));
        
        OK = true;
        FOR(i, NumberOfInersection) {
            gets(Buffer);
            for(char *C = strtok(Buffer, " "); C != NULL; C = strtok(NULL, " ")) {
                FirstMatrix[i][atoi(C) - 1] = 1;
            }
        }
        FOR(k, NumberOfInersection) {
            FOR(i, NumberOfInersection) {
                FOR(j, NumberOfInersection) {
                    FirstMatrix[i][j] = min(FirstMatrix[i][j], FirstMatrix[i][k] + FirstMatrix[k][j]);
                }
            }
        }
        FOR(i, NumberOfInersection) {
            gets(Buffer);
            for(char *C = strtok(Buffer, " "); C != NULL; C = strtok(NULL, " ")) {
                SecondMatrix[i][atoi(C) - 1] = 1;
            }
        }
        FOR(k, NumberOfInersection) {
            FOR(i, NumberOfInersection) {
                FOR(j, NumberOfInersection) {
                    SecondMatrix[i][j] = min(SecondMatrix[i][j], SecondMatrix[i][k] + SecondMatrix[k][j]);
                }
            }
        }
        scanf("%d %d", &A, &B);
        FOR(i, NumberOfInersection) {
            FOR(j, NumberOfInersection) {
                OK &= SecondMatrix[i][j] <= A * FirstMatrix[i][j] + B;
            }
        }
        puts(OK ? "Yes" : "No");
    }
    
    return (EXIT_SUCCESS);
}
