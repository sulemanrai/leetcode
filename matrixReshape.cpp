#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <functional>

using namespace std;

class Solution {
public:

	vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
		int dimensions = r * c;

		int rows = nums.size();
		int cols = nums[0].size();
		int originalDimens = rows * cols;
		//cout << originalDimens << endl;

		if (originalDimens != dimensions)
			return nums;

		vector<vector<int>> reshapedMatrix(r, vector<int>(c));
		vector<int> temp(dimensions);
		std::vector<int> ret;
		for (const auto &v : nums)
			ret.insert(ret.end(), v.begin(), v.end());

		int x = 0;
		for (int i = 0; i < r; i++)
		{
			for (int j = 0; j < c ; j++)
			{
				
				reshapedMatrix[i][j] = ret[x];
				x++;
			}
		}

		return reshapedMatrix;

	}
};


int main()
{

	vector<vector<int>> matrix = { {1,2},
	{3,4}};
	Solution s;
	vector<vector<int>> ans = s.matrixReshape(matrix,4,1);
	
	int rows = ans.size();
	int cols = ans[0].size();

	for(int r = 0; r < rows; r++)
	{
		for(int c = 0; c < cols; c++)
		{
			cout << ans[r][c] << ' ';
		}
		cout << endl;
	}

	return 0;
}