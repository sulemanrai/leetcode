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

		for(int i = 0 ; i < ans.size(); i++)
		{
			for(int j = 0; j < ans[i].size(); j++)
			{				
				if(j == 0 || j == ans[i].size() - 1)
				{
					ans[i][j] = 1;
				} 
				if(i >= 2 && j > 0 && j < ans[i].size() - 1)
				{
					//ans[i][j] = ans[i - 1][j] +  ans[i-1][j + 1];
					ans[i][j] = sumOfUpperRow(ans,i,j);
				}
				cout << ans[i][j] << ' ';
			}
			cout << endl;
		}

		return ans;
	}
};


int main()
{
	int nums =  7;
	Solution s;
	vector<vector<int>> ans = s.generate(nums);
	//cout << ans << endl;
	return 0;
}