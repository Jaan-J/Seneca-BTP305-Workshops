/*
Name: Jaan Javed
Student Number: 100131192
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#ifndef SDDS_COLLECTION_H
#define SDDS_COLLECTION_H
#include <iostream>

namespace sdds{
	template<typename T>
	class Collection{
		std::string collName;
		T* arrayItems;
		unsigned int arraySize;
		void (*funcPtr) (const Collection<T>&, const T&);
	public:
		Collection(std::string name):collName{name}, arrayItems{nullptr},arraySize{0},funcPtr(nullptr){}

		~Collection(){
			delete[] arrayItems;
			arrayItems = nullptr;
		}

		const std::string& name() const{
			return collName;
		}

		size_t size() const{
			return arraySize;
		}

		void setObserver(void (*observer)(const Collection<T>&, const T&)){
			funcPtr = observer;
		}

		Collection<T>& operator+=(const T& item){
			bool find = false;
			T* tempArray = nullptr;
			for (size_t i = 0; i < arraySize && !find; i++){
				if (arrayItems[i].title() == item.title()){
					find = true;
				}
			}
			if (!find) {
				tempArray = new T[arraySize + 1];
				for (size_t i = 0; i < arraySize; i++){
					tempArray[i] = arrayItems[i];
				}

				delete[] arrayItems;
				arrayItems = nullptr;
				tempArray[arraySize] = item;
				arrayItems = new T[arraySize + 1];

				for (size_t i = 0; i < arraySize + 1; i++){
					arrayItems[i] = tempArray[i];
				}

				arraySize++;
				delete[] tempArray;
				tempArray = nullptr;

				if (funcPtr != nullptr){
					(*funcPtr)(*this, item);
				}
			}
			return *this;
		}

		T& operator[](size_t idx){
			if (idx >= arraySize){
				throw std::out_of_range("Bad index [" + std::to_string(idx) + "]. Collection has [" + std::to_string(arraySize) + "] items.");
			}
			return arrayItems[idx];
		}

		T* operator[](std::string title) {
			int index = 0;
			bool flag = false;
			for (size_t i = 0; i < arraySize && !flag; i++){
				if (title == arrayItems[i].title()){
					index = i;
					flag = true;
				}
			}

			if (flag){
				return &arrayItems[index];
			}

			return nullptr;
		}

		friend std::ostream& operator<<(std::ostream& os, const Collection& o){
			for (size_t i = 0; i < o.size(); i++){
				os << o.arrayItems[i];
			}
			return os;
		}

		Collection(const Collection& o) = delete;
		Collection& operator=(const Collection& o) = delete;

	};
}
#endif
