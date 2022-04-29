#include <iostream>
#include <string>
#include <vector>

std::string formatPhoneNumber(std::vector<int> numbers) {
	std::string phone {"("};
	for (int i {0}; i < numbers.size(); i++)
	{
		if (i <= 2)
		{
			phone.push_back((char)numbers[i]);
		}
		else if (i == 3)
		{
			phone.push_back(')');
			phone.push_back(' ');
		}
		else if (i <= 5)
		{
			phone.push_back((char)numbers[i]);
		}
		else if (i == 6)
		{
			phone.push_back('-');
		}
		else
		{
			phone.push_back((char)numbers[i]);
		}
		
	}
	
	return phone;
}

int main()
{
    
    std::vector<int> vec {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    std::cout << formatPhoneNumber(vec) << std::endl;
    return 0;
}