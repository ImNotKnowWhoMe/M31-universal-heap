#include <iostream>
#include <termios.h>
#include <unistd.h>
#include <vector>
#include <fstream>

std::vector<std::string> arr;
int g;
int ch = 1;

int getch() {
    struct termios oldt, newt;
    int ch;
    tcgetattr( STDIN_FILENO, &oldt );
    newt = oldt;
    newt.c_lflag &= ~( ICANON | ECHO );
    tcsetattr( STDIN_FILENO, TCSANOW, &newt );
    ch = getchar();
    tcsetattr( STDIN_FILENO, TCSANOW, &oldt );
    return ch;
}

void draw(int ch) {
	std::cout << "\033[3J\033[H";
	for (int i = 0; i < g; i++) {
		if (i == ch) {
			std::cout << "\e[0;30m\e[47m" << arr[i] << "\n" << "\e[0m";
		} else {
			std::cout << arr[i] << "\n";
		}
	}
}


void read() {
	std::fstream file("list.txt");
	std::string str;
	while (std::getline(file,str)) {
		arr.push_back(str);
	}
	g = arr.size();
}


void exec(int ch) {
	std::system(arr[ch].c_str());
}


void f() {
	int z;
	while (true) {
		draw(ch);
		z = getch();
	        if (z == 27 && getch() == 91) {
			int l = getch();
			if (l == 65) {
				if (ch > 0)
					ch--;
			} else if (l == 66) {
				if (ch < (g-1))
					ch++;
			}
		} else if (z == 10) {
			exec(ch);
			break;
		}
	}
}

int main() {
	read();
	f();
}
