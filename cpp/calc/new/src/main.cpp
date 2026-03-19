#include <iostream>

#include "calculate.h"

int main() {
	double a, b, res;
	char op;
	while(true) {
		try {
			std::cin >> a >> op >> b;
			res = calculate(a, op, b);
			std::cout << "\033[1A\033[2K" << a << " " << op << " " << b << " = " << res << "\n";
		} catch (const std::invalid_argument &e){
			std::cout << "Error: " << e.what() << "\n";
		}
	}
}
