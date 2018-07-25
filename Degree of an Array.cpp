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
	int findShortestSubArray(vector<int>& nums) {
		int ans = nums.size();
		map<int, int> left;
		map<int, int> right;
		map<int, int> count;

		map<int, int>::iterator itr;
		for(int i = 0; i < nums.size(); i++)
		{
			int x = nums[i];
			itr = left.find(x);
			if(itr == left.end())
			{
				left[x] = i;
			}
			right[x] = i;

			count[x]++;
		}
		int degree = 0;
		int res = -1;
		for (auto i : count) {
			if (degree < i.second) {
				//res = i.first;
				degree = i.second;
			}
		}
		//cout << max_count << endl;

		for(auto x : count)
		{
			if(x.second == degree)
			{
				ans = min(ans, right[x.first] - left[x.first] + 1);
			}
		}
		
		return ans;
	}
};


int main()
{

	vector<int> matrix = { { 1,2,2,3,1,4,2 } };
	Solution s;
	int ans = s.findShortestSubArray(matrix);
	cout << ans << endl;

	return 0;
}