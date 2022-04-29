#include <iostream>
#include <cmath>

using namespace std;

class Shape
{
public:
    virtual double Area() = 0;
};

class Circle : public Shape
{
protected:
    double width;
public:
    Circle (double w)
    {
        width = w;
    }
    
    // Override Area()
    double Area() override
    {
        return 3.14 * std::pow(width/2, 2);
    }
    
};

class Rectangle : public Shape
{
protected:
    double height, width;
    
public:
    Rectangle (double h, double w)
    {
        height = h;
        width = w;
    }
    
    double Area() override final
    {
        return height * width;
    }
    
};

class Square : public Rectangle
{
public:
    Square (double h, double w)
        : Rectangle(h, w)
    {
        
    }
    
    /*
     * This would trigger an error
    double Area() override 
    {
        return height * 2;
    }
    */
    
    
};

// This function receives Shapes but uses the correct Area() automatically
void showArea (Shape& shape)
{
    std::cout << "Area: " << shape.Area() << endl;
}


int main() 
{
    
    Rectangle rectangle (10, 15);
    Circle circle (10);
    
    showArea(rectangle);
    showArea(circle);
    
    Square square (10, 10);
    showArea(square);   // base class Area will be called (Rectangle area)
    return 0;
}