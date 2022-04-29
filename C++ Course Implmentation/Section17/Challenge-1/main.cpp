#include <iostream>
#include <memory>
#include <vector>


class Test
{
private:
    int data;
    
public:
    Test() : data {0} { std::cout << "\tTest constructor (" << data << ")" << std::endl; }
    Test(int data) : data {data} { std::cout << "\tTest constructor (" << data << ")" << std::endl; }
    int get_data() const { return data; }
    ~Test() { std::cout << "\tTest destructor (" << data << ")" << std::endl; }
};

// Function prototypes
std::unique_ptr<std::vector<std::shared_ptr<Test>>> make();
void fill (std::vector<std::shared_ptr<Test>> &vec, int num);
void display(const std::vector<std::shared_ptr<Test>> &vec);


int main() 
{
    std::unique_ptr<std::vector<std::shared_ptr<Test>>> vec_ptr;
    vec_ptr = make();
    std::cout << "How many data points do you want to enter: ";
    int num;
    std::cin >> num;
    fill(*vec_ptr, num);
    display(*vec_ptr); 
    return 0;
}

std::unique_ptr<std::vector<std::shared_ptr<Test>>> make ()   // auto make()
{
    return std::make_unique<std::vector<std::shared_ptr<Test>>>();
}

void fill (std::vector<std::shared_ptr<Test>> &vec, int num)
{
    for (int i {0}; i < num; i++)
    {
        int value {0};
        std::cout << "Enter data point [" << i+1 << "] : ";
        std::cin >> value;
        vec.push_back(std::make_shared<Test>(value));
    }
    
}

void display (const std::vector<std::shared_ptr<Test>> &vec)
{
    std::cout << "Displaying vector data" << std::endl;
    std::cout << "=======================" << std::endl;
    for (size_t i {0}; i < vec.size(); i++)
    {
        int data = vec.at(i)->get_data();
        std::cout << data << std::endl;
    }
    std::cout << "=======================" << std::endl;
    
}