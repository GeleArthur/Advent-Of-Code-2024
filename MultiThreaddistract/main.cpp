#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <execution>

std::vector<int> singlethread(const std::vector<int>& data)
{
    std::vector<int> out(data.size());
    for (size_t i = 0; i < data.size(); i++)
    {
        out[i] = data[i]*2.0f;
    }
    return out;
}

std::vector<int> multithread(const std::vector<int>& data)
{
    std::vector<int> out(data.size());
    std::transform(std::execution::par, data.begin(), data.end(), out.begin(), [](int c){
        return c * 2.0f;
    });
    return out;
}

std::vector<int> multithreadbinned(const std::vector<int>& data)
{
    std::vector<int> out(data.size());

    
    int coreCount = std::thread::hardware_concurrency();
    std::vector coresIds(coreCount, 0);
    std::iota(coresIds.begin(), coresIds.end(), 0);

    int dataPerCode = (data.size()/coreCount) + 1;

    std::for_each(std::execution::par, coresIds.begin(), coresIds.end(), [&](int bin)
    {
        for (int i = dataPerCode*bin; i < (dataPerCode*bin + dataPerCode); ++i)
        {
            if (i >= data.size()) continue;

            out[i] =  data[i] * 2.0f;
        }
    });

    return out;
}


int main()
{
    std::vector<int> DATA{};
    for (size_t i = 0; i < 10; i++)
    {
        DATA.push_back(rand());
    }

    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    auto out1 = singlethread(DATA);
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    std::cout << "single Time difference = " << std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count() << "[ns]" << std::endl;


    begin = std::chrono::steady_clock::now();
    auto out2 = multithread(DATA);
    end = std::chrono::steady_clock::now();
    std::cout << "multi Time difference = " << std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count() << "[ns]" << std::endl;

    begin = std::chrono::steady_clock::now();
    auto out3 = multithreadbinned(DATA);
    end = std::chrono::steady_clock::now();
    std::cout << "binned Time difference = " << std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count() << "[ns]" << std::endl;

    if (out1 == out2 && out2 == out3)
    {
        std::cout << "YAY" << '\n';
    }

    return 0;
 
}


