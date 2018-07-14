#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

class Solution {
public:

	int trap(vector<int>& height) {
		int ans = 0;
		int max_left = INT_MIN;
		int max_right = INT_MIN;
		int waterVol = 0;

		int *left = new int[height.size()];
		int *right = new int[height.size()];

		left[0] = height[0];
		right[height.size() - 1] = height[height.size() - 1];

		for (int i = 1; i < height.size(); i++)
			left[i] = max(left[i - 1], height[i]);

		 for (int i = height.size() - 2; i >= 0; i--)
		 	right[i] = max(right[i + 1], height[i]);

		for(int i = 0; i < height.size(); i++)
		{
			waterVol += (min(left[i], right[i]) - height[i]);
		}

		delete[] left;
		delete[] right;

		return waterVol;
	}
};


int main()
{
	//code
	vector<int> nums1 = { 0,1,0,2,1,0,1,3,2,1,2,1 };
	//vector<int> nums1 = { 7 ,4 ,0 ,9 };
	
	int target = 8;
	Solution s;
	cout << s.trap(nums1) << endl;


	return 0;
}