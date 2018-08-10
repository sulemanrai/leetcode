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

	int arrayNesting(vector<int>& nums) {
		
		int maxsize = 0;
		for(int i = 0; i < nums.size(); i++)
		{
			int size = -1;
			for(int k = i; k >=0; size++)
			{
				int temp = nums[k];
				nums[k] = -1;
				k = temp;
			}
			maxsize = max(maxsize, size);
		}

		return maxsize;
	}
};


int main()
{
	int temp = 0;
	vector<int> nums = { 5,4,0,3,1,6,2 };
	//vector<int> nums = { 0,2,1 };
	//vector<int> nums = { 0,1,2 };
		

	Solution s;

	int ans = s.arrayNesting(nums);
	
	cout << ans << endl;
	
	return 0;
}