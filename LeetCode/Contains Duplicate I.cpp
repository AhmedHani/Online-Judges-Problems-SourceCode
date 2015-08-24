#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
using namespace std;

class Solution {
public:
	bool containsDuplicate(vector<int>& nums) {
		map<int, int> freq;

		for (int i = 0; i < nums.size(); i++) {
			freq[nums[i]]++;

			if (freq[nums[i]] >= 2) {
				return true;
			}
		}

		return false;
	}
};
