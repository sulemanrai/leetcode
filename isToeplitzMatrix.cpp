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

	bool checkDiagonal(vector<vector<int>> &mat, int i, int j, int N, int M)
	{
		int res = mat[i][j];
		while (++i < N && ++j < M)
		{
			// mismatch found
			if (mat[i][j] != res)
				return false;
		}

		// we only reach here when all elements
		// in given diagonal are same
		return true;
	}

	bool isToeplitzMatrix(vector<vector<int>>& matrix) {		
		int N, M;
		M = matrix[0].size();
		N = matrix.size();

		for(int i = 0; i < M; i++)
		{
			if (!checkDiagonal(matrix, 0, i, N, M))
				return false;
		}

		for(int i = 1; i < N; i++)
		{
			if (!checkDiagonal(matrix, i, 0, N, M))
				return false;
		}
		return true;
	}
};


int main()
{

	vector<vector<int>> matrix = { {1,2},
	{2,2}};
	Solution s;
	int ans = s.isToeplitzMatrix(matrix);
	
	cout << ans << endl;

	return 0;
}