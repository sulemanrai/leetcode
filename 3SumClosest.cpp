#include<iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <functional>
using namespace std;

class Solution {
public:
	int threeSumClosest(vector<int>& nums, int target) {
		if (nums.size() < 3)
			return 0;

		sort(nums.begin(), nums.end());
		int minDiff = INT_MAX;
		int bestSum = 0;

		for (int i = 0; i < nums.size() - 2; i++)
		{
			int left = i + 1;
			int right = nums.size() - 1;

			while(left < right)
			{
				int sum = nums[i] + nums[left] + nums[right];
				if(abs(sum - target) < minDiff)
				{
					minDiff = abs(sum - target);
					bestSum = sum;
				}

				if(sum > target)
				{
					right--;
				} else
				{
					left++;
				}
			}
		}		



		return bestSum;
	}
};


int main()
{
	//code
	vector<int> nums1 = { -1, 2, 1, -4 };
	int target = 1;
	Solution s;
	int ans = s.threeSumClosest(nums1,target);
	cout << ans << endl;
	

	return 0;
}