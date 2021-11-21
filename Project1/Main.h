#pragma once
#include<iostream>
#include "PoolManager.h"
#include<memory>
#include <vector>
#include "ClassTwoPointerTech.h"
#define ROWS 3
#define COLS 3
class SomeSprite
{
private:
	const std::string name="some random sprite";
public:
	SomeSprite() {};
	~SomeSprite() {};
	const std::string& getName() const
	{
		return name;
	}
};

int b_search(std::vector<int> elements,int value)
{
	int index = -1;
	int low = 0;
	int high = elements.size() - 1;

	while (low <= high)
	{
			
		int mid = (low+high) / 2;

		if (elements.at(mid) == value)
		{
			return mid;
		}
		 if (elements.at(mid) < value)
		{
			low = mid + 1;
		}
		else
		{
			high = mid - 1;
		}
	}
	return index;
}

int main()
{ 
	std::vector<int> values = { 1,2,11,13,24 };
	bool status = ClassTwoPointerTech::checkSum(values, 37);
	std::cout <<"plus case "<< status<<std::endl;



	bool status1 = ClassTwoPointerTech::checkMinus(values, 23);
	std::cout << "minus case " << status1 << std::endl;




	std::vector<int> arr = { 1,0,1,0,1,0,1 };


	for (auto value : ClassTwoPointerTech::sortOneZero(arr))
	{
		std::cout << value << std::endl;
	}

	/*
	std::vector<int> results = { 11,22,33,44,155 };
	int result = b_search(results, 55);
	std::cout << result << std::endl;
	
	std::vector<std::vector<int>> myVector(ROWS, std::vector<int>(COLS,0));
	for (auto row : myVector)
	{
		for (auto c : row)
		{
			std::cout <<" "<< c<<" ";
		}
		std::cout << "" << std::endl;
	}

	std::vector<int> vec1 = { 1,2,3,4,5 };
	std::vector<int> vec2 = { 6,7,8 };
	vec1.insert(vec1.begin(),vec2.begin(), vec2.end());
	*/
	/*
		delcare a pool manager
	
	std::unique_ptr<PoolManager<SomeSprite>> pool = std::make_unique<PoolManager<SomeSprite>>();
	//add 75 sprites
	for (int i = 0; i < 75; i++)
	{
		SomeSprite* sp = new SomeSprite();
		pool->addSprite(sp);
	}

	std::vector<SomeSprite*> random_pool;
	for (int i = 0; i < 10; i++)
	{
		SomeSprite* sp = new SomeSprite();
		random_pool.push_back(sp);
	}
	pool->addToPool(random_pool);

	std::cout << pool->getSprite()->getName() << std::endl;
	pool->getSprite([=](SomeSprite* sp) {
		std::cout << sp->getName() << std::endl;
		});*/
	return 0;
}
