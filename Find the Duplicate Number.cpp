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
	int findDuplicate(vector<int>& nums) {
		int ans = 0;

		unordered_map<int, int> um;
		for(int i = 0; i < nums.size(); i++)
		{
			um[nums[i]]++;
		}

		for(auto it = um.begin(); it != um.end(); ++it)
		{
			if(it->second > 1)
			{
				ans = it->first;
				break;
			}
		}

		return ans;
	}
};


int main()
{
	
	vector<int> nums = { 3,1,3,4,2 };
		

	Solution s;

	int ans = s.findDuplicate(nums);
	cout << ans << endl;
	
	
	return 0;
}