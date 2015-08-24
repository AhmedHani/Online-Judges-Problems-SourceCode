#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
using namespace std;

class Solution {
public:
	bool containsNearbyDuplicate(vector<int>& nums, int k) {
		map<int, int> visited;

		for (int i = 0; i < nums.size(); i++) {
			if (visited[nums[i]] != 0) {
				if (i - (visited[nums[i]] - 1) <= k) {
					return true;
				}
			}
			visited[nums[i]] = i + 1;
		}

		return false;
	}
};
