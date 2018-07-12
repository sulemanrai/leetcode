#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

class Solution {
public:

	void swap(int *a, int *b)
	{
		int temp;
		temp = *a;
		*a = *b;
		*b = temp;
	}

	/* Utility function that puts all non-positive (0 and negative) numbers on left
	side of arr[] and return count of such numbers */
	int segregate(int arr[], int size)
	{
		int j = 0, i;
		for (i = 0; i < size; i++)
		{
			if (arr[i] <= 0)
			{
				swap(&arr[i], &arr[j]);
				j++; // increment count of non-positive integers
			}
		}

		return j;
	}

	/* Find the smallest positive missing number in an array that contains
	all positive integers */
	int findMissingPositive2(int arr[], int size)
	{
		int i;
		//cout << "size is " << size << endl;
		// Mark arr[i] as visited by making arr[arr[i] - 1] negative. Note that 
		// 1 is subtracted because index start from 0 and positive numbers start from 1
		for (i = 0; i < size; i++)
		{
			if (abs(arr[i]) - 1 < size && arr[abs(arr[i]) - 1] > 0)
				arr[abs(arr[i]) - 1] = -arr[abs(arr[i]) - 1];

		}


		// Return the first index value at which is positive
		for (i = 0; i < size; i++)
			if (arr[i] > 0)
				return i + 1; // 1 is added becuase indexes start from 0

		return size + 1;
	}

	/* Find the smallest positive missing number in an array that contains
	both positive and negative integers */
	int findMissing(int arr[], int size)
	{
		// First separate positive and negative numbers
		int shift = segregate(arr, size);
		//cout << "shift is " << shift << endl;

		// Shift the array and call findMissingPositive for
		// positive part
		return findMissingPositive2(arr + shift, size - shift);
	}

	int firstMissingPositive(vector<int>& nums) {
		int  * arr = new int[nums.size()];

		for (int i = 0; i < nums.size(); i++) {
			arr[i] = nums[i];
		}

		int arr_size = sizeof(arr) / sizeof(arr[0]);
		int ans = findMissing(arr, nums.size());

		delete[] arr;
		return ans;
	}
};


int main()
{
	//code
	vector<int> nums1 = { 1,2,0 };
	//vector<int> nums1 = { 0, 10, 2, -10, -20 };
	int target = 8;
	Solution s;
	cout << s.firstMissingPositive(nums1) << endl;
	// Solution s;
	// int arr[] = { 1,2,0 };
	// int arr_size = sizeof(arr) / sizeof(arr[0]);
	// int missing = s.findMissing(arr, arr_size);
	// printf("The smallest positive missing number is %d ", missing);

	return 0;
}