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
	int AreaOfIsland(vector<vector<int>>& grid, int i, int j) {
	
		if(i >= 0 && i < grid.size() && j >=0 && j < grid[0].size() && grid[i][j] == 1)
		{
			grid[i][j] = 0;
			return 1 + AreaOfIsland(grid, i - 1, j) + AreaOfIsland(grid, i + 1, j) + AreaOfIsland(grid, i, j - 1) + AreaOfIsland(grid, i, j + 1);
		}
		return 0;
	}
	int maxAreaOfIsland(vector<vector<int>>& grid) {
		int maxarea = 0;

		for(int i = 0; i < grid.size(); i++)
		{
			for(int j = 0; j < grid[0].size(); j++)
			{
				if (grid[i][j] == 1) {
					maxarea = max(maxarea, AreaOfIsland(grid, i, j));
				}
			}
		}

		return maxarea;
	}
};


int main()
{

	vector<vector<int>> matrix = { 
	{ 0,0,1,0,0,0,0,1,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,1,1,1,0,0,0 },
	{ 0,1,1,0,1,0,0,0,0,0,0,0,0 },
	{ 0,1,0,0,1,1,0,0,1,0,1,0,0 },
	{ 0,1,0,0,1,1,0,0,1,1,1,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,1,0,0 },
	{ 0,0,0,0,0,0,0,1,1,1,0,0,0 },
	{ 0,0,0,0,0,0,0,1,1,0,0,0,0 },
	};
	Solution s;
	int ans = s.maxAreaOfIsland(matrix);
	cout << ans << endl;	
	return 0;
}