#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
using namespace std;

class Solution {
public:
	bool isAnagram(string s, string t) {
		if (s.size() != t.size()) return false;
		sort(s.begin(), s.end());
		sort(t.begin(), t.end());

		return s == t;
	}
};
