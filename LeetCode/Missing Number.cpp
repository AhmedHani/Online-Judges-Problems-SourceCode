#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
using namespace std;

class Solution {
public:
	int missingNumber(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		if (nums.size() == 1) {
			if (nums[0] == 0) return 1;
			if (nums[0] == 1) return 0;
		}
		for (int i = 0; i < nums.size(); i++) {
			if (i == nums.size() - 1) {
				if (i + 1 != nums[i]) {
					return i + 1;
				}
				else if (i != nums[i])
					return i;
			}
			else if (i != nums[i])
				return i;
		}

		return -1;
	}
};
