#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <functional>
#include <string>
#include <numeric>

using namespace std;

class Solution {
public:

	void rotate(vector<int>& nums, int k) {		

		if (k > nums.size())
			k = k % nums.size();

		int diff = nums.size() - k;
		int rotate_ = abs(diff);
		std::rotate(nums.begin(), nums.begin() + rotate_, nums.end());		
	}
};


int main()
{
	int temp = 0;
	vector<int> nums = { -1 };
		

	Solution s;

	s.rotate(nums, 2);

	for (int i : nums)
		cout << i << ' ';
	
	return 0;
