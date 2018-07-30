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
	int minCostClimbingStairs(vector<int>& cost) {

		for(int i = 2; i < cost.size(); i++)
		{
			cost[i] += min(cost[i - 1], cost[i - 2]);
		}
		return min(cost[cost.size() - 1], cost[cost.size() - 2]);		
	}
};


int main()
{
	vector<int> nums = { 1, 100, 1, 1, 1, 100, 1, 1, 100, 1 };
	Solution s;
	int ans = s.minCostClimbingStairs(nums);
	cout << ans << endl;
	return 0;
}