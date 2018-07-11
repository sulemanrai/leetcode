#include<iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <functional>
using namespace std;

class Solution {
public:
	int searchInsert(vector<int>& nums, int target) {

		std::vector<int>::iterator low;
		low = std::lower_bound(nums.begin(), nums.end(), target);		

		int firstIndex = low - nums.begin();		

		return firstIndex;
	}
};


int main()
{
	//code
	vector<int> nums1 = { 1,3,5,6 };
	int target = 2;
	Solution s;
	int ans = s.searchInsert(nums1,target);
	cout << ans << endl;
	
	return 0;
}