//  Created by Frank M. Carrano and Tim Henry.
//  Copyright (c) 2016 __Pearson Education__. All rights reserved.

/** Array-based implementation of the ADT heap.
 Listing 17-2.
 @file ArrayMaxHeap.h */ 
 
#ifndef ARRAY_MAX_HEAP_H
#define ARRAY_MAX_HEAP_H


#include <iostream>
#include "HeapInterface.h"
#include "PrecondViolatedExcep.h"

template<class ItemType>
class ArrayMaxHeap : public HeapInterface<ItemType>
{
private:
   static const int ROOT_INDEX = 0;        // Helps with readability
   static const int DEFAULT_CAPACITY = 10; // Small capacity to test for a full heap
   ItemType *items;                        // Array of heap items
   int itemCount;                          // Current count of heap items
   int maxItems;                           // Maximum capacity of the heap
   
   // ---------------------------------------------------------------------
   // Most of the private utility methods use an array index as a parameter
   // and in calculations. This should be safe, even though the array is an
   // implementation detail, since the methods are private.
   // ---------------------------------------------------------------------
   
   // Returns the array index of the left child (if it exists).
   int getLeftChildIndex(const int nodeIndex) const;
   
   // Returns the array index of the right child (if it exists).
   int getRightChildIndex(int nodeIndex) const;
   
   // Returns the array index of the parent node.
   int getParentIndex(int nodeIndex) const;
   
   // Tests whether this node is a leaf.
   bool isLeaf(int nodeIndex) const;
   
   // Converts a semiheap to a heap.
   void heapRebuild(int subTreeRootIndex);
   
   // Creates a heap from an unordered array.
   void heapCreate();
     
public:
   ArrayMaxHeap();
   ArrayMaxHeap(const ItemType someArray[], const int arraySize);
   virtual ~ArrayMaxHeap();
   
   // HeapInterface Public Methods:
   bool isEmpty() const;
   int getNumberOfNodes() const;
   int getHeight() const;
   ItemType peekTop() const throw(PrecondViolatedExcep);
   bool add(const ItemType& newData);
   bool remove();
   void clear();
   void displayArray(){
	   	for(int i=0;i<itemCount;i++)
		   std::cout << items[i] << " ";
		std::cout << std::endl;
    }
}; // end ArrayMaxHeap

//  Created by Frank M. Carrano and Tim Henry.
//  Copyright (c) 2013 __Pearson Education__. All rights reserved.

/** Array-based implementation of the ADT heap.
 @file ArrayMaxHeap.cpp */ 
 
#include <cmath> // for log2
#include <algorithm>  // for swap


//******************************************************************
// 
// Private methods start here
//
//******************************************************************

template<class ItemType>
int ArrayMaxHeap<ItemType>::getLeftChildIndex(const int nodeIndex) const
{
   return (2 * nodeIndex) + 1;
}  // end getLeftChildIndex

template<class ItemType>
int ArrayMaxHeap<ItemType>::getRightChildIndex(const int nodeIndex) const
{
	return (2 * nodeIndex) +  2;
}	//end of getRightChildIndex - completed

template<class ItemType>
int ArrayMaxHeap<ItemType>::getParentIndex(const int nodeIndex) const
{
	return (nodeIndex - 1) / 2;
}	// end of getParentIndex - completed

template<class ItemType>
bool ArrayMaxHeap<ItemType>::isLeaf(const int nodeIndex) const
{
	if (nodeIndex >= (itemCount - 1))
	{
		return true;
	}
	return false;
}	//end of isLeaf - Completed

