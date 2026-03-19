#include <stdexcept>

#include "calculate.h"
#include "additional_math.h"

double calculate (double a, char op, double b) {
	switch (op) {
		case '+':
			return a + b;
		case '-':
			return a - b;
		case '*':
			return a * b;
		case '/':
			return a / b;
		case '^':
			return power(a, b);
		case 'r':
			return root(a, b);
		default:
			throw std::invalid_argument("Invalid operation");
	}
}
