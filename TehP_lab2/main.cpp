#include "TEXT_FROM_FILE.h"
#include "PROGRAM.h"

#include <iostream>
#include <string>

using namespace std;

int main() {

	cout << "Select a task" << endl
		<< "1)Standard streams" << endl
		<< "2)File and string streams" << endl;
	int n_lab = 0;
	n_lab = safe_input_int();

	while (1) {
		switch (n_lab)
		{
		case 1: {
			system("cls");
			Program p;
			return 0;
		}
		case 2: {
			system("cls");
			Text_from_file();
			return 0;
		}
		default: {
			cout << "ERROR!" << endl;
			break;
		}
		}
	}
}