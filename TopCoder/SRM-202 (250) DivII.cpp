#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;


class LetterStrings {
public:
  int sum(vector <string> s) {
            int Result = 0;
            for(int i = 0; i < s.size(); i++) {
                for(int j = s[i].size() - 1; j >= NULL; j--)
                    if(s[i][j] != '-')  Result++;
            }
            return Result;
	}
};

