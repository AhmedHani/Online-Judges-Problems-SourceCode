//============================================================================
// File        : 245 - Uncompress.cpp
// Author      : AHMED HANI IBRAHIM
// Copyright   : AHani
// Version     : UVa - Accepted - 0172
// Created on May 9, 2013, 5:16 PM
//============================================================================

#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>
#include <map>
#include <algorithm>
#include <functional>
#include <list>
#include <sstream>
#define Max 200 + 5
#define INF 1000000000
//#define INT_MAX 2147483647
#define FOR(i, N) for( int i = 0 ; i < N ; i++ )
#define FOR1e(i, N) for( int i = 1 ; i <= N ; i++ )
#define FORe(i, N) for(int i = 0 ; i <= N ; i++ )
#define FOR1(i, N) for(int i = 1 ; i < N ; i++ )

using namespace std;

string Words;
int Digit;
bool Word, Number;
stringstream Sin;
list<string> W;

void TransWord() {
    W.push_back(Sin.str());
    Sin.str("");
    Word = false;
}

void TransDigit() {
    list<string>::iterator it = W.end();
    while(Digit--)      it--;
    cout << *it;
    W.push_back(*it);
    W.erase(it);
    
    Digit = 0;
    Number = false;
}

int main(int argc, char** argv) {
    //freopen("Trojan.txt", "r", stdin);   
    while(getline(cin, Words), Words != "0") {
        Word = Number = false;
        Digit = NULL;
       // W.clear();
        
        FOR(i, Words.size()) {
            char Current = Words[i];
            if(isalpha(Current)) {
                Sin << Current;
                Word = true;
            } else if(Word)     TransWord();
            
            if(Current >= '0' && Current <= '9') {
                Digit = Digit * 10, Digit += Current - '0';
                Number = true;
            } else if(Number)   TransDigit();
            
            if(!Number) cout << Current;
        }
        
        if(Word)        TransWord();
        if(Number)      TransDigit();
        puts("");
    }

    return 0;
}

