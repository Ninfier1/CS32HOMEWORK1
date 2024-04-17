#ifndef PAYERSET_H
#define PAYERSET_H

#include "Set.h"            // Include the Set class header file.
#include <limits>           // Include the <limits> header for numeric limits.

using ItemType = unsigned long;    // Define ItemType as an unsigned long.
const unsigned long NO_ACCOUNTNUMS = std::numeric_limits<unsigned long>::max();
                                // Define NO_ACCOUNTNUMS as the maximum value of unsigned long.

class PayerSet
{

public:
    PayerSet();             // Constructor: Create an empty payer set.
    bool add(unsigned long accountNum);
                            // Add an account number to the payer set.
                            // Returns true if added successfully, false otherwise.
    bool remove(unsigned long accountNum);
                            // Remove an account number from the payer set.
                            // Returns true if removed successfully, false otherwise.
    int size() const;       // Return the number of account numbers in the list.
    unsigned long minimum() const;
                            // Return the smallest account number in the payer set.
    unsigned long maximum() const;
                            // Return the largest account number in the payer set.

private:
    Set m_payerSet;         // Private member variable of type Set to store account numbers.
};

#endif
