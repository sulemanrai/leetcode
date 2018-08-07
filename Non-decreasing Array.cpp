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

	bool checkPossibility(vector<int>& nums) {
		
		for(int i = 0; i < nums.size() - 1; i++)
		{
			if(nums[i] > nums[i + 1])
			{
				int temp = nums[i];
				nums[i] = nums[i + 1];
				if (is_sorted(nums.begin(), nums.end()))
				{
					return true;
				}

				nums[i + 1] = nums[i] = temp;
				if (is_sorted(nums.begin(), nums.end()))
				{
					return true;
				}

				return false;
			}
		}

		return true;
	}
};


int main()
{
	int temp = 0;
	vector<int> nums = { 4,2,3 };
		

	Solution s;

	bool ans = s.checkPossibility(nums);
	if (ans == true)
		cout << "true" << endl;
	else
		cout << "false" << endl;	
	
	return 0;
}