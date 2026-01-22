#include <iostream>

#ifdef _WIN32 //Windows
	#include <conio.h>
	#define CLEAR() system("cls")
	#define PAUSE() system("pause")
#else
	#include <termios.h> //Linux
	#include <unistd.h>

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

	int _getch() {
		return getch();
	}

	#define CLEAR() printf("\033c")
	#define PAUSE() printf("Press any button to continue"); getch()
#endif

float CRT = 0.0; //Correct answers
int QNS = 0; //Questions
float COUNT_QNS = 0.0; //Questions count

#define rst "\033[0m"    //Reset colors
#define ch "\033[30;47m" //White bg and black text

int welcome() {
	char ready;
	printf("Hello! This is a test made by Marshall31.\n Are you ready? (y/n)\n");
	std::cin >> ready;
	switch (ready) {
		case 'y':
			return 1;
		case 'n':
			return 0;
	}
	return 10;
}

int ANSW(std::string TXT, std::string a1, std::string a2, std::string a3) { //This is the "UI" and user input
	int a = 0; //User's choice
	bool rd = true;
	
	while (rd) {
		CLEAR();
		std::cout << TXT << "\n\n"; //Question
		
		
		if (a == 0) std::cout << ch << a1 << rst << "\n"; else std::cout << a1 << "\n"; //Answers
		if (a == 1) std::cout << ch << a2 << rst << "\n"; else std::cout << a2 << "\n";
		if (a == 2) std::cout << ch << a3 << rst << "\n"; else std::cout << a3 << "\n";
		
		int tm = _getch();
		#ifdef _WIN32 //Controls on Windows
			if (tm == 224) {
				int TMP = _getch();
				/*if (TMP == 72 && a != 0) {
					a--;
				} else if (TMP == 80 && a != 2) {
					a++;
				} */
				
				switch (TMP) {
					case 72: //Up
						if (a != 0) a--;
						break;
					case 80: //Down
						if (a != 2) a++; 
				}
			} else if (tm == 13) return a; //Enter
		#else
			if (tm == 27 && getch() == 91) { //Controls on Linux
				int TMP = getch();
				switch (TMP) {
					case 65: //Up
						if (a != 0) a--;
						break;
					case 66: //Down
						if (a != 2) a++;
				}
			} else if (tm == 10) return a; //Enter
		#endif
	}
	return -1;
}

void QST(std::string TEXT, std::string AN0, std::string AN1, std::string AN2, int CORRECT) { //Questions function
	int an = ANSW(TEXT, AN0, AN1, AN2); //Answers are numbered from 0 to 2

	if (an == CORRECT) {
		CRT += 1;
		CLEAR();
	} else if (an == -1) {
		CLEAR();
		printf("How???");
		PAUSE();
	}

	/*switch(an) {
		case CORRECT:
			CRT += 1;
		case default:
			system("cls");
			std::cout << "Yay! " << QNS << " questions left!\n\nPress enter to continue";
	}*/

	QNS--;
	COUNT_QNS++;

	CLEAR();
	std::cout << "Yay! " << QNS << " questions left!\n\nPress enter to continue";

	PAUSE();
}


void q1() {
	QST("Question 1:\n2 + 2 = ?", "1", "2", "4", 1);
} 

void END() {
	float percent = (CRT / COUNT_QNS) * 100; //Correct answers percentage
	CLEAR();
	printf("Congrats! You reached the end of this test!\nPress any button to see your results");
	_getch();
	std::cout << "\n\nYou correctly answered " << CRT << " questions!\nThis is the " << percent << "%" << " of test!\n\n";
	PAUSE();
}


int main() {
	QNS = 10; //Number of questions, it used only to display how more questions left
	int *tmp = new int;
	*tmp = welcome();
	if (*tmp == 0) return 0; else if (*tmp == 10) {
		printf("How?\n\n"); 
		PAUSE();
		return 0;
	}
	delete tmp; //For some reason I didn't like that the variable is used only once and remains on the stack, so I moved it to heap
	printf("\nOkay, let's start.\n\n");
	PAUSE();
	CLEAR();
	q1();
	QST("Question 2:\nWhat is main sound driver in Linux?", "PipeWire", "PulseAudio", "ALSA", 2);
	QST("Question 3:\nWho created Linux kernel?", "Linus Torvalds", "Richard Stallman", "Bill Gates", 0);
	QST("Question 4:\nWho created this test?", "Linus Torvalds",  "Marshall31" ,"Donald Trump", 1);
	QST("Question 5:\nWhat's number of system call 'write' in x86_64?", "1", "2", "3", 0);
	QST("Question 6:\nHow to print line in terminal using C++?", "std::cout << ln", "std::cout << ln;", "std::cin >> ln;", 1);
	QST("Question 7:\nHow to reboot linux if it doesn't respond?", "Alt+SysRQ+REISUB", "Turn off computer", "Call Saul Goodman", 0);
	QST("Question 8:\nWhat's the best OS in the world?", "Linux", "GovnOS", "Windows", 3);
	CRT = CRT + 1.0;
	CLEAR();
	printf("Actually there is no best OS, everyone likes different ones.\nBtw, I like Linux\n\nAnd if you want to know: in the first version of this program there was correct answer and it was number 2.\n\n");
	PAUSE();
	QST("Question 9:\nWhat language were questions about?", "C++", "Assembly", "Linux", 0);
	QST("Question 10:\nWho created C++?", "Linus Torvalds", "Bjarne Stroustrup", "Walter White", 1);

	END();

	CLEAR();

	return 0;
}
