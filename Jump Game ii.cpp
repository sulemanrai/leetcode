#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

class Solution {
public:
	int jump(vector<int>& nums) {

		if (nums.size() <= 1)
			return 0;

		int maxReach = nums[0];
		int step = nums[0];
		int jump = 1;

		for(int i = 1; i < nums.size(); i++)
		{
			if (i == nums.size() - 1)
				return jump;

			if (i + nums[i] > maxReach)
				maxReach = i + nums[i];

			step--;

			if(step == 0)
			{
				jump++;
				step = maxReach - i;
			}
		}

		return jump;
	}
};


int main()
{
	//code
	int T;
	cin >> T;
	while (T--)
	{
		int N;
		cin >> N;
		vector<int> nums;
		for (int i = 0; i < N; i++)
		{
			int element;
			cin >> element;
			nums.push_back(element);
		}
		Solution s;
		//cout << s.jump(nums) << endl;
		int ans = s.jump(nums);
		if (ans < 0)
		{
			ans = -1;
		}
		cout << ans << endl;
	}
	return 0;


	//return 0;
}