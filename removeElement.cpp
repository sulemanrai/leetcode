#include<iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <functional>
using namespace std;

class Solution {
public:
	int removeElement(vector<int>& nums, int val) {
		
		nums.erase(std::remove(nums.begin(), nums.end(), val), nums.end());

		return nums.size();
	}
};


int main()
{
	//code
	vector<int> nums1 = { 0,1,2,2,3,0,4,2 };
	int target = 2;
	Solution s;
	int ans = s.removeElement(nums1,target);
	cout << ans << endl;
	return 0;
}