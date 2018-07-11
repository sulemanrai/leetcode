#include<iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <functional>
using namespace std;

class Solution {
public:
	vector<int> searchRange(vector<int>& nums, int target) {

		vector<int> ans;

		if (nums.size() == 0)
		{
			ans.push_back(-1);
			ans.push_back(-1);
			return ans;
		}

		std::vector<int>::iterator low, up;
		if (binary_search(nums.begin(), nums.end(), target) == true) {
			low = std::lower_bound(nums.begin(), nums.end(), target);
			up = std::upper_bound(nums.begin(), nums.end(), target);

			int firstIndex = low - nums.begin();
			int secondIndex = up - nums.begin();			
			ans.push_back(firstIndex);
			ans.push_back(secondIndex - 1);
		} else
		{
			ans.push_back(-1);
			ans.push_back(-1);
		}

		return ans;
	}
};


int main()
{
	//code
	vector<int> nums1 = { 5,7,7,8,8,10 };
	int target = 6;
	Solution s;
	vector<int> ans = s.searchRange(nums1,target);
	for (int i : ans)
		cout << i << ' ';
	cout << endl;
	
	return 0;
}