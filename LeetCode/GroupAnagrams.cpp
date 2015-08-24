#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
using namespace std;

class Solution {
public:
	  vector<vector<string>> groupAnagrams(vector<string>& strs) {
		  vector<vector<string>> res;
		  map<string, vector<string>> grp;

		  sort(strs.begin(), strs.end());

		  for (int i = 0; i < strs.size(); i++) {
			  string sorted = strs[i];
			  sort(sorted.begin(), sorted.end());
			  grp[sorted].push_back(strs[i]);
		  }

		  for (map<string, vector<string>>::iterator it = grp.begin(); it != grp.end(); it++) {
			  res.push_back(it->second);
		  }
		  
		return res;
	}
	};
