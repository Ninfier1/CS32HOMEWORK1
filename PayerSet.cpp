#include "PayerSet.h"

PayerSet::PayerSet(){}       // Constructor: Create an empty payer set.

bool PayerSet::add(unsigned long accountNum){
    // Add an account number to the payer set if it's within the valid range [0, 400].
    // Return true if added successfully, false otherwise.
    if(accountNum >= 0 && accountNum <= 400){
        m_payerSet.insert(accountNum);
        return true;
    }
    return false;
}

bool PayerSet::remove(unsigned long accountNum){
    // Remove an account number from the payer set if it exists.
    // Return true if removed successfully, false otherwise.
    int pos = m_payerSet.find(accountNum);
    if(pos != -1){
        m_payerSet.erase(pos);
        return true;
    }
    return false;
}
 
int PayerSet::size() const{
    // Return the number of account numbers in the payer set.
    return m_payerSet.size();
}

unsigned long PayerSet::minimum() const{
    // Return the smallest account number in the payer set.
    // If the set is empty, return NO_ACCOUNTNUMS.
    ItemType min;
    if(!(m_payerSet.empty())){
        m_payerSet.get(0, min);
        return min;
    }
    return NO_ACCOUNTNUMS;
}

unsigned long PayerSet::maximum() const{
    // Return the largest account number in the payer set.
    // If the set is empty, return NO_ACCOUNTNUMS.
    ItemType max;
    if(!(m_payerSet.empty())){
        m_payerSet.get(m_payerSet.size()-1, max);
        return max;
    }
    return NO_ACCOUNTNUMS;
}
