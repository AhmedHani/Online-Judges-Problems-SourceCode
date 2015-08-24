#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
using namespace std;

class Solution {
public:
	int singleNumber2(vector<int>& nums) {
		map<int, int> freq;
		int target = -1;

		for (int i = 0; i < nums.size(); i++) {
			freq[nums[i]]++;
		}

		for (int i = 0; i < nums.size(); i++) {
			if (freq[nums[i]] == 1 || freq[nums[i]] == 2) {
				target = nums[i];
				break;
			}
		}

		return target;
	}
};
