#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
using namespace std;

class Solution {
public:
	vector<string> summaryRanges(vector<int>& nums) { 
		vector<string> res;
		if (nums.size() == 1) {
			res.push_back(to_string(nums[0]));
			return res;
		}
		int index = 0;
		int i = 0;
		bool end = false;
		
		for (i = 0; i < nums.size(); i++) {
			end = false;
			res.push_back(to_string(nums[i]));
			index++;

			while (true) {
				if (i == nums.size() - 1) {
					if (abs(nums[i] - nums[i - 1]) == 1) {
						res[index - 1] += "->" + to_string(nums[i]);
					}
					break;
				}

				if (abs(nums[i] - nums[i + 1]) == 1) {
					end = true;
					i++;
				}
				else {
					if (end) {
						res[index - 1] += "->" + to_string(nums[i]);
					}
					break;
				}
			}
		}

		return res;
	}
};
