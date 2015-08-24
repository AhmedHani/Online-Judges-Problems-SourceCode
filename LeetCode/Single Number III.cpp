#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
using namespace std;

class Solution {
public:
	vector<int> singleNumber3(vector<int>& nums) {
		map<int, int> freq;
		vector<int> res;

		for (int i = 0; i < nums.size(); i++) {
			freq[nums[i]]++;
		}

		int counter = 0;
		for (int i = 0; i < nums.size(); i++) {
			if (freq[nums[i]] == 1) {
				res.push_back(nums[i]);
				counter++;
			}

			if (counter == 2) break;
		}

		return res;
	}
};
