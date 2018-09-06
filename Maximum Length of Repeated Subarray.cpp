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

	int findLength(vector<int>& A, vector<int>& B) {

		int count = 0;

		vector<vector<int>> matrix(A.size() + 1, vector<int>(B.size() + 1));

		for(int i = 1; i <= A.size(); i++)
		{
			for(int j = 1; j <= B.size(); j++)
			{
				if(A[i-1] == B[j-1])
				{
					matrix[i][j] = matrix[i - 1][j - 1] + 1;
				}
				else
				{
					matrix[i][j] = 0;
				}
			}
		}

		for(int row = 0; row < matrix.size(); row++)
		{
			for(int col = 0; col < matrix[0].size(); col++)
			{
				count = max(count, matrix[row][col]);
			}
			
		}

		return count;
	}
};

int main()
{	
	Solution s;
	
	vector<int> A = { 1,2,3,2,1 };
	vector<int> B = { 3,2,1,4,7 };

	int ans = s.findLength(A,B);
	cout << ans << endl;


	return 0;
}