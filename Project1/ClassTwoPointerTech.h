#pragma once
#include<iostream>
#include<queue>
#include<vector>
#include<mutex>
#include<functional>
#include<unordered_map>
#include<algorithm>
class ClassTwoPointerTech
{
public:

	
	static bool checkSum(std::vector<int> values,int value)
	{
		//sort the data first
		sort(values.begin(), values.end());
		bool isSumThere = false;
		int low = 0;
		int high = values.size() - 1;
		while (low<high)
		{
			int sum = values.at(low) + values.at(high);
			if (sum == value)
			{
				isSumThere = true;
				return isSumThere;
			}
			else if (sum > value)
			{
				high--;
			}
			else if (sum < value)
			{
				low++;
			}
		}
		return isSumThere;
	}
	static bool checkMinus(std::vector<int> values, int value)
	{
		sort(values.begin(), values.end());
		bool isSumThere = false;
		int first = 0;
		int second= first+1;
		while (first<second)
		{
			int minus = values.at(second) - values.at(first);
			if (minus == value)
			{

				isSumThere = true;
				return isSumThere;
			}
			else if (minus > value)
			{
				
				first++;
			}
			else if (minus < value)
			{
				second++;
			}
		}
		return isSumThere;
	}
};

