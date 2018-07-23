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
	void moveZeroes(vector<int>& nums) {
		int i, j;
		bool swapped;
		for (i = 0; i < nums.size() - 1; i++)
		{
			swapped = false;
			for (j = 0; j < nums.size() - i - 1; j++)
			{
				if (nums[j] == 0)
				{
					swap(nums[j], nums[j + 1]);
					swapped = true;
				}
			}

			// IF no two elements were swapped by inner loop, then break
			if (swapped == false)
				break;
		}

		// for (int i : nums)
		// 	cout << i << ' ';
	}
};


int main()
{

	vector<int> matrix = { { 0,1,0,3,12 }};
	Solution s;
	s.moveZeroes(matrix);
	//vector<int> ans = s.moveZeroes(matrix);
	//cout << ans << endl;	
	return 0;
}