#include "Set.h"
#include <iostream>
#include <cassert>
using namespace std;

int main()
{
    Set s;
    assert(s.empty());
    assert(s.find(42) == -1);
    assert(s.insert(42) == 0);
    assert(s.size() == 1  &&  s.find(42) == 0);

    Set s1;
    assert(s1.empty());
    assert(s1.find(63) == -1);
    assert(s1.insert(63) == 0);
    assert(s1.insert(72) == 1);
    assert(s1.size() == 2  &&  s1.find(72) == 1);
    s.swap(s1);
    assert(s.size() == 2 && s.find(63) == 0);

    cout << "All tests passed!" << endl;
    return 0;
}
