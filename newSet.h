#ifndef NEWSET_H
#define NEWSET_H

#include <string>

using namespace std;

using ItemType = unsigned long;

class Set
{
public:
    Set();    // Construct an empty set.
    Set(int s); // Construct a set with a specified maximum capacity.
    bool empty() const;  // Check if the set is empty.
    int size() const;    // Return the number of items in the set.
    int insert(int pos, const ItemType& value);
      // Insert an item into the set at a specified position.
      // Returns the position where the item was inserted, or -1 if insertion failed.

    int insert(const ItemType& value);
      // Insert an item into the set while maintaining order.
      // Returns the position where the item was inserted, or -1 if insertion failed.
     
    bool erase(int pos);
      // Remove the item at a specified position from the set.
      // Returns true if successful, false otherwise.
     
    int remove(const ItemType& value);
      // Remove all occurrences of an item from the set.
      // Returns the number of items removed.

    bool get(int pos, ItemType& value) const;
      // Retrieve the item at a specified position from the set.
      // Returns true if successful, false otherwise.

    bool set(int pos, const ItemType& value);
      // Replace the item at a specified position in the set with a new value.
      // Returns true if successful, false otherwise.

    int find(const ItemType& value) const;
      // Find the position of an item in the set.
      // Returns the position if found, -1 otherwise.

    void swap(Set& other);
      // Swap the contents of this set with another set.
    
    Set(const Set& other); // Copy constructor
    ~Set(); // Destructor
    Set& operator=(const Set& other); // Assignment operator

    bool contains(const ItemType& value) const;
      // Check if the set contains a specific item.

private:
    static const int DEFAULT_MAX_ITEMS = 180;
    ItemType* arr;
    int s_size = 0;
    int max_size;
};

#endif
