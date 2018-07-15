#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

class Solution {
public:
	void printMatrix(vector<vector<int>>& A)
	{
		for(int i = 0; i < A.size(); i++)
		{
			for(int j = 0; j < A[i].size(); j++)
			{
				cout << A[i][j] << ' ';
			}
			cout << endl;
		}
	}
	vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
	
		vector<vector<int>> matrix;
		//matrix = A;

		for (int i = 0; i < A.size(); i++)
		{
			int left = 0;
			int right = A[i].size() - 1;
			while(left < right)
			{
				std::swap((A[i][left]), (A[i][right]));
				//printMatrix(A);
				left++;
				right--;
			}
		}

		for(int i = 0; i < A.size(); i++)
		{
			for(int j = 0; j < A[i].size(); j++)
			{
				A[i][j] ^= 1;
			}
		}
		return A;
	}
};


int main()
{
	//code
//	vector<vector<int>> matrix = { {1,1,0},{1,0,1},{0,0,0} };
	vector<vector<int>> matrix = { {1,1,0,0},{1,0,0,1},{0,1,1,1},{1,0,1,0} };
	Solution s;
	vector<vector<int>> ans = s.flipAndInvertImage(matrix);

	// for(int i = 0; i < ans.size(); i++)
	// {
	// 	for(int j = 0; j < ans[i].size(); j++)
	// 	{
	// 		cout << ans[i][j] << ' ';
	// 	}
	// 	cout << endl;
	// }
	
	//std::swap(a, b);
	
	s.printMatrix(ans);

	return 0;
}