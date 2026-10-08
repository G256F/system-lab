/*构造函数学习*/
#include <iostream>
#include <vector>
#include <ostream>
#include <fstream>
#include <string>
#include <memory> // 引入智能指针头文件
bool SaveSample(const std::vector<double>& values, const std::string& filename);


class DataBatch
{
    private:
        std::vector <int> nums;
    public:
        explicit DataBatch(const std::vector<int> &n): nums(n)
        {
            std::cout << "普通构造函数被调用" << std::endl;
        }
        ~DataBatch()
        {
            std::cout << "析构函数被调用" << std::endl;
        }
        DataBatch(const DataBatch& other)
        {
            std::cout << "拷贝构造函数被调用" << std::endl;
            nums = other.nums;
        } 
        DataBatch(DataBatch&& other) noexcept
        {
            std::cout << "移动构造函数被调用" << std::endl;
            nums = std::move(other.nums);
        }
        void set(int index, int value)
        {
            if (index >= 0 && index < nums.size())
            {
                nums[index] = value;
            }
        }
        const std::vector<int>& get() const
        {
            return nums;
        }
        void PrintData() const
        {
            for (const auto& num : nums)
            {
                std::cout << num << " ";
            }
            std::cout << std::endl;
        }
};

long long consumeBatch(std::unique_ptr<DataBatch> batch);

int main()
{
    std::vector<std::vector<int>> numbers = {
        {10,-2,7},
        {},
        {4, 5, 6, 7},
        {8, 9},
        {10},
    };
    long long totalSum = 0;
    for (const auto& nums : numbers)
    {
        auto batch = std::make_unique<DataBatch>(nums);
        long long sum = consumeBatch(std::move(batch));
        if(sum == 0)
        {
            std::cout << "当前批次为空或无效" << std::endl;
        }
        else
        {
            std::cout << "当前批次的总和: " << sum << std::endl;
            totalSum += sum;
        }
        if(batch == nullptr) // 检查智能指针是否为空
        {
            std::cout << "当前批次已被释放" << std::endl;
        }
        else
        {
            std::cout << "当前批次仍然存在" << std::endl;
        }
    }
    long long sum = consumeBatch(std::move(nullptr)); // 测试传入空指针的情况
    if(sum == 0)
    {
        std::cout << "传入批次为空或无效" << std::endl;
    }

    std::cout << "所有批次的总和: " << totalSum << std::endl;
    std::cout << std::endl;

    return 0;
}
long long consumeBatch(std::unique_ptr<DataBatch> batch)
{
    long long sum = 0;
    if(batch == nullptr) // 检查智能指针是否为空
    {
        return 0;
    }
    if(batch->get().size()<=0) // 访问 nums 成员
    {
        return 0;
    }
    for (const auto& num : batch->get())
    {
        sum += num;
    }
    return sum;
}

