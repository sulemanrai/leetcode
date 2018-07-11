#include<iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <functional>
using namespace std;

class Solution {
public:
	// Print all members of ar[] that have given
	void findNumbers(vector<int>& ar, int sum,
		vector<vector<int> >& res,
		vector<int>& r, int i)
	{
		// If current sum becomes negative
		if (sum < 0)
			return;

		// if we get exact answer
		if (sum == 0)
		{
			res.push_back(r);
			return;
		}

		// Recur for all remaining elements that
		// have value smaller than sum.
		while (i < ar.size() && sum - ar[i] >= 0)
		{

			// Till every element in the array starting
			// from i which can contribute to the sum
			r.push_back(ar[i]); // add them to list

								// recur for next numbers
			findNumbers(ar, sum - ar[i], res, r, i);
			i++;

			// remove number from list (backtracking)
			r.pop_back();
		}
	}
	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		
		vector<vector<int>> res;
		vector<int> r;
		sort(candidates.begin(), candidates.end());
		findNumbers(candidates, target, res, r, 0);
		for (int i : r)
			cout << i << ' ';
		return res;
	}
};


int main()
{
	//code
	vector<int> nums1 = { 2,3,6,7 };
	int target = 7;
	Solution s;
	vector<vector<int>> ans = s.combinationSum(nums1,target);
	//cout << ans << endl;
	for(int i = 0; i < ans.size(); i++)
	{
		for (int i : ans[i])
			cout << i << ' ';
		cout << endl;
	}
	
	return 0;
}