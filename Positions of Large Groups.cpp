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

	vector<vector<int>> largeGroupPositions(string S) {
		vector<vector<int>> ans;
		//int i = 0;
		vector<pair<int, int>> temp;
		bool flag = false;
		
		int count = 1;
		int j;
		for(int i = 0; i < S.size();)
		{
			char c = S[i];
			//cout << c << ' ';
			for(j = i + 1; j < S.size(); j++)
			{
				char cc = S[j];
				if (cc == c) {
					count++;
				} else if (cc != c)
				{
					break;
				}
				
			}
			if (count >= 3) {
				temp.push_back(make_pair(i, i + count - 1));				
				i = j;
			} else if (count < 3)
			{
				i++;
			}
			count = 1;
		}
		ans.resize(temp.size());
		for (int i = 0; i < ans.size(); i++) {
			ans[i].resize(2);
		}
		for(int i = 0; i < ans.size(); i++)
		{
			//cout << temp[i].first << ' ' << temp[i].second << endl;
			//for(int j = 0; j < ans[i].size(); j++)
			ans[i][0] = temp[i].first;
			ans[i][1] = temp[i].second;
		}

		return ans;
	}
};


int main()
{

	string input = "abcaaabbaaaaa";
	Solution s;
	vector<vector<int>> ans = s.largeGroupPositions(input);

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