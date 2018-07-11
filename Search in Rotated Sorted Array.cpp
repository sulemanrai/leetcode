#include<iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <functional>
using namespace std;

class Solution {
public:
	int binarySearch(vector<int> vec, int l, int r, int x)
	{
		while (l <= r)
		{
			int m = l + (r - l) / 2;

			// Check if x is present at mid
			if (vec[m] == x)
				return m;

			// If x greater, ignore left half
			if (vec[m] < x)
				l = m + 1;

			// If x is smaller, ignore right half
			else
				r = m - 1;
		}

		// if we reach here, then element was
		// not present
		return -1;
	}
	int search(vector<int>& nums, int target) {
		//int ans = 0;

		//std::vector<int> arr = { 5,6,7,8,-2,2,3,4 };
		 auto rotation_point = std::partition_point(nums.begin(), std::prev(nums.end()),
		 	[&nums](int elem) { return elem > nums.back(); });

		 int temp = distance(nums.begin(),rotation_point);
		//int temp = partitionPoint(nums);
		//cout << temp << endl;

		if (nums[temp] == target)
			return temp;

		int tmp = binarySearch(nums, 0, temp - 1, target);
		if(tmp == -1)
		{
			tmp = binarySearch(nums, temp, nums.size() - 1, target);
		} 

		return tmp;
	}
};


int main()
{
	//code
	vector<int> nums1 = { 4,5,6,7,0,1,2 };
	int target = 4;
	Solution s;
	int ans = s.search(nums1,target);
	cout << ans << endl;
	
	return 0;
}