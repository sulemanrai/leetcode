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
	int maxProfit(vector<int>& prices) {
		int ans = 0;

		for(int i = 0; i < prices.size(); i++)
		{
			for(int j = i + 1; j < prices.size(); j++)
			{
				ans = max(ans, prices[j] - prices[i]);
			}
		}

		return ans;
	}
};


int main()
{
	vector<int> nums = { 7,1,5,3,6,4 };
	Solution s;
	int ans = s.maxProfit(nums);
	cout << ans << endl;
	return 0;
}