#include <stdio.h>
#include <string>
#include "Set.h"

// Constructor: Creates an empty set (i.e., one with size 0).
Set::Set() {
    s_size = 0;
}

// Determines if the set is empty.
bool Set::empty() const {
    return s_size == 0;
}

// Returns the number of items in the set.
int Set::size() const {
    return s_size;
}

// Inserts a value into the set at a specified position.
// Returns the position where the value was inserted if successful,
// or -1 if insertion failed.
int Set::insert(int pos, const ItemType& value) {
    if (s_size == DEFAULT_MAX_ITEMS) return -1;

    if (pos >= 0 && pos <= s_size) {
        if (!empty()) {
            for (int i = s_size; i > pos; --i) {
                arr[i] = arr[i - 1];
            }
            arr[pos] = value;
            s_size++;
            return pos;
        }
        arr[0] = value;
        s_size++;
        return pos;
    }
    return -1;
}

// Inserts a value into the set in sorted order.
// Returns the position where the value was inserted if successful,
// or -1 if insertion failed.
int Set::insert(const ItemType& value) {
    if (s_size == DEFAULT_MAX_ITEMS) return -1;

    for (int i = 0; i < s_size; ++i) {
        if (value <= arr[i]) {
            insert(i, value);
            return i;
        }
    }
    int p = s_size;
    insert(p, value);
    return p;
}

// Removes an item at a specified position from the set.
// Returns true if successful, or false otherwise.
bool Set::erase(int pos) {
    if (pos >= 0 && pos < s_size) {
        for (int i = pos; i < s_size; ++i) {
            arr[i] = arr[i + 1];
        }
        s_size--;
        return true;
    }
    return false;
}

// Removes all items with a specified value from the set.
// Returns the number of items removed.
int Set::remove(const ItemType& value) {
    int num_removed = 0;
    for (int i = 0; i < s_size; ++i) {
        if (arr[i] == value) {
            erase(i);
            num_removed++;
        }
    }
    return num_removed;
}

// Retrieves the value at a specified position in the set.
// Returns true if successful, or false otherwise.
bool Set::get(int pos, ItemType& value) const {
    if (pos >= 0 && pos < s_size) {
        value = arr[pos];
        return true;
    }
    return false;
}

// Replaces the value at a specified position in the set.
// Returns true if successful, or false otherwise.
bool Set::set(int pos, const ItemType& value) {
    if (pos >= 0 && pos < s_size) {
        arr[pos] = value;
        return true;
    }
    return false;
}

// Finds the position of the first occurrence of a value in the set.
// Returns the position if found, or -1 if not found.
int Set::find(const ItemType& value) const {
    for (int p = 0; p < s_size; ++p) {
        if (arr[p] == value) return p;
    }
    return -1;
}

// Swaps the contents of this set with another set.
void Set::swap(Set& other) {
    int temps_size = s_size;
    s_size = other.s_size;
    other.s_size = temps_size;
    
    int larger;
    ItemType temp;
    (s_size > other.s_size) ? larger = s_size : larger = other.s_size;
    for (int i = 0; i < larger; ++i) {
        temp = arr[i];
        arr[i] = other.arr[i];
        other.arr[i] = temp;
    }
}
