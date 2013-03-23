//============================================================================
// File        : 112 - Tree Summing.cpp
// Author      : AHMED HANI IBRAHIM
// Copyright   : AHani
// Version     : UVa - Accepted - 0.352
// Created on September 18, 2012, 12:09 AM
//============================================================================

#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>
//#include <map>
//#include <algorithm>
//#include <functional>
#define Max 50
#define INF 1000000000
//#define INT_MAX 2147483647
#define FOR(i, N) for( int i = 0 ; i < N ; i++ )
#define FOR1e(i, N) for( int i = 1 ; i <= N ; i++ )
#define FORe(i, N) for(int i = 0 ; i <= N ; i++ )
#define FOR1(i, N) for(int i = 1 ; i < N ; i++ )

using namespace std;

int Value, Left, Right, FirstChild, SecondChild;
string Line;
bool Answer;
char Sympol;


int Tree(int Start, int Sum){
    
    if ( Line[Start + 1] == ')' )       return -1;
    char CNumber[50];
    int Index = NULL;
    Start++;
    
    while ( Line[Start] != '(' ){
        CNumber[Index] = Line[Start];
        Index++;        Start++;
    }
    CNumber[Index] = NULL;
    int Number = atoi(CNumber);
    int FirstChild, SecondChild;
    int CounterLeft, CounterRight = NULL;
    FirstChild = Start++;
    CounterLeft = 1;
    
    while ( CounterLeft != CounterRight ){
        if (Line[Start] == '(')       CounterLeft++;
        else if (Line[Start] == ')')    CounterRight++;
        Start++;
    }
    SecondChild  = Start++;
    CounterRight = NULL;
    CounterLeft  = 1;
    
    
    while ( CounterLeft != CounterRight ){
        if (Line[Start] == '(')       CounterLeft++;
        else if (Line[Start] == ')')    CounterRight++;
        Start++;
    }
    int A = Tree(FirstChild, Sum + Number);
    int B = Tree(SecondChild, Sum + Number);
    
    if ( A == -1 && B == -1 && Sum + Number == Value )     Answer = true;
    return 0; 
    
}

int main(int argc, char** argv) {
//    freopen("Trojan.txt", "r", stdin);
    
    while ( scanf("%d", &Value) != EOF ){
        Answer = false;
        
        while ( scanf("%c", &Sympol) && Sympol != '(' );
        Left = 1;
        Right = NULL;
        Line = "(";
        
        while ( Left != Right ){
            cin >> Sympol;
            if ( Sympol == '(' )        Left++;
            else if ( Sympol == ')' )        Right++;
            if ( Sympol != ' ' )        Line += Sympol;
        }
        Tree(NULL, NULL);
        if ( Answer == true )   puts("yes");
        else    puts("no");
        
        
    }
   

    return 0;
}

