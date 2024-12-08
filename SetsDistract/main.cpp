#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <array>
#include <execution>
#include <set>

int main()
{
    std::set<int> ye{3};

    std::array<int, 12> hi;
    
    hi.at(11) = 100;
    
    ye.insert(3);
    ye.insert(4);
    ye.insert(9);
    ye.insert(1);
    ye.insert(7);

    ye.insert(3);

    std::cout << ye.upper_bound(3).operator*();

    std::multiset<int> coll2(ye.cbegin(),ye.cend());

    coll2.erase (coll2.begin(), coll2.find(3));
    
    
    return 0;
 
}


