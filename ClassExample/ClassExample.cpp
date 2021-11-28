#include <iostream>

class Point
{
private:
    double x;
    double y;
public:
    // konstruktor bezparametrowy
    Point();
    Point(double x);
    Point(double x, double y);
    ~Point(); // destruktor

    void show() const; // const oznacza, że metoda nie modyfikuje obiektu klasy
};

int main()
{
    std::cout << "Hello World!\n";
    Point p{ 0 };
    p.show();
}

// :: oznacza należy do klasy
Point::Point() : Point(0) // wywołanie innego konstruktora
{
    x = 0;
    y = 0;
}

Point::Point(double x)
{
    this->x = x;
    this->y = y;
}

Point::Point(double x, double y) : x(x), y(y) // lista inicjalizacyjna
{

}

// destruktor wołany automatycznie w momemncie usuwania obiektu
Point::~Point()
{

}

void Point::show() const
{
//    std::cout << 
}

