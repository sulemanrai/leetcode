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

	int findPairs(vector<int>& nums, int k) {

		// map<pair<int, int>, int> um;
		// map<pair<int, int>, int>::const_iterator itr1;
		// map<pair<int, int>, int>::const_iterator itr2;
  //
		// int count = 0;
  //
		// for (int i = 0; i < nums.size(); i++)
		// {
		// 	for (int j = i + 1; j < nums.size(); j++)
		// 	{
		// 		if (abs(nums[i] - nums[j]) == k)
		// 			count++;
		// 	}
		// }
		int count = 0;

		if (k < 0) return 0;
		unordered_map<int, int> m;
		for (int n : nums) m[n]++;

		if(k != 0)
		{
			for(auto it = m.begin(); it != m.end(); ++it)
			{
				if (m.find(it->first + k) != m.end()) {
					count++;
				}
			}
		} else
		{
			for (auto it = m.begin(); it != m.end(); ++it)
			{
				if (it->second > 1) {
					count++;
				}
			}
		}


		return count;
	}
};


int main()
{

	vector<int> nums = { 3, 1, 4, 1, 5 };
		

	Solution s;

	int ans = s.findPairs(nums, 2);
	cout << ans << endl;
	
	return 0;
}