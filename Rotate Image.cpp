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
	void rotate(vector<vector<int>>& matrix) {

		int length = matrix.size() - 1;

		for(int row = 0; row <= length/2; row++)
		{
			for(int col = row; col < length - row; col++)
			{
				int temp = matrix[row][col];

				matrix[row][col] = matrix[length - col][row];
				matrix[length - col][row] = matrix[length - row][length - col];
				matrix[length - row][length - col] = matrix[col][length - row];
				matrix[col][length - row] = temp;
			}
		}
	}
};


int main()
{
	
	vector<vector<int>> nums = { {1,2,3},
								 {4,5,6},
								 {7,8,9}};
		

	Solution s;

	s.rotate(nums);
	//cout << ans << endl;
	for(int i = 0; i < nums.size(); i++)
	{
		for(int j = 0; j < nums[i].size(); j++)
		{
			cout << nums[i][j] << ' ';
		}
		cout << endl;
	}
	
	return 0;
}