#include <iostream>

using namespace std;


double deg( double a, double b ) {
	double z = a;
	for( int i = 1; i < b; i++) {
		a = a * z;
	}
	return a;
}


void calc(double a, char op, double b) {
	cout << "Result: ";
	switch(op) {
		case '+':
			cout << a + b;
			break;
		case '-':
			cout << a - b;
			break;
		case '*':
			cout << a * b;
			break;
		case '/':
			cout << a / b;
			break;
		case '^':
			cout << deg(a, b);
			break;
	}
	cout << "\n";
}

int main() {
	double a, b;
	char op;

	while (true) {
		cin >> a >> op >> b;
		try {
			calc(a, op, b);
		}
		catch(const invalid_argument& e) {
			cout << "hmm\n";
		}
	}
}
