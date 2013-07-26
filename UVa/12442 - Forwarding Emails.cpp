//============================================================================
// File        : 12442 - Forwarding Emails.cpp
// Author      : AHMED HANI IBRAHIM
// Copyright   : AHani
// Version     : UVa - Accepted - 0.476
// 
//============================================================================

#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>
#include <map>
#include <algorithm>
#include <queue>
#include <vector>
#define LL long long
#define MOD 1000000007
#define Max 500000
#define FOR(i, N) for( int i = 0 ; i < N ; i++ )
#define FOR1e(i, N) for( int i = 1 ; i <= N ; i++ )
#define FORe(i, N) for(int i = 0 ; i <= N ; i++ )
#define FOR1(i, N) for(int i = 1 ; i < N ; i++ )
using namespace std;

int TestCases;
int Query, First, Second;
int Parent[Max];
vector<int> Result;
bool Visited[Max];

inline int DFS(int Source) {
    if(Visited[Source]) return 0;
    Visited[Source] = true;
    int Tmp = DFS(Parent[Source]);
    Visited[Source] = false;
    return Result[Source] = Tmp + 1;
}

int main(int argc, char** argv) {
    //freopen("Trojan.txt", "r", stdin);
    int Cases = 1;
    scanf("%d", &TestCases);
    while(TestCases-- > 0) {
        //memset(Parent, NULL, sizeof(Parent));
        //memset(Visited, false, sizeof(Visited));
        scanf("%d", &Query);
        Result = vector<int>(Max, -1);
        FOR(i, Query) {
            scanf("%d %d", &First, &Second);
            --First, --Second;
            Parent[First] = Second;
        }
        FOR(i, Query) if(Result[i] == -1) DFS(i);
        printf("Case %d: ", Cases++);
        int R = -1, Id;
        FOR(i, Result.size()) {
            if(Result[i] > R) {
                R = Result[i];
                Id = i;
            }
        }
        printf("%d\n", Id + 1);
    }

    return 0;
}
