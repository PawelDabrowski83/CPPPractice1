#include <iostream>

class Test
{
public:
    static int count;
    Test();
    Test(const Test& other);
    ~Test();
};

void fun1(Test a) {
}

void fun2(Test& a) {
}

void fun3(Test* a) {
}

int main() {
    Test t1;
    Test t2 = t1;
    t1 = t2;
    fun1(t1);
    fun2(t2);
    fun3(&t1);
}

int Test::count = 0;

Test::Test() {
    count++;
    std::cout << "Konstruktor bezargumentowy. Istnieje obiektow: " << count << std::endl;
}

Test::Test(const Test& other) {
    count++;
    std::cout << "Konstruktor kopiujacy. Istnieje obiektow: " << count << std::endl;
}

Test::~Test() {
    count--;
    std::cout << "Destruktor. Istnieje obiektow: " << count << std::endl;
}
