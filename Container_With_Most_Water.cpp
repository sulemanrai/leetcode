#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int maxArea(vector<int>& height) {
		
		int area = 0;

		// int left = 0;
		// int right = height.size() - 1;
  //
		// while (left < right)
		// {
		// 	
		// 	int base = abs(left - right);
		// 	int Height = min(height[left], height[right]);			
		// 	area = max(area, base * Height);
		// 	left++;
		// }
		for (int i = 0; i < height.size(); i++)
		{
			for (int j = i + 1; j < height.size(); j++)
			{
				int base = j - i;
				int Height = min(height[i], height[j]);
				int temp = base * Height;
				area = max(area, temp);
			}
		}
		return area;
	}
};
int main()
{
	//code
	vector<int> nums1 = { 2,3,4,5,18,17,6 };

	Solution s;
	int ans = s.maxArea(nums1);
	cout << ans << endl;
	


	return 0;
}