/* 
 * File:   10192 - Vacation.c
 * Author: ahani
 *
 * Created on May 18, 2013, 3:35 AM
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define Max 250

char First[Max], Second[Max];
int LCS[Max][Max];
int i, j, k;

int main(int argc, char** argv) {
    int Case = 1;
    while(gets(First) && First[0] != '#') {
        memset(LCS, NULL, sizeof(LCS));
        gets(Second);
        for(i = 0; i <= strlen(First); i++)      LCS[i][0] = 0;
        for(i = 0; i <= strlen(Second); i++)     LCS[0][i] = 0;
        
        for(i = 1; i <= strlen(First); i++) {
            for(j = 1; j <= strlen(Second); j++) {
                if (First[i - 1] == Second[j - 1])       LCS[i][j] = LCS[i - 1][j - 1] + 1;
                else if (LCS[i][j - 1] > LCS[i - 1][j])  LCS[i][j] = LCS[i][j - 1];
                else                                     LCS[i][j] = LCS[i - 1][j];
            }
        }
        printf("Case #%d: you can visit at most %d cities.\n", Case++, LCS[strlen(First)][strlen(Second)]);
    }  

    return (EXIT_SUCCESS);
}

