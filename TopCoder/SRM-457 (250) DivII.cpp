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


class TheSquareDivTwo {
public:
  vector <string> solve(vector <string> board) {
            vector<string> Result;
            for(int i = 0; i < board.size(); i++)       sort(board[i].begin(), board[i].end());
            for(int i = 0; i < board.size(); i++) {
                string Tmp;
                for(int j = 0; j < board.size(); j++) {
                    if(board[j][i] == 'C')      Tmp += 'C';
                    else                        Tmp += '.';
                }
                Result.push_back(Tmp);
            }
            return Result;
	}
};

