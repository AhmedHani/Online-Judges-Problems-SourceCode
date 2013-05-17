/* 
 * File:   1237 - Expert Enough?.c
 * Author: ahani
 *
 * Created on May 17, 2013, 3:35 AM
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct Car {
    char Name[25];
    int Low, High;
}C;

C Data[100000];
int TestCases;
int Size, Query, Value;
int i, Counter;
char *Rsult;

int main(int argc, char** argv) {
    
    scanf("%d", &TestCases);
    while(TestCases-- > 0) {
        scanf("%d", &Size);
        for(i = 0; i < Size; i++) {
            scanf("%s %d %d", Data[i].Name, &Data[i].Low, &Data[i].High);
        }
        Rsult = (char*) malloc(100);
        scanf("%d", &Query);
        while(Query-- > 0) {
            Counter = 0;
            scanf("%d", &Value);
            for(i = 0; i < Size; i++) {
                if(Value >= Data[i].Low && Value <= Data[i].High) {
                    Rsult = &Data[i].Name;
                    Counter++;
                }
            }
            if(Counter != 1)    puts("UNDETERMINED");
            else                printf("%s\n", Rsult);
        }
        if(TestCases != 0)      puts("");
        free(Rsult);
    }

    return (EXIT_SUCCESS);
}

