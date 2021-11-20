#pragma once
#include<iostream>
#include<queue>
#include<vector>
#include<mutex>
#include<functional>
#include<unordered_map>
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
		std::unordered_map<std::string, std::deque<T*>> multispriteMap;
		std::mutex mt;
		const int Limit = 100;
		std::deque<T*> poolContainer;
	public:
		PoolManager() {};
		~PoolManager() {};

		void addToPool(std::vector<T*> sprites, std::string poolName)
		{
			std::unique_lock<std::mutex> lock(mt);
			std::deque<T*> poolContainer;
			for (auto sprite : sprites)
			{
				poolContainer.push_back(sprite);
			}
			multispriteMap.at(std::pair<std::string, std::deque<T*>>(poolName, poolContainer));
		
		};	

		std::vector<T*> getSprites(std::string poolName,int total)
		{
			std::vector<T*> sprites;
			if (total >= poolContainer.size())
			{
				std::cout << "sprite pool don't contain that many sprites" << std::endl;
				return sprites;
			}
			std::unique_lock<std::mutex> lock(mt);
			auto find = multispriteMap.find(poolName);
			if (find != multispriteMap.end())
			{
				std::deque<T*> poolContainer= multispriteMap[poolName];
				for (int i = 0; i < poolContainer.size(); i++)
				{
					sprites.push_back(poolContainer.front());
					poolContainer.pop_front();
				}
			}
			else
			{
				std::cout << "key not found" << std::endl;
				return sprites;
			}
			
			return sprites;
		}

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
			if (poolContainer.size() > 0)
			{
				for (auto sprite : poolContainer)
				{
					delete sprite;
				}
				poolContainer.clear();
			}
			
			if (multispriteMap.size() > 0)
			{
				for (auto pool : multispriteMap)
				{
					for (auto sprite : pool)
					{
						delete sprite;
					}
				}
				multispriteMap.clear();
			}
			
		}
		/*
			Get Single sprite from the pool
		*/
		T* getSprite()
		{
			if (poolContainer.size()>0)
			{
				std::unique_lock<std::mutex> lock(mt);
				auto sprite=poolContainer.front();
				poolContainer.pop_front();
				return sprite;
			}
			return nullptr;
		}
		/*
			sprite with callback
		*/
		void getSprite(std::function<void(T*)> callBack)
		{
			if (callBack == nullptr)
			{
				std::cout << "must define a callback" << std::endl;
				return;
			}
			if (callBack)
			{
				std::unique_lock<std::mutex> lock(mt);
				auto sprite = poolContainer.front();
				poolContainer.pop_front();
				if (callBack)
				{
					callBack(sprite);
				}
			}
		}
		
		/*
		  add single sprite in pool
		*/
		void addSprite(T *sprite)
		{

			if (Limit <= poolContainer.size())
			{
			
			
				std::cout << "adding not allowed to pool" << std::endl;
				return;
			}
			std::unique_lock<std::mutex> lock(mt);
			poolContainer.push_back(sprite);
		}
};

