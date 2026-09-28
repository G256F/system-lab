#include <iostream>
#include <string>
/**/
class Test_RAII
{
    public:
        Test_RAII(std::string n) : name(n)
        {
            std::cout << "构建"<< name << std::endl;
        }
        ~Test_RAII()
        {
            std::cout << "析构" << name << std::endl;
        }
        std::string name;
};

int main()
{
    Test_RAII A("A");
    Test_RAII C("C");
    {
        Test_RAII B("B");
    }
    return 0;
}
