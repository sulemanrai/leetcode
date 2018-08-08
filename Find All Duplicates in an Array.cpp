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

	vector<int> findDuplicates(vector<int>& nums) {
		vector<int> ans;

		map<int, int> um;

		for (int i : nums)
			um[i]++;

		for(map<int,int>::iterator itr = um.begin(); itr != um.end(); ++itr)
		{
			if (itr->second > 1)
				ans.push_back(itr->first);
		}

		return ans;
	}
};


int main()
{
	int temp = 0;
	vector<int> nums = { 4,3,2,7,8,2,3,1 };
		

	Solution s;

	vector<int> ans = s.findDuplicates(nums);

	for (int i : ans)
		cout << i << ' ';
	cout << endl;
	
	return 0;
}