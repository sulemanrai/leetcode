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
	int maxProfit(vector<int>& prices, int fee) {
		
		int T_ik0 = 0, T_ik1 = INT_MIN;;

		for (int price : prices) {
			int T_ik0_old = T_ik0;
			T_ik0 = max(T_ik0, T_ik1 + price);
			T_ik1 = max(T_ik1, T_ik0_old - price - fee);
		}
		return T_ik0;
	}
};


int main()
{
	
	vector<int> nums = { 1, 3, 2, 8, 4, 9 };
		

	Solution s;

	int ans = s.maxProfit(nums,2);
	cout << ans << endl;
	
	return 0;
}