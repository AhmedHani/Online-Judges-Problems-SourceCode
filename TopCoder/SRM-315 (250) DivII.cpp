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


class RosePetals {
public:
  int getScore(vector <int> dice) {
            int Total = 0;
            for(int i = 0; i < dice.size(); i++) {
                if(dice[i] == 3)        Total += 2;
                if(dice[i] == 5)        Total += 4;
            }
            return Total;
	}
};

