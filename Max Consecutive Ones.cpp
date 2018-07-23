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

	int findMaxConsecutiveOnes(vector<int>& nums) {
		int max1 = 0;
		int temp = 0;
		for(int i = 0; i < nums.size(); i++)
		{
			if(nums[i] == 1)
			{
				temp++;
			} else if(nums[i] == 0)
			{
				max1 = max(max1, temp);
				temp = 0;
			}
		}

		if(temp != 0)
		{
			max1 = max(max1, temp);
		}
		return max1;
	}
};


int main()
{

	vector<int> matrix = { 1,1,0,1,1,1};
	Solution s;
	int ans = s.findMaxConsecutiveOnes(matrix);
	cout << ans << endl;	
	return 0;
}