#include <iostream>
#include <vector>

using namespace std;
int main()
{
	std::vector<int> nums = {1,2,3,4,5,6,7,8,9,10};
	int sum = 0;
	for(int n:nums)
	{
		sum=sum+n;
	} 
	std::cout << "Sum:" << sum << endl;
	std::cout << "Hello World!" <<endl;
	return 0;
}
