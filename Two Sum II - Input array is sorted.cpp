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
	vector<int> twoSum(vector<int>& numbers, int target) {
		vector<int> ans;
		bool flag = false;

		for(int i = 0; i < numbers.size(); i++)
		{
			for(int j = i+1; j < numbers.size(); j++)
			{
				
				if(numbers[i] + numbers[j] == target)
				{
					ans.push_back(i+1);
					ans.push_back(j+1);
					flag = true;
				}
				if (flag == true)
					break;
			}
			if (flag == true)
				break;
		}

		return ans;
	}
};


int main()
{

	vector<int> matrix = { { 2,7,11,15 } };
	Solution s;
	vector<int> ans = s.twoSum(matrix, 9);
	for (int i : ans)
		cout << i << ' ';

	return 0;
}