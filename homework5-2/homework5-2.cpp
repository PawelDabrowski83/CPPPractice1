#include <iostream>

int main()
{
    std::cout << "Hello World!\n";
}

/*
* 
Utwórz szablon klasy Stack, reprezentujący stos dla elementów pewnego typu. Implementacja klasy powinna opierać się na strukturze listy 
jednokierunkowej dla której pamiętany jest wskaźnik head, wskazujący na pierwszy element listy. Dla klasy Stack powinny zostać zdefiniowane 
następujące metody:
- konstruktor bezparametrowy, tworzący pusty stos
- konstruktor kopiujący, tworzący kopię stosu
- metoda empty(), zwracającą prawdę jeżeli stos jest pusty i fałsz w przeciwnym przypadku
- metoda put(const T&), dodająca element na koniec stosu
- metoda get(), zwracająca i usuwająca ostatni element stosu
- destruktor, w razie potrzeby zwalniający zaalokowaną pamięć wraz z wypisywaniem wartości usuwanych elementów listy

W celu lepszego zrozumienia zadania przykładowy program:

template<typenameT>
classStack
{
private:
  structNode
  {
    T value;
    Node* next;
  };
  Node* head;
public:
  Stack();
  Stack(constStack&);
  ~Stack();
  bool empty() const;
  void put(constT&);
  T get();
};

int main()
{
  Stack<int> first_stack;

  for (size_t i = 0; i < 5; ++i)
  {
    first_stack.put(i * i);
  }

  for (size_t i = 0; i < 5; ++i)
  {
    std::cout <<"Removing element from first stack: "<< first_stack.get() <<"\n";
  }
  std::cout <<"\n";

  for (size_t i = 0; i < 5; ++i)
  {
    first_stack.put(i);
  }

  Stack<int> second_stack{ first_stack };

  for (size_t i = 0; i < 5; ++i)
  {
    std::cout <<"Removing element from second stack: "<< second_stack.get() <<"\n";
  }
  std::cout <<"\n";

}

powinien posiadać efekt zbliżony do przedstawionego poniżej:
Removing element from first stack: 16
Removing element from first stack: 9
Removing element from first stack: 4
Removing element from first stack: 1
Removing element from first stack: 0


Removing element from second stack: 4
Removing element from second stack: 3
Removing element from second stack: 2
Removing element from second stack: 1
Removing element from second stack: 0

Destructor starts.
Destructor ends.
Destructor starts.
Removing 4
Removing 3
Removing 2
Removing 1
Removing 0
Destructor ends.

*/