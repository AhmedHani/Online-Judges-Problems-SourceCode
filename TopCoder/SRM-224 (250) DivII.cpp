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


class InsideOut {
public:
  string unscramble(string line) {
            int L = line.size() / 2;
            string First = line.substr(0, L);
            line.erase(0, L);
            reverse(First.begin(), First.end());
            reverse(line.begin(), line.end());
            return First + line;
	}
};

