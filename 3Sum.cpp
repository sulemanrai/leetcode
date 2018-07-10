#include<iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int> > matrix;
		map<vector<int>, int> permutation;
		map<vector<int>, int>::iterator itr;
		if (nums.size() < 3 )
			return matrix;

		sort(nums.begin(), nums.end());
		int left, right;
		int sum = 0;
		for (int i = 0; i < nums.size() - 2; i++)
		{
			left = i + 1;
			right = nums.size() - 1;

			int temp = sum - nums[i];
			while(left < right)
			{
				if(nums[left] + nums[right] > temp)
				{
					right--;
				} else if(nums[left] + nums[right] < temp)
				{
					left++;
				} else if(nums[left] + nums[right] == temp)
				{
					vector<int> v = {nums[i], nums[left], nums[right]};
					permutation[v]++;					
                    left++;
                    right--;
				}
			}
		}		
        for (map<vector<int>, int>::iterator it = permutation.begin(); it != permutation.end(); ++it)
		{
			vector<int> vec = it->first;
			matrix.push_back(vec);
		}
		 return matrix;
    }
};

int main()
{
	//code
	vector<int> nums1 = { -2,0,1,1,2 };

	Solution s;
	vector<vector<int>> ans = s.threeSum(nums1);

	//To access values
	for (vector<vector<int> >::iterator it = ans.begin(); it != ans.end(); ++it)
	{
		//it is now a pointer to a vector<int>
		for (vector<int>::iterator jt = it->begin(); jt != it->end(); ++jt)
		{
			// jt is now a pointer to an integer.
			cout << *jt << ' ';
		}
		cout << endl;
	}

	return 0;
}