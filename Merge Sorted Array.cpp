#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <functional>
#include <string>
#include <numeric>

using namespace std;

class Solution {
public:

	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

		if (nums2.size() == 0)
			return;
	
		int j = 0;
		for (int i = m; i < nums1.size(); i++)
		{
			if (nums1[i] == 0)
			{
				nums1[i] = nums2[j];
				j++;
			}
		}
  
		sort(nums1.begin(), nums1.end());
		
	}
};


int main()
{

	//vector<int> nums = { 1,2,1 };
	vector<int> nums1 = { -1,0,0,3,3,3,0,0,0 };
	vector<int> nums2 = { 1,2,2 };
	//vector<int> nums = { 1,0,1,1 };
	//vector<int> nums = { 1,2,3,1,2,3 };
	//vector<int> nums = { 99,99 };
	

	Solution s;

	s.merge(nums1, 6 ,nums2, 3);	
	
	return 0;
}