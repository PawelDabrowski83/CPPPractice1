#include <iostream>

int main() {

	int x = 15;
	std::cout << x << std::endl;

	char c{ 'a' };
	unsigned int y{ 73 };

	for (int i = 0; i < 5; ++i) {
		if (i % 2 == 0) {
			std::cout << i << std::endl;
		}
	}
}