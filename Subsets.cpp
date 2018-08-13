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
	vector<vector<int>> subsets(vector<int>& nums) {

		

		/*set_size of power set of a set with set_size
		n is (2**n -1)*/
		unsigned int pow_set_size = pow(2, nums.size());
		vector<vector<int>> ans(pow_set_size);
		int counter, j;

		/*Run from counter 000..0 to 111..1*/
		for (counter = 0; counter < pow_set_size; counter++)
		{
			for (j = 0; j < nums.size(); j++)
			{
				/* Check if jth bit in the counter is set
				If set then pront jth element from set */
				if (counter & (1 << j)) {
					//printf("%i", nums[j]);
					ans[counter].push_back(nums[j]);
				}
			}
			//cout << endl;
		}

		return ans;
	}
};


int main()
{
	
	vector<int> nums = { 1, 2 , 3 };
		

	Solution s;

	vector<vector<int>> ans = s.subsets(nums);
	//cout << ans << endl;
	for(int i = 0; i < ans.size(); i++)
	{
		for(int j = 0; j < ans[i].size(); j++)
		{
			cout << ans[i][j] << ' ';
		}
		cout << endl;
	}
	
	return 0;
}