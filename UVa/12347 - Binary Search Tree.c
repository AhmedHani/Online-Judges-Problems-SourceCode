/* 
 * File:   12347 - Binary Search Tree.c
 * Author: ahani
 *
 * Created on June 28, 2013, 3:10 AM
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#define max(a, b) a > b ? a : b
#define min(a, b) a > b ? b : a
#define LL long long

int Values;
int PreOrder[10000 + 5];
int PostOrder[10000 + 5];
int Index1, Inddex2;
int ii, Tmp;

void Solve(int i, int j) {
    int Next = i + 1;
    while(Next < j && PreOrder[Next] < PreOrder[i]) Next++;
    if(i + 1 < Next)    Solve(i + 1, Next);
    if(j > Next)        Solve(Next, j);
    PostOrder[Inddex2++] = PreOrder[i];
}

int main(int argc, char** argv) {
    
    Index1 = Inddex2 = 0;
    for(Tmp = 0; scanf("%d", &Tmp) != EOF; PreOrder[Index1++] = Tmp);
    Solve(0, Index1);
    for(ii = 0; ii < Inddex2; ii++)     printf("%d\n", PostOrder[ii]);
    
    return (EXIT_SUCCESS);
}

