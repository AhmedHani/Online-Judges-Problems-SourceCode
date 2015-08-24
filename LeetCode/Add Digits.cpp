#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
using namespace std;

class Solution {
public:
	int addDigits(int num) {
		return num == 0 ? 0 : ((--num) % 9) + 1;
	}
};
