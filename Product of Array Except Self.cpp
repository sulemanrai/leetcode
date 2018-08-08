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

	vector<int> productExceptSelf(vector<int>& nums) {
		vector<int> ans;		
		int *left = new int[nums.size()];
		int *right = new int[nums.size()];		

		left[0] = 1;
		right[nums.size() - 1] = 1;		

		for (int i = 1; i < nums.size(); i++) {			
			left[i] = nums[i - 1] * left[i - 1];			
		}

		for (int j = nums.size() - 2; j >= 0; j--) {
			right[j] = nums[j + 1] * right[j + 1];
		}

		for (int i = 0; i < nums.size(); i++)
		{
			ans.push_back(left[i] * right[i]);
		}

		return ans;
	}
};


int main()
{
	int temp = 0;
	vector<int> nums = {1 , 0 };
		

	Solution s;

	vector<int> ans = s.productExceptSelf(nums);
	
	for (int i : ans)
		cout << i << ' ';

	cout << endl;
	return 0;
}