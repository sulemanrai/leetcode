#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <functional>
#include <string>

using namespace std;

class Solution {
public:
	int pivotIndex(vector<int>& nums) {
								
		if (nums.size() == 0)
			return -1;

		int left = 0;
		int right = 0;

		for(int i = 1; i < nums.size(); ++i)
		{
			right += nums[i];
		}
		if (left == right)
			return 0;
		for (int i = 1; i < nums.size(); ++i) {
			left += nums[i - 1];
			right -= nums[i];
			if (left == right)
			{
				return i;
			}
		}

		return -1;
			
	}

};


int main()
{
	//vector<int> nums = { -1,-1,-1,-1,-1,-1 };
	//vector<int> nums =  { -1,-1,-1,1,0,1};
	//vector<int> nums = { 1, 2, 3 };
	vector<int> nums = { 1, 7, 3, 6, 5, 6 };
	//vector<int> nums = { -1,-1,0,1,0,-1 };
	Solution s;

	int ans = s.pivotIndex(nums);
	// vector<int> ans = s.plusOne(nums);
	cout << ans << endl;	
	//cout << endl;
	return 0;
}