#include <fstream>
#include <iostream>
#include <numeric>
#include <regex>

int main()
{
    std::ifstream in{"input.txt"};
    std::string str((std::istreambuf_iterator(in)), std::istreambuf_iterator<char>()); // ???? how does this work;
    
    

    std::regex regex(R"(mul\((\d\d?\d?,\d\d?\d?)\))");
    std::regex regexDo(R"(do\(\))");
    std::regex regexDont(R"(don't\(\))");

    std::sregex_iterator pos(str.begin(), str.end(), regex);
    std::sregex_iterator posDo(str.begin(), str.end(), regexDo);
    std::sregex_iterator posDont(str.begin(), str.end(), regexDont);
    std::sregex_iterator end{}; // 
    
    int total = 0;
    for (; pos != end; ++pos)
    {
        std::string input = pos->str(1);
        
        auto split = std::find_if(input.begin(), input.end(), [](char c){return c ==',';});
        
        int thing1 = std::stoi(std::string(input.begin(), split));
        int thing2 = std::stoi(std::string(split+1, input.end()));

        total += thing1 * thing2;
        
    }
    std::cout << total << std::endl;
}
