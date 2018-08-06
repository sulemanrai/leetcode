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

	int findUnsortedSubarray(vector<int>& nums) {

		int s = 0, e = nums.size() - 1, i, max, min, ans;

		// step 1(a) of above algo
		for(s = 0; s < nums.size() - 1; s++)
		{
			if(nums[s+1] < nums[s])
			{				
				break;
			}
		}

		if (s == nums.size() - 1)
			return 0;

		for (e = nums.size() - 1; e >=0; e--)
		{
			if (nums[e - 1] > nums[e])
			{
				break;
			}
		}

		max = nums[s];
		min = nums[s];

		for(i = s +1; i <=e; i++)
		{
			if(nums[i] > max)
			{
				max = nums[i];
			}
			if(nums[i] < min)
			{
				min = nums[i];
			}
		}

		// step 2(b) of above algo
		for (i = 0; i < s; i++)
		{
			if (nums[i] > min)
			{
				s = i;
				break;
			}
		}

		// step 2(c) of above algo
		for (i = nums.size() - 1; i >= e + 1; i--)
		{
			if (nums[i] < max)
			{
				e = i;
				break;
			}
		}
		ans = e - s + 1;
		return ans;
	}
};


int main()
{

	vector<int> nums = { 2, 6, 4, 8, 10, 9, 15 };
		

	Solution s;

	int ans = s.findUnsortedSubarray(nums);
	cout << ans << endl;
	
	return 0;
}