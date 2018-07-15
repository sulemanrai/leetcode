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
	vector<vector<int>> transpose(vector<vector<int>>& A) {
		
		int NumberOfRows = 0;
		int NumberOfCols = 0;
		bool flag = false;
		for (int row = 0; row < A.size(); row++)
		{
			for (int col = 0; col < A[row].size(); col++)
			{
				if (flag == false) {
					NumberOfCols++;
				}
			}
			flag = true;
			NumberOfRows++;
		}

		vector < vector<int> > matrix(NumberOfCols);
		for (int i = 0; i < NumberOfCols; i++) {
			matrix[i].resize(NumberOfRows);
		}

		for(int col = 0; col < NumberOfCols; col++)
		{
			for(int row = 0; row < NumberOfRows; row++)
			{
				matrix[col][row] = A[row][col];
			}

		}

	
		return matrix;
	}
};


int main()
{

	vector<vector<int>> matrix = { {1,2,3 }, { 4,5,6 }, { 7,8,9 }};
	Solution s;
	vector<vector<int>> ans = s.transpose(matrix);
	
	s.printMatrix(ans);

	return 0;
}