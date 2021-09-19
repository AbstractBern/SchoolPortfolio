/** @author bernardo flores
	@file BagInterface.h 
*/
#ifndef BAG_INTERFACE_H
#define BAG_INERFACE_H

#include <vector>

template<class ItemType>
class BagInterface
{
	public:
		/** Adds a new entry to his bag.
		@post If successful, newEntry is stored in the bag and
			the count of items in the bag has increased by 1.
		@param newEntry The object to be added as a new entry.
		@return rue if addition was successful, or false if not. */
		virtual bool add(const ItemType& newEntry) = 0;
		
		/** Removes a random entry from Node in this bag.
		@post If successful, the random num generated
			will be moved to the front of the link and be removed
		@return True if random num of linked entry is removed or successful from this bag,
			False otherwise */
		virtual bool remove() = 0;
		
		/** Removes all entries from his bag.
		@post Bag contains no items, and the coun of items is0. */
		virtual void clear() = 0;
		
		/** Tests whether this ba contains a given entry.
		@param anEntry The Entry to locate.
		@return True if bag contains anEntry, or false otherwise. */
		virtual bool contains(const ItemType& anEntry) const = 0;
		
		/** Gets the curent number of entries in this bag.
		@return The ineger number of entries currently in the bag. */
		virtual int getCurrentSize() const = 0;
		
		/** Counts the number fo imes a given entry appears in bag.
		@paam anEntry The entry to be counted.
		@return The number of times anEntry appears in the bag. */
		virtual int getFrequencyOf(const ItemType& anEntry) const = 0;
				
		/** Sees whether this bag is empty.
		@return True if the bag is empty, or false if not. */
		virtual bool isEmpty() const = 0;
		
		/** Removes one occurrence of a given entry from this bag, if possible
		@post If successful, anEntry has ben removed from he bag
			and the count of items in the bag has decreased by 1.
		@param anEnry The entry to be removed.
		@return True if removal was successful, or false if not. */
		virtual bool remove(const ItemType& anEntry) = 0;
				
		/** Empties and then fills a iven vector with all entries that are in this bag.
		@return A vector containing all the entries in the bag. */
		virtual std::vector<ItemType> toVector() const = 0;
		
		/** Destroys object and frees memory allocated by object. */
		virtual ~BagInterface () {}
};	//end of BagInterface
#endif
