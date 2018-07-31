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
	int findLengthOfLCIS(vector<int>& nums) {

		int length = 1;

		if (nums.size() == 0)
			return 0;

		if (nums.size() == 1)
			return 1;

		vector<int> ans;

		for(int i = 0; i < nums.size() - 1; i++)
		{
			if (nums[i + 1] > nums[i]) {
				length++;
			}else {
				ans.push_back(length);
				length = 1;
			}			
		}

		if(length != 1)
		{
			ans.push_back(length);
		}
		sort(ans.begin(), ans.end());
		return ans[ans.size() - 1];
	}
};


int main()
{
	vector<int> nums = { 1,3,5,4,2,3,4,5 };
	Solution s;
	int ans = s.findLengthOfLCIS(nums);
	cout << ans << endl;
	return 0;
}