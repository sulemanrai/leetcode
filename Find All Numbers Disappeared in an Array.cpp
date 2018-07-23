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
	vector<int> findDisappearedNumbers(vector<int>& nums) {
		vector<int> ans;
		if (nums.size() == 0)
			return ans;
		sort(nums.begin(), nums.end());
		int low = 1;
		int max = nums.size();

		while(low <= max)
		{
			if(binary_search(nums.begin(), nums.end(), low) == false)
			{
				ans.push_back(low);
			}
			low++;
		}
		return ans;
	}
};


int main()
{

	vector<int> matrix = { { 1,1 }};
	Solution s;
	vector<int> ans = s.findDisappearedNumbers(matrix);
	for (int i : ans)
		cout << i << ' ';

	return 0;
}