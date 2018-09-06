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

	int triangleNumber(vector<int>& nums) {

		int count = 0;

		for(int i = 0; i < nums.size(); i++)
		{
			for(int j = i + 1; j < nums.size(); j++)
			{
				for(int k = j + 1; k < nums.size(); k++)
				{
					if((nums[i] + nums[j] > nums[k]) && (nums[k] + nums[i] > nums[j]) && (nums[k] + nums[j] > nums[i]))
					{
						count++;
					}
				}
			}
		}

		return count;
	}
};

int main()
{	
	Solution s;

	vector<int> nums = { 2,2,3,4 };

	int ans = s.triangleNumber(nums);
	cout << ans << endl;


	return 0;
}