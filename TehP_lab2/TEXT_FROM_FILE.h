#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

void Text_from_file() {
	ifstream file("txt_2.txt");
	string s;

	while (!file.eof()) {
		getline(file, s);
		int n = 0;
		for (int i = 0; i < s.length(); i++) {

			if (isdigit(s[i])) n = 0;

			while (isdigit(s[i])) {
				n++;
				i++;
			}

			if (n != 2 && n != 0) break;

		}
		if (n == 2) cout << s << endl;
	}
	file.close();
	return;

}