#include<iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <functional>
using namespace std;

class Solution {
public:
	vector<vector<int>> fourSum(vector<int>& nums, int target) {
		vector<vector<int>> matrix;
		sort(nums.begin(), nums.end());		
		int left, right;
		int sum = 0;

		map<vector<int>, int> m;

		for (int i = 0; i < nums.size() - 3; i++)
		{
			for(int j = i + 1; j < nums.size() - 2; j++)
			{
				for(int k = j + 1; k < nums.size() - 1; k++)
				{
					for(int l = k + 1; l < nums.size(); l++)
					{
						int sum = nums[i] + nums[j] + nums[k] + nums[l];
						if (sum == 0)
						{
							vector<int> v = { nums[i] , nums[j],nums[k] ,nums[l] };
							m[v]++;
						}
					}
				}
			}
		}

		for (map<vector<int>, int>::iterator it = m.begin(); it != m.end(); ++it)
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
	vector<int> nums1 = { 1, 0, -1, 0, -2, 2 };
	int target = 1;
	Solution s;
	vector<vector<int>> ans = s.fourSum(nums1,target);
	//cout << ans << endl;
	for(int i = 0; i < ans.size(); i++)
	{
		vector<int> tmp = ans[i];
		for (int i : tmp)
			cout << i << ' ';

		cout << endl;
	}	
	return 0;
}