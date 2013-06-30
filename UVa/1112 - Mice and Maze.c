/* 
 * File:   1112 - Mice and Maze.c
 * Author: ahani
 *
 * Created on June 28, 2013, 3:10 AM
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#define Max 100 + 5
#define max(a, b) a > b ? a : b
#define min(a, b) a > b ? b : a
#define LL long long
#define FOR(i, N) for( int i = 0 ; i < N ; i++ )
#define FOR1e(i, N) for( int i = 1 ; i <= N ; i++ )
#define FORe(i, N) for(int i = 0 ; i <= N ; i++ )
#define FOR1(i, N) for(int i = 1 ; i < N ; i++ )

int TestCases;
int NumberOfCells, NumberOfExits, Timer;
int Connections;
int First, Second, Cost;
int Matrix[Max][Max];
int i, j, k;

int main(int argc, char** argv) {
    freopen("Trojan.txt", "r", stdin);
    
    scanf("%d\n", &TestCases);
    while(TestCases-- > 0) {
        for(i = 0; i < Max; i++) for(j = 0; j < Max; j++)       Matrix[i][j] = 100000000; 
        scanf("%d\n%d\n%d\n%d\n", &NumberOfCells, &NumberOfExits, &Timer, &Connections);
        NumberOfCells++;
        for(i = 0; i < Connections; i++)     scanf("%d %d %d", &First, &Second, &Cost), Matrix[First][Second] = Cost;
        
        for(k = 0; k < NumberOfCells; k++) {
            for(i = 0; i < NumberOfCells; i++) {
                for(j = 0; j < NumberOfCells; j++) {
                    Matrix[i][j] = min(Matrix[i][j], Matrix[i][k] + Matrix[k][j]);
                }
            }
        }
        int Counter = 0;
        for(i = 0; i < NumberOfCells; i++) {
            if(Matrix[i][NumberOfExits] <= Timer || i == NumberOfExits)       Counter++;
        }
        printf("%d\n", Counter);
        if(TestCases)   puts("");
    }
    
    return (EXIT_SUCCESS);
}

