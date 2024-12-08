#include <fstream>
#include <iostream>
#include <numeric>
#include <regex>

int main()
{
    std::ifstream in{"input.txt"};
    std::string str((std::istreambuf_iterator(in)), std::istreambuf_iterator<char>()); // ???? how does this work;
    // Future me: It's a null pointer and strings end with a null terminator. Holy crap this is smart.
    

    std::regex regex(R"(mul\((\d+,\d+)\)|(don't\(\))|(do\(\)))");

    std::sregex_iterator pos(str.begin(), str.end(), regex);
    std::sregex_iterator end{}; 
    
    int total = 0;
    bool stop{};
    
    for (;pos != end; ++pos)
    {
        ptrdiff_t wtf = pos->length();
        if (wtf > 1)
        {
            std::string input = pos->str(2);
            if (input == "don't()")
            {
                stop = true;
            }
            else
            {
                stop = false;
            }
            continue;
        }

        std::string input = pos->str(1);

        std::cout << input << std::endl;
        
        auto split = std::find_if(input.begin(), input.end(), [](char c){return c ==',';});
        
        int thing1 = std::stoi(std::string(input.begin(), split));
        int thing2 = std::stoi(std::string(split+1, input.end()));
        
        total += thing1 * thing2;
    }
    std::cout << total << std::endl;
}
