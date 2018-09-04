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

	vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {

		vector<int> ans;

		int sumA = 0;
		int sumB = 0;

		for (int i : A) {
			sumA += i;
		}

		for (int j : B) {
			sumB += j;
		}

		int diff = (sumA + sumB) / 2;
		bool found = false;

		for(int i = 0; i < A.size(); i++)
		{
			int offset = sumA - A[i];
			int num = diff - offset;
			for(int j = 0; j < B.size(); j++)
			{
				if(B[j] == num)
				{
					ans.push_back(A[i]);
					ans.push_back(B[j]);
					found = true;
					break;
				}
			}
			if (found == true)
				break;
		}

		return ans;
	}
};

int main()
{	
	Solution s;
	vector<int> A = { 1, 1};
	vector<int> B = { 2, 2};
	vector<int>  ans = s.fairCandySwap(A,B);
	for (int i : ans)
		cout << i << ' ';


	return 0;
}