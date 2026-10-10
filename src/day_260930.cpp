#include <iostream>
#include <vector>
#include <ostream>
#include <fstream>
#include <string>
#include <memory> // 引入智能指针头文件
#include <cstdlib> // 引入标准库函数头文件

struct VoltageStats
{
    double maxnum;
    double minnum;
    double average;
};

bool calculateStats(const std::vector<double>& voltages, VoltageStats& results)
{
    if (voltages.empty())
    {
        // 输入向量为空时返回 false
        return false;
    }

    // 使用第一个电压值初始化最大值和最小值
    results.maxnum = voltages.front();
    results.minnum = voltages.front();
    results.average = 0;

    double sum = 0;

    for (const auto& voltage : voltages)
    {
        sum += voltage;

        if (voltage < results.minnum)
        {
            // 发现更小的电压值时更新最小值
            results.minnum = voltage;
        }

        if (voltage > results.maxnum)
        {
            // 发现更大的电压值时更新最大值
            results.maxnum = voltage;
        }
    }

    // 计算平均电压
    results.average = sum / voltages.size();

    // 统计计算成功时返回 true
    return true;
}

using namespace std;

int main(int argc, char* argv[])
{
    if (argc < 2)
    {
        std::cerr << "使用方式: " << argv[0] << " <输入文件名>" << std::endl;
        return 1;
    }
    std::string inputFileName = argv[1];
    std::string extension = inputFileName.substr(inputFileName.find_last_of(".") + 1);
    if (extension != "csv")
    {
        std::cerr << "输入文件必须是 CSV 格式" << std::endl;
        return 1;
    }

    std::ifstream readFile;
    readFile.open(inputFileName);
    std::vector<double> dataRecords = {};
    if (!readFile.is_open())
    {
        std::cerr << "无法打开文件: " << inputFileName << std::endl;
        return 1;
    }
    // if(readFile.size() == 0)
    // {
    //     std::cerr << "文件为空: " << inputFileName << std::endl;
    //     return 1;
    // }
    std::string data;
    std::getline(readFile, data); // 读取并忽略第一行标题
    std::cout << "读取文件: " << inputFileName << "   数据名称：" << data << std::endl;
    while (std::getline(readFile, data))
    {
        std::unique_ptr<char*> commaPos(new char*);
        if(!data.empty()&&data.back() == '\r') // 处理 Windows 风格的换行符
        {
            data.pop_back();
        }
        dataRecords.push_back(std::strtod(data.c_str(),commaPos.get()));
        if(*commaPos.get() - data.c_str()!= data.size())
        {
            std::cerr << "数据格式错误: " << data << std::endl;
            return 1;
        }
        else
        {
            std::cout << "读取的数据: " << data << std::endl;
        }
    }


    std::cout << "Have results?\t\tMax\t\tMin\t\tAverage" << std::endl;


    VoltageStats stats;

    if (calculateStats(dataRecords, stats))
    {
        std::cout << "Yes\t\t\t"
                    << stats.maxnum << "\t\t"
                    << stats.minnum << "\t\t"
                    << stats.average << std::endl;
    }
    else
    {
        std::cout << "No\t\t\t/\t\t/\t\t/" << std::endl;
    }

    return 0;
}