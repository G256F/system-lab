/*RAII思想学习*/
#include <iostream>
#include <vector>
#include <ostream>
#include <fstream>
#include <string>
/*RAII周期学习*/
bool SaveSample(const std::vector<double>& values, const std::string& filename);


class DataBatch
{
    public:
        DataBatch(const std::vector<double> &v): voltages(v)
        {
            std::cout << "构建采样对象" << std::endl;
        }
        ~DataBatch()
        {
            std::cout << "析构采样对象" << std::endl;
        }
        bool empty() const
        {
            return voltages.empty();
        }
        void writeTo(std::ostream &os) const
        {
            for (const auto &v : voltages)
            {
                os << v << " ";
            }
            os << std::endl;
        }

    private:
        std::vector <double> voltages;
};

int main()
{
    std::vector<std::vector<double>> voltages = {
        {},
        {3.72},
        {3.6, 3.6, 3.6},
        {3.7, 3.65, 3.80, 3.75},
        {4.2, 4.0, 3.8}
    };
    int i=0;
    for (const auto& v : voltages)
    {
        std::cout<<"开始调用"<<std::endl;
        const bool success = SaveSample(v, "/home/jinxiao/systems-lab/test_file/260924/sample_" + std::to_string(i++) + ".txt");
        std::cout<<"调用已结束，返回值为"<<success<<std::endl;
    }
    return 0;
}
bool SaveSample(const std::vector<double>& values, const std::string& filename)
{
    DataBatch sample(values);
    std::ofstream file(filename);
    if (!file.is_open())
    {
        std::cerr << "无法打开文件: " << filename << std::endl;
        return false;
    }
    file<<"开始处理\n";

    if(sample.empty())
    {
        file<<"数据为空\n";
        std::cerr << "输入向量为空，无法保存采样数据,准备提前返回。" << std::endl;
        return false;
    }
    std::cout << "保存采样数据到文件: " << filename << std::endl;
    sample.writeTo(file);
    file<<"处理完成\n";

    std::cout<<"正常返回\n";
    return true;
}
