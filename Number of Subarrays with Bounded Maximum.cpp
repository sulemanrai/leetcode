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

	int numSubarrayBoundedMax(vector<int>& A, int L, int R) {

		int res = 0, heads = 0, tails = 0;

		for(int i = 0; i < A.size(); i++)
		{
			if(A[i] >= L && A[i] <= R)
			{
				heads += tails + 1;
				res += heads;
			} else if(A[i] < L)
			{
				tails++;
				res += tails;
			} else
			{
				heads = 0;
				tails = 0;
			}
		}

		return res;
	}
};

int main()
{	
	Solution s;
	
	vector<int> A = { 2, 1, 4, 3 };

	int ans = s.numSubarrayBoundedMax(A , 2, 3);
	cout << ans << endl;


	return 0;
}