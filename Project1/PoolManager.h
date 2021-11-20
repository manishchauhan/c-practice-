#pragma once
#include<iostream>
#include<queue>
#include<vector>
#include<mutex>
/*
	Pool Manager class
*/

template<typename T>
class PoolManager
{
	private:
		/*
			pool can only hold 100 sprites
		*/
		std::mutex mt;
		const int Limit = 100;
		std::deque<T*> poolContainer;
	public:
		PoolManager() {};
		~PoolManager() {};
		void addToPool(std::vector<T*> sprites)
		{
			if (sprites.size() >= Limit)
			{
				std::cout << "too many spries in the pool" << std::endl;
				return;
			}
			std::unique_lock<std::mutex> lock(mt);
			for (auto sprite:sprites)
			{
				poolContainer.push_back(sprite);
			}
		};
		/*
			get multiple sprites from pool
		*/

		std::vector<T*> getSprites(int total)
		{
			std::vector<T*> sprites;
			if (total >= poolContainer.size())
			{
				std::cout << "sprite pool don't contain that many sprites" << std::endl;
				return sprites;
			}
			std::unique_lock<std::mutex> lock(mt);
		
			for (int i = 0; i < total; i++)
			{
				sprites.push_back(poolContainer.front());
				poolContainer.pop_front();
			}
			return sprites;
		}
		/*
			Destory pool
		*/
		void DestoryPool()
		{
			for (auto sprite : poolContainer)
			{
				delete sprite;
			}
			poolContainer.clear();
		}
		/*
			Get Single sprite from the pool
		*/
		T* getSprite()
		{
			if (poolContainer.size()>0)
			{
				unique_lock<std::mutex> lock(mt);
				std::unique_lock<std::mutex> lock(mt);
				auto sprite=poolContainer.front();
				poolContainer.pop_front();
				return sprite;
			}
			return nullptr;
		}
		/*
		  add single sprite in pool
		*/
		void addSprite(T *sprite)
		{

			if (Limit <= poolContainer.size())
			{
				unique_lock<std::mutex> lock(mt);
				std::unique_lock<std::mutex> lock(mt);
				std::cout << "adding not allowed to pool" << std::endl;
				return;
			}
			poolContainer.push_back(sprite);
		}
};

