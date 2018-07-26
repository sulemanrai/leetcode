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

	int missingNumber(vector<int>& nums) {

		int ans = -1;

		sort(nums.begin(),nums.end());

		for(int i = 0; i < nums.size(); i++)
		{
			if(i != nums[i])
			{
				ans = i;
				break;
			}
		}

		if(ans == -1)
		{
			ans = nums.size();
		}

		return ans;
	}
};


int main()
{
	vector<int> nums = { 0, 1};
	Solution s;
	int ans = s.missingNumber(nums);
	cout << ans << endl;
	return 0;
}