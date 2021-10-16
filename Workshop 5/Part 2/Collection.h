#ifndef SDDS_COLLECTION_H
#define SDDS_COLLECTION_H
#include <iostream>

namespace sdds
{
	template<typename T>
	class Collection
	{
		std::string c_collection;
		T* c_arr;
		unsigned int c_size;
		void (*c_ptrToFunc) (const Collection<T>&, const T&); // observer function called when an item is added to a collectiom.
	public:
		Collection(std::string name)
		{
			c_collection = name;
			c_arr = nullptr;
			c_size = 0;
			c_ptrToFunc = nullptr;
		}

		~Collection()
		{
			delete[] c_arr;
			c_arr = nullptr;
		}

		const std::string& name() const
		{
			return c_collection;
		}

		size_t size() const
		{
			return c_size;
		}

		void setObserver(void (*observer)(const Collection<T>&, const T&))
		{
			c_ptrToFunc = observer;
		}

		Collection<T>& operator+=(const T& item)
		{
			bool find = false;
			T* temp = nullptr;
			for (auto i = 0u; i < c_size && !find; i++)
			{
				// Is the movie already in the collection?
				if (c_arr[i].title() == item.title())
				{
					find = true;
				}
			}

			if (!find) // If the movie is not in the collection, add it.
			{
				temp = new T[c_size + 1];
				for (auto i = 0u; i < c_size; i++)
				{
					temp[i] = c_arr[i];
				}
				delete[] c_arr;
				c_arr = nullptr;
				temp[c_size] = item;
				c_arr = new T[c_size + 1];
				for (auto j = 0u; j < c_size + 1; j++)
				{
					c_arr[j] = temp[j];
				}
				c_size++;
				delete[] temp;
				temp = nullptr;
				if (c_ptrToFunc != nullptr)
				{
					(*c_ptrToFunc)(*this, item);
				}
			}
			return *this;
		}

		T& operator[](size_t idx)
		{
			//Catches an out of range exception
			if (idx >= c_size)
			{
				throw std::out_of_range("Bad index [" + std::to_string(idx) + "]. Collection has [" + std::to_string(c_size) + "] items.");
			}
			return c_arr[idx];
		}

		T* operator[](std::string title) // Loks for a movie in the collection, if not found it returns nullptr
		{
			int index = -1;
			bool found = false;
			for (auto i = 0u; i < c_size && !found; i++)
			{
				if (title == c_arr[i].title())
				{
					index = i;
					found = true;
				}
			}

			if (found)
			{
				return &c_arr[index];
			}

			return nullptr;
		}

		Collection(const Collection& o) = delete;
		Collection& operator=(const Collection& o) = delete;

		friend std::ostream& operator<<(std::ostream& os, const Collection& o)
		{
			for (auto i = 0u; i < o.size(); i++)
			{
				os << o.c_arr[i];
			}
			return os;
		}

	};
}


#endif
