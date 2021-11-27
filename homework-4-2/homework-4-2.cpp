#include <iostream>

struct Node {
	char letter;
	Node* next;
};

void addLetter(struct Node*& head, char c)
{

}

void printLetters(const struct Node* head)
{
}

bool checkLetter(const struct Node* head, char c)
{
	return false;
}

void removeLetter(struct Node*& head, char c)
{
}

void clear(struct Node*& head)
{
}

int main()
{
	struct Node* head = nullptr;
	std::string s{ "Ala ma kota" };
	for (size_t i = 0; i < s.size(); ++i)
	{
		addLetter(head, s[i]);
	}

	printLetters(head);
	std::cout << checkLetter(head, 'a') << "\n";
	std::cout << checkLetter(head, 'i') << "\n";
	removeLetter(head, 'a');

	std::cout << checkLetter(head, 'a') << "\n";

	removeLetter(head, 'A');

	std::cout << checkLetter(head, 'A') << "\n";

	printLetters(head);

	clear(head);
}

/*

Zadanie 2 [0,5 pkt]

Struktura Node o następującej postaci:

struct Node
{
char letter;
Node∗ next;
};

stanowi podstawę listy jednokierunkowej. Na tej podstawie utwórz podane funkcje:

1. addLetter, dodającą wybraną literę na koniec listy jednokierunkowej

2. printLetters, wypisującą wszystkie litery z listy jednokierunkowej w kolejności ich występowania na konsoli

3. checkLetter, sprawdzającą czy podana litera występuje na liście jednokierunkowej

4. removeLetter, usuwającą wszystkie wystąpienia wybranej litery z listy jednokierunkowej

5. clear, usuwającą wszystkie elementy listy

W przypadku poprawnego uzupełnienia wszystkich funkcji poniższy program:

#include<iostream>
structNode
{
char letter;
Node* next;
};

void addLetter(structNode*& head, charc)
{
...
}

void printLetters(conststructNode* head)
{
...
}

bool checkLetter(conststructNode* head, charc)
{
...
}

void removeLetter(structNode*& head, charc)
{
...
}

void clear(structNode*& head)
{
...
}

int main()
{
structNode* head = nullptr;
std::string s{ "Ala ma kota" };
for (size_t i = 0; i < s.size(); ++i)
{
addLetter(head, s[i]);
}

printLetters(head);
std::cout << checkLetter(head, 'a') <<"\n";
std::cout << checkLetter(head, 'i') <<"\n";
removeLetter(head, 'a');

std::cout << checkLetter(head, 'a') <<"\n";

removeLetter(head, 'A');

std::cout << checkLetter(head, 'A') <<"\n";

printLetters(head);

clear(head);
}

powinien wypisać:

Ala ma kota
1
0
0
0
l m kot

 */

