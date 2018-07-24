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
	bool isValidCharacter(int a, int b)
	{
		bool isValid = false;

		 if(a == 1 && b == 1)
		{
			isValid = true;
		} else if(a == 1 && b == 0)
		{
			isValid = true;
		} else if (a == 0 && b == 0)
		{
			isValid = true;
		} else if(a == 0 && b == 1)
		{
			isValid = false;
		}

		return isValid;
	}


	bool isOneBitCharacter(vector<int>& bits) {		
		bool isOneBit = false;
		list<int> listBit;
		for (int i : bits)
			listBit.push_back(i);

		if (listBit.size() == 1 && listBit.front() == 0)
			return true;


		int a;
		int b;
		
		while (listBit.size() != 2)
		{
			list<int>::iterator itr = listBit.begin();
			a = listBit.front();
			++itr;
			b = *itr;
			if (isValidCharacter(a, b) == true)
			{
				listBit.pop_front();
				listBit.pop_front();
			}
			else if (isValidCharacter(a, b) == false)
			{
				listBit.pop_front();
			}
			if (listBit.size() == 1)
				break;
		}

		if (listBit.size() == 2)
		{
			a = listBit.front();
			listBit.pop_front();
			b = listBit.front();
			listBit.pop_front();

			if (a == 1 && b == 0)
			{
				isOneBit = false;
			}
			else if (a == 0 && b == 0)
			{
				isOneBit = true;
			}
		} else if(listBit.size() == 1 && listBit.front() == 0)
		{
			isOneBit = true;
		}

		

		//isOneBit = isValidCharacter(a, b);
		return isOneBit;
	}
};


int main()
{

	vector<int> matrix = { {0,1,0,0}};
	Solution s;
	bool ans = s.isOneBitCharacter(matrix);
	if (ans == true) {
		cout << "true" << endl;
	} else
	{
		cout << "false" << endl;
	}

	return 0;
}