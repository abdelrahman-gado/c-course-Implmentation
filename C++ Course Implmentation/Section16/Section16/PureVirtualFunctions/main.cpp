#include <iostream>
#include <vector>

using namespace std;

class Shape  // Abstract Base class
{
private:
    
public:
    virtual void draw() = 0;    // pure virtual method
    virtual void rotate() = 0; // pure virtual method
    virtual ~Shape() { }
};

void Shape::draw()
{
    cout << "Hello World" << endl;
}

class Open_Shape : public Shape    // Abstarct base class
{
public:
    virtual ~Open_Shape() { }

};

class Close_Shape : public Shape     // Abstarct base class
{
public:
    virtual ~Close_Shape() { }

};

class Circle : public Close_Shape     // concrete class
{
private:
    
public:
    
    virtual void draw() override
    {
        Shape::draw();
    }
    
    virtual void rotate() override;
    
    virtual ~Circle() { }
};

void Circle::rotate()
{
    cout << "Rotating a Circle" << endl;
}



class Square : public Close_Shape      // concrete class
{
private:
    
public:
    
    virtual void draw() override 
    {
        cout << "Drawing a Square" << endl;
    }
    
    virtual void rotate() override
    {
        cout << "Rotating a Square" << endl;
    }
    
    virtual ~Square() { }
};


class Line : public Open_Shape  // Concrete class
{
private:
    
public:
    
    virtual void draw() override
    {
        cout << "Drawing a Line" << endl;
    }
    
    virtual void rotate() override
    {
        cout << "Rotating a Line" << endl;
    }
    
    virtual ~Line() { }
};

void screen_refresh(const vector<Shape *> &shapes)
{
    cout << "Refreshing" << endl;
    for (Shape *const p : shapes)
    {
        p->rotate();
    }
}


int main() 
{
    
//    Shape s;
//    Shape *ptr = new Shape;
//    
//    Open_Shape o;
//    Open_Shape *ptr1 = new Open_Shape();

//    Circle c;
//    c.draw();
//    c.rotate();
        
//    Circle *ptr = new Circle;
//    ptr->draw();
//    ptr->rotate();

//    Shape *ptr = new Circle();   // dynamic ploymorphism 
//    ptr->draw();            // --> bind at runtime
//    ptr->rotate();        // --> bind at runtime
//    
    Shape *s1 = new Circle();
    Shape *s2 = new Line();
    Shape *s3 = new Square();
    
    vector<Shape *> shapes {s1, s2, s3};

    screen_refresh(shapes);
//    
//    for (const auto p : shapes)
//    {
//        p->draw();
//    }
    
    
    
    delete s1;
    delete s2;
    delete s3;
    
    return 0;
}