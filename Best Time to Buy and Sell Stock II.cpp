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
	// solution structure
	struct Interval
	{
		int buy;
		int sell;
	};

	int maxProfit(vector<int>& prices) {
		int ans = 0;

		// Prices must be given for at least two days
		if (prices.size() == 1)
			return 0;

		int count = 0; // count of solution pairs

					   // solution vector
		int n = prices.size();
		Interval * sol = new Interval[n/2 + 1] ;

		// Traverse through given price array
		int i = 0;
		while(i < n - 1)
		{
			// Find Local Minima. Note that the limit is (n-2) as we are
			// comparing present element to the next element. 
			while ((i < n - 1) && (prices[i + 1] <= prices[i]))
			{
				i++;
			}

			// If we reached the end, break as no further solution possible
			if (i == n - 1)
				break;

			// Store the index of minima
			sol[count].buy = prices[i++];

			// Find Local Maxima.  Note that the limit is (n-1) as we are
			// comparing to previous element
			while ((i < n ) && (prices[i] >= prices[i-1]))
			{
				i++;
			}

			// Store the index of minima
			sol[count].sell = prices[i-1];

			count++;
		}
		for(int j = 0; j < count; j++)
		{
			ans += sol[j].sell - sol[j].buy;
		}

		delete[] sol;
		return ans;
	}
};


int main()
{

	vector<int> matrix = { { 7,1,5,3,6,4 } };
	Solution s;
	int ans = s.maxProfit(matrix);
	cout << ans << endl;

	return 0;
}