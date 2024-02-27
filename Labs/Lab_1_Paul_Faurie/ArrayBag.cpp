#include "ArrayBag.h"
#include <iostream>
#include <cstddef>
#include <string>

// Default constructor
// Creates an ADT bag
template<class ItemType>
ArrayBag<ItemType>::ArrayBag(): itemCount(0), maxItems(DEFAULT_CAPACITY)
{
}  // end default constructor

//Return an integer count of the number of items in the bag.
template<class ItemType>
int ArrayBag<ItemType>::getCurrentSize() const
{
	return itemCount;   //Uses the item count tracking variable.
}  // end getCurrentSize


//Return whether or not the bag contains any items.
template<class ItemType>
bool ArrayBag<ItemType>::isEmpty() const
{
	return itemCount == 0; //Uses the item count tracking variable.
}  // end isEmpty

//Adds an item to the bag.
template<class ItemType>
bool ArrayBag<ItemType>::add(const ItemType& newEntry)
{
	bool hasRoomToAdd = (itemCount < maxItems);  //Verification that there is room to add an item.
	if (hasRoomToAdd)
	{
		items[itemCount] = newEntry; // Inserts the item at the end of the bag.
		itemCount++; //Increases the itemcount tracker variable by 1.
      sorted = false; //signify that the bag is no longer sorted.
	}  // end if
	return hasRoomToAdd;
}  // end add

// Removes an item from the bag.
template<class ItemType>
bool ArrayBag<ItemType>::remove(const ItemType& anEntry)
{
   int locatedIndex = getIndexOf(anEntry);   //Find the index of the item to be removed.
	bool canRemoveItem = !isEmpty() && (locatedIndex > -1); // Verifies that the item can be removed (found).
	if (canRemoveItem)
	{
		itemCount--; //Decrement the bag item count tracking variable.
		items[locatedIndex] = items[itemCount]; //Replaces the item with the last item in the bag.
      sorted = false; //Signify that the bag is no longer sorted.
	}  // end if
	return canRemoveItem;
}  // end remove

//Sorts the bag in ascending order via a bubble sort algorithm.
template<class ItemType>
void ArrayBag<ItemType>::bubbleSort()
{
      int i, j; //Bubble or pair indecies for the sort.
      bool swapped;
      for (i = 0; i < itemCount - 1; i++)
      {
         swapped = false;
         for (j = 0; j < itemCount - i - 1; j++)
         {
            if (items[j] > items[j+1])    //Comparator of the bubbled indecies and determinant for a swap.
            {
               std::swap(items[j], items[j + 1]);  //Swap of the indecies, magic of the bubble sort happens here.
               swapped = true;
            }
         } // End for.
      } // End for.
      sorted = true;
  // }  
 }// end bubbleSort


//Binary search algorithm via ITERATIVE method.
template<class ItemType>	
bool ArrayBag<ItemType>::iterativeBinarySearch(const ItemType searchArray[], const ItemType& low_index, const ItemType& high_index, const ItemType& searchValue) const
{
   if (sorted)
   {
      int lower_index = low_index;                        //
      int higher_index = high_index;                      // Standard required ingredients for 
      bool valueFound = false;  //base case NOT FOUND.    // An iterative binary search.
      while (lower_index <= higher_index && !valueFound)  //
      {
          int middle_index = lower_index + (higher_index - lower_index) / 2; //'halving' binary effect search.
          if (items[middle_index] == searchValue)
          {
           valueFound = true; // Base case FOUND.
          }
          if (items[middle_index] < searchValue)
          {
            lower_index = middle_index + 1;  //Iterative split skewed right ->
          }
          else
          {
            higher_index = middle_index - 1; //Iterative split skewed left <-
          }
      } // End while
      return valueFound;
   }
}
//end iterativeBinarySearch

