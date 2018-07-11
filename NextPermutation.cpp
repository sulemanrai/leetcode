#include<iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <functional>
using namespace std;

class Solution {
public:
	void nextPermutation(vector<int>& nums) {
		std::next_permutation(nums.begin(),nums.end());
	}
};


int main()
{
	//code
	vector<int> nums1 = { 1,1,5 };
	int target = 2;
	Solution s;
	s.nextPermutation(nums1);

	for (int i : nums1)
		cout << i << ' ';
	cout << endl;
	return 0;
}