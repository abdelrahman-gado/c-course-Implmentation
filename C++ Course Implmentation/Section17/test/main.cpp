#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <functional>


using namespace std;

std::vector<int> GenerateRandVec(int numOfNums, int min, int max)
{
    std::vector<int> vecValues;
    srand(time(NULL));
    int i = 0, randVal = 0;
    while(i < numOfNums)
    {
        randVal = min + std::rand() % ((max+1) - min);
        vecValues.push_back(randVal);
        i++;
    }
    
    return vecValues;
}



int main() 
{
    std::vector<int> vecVals = GenerateRandVec(10, 1, 50);
//    std::vector<int> evenVecvals;
//    std::sort(vecVals.begin(), vecVals.end(), [](int x, int y){ return x > y;});
//    std::copy_if(vecVals.begin(), vecVals.end(), std::back_inserter(evenVecvals), [](int x) {return (x % 2) == 0;});
//    int sum = 0;
//    std::for_each(vecVals.begin(), vecVals.end(), [&](int x) { sum += x; });
//    cout << "Sum: " << sum << endl;
//    
//    int divisor;
////    std::vector<int> vecVals2;
////    std::cout << "List of Values Divisable by : ";
////    std::cin >> divisor;
////    std::copy_if(vecVals.begin(), vecVals.end(), std::back_inserter(vecVals2), [divisor](int x) {return (x % divisor) == 0;});
//    
//    std::vector<int> doubleVec;
//    std::for_each(vecVals.begin(), vecVals.end(), [&](int x) {doubleVec.push_back(x * 2); });
    
        
        
//    std::vector<int> vec1 = {1, 2, 3, 4, 5};
//    std::vector<int> vec2 = {1, 2, 3, 4, 5};
//    std::vector<int> vec3(5);
//    transform(vec1.begin(), vec1.end(), vec2.begin(), vec3.begin(), 
//        [](int x, int y) {return x+y;});
//    
//    for (auto val : vec3) { std::cout << val << "\n";}

    
    std::function<int(int)> Fib = 
    [&Fib](int n) {return (n < 2) ? n : Fib(n - 1) + Fib(n - 2);};
    
    //cout << "Fib 4 : " << Fib(4) << endl;
    
    std::vector<int> listOfFibs;
    std::function<void(int)> GenerateFibList = [&](int &x) 
    {
    while (x >= 0)
    {
        listOfFibs.push_back(Fib(x)); 
        x--;
    };
    
    GenerateFibList(10);
    
    for (auto val : listOfFibs)
        std::cout << val << endl;
    
    return 0;
}

