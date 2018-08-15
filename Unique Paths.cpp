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
	int uniquePaths(int m, int n) {
		
		int ans = 0;

		int rows = n;
		int cols = m;

		vector<vector<int>> matrix(rows);
		for(int i = 0; i < matrix.size(); i++)
		{
			matrix[i].resize(cols);
		}

		for (int i = 0; i < cols; i++) {
			matrix[0][i] = 1;
		}

		for (int i = 0; i < rows; i++) {
			matrix[i][0] = 1;
		}

		for(int row = 1; row < rows; row++)
		{
			for(int col = 1; col < cols; col++)
			{
				//cout << matrix[row][col] << ' ';
				matrix[row][col] = matrix[row - 1][col] + matrix[row][col - 1];
			}
			//cout << endl;
		}

		ans = matrix[rows - 1][cols - 1];
		return ans;
	}
};


int main()
{
	
	vector<int> nums = { 3,1,3,4,2 };
		

	Solution s;

	int ans = s.uniquePaths(3,2);
	cout << ans << endl;
	
	
	return 0;
}