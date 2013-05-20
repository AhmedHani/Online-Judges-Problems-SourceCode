/* 
 * File:   10635 - Prince and Princess.c
 * Author: ahani
 *
 * Created on May 20, 2013, 3:35 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define Max 250 * 250 + 5

int TestCases;
int Size, PrinceJumbs, PrincessJumbs;
int First[Max];
int Second[Max];
int Index[Max];
int LIS[Max];
int Mid, High, Low, Top;
int i, j;

int main(int argc, char** argv) {
    scanf("%d", &TestCases);
    int Cases = 1;
    while(TestCases-- > 0) {
        scanf("%d %d %d", &Size, &PrinceJumbs, &PrincessJumbs);
        ++PrinceJumbs, ++PrincessJumbs;
        for(i = 0; i < Size * Size; i++) Index[i + 1] = -1;
        Index[0] = 0;
        
        for(i = 0; i < PrinceJumbs; i++) {
            scanf("%d", &First[i]);
            Index[First[i]] = i;
        }
        for(i = 0; i < PrincessJumbs; i++) {
            scanf("%d", &Second[i]);
            Second[i] = Index[Second[i]];
        }
        Top = 0;
        
        for(i = 0; i < PrincessJumbs; i++) {
            if(Top == -1 || Second[i] > LIS[Top]) {
                LIS[++Top] = Second[i];
            } else {
                Low = 0;
                High = Top;
                Mid;
                while(Low < High) {
                    Mid = (Low + High) >> 1;
                    if(Second[i] > LIS[Mid])    Low = Mid + 1;
                    else                        High = Mid;
                }
                if(Second[i] < LIS[Low])        LIS[Low] = Second[i];
            }
        }
        printf("Case %d: %d\n", Cases++, Top + 1);
    }   
    
    return (EXIT_SUCCESS);
}
