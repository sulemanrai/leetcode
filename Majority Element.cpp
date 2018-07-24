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
	int majorityElement(vector<int>& nums) {
		unordered_map<int, int> um;

		for (int i = 0; i < nums.size(); i++) {
			um[nums[i]]++;
		}
		int freq = floor(nums.size() / 2);
		int ans = 0;
		for(unordered_map<int, int>::iterator itr = um.begin(); itr != um.end(); ++itr)
		{
			//cout << itr->first << ' ' << itr->second << endl;
			if(itr->second > freq)
			{
				ans = itr->first;
			}
		}

		return ans;
	}
};


int main()
{

	vector<int> matrix = { { 2,2,1,1,1,2,2 } };
	Solution s;
	int ans = s.majorityElement(matrix);
	cout << ans << endl;

	return 0;
}