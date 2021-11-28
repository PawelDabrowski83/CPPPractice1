#include <iostream>

template<typename T>
class Queue {
	struct Node {
		T value;
		Node* next;
	};
	Node* head;
	Node* tail;
public:
	Queue();
	bool empty() const;
	void put(const T& data);
	T get();
	~Queue();
};

// w przypadku szablonów definicje są powyżej miejsca wywołania
template<typename T>
Queue<T>::Queue() : head(nullptr), tail(nullptr) {
}

template<typename T>
bool Queue<T>::empty() const {
	return head == nullptr;
}

template<typename T>
void Queue<T>::put(const T& data) {
	if (!empty()) {
		Node* ptr = new Node{ data, nullptr };  // tworzę nowy element listy
		tail->next = ptr;  // dołączam nowy element listy za ogonem
		tail = ptr;  // nowy element listy staje się ogonem
	}
	else {
		head = new Node{ data, nullptr };  // tworzę nowy element listy
		tail = head;  // pierwszy element listy jest jednocześnie jej ogonem
	}
}

template<typename T>
T Queue<T>::get() {
	Node* ptr = head;  // zapamiętuje wskaźnik do głowy
	head = head->next;  // przesuwam głowę dalej
	T value = ptr->value;  // wyciągam element ze starej głowy
	delete ptr;  // muszę zwolnić pamięć, alokowaną poprzez new
	return value;
}

template<typename T>
Queue<T>::~Queue() {  // destruktor służy do zwolnienia zaalokowanej pamięci
	while (!empty()) {
		Node* ptr = head;  // zapamiętuje wskaźnik do głowy
		head = head->next;  // przesuwam głowę dalej
		std::cout << "DEL: " << ptr->value << " ";
		delete ptr;  // muszę zwolnić pamięć, alokowaną poprzez new
	}
}

int main() {
	int data1, data2;
	Queue<int>* q = new Queue<int>();
	q->put(1);
	data1 = q->get();
	std::cout << " data1=" << data1;
	std::cout << std::endl;
	q->put(1);
	q->put(2);
	data1 = q->get();
	data2 = q->get();
	std::cout << " data1=" << data1
		<< " data2=" << data2 << std::endl;
	q->put(1); q->put(2); q->put(3);
	q->put(4); q->put(5); q->put(6);
	while (!q->empty())
		std::cout << " " << q->get();
	std::cout << std::endl;
	q->put(1); q->put(2); q->put(3);
	delete q;
}