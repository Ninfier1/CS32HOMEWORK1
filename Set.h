#ifndef SET_H
#define SET_H

#include <string>

using namespace std;

using ItemType = unsigned long;

class Set
{
public:
    Set();    // Constructs an empty set (i.e., one with size() equal to 0).
    bool empty() const;  // Checks if the set is empty. Returns true if empty, false otherwise.
    int size() const;    // Returns the number of items in the set.
    int insert(int pos, const ItemType& value);
      // Inserts a value into the set at position pos. The original item at position pos and those that
      // follow it are moved to positions one greater than their previous positions.
      // Returns pos if 0 <= pos <= size() and the value could be inserted.
      // Returns -1 if insertion failed, possibly due to the set reaching its fixed capacity.
      // If pos equals size(), the value is inserted at the end.

    int insert(const ItemType& value);
      // Inserts a value into the set in sorted order.
      // Returns the position where the value was inserted if successful.
      // Returns -1 if insertion failed, possibly due to the set reaching its fixed capacity.

    bool erase(int pos);
      // Removes the item at position pos from the set.
      // Returns true if successful, false otherwise.

    int remove(const ItemType& value);
      // Removes all items from the set that are equal to value.
      // Returns the number of items removed.

    bool get(int pos, ItemType& value) const;
      // Retrieves the value at position pos in the set.
      // Returns true if successful, false otherwise.

    bool set(int pos, const ItemType& value);
      // Replaces the value at position pos in the set with the given value.
      // Returns true if successful, false otherwise.

    int find(const ItemType& value) const;
      // Finds the position of the first occurrence of value in the set.
      // Returns the position if found, -1 otherwise.

    void swap(Set& other);
      // Swaps the contents of this set with another set.

private:
    static const int DEFAULT_MAX_ITEMS = 180;
    ItemType arr[DEFAULT_MAX_ITEMS];
    int s_size = 0;
};

#endif
