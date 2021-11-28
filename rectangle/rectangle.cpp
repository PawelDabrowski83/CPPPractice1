#include <iostream>
#include <cmath>

class Rectangle
{
private:
    double width;
    double height;
public:
    Rectangle();
    Rectangle(double side);
    Rectangle(double width, double height);
    double getWidth() const;
    double getHeight() const;
    double getDiagonal() const;
    double getArea() const;
    bool isLargerThan(const Rectangle& rect) const;
    void info() const;
};

int main()
{
    Rectangle rect1{};
    Rectangle rect2{ 2 };
    std::cout << rect2.isLargerThan(rect1);

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

double Rectangle::getWidth() const{
    return this->width;
}

double Rectangle::getHeight() const {
    return this->height;
}

double Rectangle::getDiagonal() const {
    return sqrt(pow(getWidth(), 2) + pow(getHeight(), 2));
}

double Rectangle::getArea() const {
    return getWidth() * getHeight();
}

bool Rectangle::isLargerThan(const Rectangle& rect) const {
    return this->getArea() > rect.getArea();
}

void Rectangle::info() const {
    std::cout << "Info about" << std::endl;
}