//Binary search algorithm via RECURSIVE method.
template<class ItemType>
bool ArrayBag<ItemType>::recursiveBinarySearch(const ItemType searchArray[], const ItemType& low_index, const ItemType& high_index, const ItemType& searchValue) const
{
    if (high_index >= low_index) {
        int middle_index = low_index + (high_index - low_index) / 2; //Halving binary effect.
 
        // If the element is present at the middle
        // itself
        if (searchArray[middle_index] == searchValue) //Base case FOUND
            return true;
 
        // If element is smaller than mid, then
        // it can only be present in left subarray
        if (searchArray[middle_index] > searchValue)
            return iterativeBinarySearch(searchArray, low_index, middle_index - 1, searchValue); //Recursively search using a left skewed split <-
 
        // Else the element can only be present
        // in right subarray
        return iterativeBinarySearch(searchArray, middle_index + 1, high_index, searchValue); //Recusrively search using a right skewed split ->
    }
 
    // We reach here when element is not
    // present in array
    return -1; //Base case NOT FOUND
}
//end recursiveBinarySearch


//Daughter function to serve the binary search methodologies.
//Supports granulation both iterative and recursive binary searches.
template<class ItemType>
bool ArrayBag<ItemType>::binarySearchHelper(const int& searchType, const ItemType& searchValue) const //injest value and type. (determined by client)
{
   switch (searchType)
   {
      case 1: //Execute iterative binary search.
         return iterativeBinarySearch(items, 0, DEFAULT_CAPACITY - 1, searchValue);
         break;

      case 2: //Execute recursive binary search.
      {
         return recursiveBinarySearch(items, 0, DEFAULT_CAPACITY - 1, searchValue);
         break;
      }
      default: //Layer of robust in case client bypasses limits of 1 and 2.
      {
         return false;
         break;
      }
   } // End switch
}
//end binarySearchHelper

//Clears all values in a bag.
template<class ItemType>
void ArrayBag<ItemType>::clear()
{
	itemCount = 0; //Uses the item tracking variable.
}  // end clear


//Attempts to find a specified bag item.
template<class ItemType>
bool ArrayBag<ItemType>::contains(const ItemType& anEntry) const
{
	return getIndexOf(anEntry) > -1;  //One liner of whether or not the item exists within the bag.
}  // end contains

//Finds the occurence of a specified item in a bag.
template<class ItemType>
int ArrayBag<ItemType>::getFrequencyOf(const ItemType& anEntry) const
{
   int frequency = 0;
   int curIndex = 0;       // Current array index
   while (curIndex < itemCount)  //Limit search to the number of items in the bag using the count tracking variable.
   {
      if (items[curIndex] == anEntry) //If the item is found 
      {
         frequency++; //incremet the occurence (frequency)
      }  // end if
      
      curIndex++; // Increment to next entry
   }  // end while
   
   return frequency;
}  // end getFrequencyOf


//Converts the item of the bag to a vector. 
template<class ItemType>
std::vector<ItemType> ArrayBag<ItemType>::toVector() const
{
   std::vector<ItemType> bagContents; //Creation of the vector
	for (int i = 0; i < itemCount; i++) //Limites the operation to the number of items in the bag.
   {
		bagContents.push_back(items[i]); // add item to the vector.
   } //end for
   return bagContents; //return the vector.
}  // end toVector


// Attempts to return the location of the specified item within the bag.
template<class ItemType>
int ArrayBag<ItemType>::getIndexOf(const ItemType& target) const
{
	bool found = false;  //Default flag NOT FOUND
   int result = -1;     //Default result NOT FOUND
   int searchIndex = 0; //Beginning index.
   
   while (!found && (searchIndex < itemCount)) // If the bag is empty, itemCount is zero, so loop is skipped
   {
      if (items[searchIndex] == target) //If the value is found...
      {
         found = true;         //Raise the flag
         result = searchIndex; //Set the index of the value.
      } 
      else
      {
         searchIndex++; //Increment to the next index.
      }  // end if
   }  // end while
   
   return result; //Return the index.
}  // end getIndexOf
