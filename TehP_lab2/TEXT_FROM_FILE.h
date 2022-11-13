#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

void Text_from_file() {
	ifstream file("txt_2.txt");
	string s;
	//char c, cc, ccc;

	while (!file.eof()) {

		//stringstream ss;
		//ss << "kal govna ebanogo";
		//cout << ss.str();



		getline(file, s);
		int n = 0;
		for (int i = 0; i < s.length(); i++) {

			if (isdigit(s[i])) n = 0;

			while (isdigit(s[i])) {
				n++;
				i++;
			}

			if (n != 2 && n != 0) break;



			//if (isdigit(s[i]) && isdigit(s[i + 1]) && !isdigit(s[i + 2])) {
			//	cout << s << endl;
			//	break;
			//}
		}
		if (n == 2) cout << s << endl;
		//char a = s[s.length()];
		//if (s[s.length()] == '/0') {
		//	file.close();
		//	return;
		//}
	}
	file.close();
	return;

	//for (; file >> c, file >> cc, file>>ccc;) {
	//	if (isdigit(c) && isdigit(cc) && !isdigit(ccc)) {
	//		getline(file, s);
	//		cout << s;
	//	}
	//}
	//file.close(); 
	//return;
}