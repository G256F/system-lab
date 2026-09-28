#include<iostream>
#include<vector>

int BinarySearch(const std::vector<int>& nums,int x);

struct InputStruct
{
    std::vector<int> nums;
    int x;
};
int main()
{
    std::vector<InputStruct> Teststructs =
    {
        {{},5},
        {{5},5},
        {{5},4},
        {{1,2},1},
        {{1,2},2},
        {{1,3},2},
        {{0,1,2,3,4,5},0},
        {{0,1,2,3,4,5},5},
    };
    for(const InputStruct& T:Teststructs)
    {
        int result=BinarySearch(T.nums, T.x);
        if(result==-1)
        {
            std::cout<<"未找到"<<std::endl;
        }
        else
        {
            std::cout<<"查找结果为"<<result<<std::endl;
        }
    }

    return 0;
}

int BinarySearch(const std::vector<int>& nums,int x)
{
    int right = nums.size();
    int left = 0;
    while(left<right)
    {
        int mid = left + (right - left) / 2;
        if(nums[mid] == x)
        {
            return mid; // 找到目标值，返回索引
        }
        else if(nums[mid] < x)
        {
            left = mid + 1; // 在右半部分继续搜索
        }
        else
        {
            right = mid; // 在左半部分继续搜索
        }
    }
    return -1; // 未找到目标值，返回 -1
}