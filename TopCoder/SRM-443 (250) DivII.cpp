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


class SoccerLeagues {
public:
  vector <int> points(vector <string> matches) {
            vector<int> All;
            for(int i = 0; i < matches[0].size(); i++) {
                All[0].push_back(i);
            }
            for(int i = 0; i < matches.size(); i++) {
                for(int j = 0; j < matches[i].length(); j++) {
                    if(matches[i][j] == 'W')    All[i] += 3;
                    else if(matches[i][j] == 'D')       All[i]++, All[j]++;
                    else if(matches[i][j] == 'L')       All[j] += 3;
                }
            }
            return All;
	}
};