template<class ItemType>
void ArrayMaxHeap<ItemType>::heapRebuild(int subTreeRootIndex)
{
	if (! isLeaf(subTreeRootIndex))
	{
		//root has a left, finding larger child
		int leftChildIndex = 2 * subTreeRootIndex + 1;
		int rightChildIndex = leftChildIndex + 1;
		int largerChildIndex = rightChildIndex;	//assuming right exist
		
		//check if right exist so let child is larger, if no right child left is larger.
		if (largerChildIndex >= itemCount || (items[leftChildIndex] > items[rightChildIndex]))
		{
			largerChildIndex = leftChildIndex;	//assumption was wrong
		}
		if (items[subTreeRootIndex] < items[largerChildIndex])
		{
			std::swap(items[subTreeRootIndex],items[largerChildIndex]);
//			ItemType temp = items[subTreeRootIndex];
//			items[subTreeRootIndex] = items[largerChildIndex];
//			items[largerChildIndex] = temp;
			//trasnfer semiheap to largerchildinex into a heap
			heapRebuild(largerChildIndex);
		}
	}//else root is leaf, and done
	
}	//end of heapRebuild - Completed

template<class ItemType>
void ArrayMaxHeap<ItemType>::heapCreate()
{
	for (int index = itemCount / 2 - 1; index >= 0; index--)
	{
		heapRebuild(index);
	}
}	//end of heapCreate - Completed

//******************************************************************
// 
// Public methods start here
//
//******************************************************************
template<class ItemType>
ArrayMaxHeap<ItemType>::ArrayMaxHeap()
{
	itemCount = 0;					//count of heaps inti. to 0
	maxItems = DEFAULT_CAPACITY;	//max count of heaps is set to default cap.
	items = new ItemType [maxItems];
	
}	//end of ArrayMaxHeap() - completed

template<class ItemType>
ArrayMaxHeap<ItemType>::ArrayMaxHeap(const ItemType someArray[], const int arraySize): itemCount(arraySize), maxItems(2 * arraySize)
{
   // Allocate the array
   items = new ItemType[2 * arraySize];

   // Copy given values into the array
   for (int i = 0; i < itemCount; i++)
      items[i] = someArray[i];
   
   // Reorganize the array into a heap
   heapCreate();
} // end constructor

template<class ItemType>
ArrayMaxHeap<ItemType>::~ArrayMaxHeap()
{  
   delete [] items;
}  // end destructor

template<class ItemType>
bool ArrayMaxHeap<ItemType>::isEmpty() const
{
	return itemCount == 0;
}	//end of isEmpty - completed

template<class ItemType>
int ArrayMaxHeap<ItemType>::getHeight() const
{
   return ceil(log2(itemCount + 1));
}  // end getHeight

template<class ItemType>
int ArrayMaxHeap<ItemType>::getNumberOfNodes() const
{
	return itemCount;
}	//end of getNumberOfNodes - completed

template<class ItemType>
void ArrayMaxHeap<ItemType>::clear()
{
	itemCount = 0;	//sets nodes to zero;
}	//end of clear - Completed

template<class ItemType>
ItemType ArrayMaxHeap<ItemType>::peekTop() const throw(PrecondViolatedExcep)
{
   if (isEmpty())
      throw PrecondViolatedExcep("Attempted peek into an empty heap.");
   
   return items[0];
} // end peekTop

template<class ItemType>
bool ArrayMaxHeap<ItemType>::add(const ItemType& anItem)
{
	bool inPlace = false;
	if (itemCount<maxItems)
	{
		items[itemCount] = anItem;	//new item bottom of tree
		int newDataIndex = itemCount;	
		//new bubble up to approp. spot
		while ((newDataIndex >= 0) && (! inPlace))
		{
			int parentIndex = (newDataIndex - 1) / 2;
			if (items[newDataIndex] <= items[parentIndex])
			{
				inPlace = true;
			}
			else
			{
				std::swap(items[newDataIndex], items[parentIndex]);
				newDataIndex = parentIndex;
			}
		}
		itemCount++;
	}
	return inPlace;
}	//end of add - Completed
    
template<class ItemType>
bool ArrayMaxHeap<ItemType>::remove()
{
	if (items != nullptr)
	{
		std::cout << "remove start\n";
		this->displayArray();
		items[0] = items[itemCount - 1];
		std::cout << "remove step 1\n";
		this->displayArray();
		itemCount--;
		std::cout << "remove step 2\n";
		this->displayArray();
		heapRebuild(0);
		std::cout << "remove step 3\n";
		this->displayArray();
		
		return true;
	}
	return false;

}	//end of remove - Completed

#endif
