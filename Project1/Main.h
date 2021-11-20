#pragma once
#include<iostream>
#include "PoolManager.h"
#include<memory>
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
int main()
{
	/*
		delcare a pool manager
	*/
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
	/*
	for (auto sprite :pool->getSprites(84))
	{
		std::cout << sprite->getName() << std::endl;
	}*/
	std::cout << pool->getSprite()->getName() << std::endl;
	return 0;
}
