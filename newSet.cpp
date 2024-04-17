#include <stdio.h>
#include <string>
#include "newSet.h"

Set::Set() : s_size(0), max_size(DEFAULT_MAX_ITEMS){
    arr = new ItemType[DEFAULT_MAX_ITEMS];
}    // Create an empty set (i.e., one whose size() is 0).

Set::Set(int s) : s_size(0), max_size(s){
    arr = new ItemType[s];
} // Create an empty set with a specified size.

bool Set::empty() const{
    return s_size == 0;
}  // Return true if the set is empty, otherwise false.

int Set::size() const{
    return s_size;
}    // Return the number of items in the set.

int Set::insert(int pos, const ItemType& value){
    if(s_size == max_size) return -1;
    if(pos >= 0 && pos <= s_size){
        for(int i = s_size; i> pos; --i){
            arr[i] = arr[i-1];
        }
        arr[pos] = value;
        s_size++;
        return pos;
    }
    return -1;
}
  // Insert value into the set so that it becomes the item at
  // position pos.  Return the position if successful, -1 otherwise.

int Set::insert(const ItemType& value){
    if(s_size == max_size) return -1;
    for(int i = 0; i< s_size; ++i){
        if(value <= arr[i]){
            insert(i, value);
            return i;
        }
    }
    insert(s_size, value);
    return s_size;
}
  // Insert value into the set so that it maintains order.
  // Return the position if successful, -1 otherwise.
 
bool Set::erase(int pos){
    if(pos >= 0 && pos < s_size){
        for(int i = pos; i < s_size - 1; ++i){
            arr[i] = arr[i+1];
        }
        s_size--;
        return true;
    }
    return false;
}
  // Erase the item at position pos from the set.
  // Return true if successful, false otherwise.
 
int Set::remove(const ItemType& value){
    int num_removed = 0;
    for(int i = 0; i < s_size; ++i){
        if(arr[i] == value){
            erase(i);
            num_removed++;
        }
    }
    return num_removed;
}
  // Erase all items from the set that equal value.
  // Return the number of items removed.

bool Set::get(int pos, ItemType& value) const{
    if(pos >= 0 && pos < s_size){
        value = arr[pos];
        return true;
    }
    return false;
}
  // Copy the item at position pos into value.
  // Return true if successful, false otherwise.

bool Set::set(int pos, const ItemType& value){
    if(pos >= 0 && pos < s_size){
        arr[pos] = value;
        return true;
    }
    return false;
}
  // Replace the item at position pos with value.
  // Return true if successful, false otherwise.

int Set::find(const ItemType& value) const{
    for(int p = 0; p < s_size; ++p){
        if(arr[p] == value) return p;
    }
    return -1;
}
  // Find the position of the item equal to value.
  // Return the position if found, -1 otherwise.

void Set::swap(Set& other){
    int temps_size = s_size;
    s_size = other.s_size;
    other.s_size = temps_size;
    
    ItemType* temp = arr;
    arr = other.arr;
    other.arr = temp;
    
    int tempmax_size = max_size;
    max_size = other.max_size;
    other.max_size = tempmax_size;
}
  // Exchange the contents of this set with the other one.

Set::Set(const Set& other) : max_size(other.max_size){
    s_size = other.s_size;
    arr = new ItemType[s_size];
    for(int i = 0; i < s_size; ++i){
        arr[i] = other.arr[i];
    }
} // Copy constructor

Set::~Set(){
    delete[] arr;
} // Destructor

Set& Set::operator=(const Set& other){
    if(this != &other){
        Set temp(other);
        swap(temp);
    }
    return *this;
}

bool Set::contains(const ItemType& value) const {
    for (int i = 0; i < s_size; ++i) {
        if (arr[i] == value) {
            return true;
        }
    }
    return false;
}
