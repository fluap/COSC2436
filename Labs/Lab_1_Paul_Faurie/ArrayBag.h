#ifndef ARRAY_BAG_
#define ARRAY_BAG_
#include "BagInterface.h"
#include <vector>

template<class ItemType>
class ArrayBag : public BagInterface<ItemType>
{
private:
	static const int DEFAULT_CAPACITY = 5; // Small size to test for a full bag
	ItemType items[DEFAULT_CAPACITY];       // Array of bag items
	int itemCount;                          // Current count of bag items 
	int maxItems;                           // Max capacity of the bag
	bool sorted = false;                    // Is the array currently sorted?
	// Returns either the first index of the element in the array items that
	// contains the given target or -1, if the array does not contain 
	// the target.
	int getIndexOf(const ItemType& target) const;   //Private helper function
													//Client never needs to know this.

public:
	ArrayBag(); //Constructor
	
	int getCurrentSize() const;  //Returns the number of items in a bag.
	bool isEmpty() const;  //Determines if the bag has any items in it.
	bool add(const ItemType& newEntry);  //Attempts to an item to the bag.
	bool remove(const ItemType& anEntry); //Attempts to remove a item from the bag.
	void clear(); //Removes all items from the bag.
	bool contains(const ItemType& anEntry) const; //Attempts to locate an item in the bag.
	int getFrequencyOf(const ItemType& anEntry) const; //Returns the frequency of an item in a bag.
    std::vector<ItemType> toVector() const; //Converts the bag item(s) into a vector.
	void bubbleSort(); //Sorts the bag in ascending order.
	bool binarySearchHelper(const int& searchType, const ItemType& searchValue) const; // Granulates the binary search algorithm 
	bool iterativeBinarySearch(const ItemType searchArray[], const ItemType& low_index, const ItemType& high_index, const ItemType& searchValue) const; //Executes a binary search algorithm iteratively.
	bool recursiveBinarySearch(const ItemType searchArray[], const ItemType& low_index, const ItemType& high_index, const ItemType& searchValue) const; //Executes a binary search alogorithm recursively.
}; // end ArrayBag

#include "ArrayBag.cpp"
#endif
