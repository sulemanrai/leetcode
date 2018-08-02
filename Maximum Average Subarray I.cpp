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

	double findMaxAverage(vector<int>& nums, int k) {

		// double ans = -INFINITY;
		// int left = 0;
		// int right = k - 1;
		// double temp = 0;
  //
		// if (nums.size() == 1)
		// 	return nums[0];
  //
		// while(right < nums.size())
		// {
		// 	for(int i = left; i <= right; i++)
		// 	{
		// 		temp += nums[i];
		// 	}	
		// 	//temp = std::accumulate(nums[left], nums.begin() + right, 0);
		// 	//temp = std::accumulate(nums[left], nums.begin() + right, 0);
		// 	temp = temp / k;
		// 	ans = max(ans, temp);
		// 	temp = 0;
		// 	left++;
		// 	right++;
		// }
  //
		// return ans;
		double sum = 0;
		for (int i = 0; i<k; i++)
			sum += nums[i];
		double result = sum / k;
		for (int i = k; i<nums.size(); i++) {
			sum = sum - nums[i - k] + nums[i];
			result = max(result, sum / k);
		}
		return result;
	}
};


int main()
{

	vector<int> nums = { 1,12,-5,-6,50,3 };
	Solution s;

	double ans = s.findMaxAverage(nums, 4);
	cout << ans << endl;	
	return 0;
}