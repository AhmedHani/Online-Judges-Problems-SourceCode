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


class Sortness {
public:
  double getSortness(vector <int> a) {
            double Total = 0;
            int L = a.size();
            double After, Before;
            for(int i = 0; i < L; i++) {
                
                After = Before = 0;
                for(int j = 0; j < i; j++)      if(a[i] < a[j])         Before++;
                for(int j = i + 1; j < a.size(); j++)   if(a[j] < a[i]) After++;
                Total += After + Before;
            }
            return Total /(double)a.size();
	}
};
