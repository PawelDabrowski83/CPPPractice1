#include <iostream>
#include <vector>
#include <functional>
#include <cmath>

struct Rectangle {
    double width;
    double height;
};

double process(const std::vector<Rectangle>& rects, double startVal, std::function<double(double, const Rectangle&)> f) {
    for (int i = 0; i < rects.size(); i++) {
        startVal = f(startVal, rects[i]);
    }
    return startVal;
}

double calculateArea(Rectangle rectangle) {
    return rectangle.width * rectangle.height;
}


int main()
{
    std::vector<Rectangle> shapes = {
        Rectangle{10, 10},
        Rectangle{10, 10},
        Rectangle{10, 10}
    };

    std::cout << "Expected result is: 301" << std::endl;
    double startVal = 1;
    double result = process(shapes, startVal, [](double n, Rectangle rect) -> double {return n + rect.height * rect.width; });
    std::cout << "Actual result is: " << result << std::endl;

    shapes.clear();
    shapes = {
        Rectangle{3, 4},
        Rectangle{5, 12},
        Rectangle{8, 15}
    };

    result = process(shapes, startVal, [](double n, Rectangle rect) -> double {
        return std::max(
            n, 
            sqrt(
                pow(rect.width, 2) + pow(rect.height, 2)
            )); 
        });
    std::cout << "Expected result is: 17" << std::endl;
    std::cout << "Actual result is: " << result << std::endl;
}

/*
Zadanie 1 [0,5 pkt]

Zdefiniuj strukturę Rectangle opisującą prostokąt na płaszczyźnie kartezjańskiej z bokami równoległymi do osi. Struktura Rectangle powinna zawierać
dwa pola typu double, reprezentujące długość i szerokość prostokąta. Napisz funkcję:

double process(const std::vector<Rectangle>& rects, double startVal, std::function<double(double, constRectangle&)> f);

która pobiera wektor struktur Rectangle, wartość początkową startVal oraz funkcję f, a zwraca wynik przekształcenia kolejnych prostokątów z tablicy 
przy pomocy funkcji f zgodnie z zależnością:

result = f(result, rects[i]);

Wykorzystaj przygotowaną funkcję process, wywoływaną z odpowiednią wartością początkową do:
1. wyznaczenia sumy pól wszystkich prostokątów w wektorze, przy czym jako trzeci argument funkcji przekaż odpowiednie wyrażenie lambda
2. wyznaczenia najdłuższej przekątnej spośród przekątnych wszystkich prostokątów w wektorze, przy czym jako trzeci argument funkcji przekaż 
odpowiednie wyrażenie lambda
*/