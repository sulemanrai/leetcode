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

	bool isMagicSqaure(vector<vector<int>>& grid, int row, int col)
	{
		if (grid[row + 1][col + 1] != 5)
			return false;

		//int* valid = new int[16];
		vector<int> valid;

		for (int i = row; i <= row + 2; i++) {
			for (int j = col; j <= col + 2; j++) {
				//valid[grid[i][j]]++;				
				valid.push_back(grid[i][j]);
			}			
		}
		sort(valid.begin(), valid.end());
		for (int v = 0; v < valid.size() ; v++)
			if (valid[v] != v + 1) return false;

		if ((grid[row][col] + grid[row][col + 1] + grid[row][col + 2]) != 15)         return false;
		if ((grid[row][col] + grid[row + 1][col + 1] + grid[row + 2][col + 2]) != 15)     return false;
		if ((grid[row][col] + grid[row + 1][col] + grid[row + 2][col]) != 15)         return false;
		if ((grid[row + 2][col] + grid[row + 2][col + 1] + grid[row+ 2][col + 2]) != 15)   return false;
		if ((grid[row][col + 2] + grid[row + 1][col + 2] + grid[row + 2][col + 2]) != 15)   return false;
		if ((grid[row][col + 2] + grid[row + 1][col + 1] + grid[row + 2][col]) != 15)     return false;
		return true;		
	}

	int numMagicSquaresInside(vector<vector<int>>& grid) {

		int ans = 0;
		int offset = 0;

		if (grid.size() < 3 && grid[0].size() < 3)
			return 0;

		bool flag = false;

		int numberofrows = grid.size();
		int numberofcols = grid[0].size();

		for(int row = 0; row <= grid.size() - 3; row++)
		{
			for(int col = 0; col <= grid[0].size() - 3; col++)
			{
				if (isMagicSqaure(grid, row, col) == true) {
					ans++;
				}
			}
		}

		return ans;
	}
};


int main()
{

	vector<vector<int>> nums = {{4, 3, 8, 4},
								{9, 5, 1, 9},
								{2, 7, 6, 2}};

	Solution s;

	int ans = s.numMagicSquaresInside(nums);
	cout << ans << endl;	
	return 0;
}