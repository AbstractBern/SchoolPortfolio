/** Header file for an array-based implementation of the ADT bag.
 @author bernardo flores : @file ArraySet.h */

#ifndef ARRAY_SET_H
#define ARRAY_SET_H
#include "SetInterface.h"

template<class ItemType>
class ArraySet : public SetInterface<ItemType>
{
	private:
		static const int DEFAULT_CAPACITY = 6; // Small size to test for a full set
		ItemType items[DEFAULT_CAPACITY];      // Array of set items
		int itemCount;                         // Current count of set items 
		int maxItems;                          // Max capacity of the set
		// Returns either the index of the element in the array items that
		// contains the given target or -1, if the array does not contain 
		// the target.
		int indexPos(const ItemType& target) const;   
	public:
		ArraySet();
		ArraySet(const ItemType arr[], int itemCount);
		int currentSize() const;
		bool emptyData() const;
		bool addEntry(const ItemType& newEntry);
		bool removeEntry(const ItemType& anEntry);
		void eraseData();
		bool findEntry(const ItemType& anEntry) const;
	   std::vector<ItemType> toVector() const;
}; // end ArraySet

/** Implementation file for the class ArraySet.
 @file ArraySet.cpp */

#include <cstddef>

template<class ItemType>
ArraySet<ItemType>::ArraySet(): itemCount(0), maxItems(DEFAULT_CAPACITY)
{
}  // end default constructor

template<class ItemType>
ArraySet<ItemType>::ArraySet(const ItemType arr[], int num): itemCount(num), maxItems(DEFAULT_CAPACITY)
{
	for (int i=0; i<num; i++)
	{
		items[i]=arr[i];
	}
}  // end second constructor

template<class ItemType>
int ArraySet<ItemType>::currentSize() const
{
	return itemCount;
}  // end currentSize

template<class ItemType>
bool ArraySet<ItemType>::emptyData() const
{
	return itemCount == 0;
}  // end emptyData

template<class ItemType>
bool ArraySet<ItemType>::addEntry(const ItemType& newEntry)
{
	bool hasRoomToAdd = (itemCount < maxItems);
	if (hasRoomToAdd)
	{
		if (newEntry != items[itemCount])
		{
			items[itemCount] = newEntry;
			itemCount++;
		}
		//if entry could not be added operation  unsuccessful!?
	}  // end if
	return hasRoomToAdd;
}  // end addEntry

template<class ItemType>
bool ArraySet<ItemType>::removeEntry(const ItemType& anEntry)
{
   int locatedIndex = indexPos(anEntry);
	bool canRemoveItem = !emptyData() && (locatedIndex > -1);
	if (canRemoveItem)
	{
		itemCount--;
		items[locatedIndex] = items[itemCount];
	}  // end if
    
	return canRemoveItem;
}  // end removeEntry

template<class ItemType>
void ArraySet<ItemType>::eraseData()
{
	itemCount = 0;
}  // end eraseData

template<class ItemType>
bool ArraySet<ItemType>::findEntry(const ItemType& anEntry) const
{
	return indexPos(anEntry) > -1;
}  // end findEntry

template<class ItemType>
std::vector<ItemType> ArraySet<ItemType>::toVector() const
{
   std::vector<ItemType> setContents;
	for (int i = 0; i < itemCount; i++)
		setContents.push_back(items[i]);
      
   return setContents;
}  // end toVector

// private
template<class ItemType>
int ArraySet<ItemType>::indexPos(const ItemType& target) const
{
	bool found = false;
   int result = -1;
   int searchIndex = 0;
   
   // If the bag is empty, itemCount is zero, so loop is skipped
   while (!found && (searchIndex < itemCount))
   {
      if (items[searchIndex] == target)
      {
         found = true;
         result = searchIndex;
      } 
      else
      {
         searchIndex++;
      }  // end if
   }  // end while
   
   return result;
}  // end indexPos
#endif
