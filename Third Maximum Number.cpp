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

	int thirdMax(vector<int>& nums) {
		int ans = 0;

		map<int, int> um;
		bool flag = false;
		for (auto i : nums) {
			if(i == INT_MIN)
			{
				flag = true;
			}
			um[i]++;
		}
		
		//map<int, int>::iterator it = um.begin();

		vector<int> temp;
		for (auto i : um)
			temp.push_back(i.first);

		
		int maximum = temp[0];
		int secondmaximum = INT_MIN;
		int thirdmaximum = INT_MIN;

		for (int i = 1; i < temp.size(); i++)
		{
			if (temp[i] > maximum)
			{
				thirdmaximum = secondmaximum;
				secondmaximum = maximum;
				maximum = temp[i];
			}
			else if (temp[i] > secondmaximum)
			{
				thirdmaximum = secondmaximum;
				secondmaximum = temp[i];
			}
			else if (temp[i] > thirdmaximum)
			{
				thirdmaximum = temp[i];
			}
		}

		if (thirdmaximum == INT_MIN   && temp.size() < 3)
		{
			thirdmaximum = maximum;
		}

		return thirdmaximum;
	}
};


int main()
{
	int temp = 0;
	vector<int> nums = { 1,2,std::numeric_limits<int>::min() };
		

	Solution s;

	int ans = s.thirdMax(nums);
	cout << ans << endl;
	
	return 0;
}