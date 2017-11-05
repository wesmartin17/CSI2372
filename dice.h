#include <iostream>
#include <vector>

enum Color { red, yellow, blue };

struct dice {
	const Color dColor;
	int number;
	void print(std::ostream& o);
};
