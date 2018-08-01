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
	int addWithCarry(vector<int> & vec, int index)
	{
		if (index == vec.size())
			return 1;
		
		index++;
		int res = vec[index - 1] + addWithCarry(vec,index);		
		vec[index - 1] = (res) % 10;
		return (res) / 10;
	}

	vector<int> plusOne(vector<int>& digits) {
		vector<int> ans;
		int index = 0;
		int  carry = addWithCarry(digits, index);;
		vector<int>::const_iterator first = digits.begin();
		vector<int>::const_iterator last = digits.end();

		if(carry == 1)
		{
			ans.push_back(carry);
			copy(digits.begin(), digits.end(), back_inserter(ans));
		} else
		{
			ans = digits;
		}
		
		return ans;
	}
};


int main()
{
	vector<int> nums =  {7,2,8,5,0,9,1,2,9,5,3,6,6,7,3,2,8,4,3,7,9,5,7,7,4,7,4,9,4,7,0,1,1,1,7,4,0,0,6 };
	//vector<int> nums = { 4,3,2,1 };
	Solution s;

	 vector<int> ans = s.plusOne(nums);
	 for (int i : ans)
	 	cout << i << ' ';
	cout << endl;
	return 0;
}