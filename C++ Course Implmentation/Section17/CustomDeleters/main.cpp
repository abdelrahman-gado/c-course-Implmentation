#include <iostream>
#include <memory>

using namespace std;

class Test
{
private:
    int data;
    
public:
    Test() : data {0} { std::cout << "\tTest constructor (" << data << ")" << std::endl; }
    Test (int data) : data {data} { std::cout << "\tTest constructor (" << data << ")" << std::endl; }
    int get_data() const { return data; }
    ~Test() { std::cout << "\tTest destructor (" << data << ")" << std::endl; }
};

void my_deleter (Test *ptr)
{
    cout << "\tUsing my custom function deleter" << std::endl;
    delete ptr;
}


int main() 
{
    {
        // Using function
        std::shared_ptr<Test> ptr1 {new Test {1000}, my_deleter};
        
    }
    
    std::cout << "====================================" << std::endl;
    
    {
        // Using lambda function
        std::shared_ptr<Test> ptr1 {new Test {100}, [] (Test *ptr)
        {
            cout << "\tUsing my custom lambda function" << endl;
            delete ptr;
        }};
    }
    
    return 0;
}