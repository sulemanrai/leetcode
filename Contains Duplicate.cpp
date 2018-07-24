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
	bool containsDuplicate(vector<int>& nums) {
		unordered_map<int, int> um;
		for (int i = 0; i < nums.size(); i++) {
			um[nums[i]]++;
		}

		bool duplicates = false;
		for(unordered_map<int,int>::iterator itr = um.begin(); itr != um.end(); ++itr)
		{
			if(itr->second > 1)
			{
				duplicates = true;
			}

			if (duplicates == true)
				break;
		}

		return duplicates;
	}
};


int main()
{

	vector<int> matrix = { { 1,2,3,1 } };
	Solution s;
	int ans = s.containsDuplicate(matrix);
	cout << ans << endl;

	return 0;
}