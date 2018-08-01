#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <functional>
#include <string>

using namespace std;

class Solution {
public:
	int sumOfUpperRow(vector<vector<int>> vec, int i, int j)
	{
		int sum = 0;
		int row = i - 1;
		int lower = j - 1;
		int upper = j;

		sum = vec[row][lower] + vec[row][upper];

		return sum;
	}

	vector<vector<int>> generate(int numRows) {
		vector<vector<int>> ans(numRows);
		for (int i = 0; i < ans.size(); i++) {
			ans[i].resize(i + 1);
		}

		for (int i = 0; i < ans.size(); i++)
		{
			for (int j = 0; j < ans[i].size(); j++)
			{
				if (j == 0 || j == ans[i].size() - 1)
				{
					ans[i][j] = 1;
				}
				if (i >= 2 && j > 0 && j < ans[i].size() - 1)
				{
					//ans[i][j] = ans[i - 1][j] +  ans[i-1][j + 1];
					ans[i][j] = sumOfUpperRow(ans, i, j);
				}
			//	cout << ans[i][j] << ' ';
			}
			//cout << endl;
		}

		return ans;
	}

	vector<int> getRow(int rowIndex) {

		vector<vector<int>> pascalTriangle = generate(rowIndex+1);

		vector<int> ans = pascalTriangle[pascalTriangle.size() - 1];

		return ans;
	}

};


int main()
{
	vector<int> nums =  {7,2,8,5,0,9,1,2,9,5,3,6,6,7,3,2,8,4,3,7,9,5,7,7,4,7,4,9,4,7,0,1,1,1,7,4,0,0,6 };
	//vector<int> nums = { 4,3,2,1 };
	Solution s;

	vector<int> ans = s.getRow(3);
	// vector<int> ans = s.plusOne(nums);
	for (int i : ans)
		cout << i << ' ';
	cout << endl;
	return 0;
}