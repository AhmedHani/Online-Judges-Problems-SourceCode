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


class ArrayHash {
public:
  int getHash(vector <string> input) {
            int Result = 0;
            for(int i = 0; i < input.size(); i++) {
                for(int j = 0; j < input[i].length(); j++) {
                    Result += input[i][j] - 'A' + i + j;
                }
            }
             return Result;
		
	}
};
