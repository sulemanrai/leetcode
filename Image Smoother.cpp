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

	bool static  checkValidCell(vector<vector<int>> & M, pair<int,int> p)
	{
		bool exists = true;
		try
		{
		M.at(p.first).at(p.second);
		} catch(const std::out_of_range& oor)
		{
			exists = false;
		}
		return exists;
	}

	int sumOfEachCell(int i, int j, vector<vector<int>>& M)
	{
		pair<int, int> p1 = make_pair(i-1,j-1);
		pair<int, int> p2 = make_pair(i-1,j);
		pair<int, int> p3 = make_pair(i-1,j+1);
		pair<int, int> p4 = make_pair(i,j-1);
		pair<int, int> p5 = make_pair(i,j+1);
		pair<int, int> p6 = make_pair(i+1,j-1);
		pair<int, int> p7 = make_pair(i+1,j);
		pair<int, int> p8 = make_pair(i+1,j+1);
		pair<int, int> p9 = make_pair(i, j);

		vector<pair<int, int>> vp;
		int sum = 0;

		if (checkValidCell(M, p1) == true) {
			vp.push_back(p1);
		}
		if(checkValidCell(M, p2) == true)
		{
			vp.push_back(p2);
		}
		 if (checkValidCell(M, p3) == true)
		{
			vp.push_back(p3);
		}
		 if (checkValidCell(M, p4) == true)
		{
			vp.push_back(p4);
		}
		 if (checkValidCell(M, p5) == true)
		{
			vp.push_back(p5);
		}
		 if (checkValidCell(M, p6) == true)
		{
			vp.push_back(p6);
		}
		 if (checkValidCell(M, p7) == true)
		{
			vp.push_back(p7);
		}
		 if (checkValidCell(M, p8) == true)
		{
			vp.push_back(p8);
		}
		 if (checkValidCell(M, p9) == true)
		{
			vp.push_back(p9);
		}

		for (int i = 0; i < vp.size(); i++)
		{
			sum += M[vp[i].first][vp[i].second];
		}
		int result = floor(sum / vp.size());
		vp.clear();

		return result;
	}

	vector<vector<int>> imageSmoother(vector<vector<int>>& M) {

		vector<vector<int>> ans(M.size());
		for (int i = 0; i < ans.size(); i++)
			ans[i].resize(M[0].size());


		for(int i = 0; i < ans.size(); i++)
		{
			for(int j = 0; j < ans[i].size(); j++)
			{
				ans[i][j] = sumOfEachCell(i, j, M);
			}
		}

		return ans;
	}
};


int main()
{

	vector<vector<int>> matrix = { {2,3,4 }, { 5,6,7 }, { 8,9,10 }, { 11,12,13 }, { 14,15,16 }};
	Solution s;
	vector<vector<int>> ans = s.imageSmoother(matrix);

	for(int i = 0; i < ans.size(); i++)
	{
		for(int j = 0; j < ans[i].size();j++)
		{
			cout << ans[i][j] << ' ';
		}
		cout << endl;
	}

	return 0;
}