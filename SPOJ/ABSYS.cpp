#include <iostream>
#include <string>
#include <stdio.h>
#include <cstring>
using namespace std;

int TestCases, IFirst, ISecond, IThird;
string First, Second, Third, Fourth, Fivth;

int Converter(string st) {
    int Result = NULL;
    for(int i = 0; i < st.length(); i++) {
        if(!isdigit(st[i]))     return -1;
        Result = Result * 10 + (st[i] - '0');
    }
    return Result;
}

int main(){
  // freopen("Trojan.txt", "r", stdin);
    scanf("%d", &TestCases);
    while(TestCases--) {
        cin >> First >> Second >> Third >> Fourth >> Fivth;
        IFirst = Converter(First);
        ISecond = Converter(Third);
        IThird = Converter(Fivth);
        if(IFirst < NULL)       IFirst = IThird - ISecond;
        if(ISecond < NULL)      ISecond = IThird - IFirst;
        if(IThird < NULL)       IThird = ISecond + IFirst;
        cout << IFirst << " + " << ISecond << " = " << IThird <<endl; 
    } 

return 0;
}
