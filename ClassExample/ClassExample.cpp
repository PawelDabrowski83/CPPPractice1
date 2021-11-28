#include <iostream>

class Point
{
private:
    double x;
    double y;
    
public:
    static int count;
    static void test();
    // konstruktor bezparametrowy
    Point();
    Point(double x);
    Point(double x, double y);
    Point(const Point& other);
    ~Point(); // destruktor

    void show() const; // const oznacza, że metoda nie modyfikuje obiektu klasy
};

int main()
{
    Point p{ 0 };
    p.show();

    Point p1 = p;
    p1 = p;
    p1.show();

    p1.count = 2;

    p.count = 6;

    Point* ptr = new Point{ 5, 5 }; // alokacja obiektu ze stosu
    delete ptr;

    // metoda statyczna
    Point::test();
    p.test();
}

// inicjalizacja pola statycznego poza ciałem klasy
int Point::count = 0;

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
    std::cout << "Usuwanie obiektu klasy Point.\n";
}

void Point::show() const
{
    std::cout << "Point [" << x << ", " << y << "]\n";
}

// konstruktor kopiujący
Point::Point(const Point& other) : Point(other.x, other.y)
{

}

