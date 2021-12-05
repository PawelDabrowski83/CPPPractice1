
#include <iostream>

class Point
{
private:
	double x;
	double y;
public:
	Point();
	Point(double);
	Point(double, double);
	getX();
	getY();
};

int main()
{
	Point p0{};
	p0.show();
	p0.transX(5).transY(3).transXY(-2, -1);
	p0.show();

	Point p1{ p0.getX(), p0.getY() };
	p1.show();
	p1.setX(-3);
	p1.setY(3);
	p1.show();
	p1.transXY(3, 4).transX(-2).transY(2);
	p1.show();
	p1.transX(5).transY(3).show();

	std::cout << "Distance [p0, p1] = " << Point::distance(p0, p1) << "\n";
}

Point::Point() : Point(0)
{}

Point::Point(double x) : Point(x, x)
{}

Point::Point(double x, double y) : x(x), y(y)
{}





/*
* 
Zadanie 1 [0,5 pkt]

Utwórz klasę Point zawierającą:
- dwa prywatne pola typu double, opisujące współrzędne kartezjańskie punktu
- konstruktor bezparametrowy, ustawiający wartość obu współrzędnych na zero
- konstruktor jednoparametrowy, ustawiajacy wartość obu współrzędnych na wartość przekazanego parametru
- konstruktor dwuparametrowy, ustawiający wartości współrzędnych na wartości przekazanych parametrów
- metody getX() oraz getY() zwracające wartości odpowiednich współrzędnych
- metody setX(double) oraz setY(double), ustawiające wartość odpowiedniej współrzędnej na wartość przekazanego parametru
- metodę show(), wypisującą wartości współrzędnych punktu na konsoli wraz z opisem
- metody transX(double) oraz transY(double), zwiększające wartość odpowiedniej współrzędnej o przekazaną wartość (wykonujące odpowiednią translację)
- metodę transXY(double, double), zwiekszającą wartości odpowiednich współrzędnych o przekazane wartości (wykonującą odpowiednią translację)
- statyczną metodę distance(const Point&, const Point&), zwracającą odległość pomiędzy dwoma punktami

Metody transX, transY oraz transXY powinny zwracać referencję do obiektu na rzecz którego zostały wywołane (zastanów się jak możesz wykorzystać w tym
celu wskaźnik this), tak aby możliwy był następujący ciąg operacji:

p.transX(5).transY(3).show();

W zadaniu oceniane będzie wykorzystanie języka C++, czyli pola i metody powinny zostać oznaczone jako publiczne lub prywatne, definicje metod 
powinny zostać umieszczone poza klasą, konstruktory powinny wykorzystywać listę inicjalizacyjną, a metody niemodyfikujące obiektu na rzecz którego 
są wołane powinny posiadać modyfikator const.



W celu lepszego zrozumienia zadania przykładowy program:

int main()
{
  Point p0{};
  p0.show();
  p0.transX(5).transY(3).transXY(-2, -1);
  p0.show();

  Point p1{ p0.getX(), p0.getY() };
  p1.show();
  p1.setX(-3);
  p1.setY(3);
  p1.show();
  p1.transXY(3, 4).transX(-2).transY(2);
  p1.show();
  p1.transX(5).transY(3).show();

  std::cout <<"Distance [p0, p1] = "<<Point::distance(p0, p1) <<"\n";
}

powinien posiadać efekt zbliżony do przedstawionego poniżej:

Point [0; 0]
Point [3; 2]
Point [3; 2]
Point [-3; 3]
Point [-2; 9]
Point [3; 12]
Distance [p0, p1] = 10

*/