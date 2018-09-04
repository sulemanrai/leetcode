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
	void rotate(vector<vector<int>>& matrix) {

		int length = matrix.size() - 1;

		for(int row = 0; row <= length/2; row++)
		{
			for(int col = row; col < length - row; col++)
			{
				int temp = matrix[row][col];

				matrix[row][col] = matrix[length - col][row];
				matrix[length - col][row] = matrix[length - row][length - col];
				matrix[length - row][length - col] = matrix[col][length - row];
				matrix[col][length - row] = temp;
			}
		}
	}
};

class MyCalendar {
	vector<pair<int, int>> bookings;
public:
	MyCalendar() {

	}

	bool book(int start, int end) {
		
		if(bookings.empty() == true)
		{
			bookings.push_back(make_pair(start,end));
			return true;
		} 
		for (pair<int, int> element : bookings)
		{
				if(max(element.first,start) < min(element.second,end))
				{
					return false;
				}
				bookings.push_back(make_pair(start, end));
		}
		
		return true;
	}
};

int main()
{
	
	vector<vector<int>> nums = { {1,2,3},
								 {4,5,6},
								 {7,8,9}};
		

	Solution s;

	//s.rotate(nums);
	//cout << ans << endl;
	MyCalendar obj;
	bool ans = obj.book(10, 20);
	bool ans2 = obj.book(15, 25);	

	if (ans == false)
		cout << "false" << endl;
	else
		cout << "true" << endl;

	if (ans2 == false)
		cout << "false" << endl;
	else
		cout << "true" << endl;
	
	
	return 0;
}