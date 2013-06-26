/* 
 * File:  12032 - The Monkey and the Oile.c
 * Author: ahani
 *
 * Created on June 21, 2013, 3:10 AM
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#define max(a, b) a > b ? a : b
#define min(a, b) a > b ? b : a
#define LL long long

int TestCase;
int NumberOfRugns;
int* Rungs;
int Result, Maximum;
int i;

int main(int argc, char** argv) {
    
    scanf("%d", &TestCase);
    int Cases = 1;
    while(TestCase-- > 0) {
        scanf("%d", &NumberOfRugns);
        Rungs = (int*) malloc(10000000 + 10);
        Rungs[0] = 0;
        
        for(i = 1; i <= NumberOfRugns; i++) {
            scanf("%d", &Rungs[i]);
        }
        
        Maximum = INT_MIN;
        
        for(i = 1; i <= NumberOfRugns; i++) {
            int Diff = Rungs[i] - Rungs[i - 1];
            if(Diff > Maximum)  Maximum = Diff;
        }
        
        Result = Maximum;
        
        for(i = 1; i <= NumberOfRugns; i++) {
            int Diff = Rungs[i] - Rungs[i - 1];
            if(Diff == Maximum) --Maximum;
            else if(Diff > Maximum) { 
                Result++;
                break;
            } else ;
        }
        printf("Case %d: %d\n", Cases++, Result);
    }
    return (EXIT_SUCCESS);
}

