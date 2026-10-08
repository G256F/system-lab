/*构造函数学习*/
#include <iostream>
#include <vector>
#include <ostream>
#include <fstream>
#include <string>
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

int main()
{
    std::vector<int> numbers = {10,20,30};
    DataBatch a(numbers); // 调用普通构造函数
    DataBatch b = a; // 调用拷贝构造函数
    a.set(0, 90); // 修改 a 的第一个元素
    std::cout << "a 的数据: ";
    a.PrintData(); // 输出 a 的数据
    std::cout << "b 的数据: ";
    b.PrintData(); // 输出 b 的数据，验证 b 是否受 a 的修改影响

    std::cout << "numbers 的数据: ";
    for (const auto& num : numbers)
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
