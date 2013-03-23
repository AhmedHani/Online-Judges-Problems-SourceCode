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


class 
  TheSimilarNumbers{
public :
	int find(int lower, int upper)
	{
		int result = 0 ;
		while(lower<=upper)
		{
			result++ ;
			lower*=10 ;
			lower++;
		}
		return result;
	}
};



<%:testing-code%>

//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!
