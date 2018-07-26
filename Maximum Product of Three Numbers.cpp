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

	int maximumProduct(vector<int>& nums) {
		int maxProduct = 0;

		int first = INT_MIN;
		int second = INT_MIN;
		int third = INT_MIN;

		int minimumNumber = INT_MAX;
		int secondMinimum = INT_MAX;

		for(int i = 0; i < nums.size(); i++)
		{
			if(nums[i] <= minimumNumber)
			{
				secondMinimum = minimumNumber;
				minimumNumber = nums[i];				
			} else if(nums[i] <= secondMinimum && nums[i] != minimumNumber)
			{
				secondMinimum = nums[i];
			}

			if(nums[i] > first)
			{
				third = second;
				second = first;
				first = nums[i];
			} else if(nums[i] > second)
			{
				third = second;
				second = nums[i];
			} else if (nums[i] > third)
			{
				third = nums[i];
			}
		}
		

		int a = minimumNumber * secondMinimum * first;
		int b = first * second * third;				
		maxProduct = max(a, b);

		return maxProduct;
	}
};


int main()
{
	vector<int> nums = { -1000,-1000,-1000 };
	Solution s;
	int ans = s.maximumProduct(nums);
	cout << ans << endl;
	return 0;
}