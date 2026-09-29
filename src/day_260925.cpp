#include <iostream>
#include <vector>

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

int main()
{
    std::vector<std::vector<double>> voltages = {
        {},
        {3.72},
        {3.6, 3.6, 3.6},
        {3.7, 3.65, 3.80, 3.75},
        {4.2, 4.0, 3.8}
    };

    std::cout << "Have results?\t\tMax\t\tMin\t\tAverage" << std::endl;

    for (const auto& i : voltages)
    {
        VoltageStats stats;

        if (calculateStats(i, stats))
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
    }

    return 0;
}