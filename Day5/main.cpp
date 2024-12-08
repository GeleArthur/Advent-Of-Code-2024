#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

bool CheckIfCorrect(const std::vector<int>& list, const std::vector<std::pair<int, int>>& rules)
{
    auto iterator = list.begin();
    ++iterator;

    while (iterator != list.end())
    {
        int currentPage = *iterator;

        for (auto& rule : rules)
        {
            if (rule.first == currentPage)
            {
                auto currentPos = iterator;
                while (currentPos != list.end())
                {
                    if (rule.second == *currentPos)

                    ++currentPos;
                }
            }
            else if (rule.second == currentPage)
            {
                
            }
        }

        
        auto iteratorBack = iterator;
        --iteratorBack;
        do
        {

        }
        while (iteratorBack != list.begin());
    }
    
}

int main()
{
    std::ifstream in{"input.txt"};
    std::vector<std::pair<int, int>> rules;
    std::vector<std::vector<int>> lists;
    
    bool part2{};
    std::string line;
    while (std::getline(in, line))
    {
        if (line.empty())
        {
            part2 = true;
            continue;
        }
        if (!part2)
        {
            int first = std::stoi(line.substr(0, 2));
            int before = std::stoi(line.substr(3, 5));

            rules.push_back(std::pair{first, before});
        }
        else
        {
            std::vector<int> result;
            std::stringstream streamLine(line);
            std::string number;
            while (std::getline(streamLine, number, ','))
            {
                result.push_back(std::stoi(number));
            }
            lists.push_back(std::move(result));
        }
    }

    for (auto& list : lists)
    {
        for (auto& number : list)
        {
            std::cout << number << ',';
        }
        std::cout << '\n';
    }
 
}
