#include <stdio.h>
#include <iostream>
#include <cassert>
#include "PayerSet.h"

using namespace std;

int main(){
    PayerSet ps;
    assert(ps.add(0));
    assert(!ps.remove(114));
    assert(ps.size() == 1);
    assert(ps.minimum() == 0);
    assert(ps.maximum() == 0);
    cout << "All tests passed!" << endl;
    
    return 0;
}
