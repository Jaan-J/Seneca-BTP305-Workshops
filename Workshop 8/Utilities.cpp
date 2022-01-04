/*
Name: Jaan Javed
Student Number: 100131192
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#include <memory>
#include "List.h"
#include "Element.h"
#include "Utilities.h"

using namespace std;

namespace sdds {
	List<Product> mergeRaw(const List<Description>& desc, const List<Price>& price) {
		List<Product> priceList;
		// TODO: Add your code here to build a list of products
		//         using raw pointers

		Product* mrProduct = nullptr;
		for (size_t i = 0; i < desc.size(); i++)
			for (size_t d = 0; d < price.size(); d++)
				if (desc[i].code == price[d].code) {
					mrProduct = new Product(desc[i].desc, price[d].price);
					mrProduct ->validate();
					priceList += (mrProduct);
					delete mrProduct;
					mrProduct = nullptr;
				}

		return priceList;
	}

	List<Product> mergeSmart(const List<Description>& desc, const List<Price>& price) {
		List<Product> priceList;
		// TODO: Add your code here to build a list of products
		//         using raw pointers

		for (size_t i = 0; i < desc.size(); i++)
			for (size_t d = 0; d < price.size(); d++)
				if (desc[i].code == price[d].code) {
					std::unique_ptr<Product> msProduct(new Product(desc[i].desc, price[d].price));
					msProduct->validate();
					priceList += (msProduct);
					msProduct = nullptr;
				}

		return priceList;
	}
}