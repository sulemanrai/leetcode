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

	bool MonotonicIncreasing(vector<int> &A)
	{
		bool forward = false;
		for (int i = 0; i < A.size() - 1; i++)
		{
			if (A[i + 1] >= A[i])
			{
				forward = true;
			}
			else
			{
				forward = false;
				break;
			}
		}
		return forward;
	}

	bool MonotonicDecreaseing(vector<int> &A)
	{
		reverse(A.begin(), A.end());
		bool backward = false;
		for (int j = A.size() - 1; j > 0; j--)
		{
			if (A[j] >= A[j - 1])
			{
				backward = true;
			}
			else
			{
				backward = false;
				break;
			}
		}
		return backward;
	}

	bool isMonotonic(vector<int>& A) {

		if (A.size() == 1)
			return true;
		
		bool ans = MonotonicIncreasing(A) || MonotonicDecreaseing(A);		
		return ans;
	}
};

int main()
{	
	Solution s;
	vector<int> arr = { 1,1,1 };
	bool  ans = s.isMonotonic(arr);
	if (ans == false)
		cout << "false" << endl;
	else
		cout << "true" << endl;


	return 0;
}