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
	int maxDistToClosest(vector<int>& seats) {
		int maxDistance = 0;

		int prev = -1;
		int future = 0;

		for(int i = 0; i < seats.size(); i++)
		{
			if (seats[i] == 1) {
				prev = i;
			} else
			{
				while(future < seats.size() && seats[future] == 0 || future < i)
				{
					future++;
				}
			}
			int left = prev == -1 ? seats.size() : i - prev;
			int right = future == seats.size() ? seats.size() : future - i;
			maxDistance = max(maxDistance, min(left, right));
		}

		return maxDistance;
	}

};


int main()
{

	vector<int> nums = { 1,0,0,0 };
	Solution s;

	int ans = s.maxDistToClosest(nums);
	cout << ans << endl;	
	return 0;
}