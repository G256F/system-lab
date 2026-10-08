/*构造函数学习*/
#include <iostream>
#include <vector>
#include <ostream>
#include <fstream>
#include <string>
#include <memory> // 引入智能指针头文件
#include <algorithm> // 引入算法头文件
#include <unordered_map> // 引入哈希表头文件

bool SaveSample(const std::vector<double>& values, const std::string& filename);
struct Record
{
    int time;
    int mv;
};
struct testRecord
{
    std::vector<Record> records;
    int threshold;
};
struct testTwoSum
{
    std::vector<int> nums;
    int target;
};

template <typename T>T larger(T a, T b)
{
    return (a > b) ? a : b;
}

void SortByVoltage(std::vector<Record>& records)
{
    std::sort(records.begin(), records.end(), [](const Record& a, const Record& b) {
        return a.mv < b.mv;
    });
}
void printRecords(const std::vector<Record>& records)
{
    for (const auto& record : records)
    {
        std::cout << "Time: " << record.time << ", Voltage: " << record.mv << std::endl;
    }
}

std::vector<Record> filterRecords(const std::vector<Record>& records, int threshold)
{
    std::vector<Record> filtered;
    auto it = records.begin();
    while (true)
    {
        it = std::find_if(it, records.end(), [threshold](const Record& record) {
            return record.mv > threshold;
        });
        if (it == records.end())
        {
            break;
        }
        filtered.push_back(*it);
        ++it; // Move to the next element to avoid infinite loop
    }
    return filtered;
}
std::vector<int>TwoSum(const std::vector<int>& nums, int target)
{
    std::vector<int> result;
    for (size_t i = 0; i < nums.size(); ++i)
    {
        for (size_t j = i + 1; j < nums.size(); ++j)
        {
            if (nums[i] + nums[j] == target)
            {
                result.push_back(i);
                result.push_back(j);
                return result;
            }
        }
    }
    return result; // Return empty vector if no solution is found
}
std::vector<int>TwoSumHash(const std::vector<int>& nums, int target)
{
    std::unordered_map<int, int> numMap; // value -> index
    for(size_t i = 0; i < nums.size(); ++i)
    {
        int complement = target - nums[i];
        if (numMap.find(complement) != numMap.end())
        {
            return {numMap[complement], static_cast<int>(i)};
        }
        numMap[nums[i]] = static_cast<int>(i);
    }
    return {}; // Return empty vector if no solution is found
}

int main()
{
    std::vector<testRecord> records = {
        {{}, 4200},
        {{{1, 4200}}, 4200},
        {{{1, 4300}, {2, 4300}, {3, 4100}}, 4200}
    };
    for (auto& recordBatch : records)
    {
        std::cout << "排序前：" << std::endl;
        printRecords(recordBatch.records);
        SortByVoltage(recordBatch.records);
        std::cout << "排序后：" << std::endl;
        printRecords(recordBatch.records);
        auto filteredRecords = filterRecords(recordBatch.records, recordBatch.threshold);
        std::cout << "Filtered records (mv > " << recordBatch.threshold << "):" << std::endl;
        printRecords(filteredRecords);
    }
    std::cout << "larger(-2,-5):" << larger(-2, -5) << std::endl;
    std::cout << "larger(4,4):" << larger(4, 4) << std::endl;
    std::cout << "larger(2.5,1.5):" << larger(2.5, 1.5) << std::endl;

    std::vector<testTwoSum> testCases = {
        {{2, 7, 11, 15}, 9},
        {{3, 2, 4}, 6},
        {{3, 3}, 6}
    };

    for (const auto& testCase : testCases)
    {
        auto result = TwoSum(testCase.nums, testCase.target);
        std::cout << "TwoSum((";
        for (size_t i = 0; i < testCase.nums.size(); ++i)
        {
            std::cout << testCase.nums[i];
            if (i < testCase.nums.size() - 1) std::cout << ", ";
        }
        std::cout << "), " << testCase.target << ") = ";
        if (!result.empty())
        {
            std::cout << "[" << result[0] << ", " << result[1] << "]";
        }
        else
        {
            std::cout << "No solution found";
        }
        std::cout << std::endl;
    } 
    for (const auto& testCase : testCases)
    {
        auto result = TwoSumHash(testCase.nums, testCase.target);
        std::cout << "TwoSumHash((";
        for (size_t i = 0; i < testCase.nums.size(); ++i)
        {
            std::cout << testCase.nums[i];
            if (i < testCase.nums.size() - 1) std::cout << ", ";
        }
        std::cout <<"),"<< testCase.target << ")=";
        if (!result.empty())
        {
            std::cout << "[" << result[0] << ", " << result[1] << "]";
        }
        else
        {
            std::cout << "No solution found";
        }
        std::cout << std::endl;
    } 


    return 0;
}


