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

	bool containsNearbyDuplicate(vector<int>& nums, int k) {

		//bool ans = false;
		unordered_map<int, int> um;

		for(int i = 0; i < nums.size(); i++)
		{
			if (um.count(nums[i]) == 0)
				um[nums[i]] = i;
			else if (i - um[nums[i]] <= k)
				return true;
			else
				um[nums[i]] = i;

		}
		return false;
	}
};


int main()
{

	//vector<int> nums = { 1,2,1 };
	vector<int> nums = { 1,2,3,1 };
	//vector<int> nums = { 1,0,1,1 };
	//vector<int> nums = { 1,2,3,1,2,3 };
	//vector<int> nums = { 99,99 };
	

	Solution s;

	bool  ans = s.containsNearbyDuplicate(nums, 3);
	if (ans == true)
		cout << "true" << endl;
	else
		cout << "false" << endl;
	//cout << ans << endl;	
	return 0;
}