#include <iostream>
#include <vector>
#include <string>

using namespace std;

int takeInput() {
    std::cout << "Please enter a non-negative number:" << std::endl;
    int response;
    std::cin >> response;
    return response;
}

int getMaxFrom(const std::vector<int>& numbers) {
    int max = numbers[0];
    for (int i = 1; i < numbers.size(); i++) {
        int currentNum = numbers[i];
        if (max < currentNum) {
            max = currentNum;
        }
    }
    return max;
}

void printEmpty() {
    std::cout << "  ";
}

void printFull() {
    std::cout << "* ";
}

void drawHistagram(std::vector<int>& numbers) {
    int counter = getMaxFrom(numbers);

    for (int row = 0; row < counter; row++) {
        int rowTriggered = counter - row;
        for (int col = 0; col < numbers.size(); col++) {
            if (numbers[col] >= rowTriggered) {
                printFull();
            }
            else {
                printEmpty();
            }
        }
        std::cout << std::endl;
    }
}

int main()
{
    std::cout << "HISTOGRAM" << std::endl;
    std::vector<int> memory;

    int response = -1;
    while (response != 0) {
        response = takeInput();
        if (response > 0 ) {
            memory.push_back(response);
            std::cout << "Number: " << response << " collected." << std::endl;
        }
    }
    std::cout << "Finished taking input. I collected " << memory.size() << " numbers." << std::endl;

    std::cout << "Who wants to draw a histogram?" << std::endl;
    std::cout << std::endl;
    
    drawHistagram(memory);

}

/*
Napisz program, który w pętli będzie prosił użytkownika o wpisanie dodatniej liczby całkowitej.  Wczytywanie kończy się, gdy użytkownik poda liczbę 0.
Program następnie wypisze na ekranie „histogram” dla wprowadzonych wartości.  

„Histogram” ma postać „słupków”, złożonych ze znaków ’*’ i wyrównanych od dołu, o wysokościach równych wartościom wczytanych liczb.

Przykładowy efekt działania programu wygląda następująco:

E n t e r   non−n e g a t i v e   n u m b e r s :   3   1   5   0

     *
     *
∗    *
∗    *
∗ ∗  *

Podpowiedź:  Pomyśl jak możesz wykorzystać obiekt klasy vector.
*/