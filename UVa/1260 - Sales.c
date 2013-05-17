/* 
 * File:   1260 Sales.c
 * Author: ahani
 *
 * Created on May 17, 2013, 3:35 AM
 */

#include <stdio.h>
#include <stdlib.h>

int TestCases;
int* Array;
int Number;
int Sum, i, k, Counter;

int main(int argc, char** argv) {
    scanf("%d", &TestCases);
    while(TestCases-- > 0) {
        Sum = 0;
        scanf("%d", &Number);
        Array = (int*) malloc(Number + 1);
        for(i = 0; i < Number; i++) {
            scanf("%d", &Array[i]);
        }
        for(i = 0; i < Number; i++) {
            Counter = 0;
            for(k = i; k > 0; k--) {
                if(Array[i] >= Array[k - 1]) Counter++;
            }
            Sum += Counter;
        }
        printf("%d\n", Sum);
    }

    return (EXIT_SUCCESS);
}

