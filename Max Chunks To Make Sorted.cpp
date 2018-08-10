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

	int maxChunksToSorted(vector<int>& arr) {
		int ans = 0;
		int max_so_far = 0;

		for(int i = 0; i < arr.size(); i++)
		{
			max_so_far = max(max_so_far, arr[i]);

			if (max_so_far == i) {
				ans++;
			}
		}
		return ans;
	}
};


int main()
{
	int temp = 0;
	vector<int> nums = { 4,3,2,1,0 };
	//vector<int> nums = { 1,0,2,3,4 };

		

	Solution s;

	int ans = s.maxChunksToSorted(nums);
	
	cout << ans << endl;
	
	return 0;
}