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
	static std::vector<int> sortOneZero(std::vector<int> arr)
	{
		int left = 0;
		int right = arr.size() - 1;
		while (left<right)
		{
			if (arr[left] == 1)
			{
				
				std::swap(arr[left], arr[right]);
				right--;
			}
			else
			{
				left++;
			}
		}
		return arr;
	}
};

