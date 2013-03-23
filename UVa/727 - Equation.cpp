//============================================================================
// File        : 727 - Equation.cpp
// Author      : AHMED HANI IBRAHIM
// Copyright   : AHani
// Version     : UVa - Accepted - 0.052
// Created on January 30, 2013, 20:39 PM
//============================================================================

#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>
#include <stack>
#include <algorithm>
#include <functional>
#define Max 1000 + 5
#define INF 1000000000
//#define INT_MAX 2147483647
#define FOR(i, N) for( int i = 0 ; i < N ; i++ )
#define FOR1e(i, N) for( int i = 1 ; i <= N ; i++ )
#define FORe(i, N) for(int i = 0 ; i <= N ; i++ )
#define FOR1(i, N) for(int i = 1 ; i < N ; i++ )

using namespace std;

int TestCases;
char Char;
void *Ptr;
string Result;
stack<char> Stack;

int main(int argc, char** argv) {
    //freopen("Trojan.txt", "r", stdin);
    scanf("%d", &TestCases);
    getchar();
    getchar();
    while(TestCases--) {
        stack<char> Stack;
        while(scanf("%c", &Char) != EOF && Char != '\n') {
            getchar();
            if(isdigit(Char))   printf("%c", Char);
            else if(Char == '(')        Stack.push(Char);
            else if(Char == '*' || Char == '/') {
                while(!Stack.empty() && (Stack.top() == '*' || Stack.top() == '/')) {
                    printf("%c", Stack.top());
                    Stack.pop();
                }
                Stack.push(Char);
            }
            else if(Char == '+' || Char == '-') {
                while(!Stack.empty() && (Stack.top() == '+' || Stack.top() == '-' || Stack.top() == '/' || Stack.top() == '*')) {
                    printf("%c", Stack.top());
                    Stack.pop();
                }
                Stack.push(Char);
            }
            else if(Char == ')') {
                while(Stack.top() != '(') {
                    printf("%c", Stack.top());
                    Stack.pop();
                }
                Stack.pop();
            }
        }
        while(!Stack.empty()) {
            printf("%c", Stack.top());
            Stack.pop();
        }
       puts("");
    }

    return 0;
}

