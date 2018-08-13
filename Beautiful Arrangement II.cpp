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
	vector<int> constructArray(int n, int k) {

		vector<int> ans;
		int c = 0;
		int *arr = new int[n];

		for(int v = 1; v < n - k; v++)
		{
			arr[c++] = v;			
		}

		for(int i = 0; i <= k; i++)
		{
			arr[c++] = (i % 2 == 0) ? (n - k + i / 2) : (n - i / 2);
		}

		for(int i = 0; i < n; i++)
		{
			ans.push_back(arr[i]);
		}
		
		delete [] arr;
		return ans;

	}
};


int main()
{
	int temp = 0;
	vector<int> nums = { 4,3,2,1,0 };
		

	Solution s;

	vector<int> ans = s.constructArray(3,2);
	for (auto i : ans)
		cout << i << ' ';
	cout << endl;
	
	return 0;
}