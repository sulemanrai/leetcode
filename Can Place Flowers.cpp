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

	bool canPlaceFlowers(vector<int>& flowerbed, int n) {
		bool ans = false;
		int count = 0;

		if (flowerbed[0] == 0 && flowerbed[1] == 0 && flowerbed[2] == 1) {
			flowerbed[0] = 1;
			count++;
		}
		if (flowerbed[0] == 0 && flowerbed[1] == 0 && flowerbed[2] == 0 && count < n) {

			flowerbed[0] = 1;
			count++;
		}
		if (flowerbed[flowerbed.size() - 1] == 0 && flowerbed[flowerbed.size() - 2] == 0 && flowerbed[flowerbed.size() - 3] == 1 && count < n) {

			flowerbed[flowerbed.size() - 1] = 1;
			count++;
		}
		if (flowerbed[flowerbed.size() - 1] == 0 && flowerbed[flowerbed.size() - 2] == 0 && flowerbed[flowerbed.size() - 3] == 0 && count < n) {

			flowerbed[flowerbed.size() - 1] = 1;
			count++;
		}

		if (count < n) {

			for (int i = 1; i < flowerbed.size() - 1; i++)
			{
				if (flowerbed[i] == 0 && flowerbed[i - 1] == 0 && flowerbed[i + 1] == 0)
				{
					count++;
					flowerbed[i] = 1;
				}
				if (count == n)
					break;
			}
		}
		if(count == n)
		{
			ans = true;
		}

		return ans;
	}
};


int main()
{

	//vector<int> nums = { 1,2,1 };
	vector<int> nums = { 0,1,0,1,0,1,0,0,1,0,0,0,0,1,0,0,1,0,1,0,1,0,1,0,1,0,0,0,1,0,1,0,0,0,0,0,0,1,0,0,1,0,1,0,1,0,0,0,1,0,1,0,1,0,1,0,1,0,0,1,0,0,0,0,0,1,0,1,0,1,0,1,0,0,1,0,1,0,0,1,0,1,0,1,0,1,0,1,0,1,0,0,0,1,0,1,0,0,0,0,1,0,1,0,1,0,1,0,0,1,0,0,0,1,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,1,0,1,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,1,0,1,0,0,1,0,1,0,0,1,0,1,0,1,0,1,0,1,0,1,0,0,0,1,0,1,0,0,0,0,1,0,0,0,1,0,0,1,0,0,0,1,0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,1,0,1,0,1,0,0,0,1,0,0,1,0,1,0,0,1,0,0,1,0,1,0,1,0,1,0,1,0,1,0,0,1,0,1,0,0,1,0,0,0,0,1,0,1,0,1,0,0,1,0,1,0,0,1,0,0,1,0,0,1,0,1,0,1,0,0,0,1,0,1,0,0,1,0,1,0,1,0,1,0,1,0,1,0,0,0,1,0,0,1,0,0,1,0,1,0,0,1,0,0,0,1,0,0,1,0,1,0,1,0,0,0,1,0,0,0,1,0,1,0,1,0,0,0,1,0,0,1,0,0,1,0,0,0,0,1,0,0,0,0,0,1,0,1,0,1,0,1,0,0,1,0,1,0,1,0,0,0,1,0,0,0,1,0,0,1,0,1,0,0,0,1,0,0,0,1,0,0,1,0,1,0,1,0,0,1,0,1,0,1,0,1,0,1,0,1,0,0,1,0,1,0,1,0,1,0,0,1,0,1,0,0,0,1,0,1,0,1,0,1,0,0,1,0,0,1,0,0,0,1,0,1,0,1,0,0,0,0,0,1,0,0,0,1,0,1,0,0,0,0,1,0,1,0,1,0,0,0,1,0,1,0,1,0,0,1,0,0,1,0,1,0,1,0,1,0,0,1,0,0,1,0,1,0,0,0,1,0,0,0,1,0,0,1,0,1,0,0,0,1,0,1,0,0,1,0,0,0 };
	//vector<int> nums = { 1,0,1,1 };
	//vector<int> nums = { 1,2,3,1,2,3 };
	//vector<int> nums = { 99,99 };
	

	Solution s;

	bool ans = s.canPlaceFlowers(nums, 25);	
	if (ans == true)
		cout << "true" << endl;
	else
		cout << "false" << endl;
	
	return 0;
}