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

	int findMin(vector<int>& nums) {

		int min = 0;

		if (nums.size() == 1)
			return nums[0];

		bool flag = false;
		for(int i = 0; i < nums.size() - 1; i++)
		{
			if(nums[i+1] < nums[i])
			{
				min = nums[i + 1];
				flag = true;
			} else
			{
				min = nums[0];
			}
			if(flag == true)
			{
				break;
			}
		}

		return min;
	}
};

int main()
{	
	Solution s;
	
	vector<int> A = { 1,2 };

	int ans = s.findMin(A);
	cout << ans << endl;


	return 0;
}