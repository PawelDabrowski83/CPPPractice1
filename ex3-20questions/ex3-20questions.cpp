#include <iostream>
#include <string>

void printIntro() {
	std::cout << "Zagrajmy w 20 pytan. Pomysl liczbe w zakresie od 1 do 1 000 000 a ja sprobuje ja odgadnac." << std::endl;
	std::cout << "Za kazdym razem kiedy podam swoj typ liczby, mozesz zareagowac wpisujac okreslony znak:" << std::endl;
	std::cout << "Jesli liczba zostala odgadnieta, wpisz jeden z nastepujacych: t, y, =" << std::endl;
	std::cout << "Jesli Twoja liczba jest wieksza, wpisz: g, >, w" << std::endl;
	std::cout << "Jesli Twoja liczba jest mniejsza, wpisz: l, <, m" << std::endl;
}

int readInput(std::string& input) {
	if (input == "t" || input == "y" || input == "=") {
		return 0;
	}
	if (input == "g" || input == "w" || input == ">") {
		return 1;
	}
	if (input == "l" || input == "m" || input == "<") {
		return -1;
	}
	return 999;
}

std::string takeInput(std::string& prompt) {
	std::cout << prompt << std::endl;
	std::string input;
	std::cin >> input;
	return input;
}

void resultEqual() {
	std::cout << "I have guessed correctly, game is over." << std::endl;
}

void resultTooSmall() {
	std::cout << "I will try with bigger number." << std::endl;
}

void resultTooBig() {
	std::cout << "I will try with smaller number." << std::endl;
}

int singleStep(int number) {
	std::string prompt = "Is your number?: " + std::to_string(number);
	std::string response = takeInput(prompt);
	int responseCode = readInput(response);
	if (responseCode == 0) {
		resultEqual();
	}
	else if (responseCode == 1) {
		resultTooSmall();
	}
	else if (responseCode == -1) {
		resultTooBig();
	}
	return responseCode;
}

int calculateEducatedGuess(int lower, int upper) {
	if (lower == upper) {
		return lower;
	}
	return (upper - lower) / 2 + lower;
}

int main() {
	int questions = 20;
	const int LOWER_BOUND = 1;
	const int UPPER_BOUND = 1000000;
	int lowerBound = LOWER_BOUND;
	int upperBound = UPPER_BOUND;


	printIntro();
	int responseCode = 888;
	while (questions > 0 && responseCode != 0) {
		int educatedGuess = calculateEducatedGuess(lowerBound, upperBound);
		responseCode = singleStep(educatedGuess);
		if (responseCode == 1) {
			lowerBound = educatedGuess;
		}
		else if (responseCode == -1) {
			upperBound = educatedGuess;
		}

	}
	std::cout << "Thank you for playing." << std::endl;


}