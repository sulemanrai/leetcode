#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <functional>

using namespace std;

class Solution {
public:
	int arrayPairSum(vector<int>& nums) {
		int sum = 0;

		sort(nums.begin(), nums.end());

		for(int i = 0; i < nums.size(); i+=2)
		{
			sum += min(nums[i], nums[i + 1]);
		}

		return sum;
	}
};


int main()
{

	vector<int> matrix = { 1,2,3,2};
	Solution s;
	int ans = s.arrayPairSum(matrix);
	
	cout << ans << endl;

	return 0;
}