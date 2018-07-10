#include<iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <functional>
using namespace std;

class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		// using default comparison:
		std::vector<int>::iterator it;
		it = std::unique(nums.begin(), nums.end());

		nums.resize(std::distance(nums.begin(), it));

		return nums.size();
	}
};


int main()
{
	//code
	vector<int> nums1 = { 0,0,1,1,1,2,2,3,3,4 };
	int target = 1;
	Solution s;
	int ans = s.removeDuplicates(nums1);
	cout << ans << endl;
	return 0;
}