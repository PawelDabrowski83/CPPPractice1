#include <iostream>

class Rectangle
{
private:
    double width;
    double height;
public:
    Rectangle();
    Rectangle(double side);
    Rectangle(double width, double height);
    double getWidth();
    double getHeight();
    double getDiagonal();
    double getArea();
    bool isLargerThan(const Rectangle&);
    void info();
};

int main()
{
    std::cout << "Hello World!\n";
}

Rectangle::Rectangle() : Rectangle(1)
{
}

Rectangle::Rectangle(double side) : Rectangle(side, side)
{
}

Rectangle::Rectangle(double width, double height) {
    this->width = width;
    this->height = height;
}