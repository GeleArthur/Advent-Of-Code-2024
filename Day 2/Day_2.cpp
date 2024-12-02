#include <filesystem>
#include <fstream>
#include <iostream>
#include <numeric>
#include <sstream>

// bool CheckList(const std::vector<int>& number)
// {
//     bool direction = number[0] > number[1];
//     for (auto iterator = number.cbegin(); iterator != number.cend()-1; ++iterator)
//     {
//         int subtract = *iterator - *(iterator+1);
//         if (
//             direction ? subtract < 0 : (subtract > 0) ||
//             std::abs(subtract) > 3 ||
//             subtract == 0)
//         {
//             return false;
//         }
//     }
//     return true;
// }

bool CheckList(std::vector<int>& v)
{
    bool direction = v[0] > v[1];

    for (auto iterator = v.cbegin(); iterator != v.cend()-1; ++iterator)
    {
        int subtract = *iterator - *(iterator+1);
        if (direction ? subtract < 0 : (subtract > 0))
        {
            return false;
        }
        if (std::abs(subtract) > 3 || subtract == 0)
        {
            return false;
        }
    }
    return true;
        
}


bool add(std::vector<int>& v)
{
    if (CheckList(v))
    {
        return true;
    }
    
    for (int i = 0; i < v.size(); ++i)
    {
        std::vector temp(v);
        temp.erase(temp.begin()+i);
        if (CheckList(temp)) return true;
    }

    return false;
        
}


int main(int argc, char* argv[])
{
    std::ifstream in{"input.txt"};

    std::vector<std::vector<int>> safeList{};

    std::string line;
    while (std::getline(in, line, '\n'))
    {
        std::istringstream iss(line);
        safeList.emplace_back();
        
        while (std::getline(iss, line, ' '))
        {
            safeList.back().push_back(std::stoi(line));
        }
    }

    
    // Accumlate???
    int total{};
    for (auto list : safeList)
    {
        if (add(list))
        {
            ++total;
        }
    }
    
    std::cout << total << '\n';

    
    
    
    return 0;
}


