/* 
 * File:   11258 - String Partition.c
 * Author: ahani
 *
 * Created on June 21, 2013, 3:10 AM
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#define max(a, b) a > b ? a : b
#define LL long long

char Line[11];
int TestCases;
LL DPMemo[500];
int Length, j;

long long Solve(int Index) {
    if(DPMemo[Index] != -1)     return DPMemo[Index];
    if(Index == Length)         return 0;
    if(Line[Index] == '0')          return Solve(Index + 1);
    int Next = 1;
    LL Result = 0;
    LL Before;
    while(1) {
        Before = 0;
        for(j = Index; j < Index + Next; j++) {
            Before = Before * 10 + (Line[j] - '0');
        }
        if(Before > INT_MAX)    break;
        Result = max(Result, (int) Before + Solve(Index + Next));
        Next++;
        if(Index + Next > Length)       break;
    }
    return DPMemo[Index] = Result;
}

int main(int argc, char** argv) {
   
    scanf("%d", &TestCases);
    while(TestCases-- > 0) {
        memset(DPMemo, -1, sizeof(DPMemo));
        scanf("%s", &Line);
        Length = strlen(Line);
        printf("%lld", Solve(0));
    }

    return (EXIT_SUCCESS);
}

