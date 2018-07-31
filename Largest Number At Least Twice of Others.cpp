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
	int dominantIndex(vector<int>& nums) {

		int maximum = INT_MIN;
		int index;

		if (nums.size() == 1)
			return 0;

		vector<int> tmpvec;
		
		for (int i : nums)
			tmpvec.push_back(i);

		sort(tmpvec.begin(), tmpvec.end());
		maximum = tmpvec[tmpvec.size() - 1];

		for(int i = 0; i < nums.size(); i++)
		{
			if (nums[i] == maximum) {
				index = i;
			}
		}

		vector<float> temp;
		float tmp;
		for(int i = 0; i < nums.size(); i++)
		{
			if(nums[i] == 0)
			{
				tmp = INT_MAX;
			} else if(nums[i] == maximum)
			{
				continue;
			}
			else {
				tmp = (float) maximum / (float)nums[i];
			}
			temp.push_back(tmp);			
		}
		bool flag = false;
		for(int i = 0; i < temp.size(); i++)
		{			
			if(temp[i] >= 2)
			{
					flag = true;
			} else
			{
				flag = false;
				break;
			}
			
		}
		if (flag == false)
			index = -1;

		return index;
	}
};


int main()
{
	vector<int> nums =  { 1, 2, 3, 4 };
	Solution s;
	int ans = s.dominantIndex(nums);
	cout << ans << endl;
	return 0;
}