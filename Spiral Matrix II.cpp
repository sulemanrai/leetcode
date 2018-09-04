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
	vector<vector<int>> generateMatrix(int n) {

		vector<vector<int>> ans(n, vector<int> (n));

		if (n == 0)
			return ans;
		// Normal Case
		int rowStart = 0;
		int rowEnd = n - 1;
		int colStart = 0;
		int colEnd = n - 1;
		int num = 1; //change

		while(rowStart <= rowEnd && colStart <= colEnd)
		{
			/* Print the first row from the remaining rows */
			for (int i = colStart; i <= colEnd; ++i)
			{
				ans[rowStart][i] = num++;				
			}
			rowStart++;

			for (int i = rowStart; i <= rowEnd; ++i) {
				ans[i][colEnd] = num++; //change
			}
			colEnd--;

			for (int i = colEnd; i >= colStart; i--) {
				if (rowStart <= rowEnd)
					ans[rowEnd][i] = num++; //change
			}
			rowEnd--;

			for (int i = rowEnd; i >= rowStart; i--) {
				if (colStart <= colEnd)
					ans[i][colStart] = num++; //change
			}
			colStart++;
		}

		return ans;
	}
};

int main()
{	
	Solution s;
	vector<vector<int>> ans = s.generateMatrix(3);

	for (int row = 0; row < ans.size(); row++)
	{
		for (int col = 0; col < ans[row].size(); col++)
		{
			cout << ans[row][col] << ' ';
		}
		cout << endl;
	}

	return 0;
}