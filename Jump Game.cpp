#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

class Solution {
public:
	bool canJump(vector<int>& nums) {
		bool jump = false;

		if (nums.size() == 0)
			return false;


		int *boolJumpArr = new int[nums.size()];
		for(int i = 0; i < nums.size(); i++)
		{
			boolJumpArr[i] = false;
		}
		boolJumpArr[0] = true;

		for (int i = 1; i < nums.size(); i++) {

			for (int j = 0; j < i; j++)
			{
				if(i <= j + nums[j])
				{
					boolJumpArr[i] = true;
				}
			}
		}
		for (int i = 0; i < nums.size(); i++) {
			if(boolJumpArr[i] == false)
			{
				jump = false;
				break;
			} 
			jump = boolJumpArr[i];
			
		}				
		delete[] boolJumpArr;

		return jump;

	}
};


int main()
{
	//code
	vector<int> nums = {0,2,3};
	
	
	int target = 8;
	Solution s;
	//cout << s.canJump(nums) << endl;
	bool ans = s.canJump(nums);

	if (ans == false)
		cout << "false" << endl;
	else if (ans == true)
		cout << "true" << endl;


	return 0;
}