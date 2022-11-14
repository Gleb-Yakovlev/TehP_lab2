#include "STUDENT.h"

void Student::Add(int idd) {

	cout << "Enter the group number: ";
	group_number = safe_input_string();

	cout << "Enter surname: ";
	surname = safe_input_string();

	cout << "Enter the title and assessment, if the input is finished, enter 0" << endl;
	while (1) {
		cout << "Title: ";
		string s = safe_input_string();
		if (s == "0") break;
		resize_sub();
		sub[sub_size-1].title = s;

		cout << "Assessment (2, 3, 4, 5 or c for credit or n for non-credit): ";
		do {
			try
			{
				sub[sub_size-1].ocenka = safe_input_char();
				if (Cor_ocenk(sub[sub_size-1].ocenka)) 
					throw 1;
				break;
			}
			catch (int a) {
				cout << "Incorrect input" << endl;
			}
		} 
		while (1);
	}
	id = idd;
	aver_score = Average_score();
}

void Student::Add(int idd, string sur, string gr, int su_si, subjects* su) {
	surname = sur;
	group_number = gr;

	for (int i = 0; i < su_si; i++) {
		resize_sub();
		sub[sub_size-1].title = su[i].title;
		sub[sub_size-1].ocenka = su[i].ocenka;
	}
	id = idd;
	aver_score = Average_score();
}

void Student::Show() {
	cout << "(" << id << ")" << endl
		<< "Groupe: " << group_number << endl
		<< "Name: " << surname << endl
		<< "Title and assessment:" << endl;

	for (int i = 0; i < sub_size; i++) cout << sub[i].title << "[" << sub[i].ocenka << "]" << endl;
}

void Student::Change_title() {
	int t;
	do {
		try {
			system("cls");
			for (int i = 0; i < sub_size; i++) cout << i+1 << ")" << sub[i].title << "[" << sub[i].ocenka << "]" << endl;
			cout << "Enter the number of the title you are changing" << endl;
			t = safe_input_int();
			if (t < 0 || t > sub_size) throw 1;
			break;
		}
		catch (int s) {
			cout << "Wrong number" << endl;
			system("pause");
		}
	} while (1);

	cout << "What to change" << endl
		<< "1)Title" << endl
		<< "2)Assessment" << endl;

	while (1) {
		switch (safe_input_int())
		{
		case 1: {
			cout << "New title: ";
			sub[t - 1].title = safe_input_string();
			return;
		}
		case 2: {
			cout << "New assessment (2, 3, 4, 5 or c for credit or n for non-credit): ";
			do {
				try
				{
					sub[t - 1].ocenka = safe_input_char();
					cout << endl;
					if (Cor_ocenk(sub[t - 1].ocenka)) throw "Incorrect input";
					break;
				}
				catch (string s) {
					cout << s << endl;
				}
			} while (1);
			return;
		}
		default:
			break;
		}
	}
	aver_score = Average_score();
}

bool Student::Prolem() {
	for (int i = 0; i < sub_size; i++) if (sub[i].ocenka == '2' || sub[i].ocenka == 'n' || sub[i].ocenka == 'N') return true;
	return false;
}

float Student::Average_score() {
	float sum = 0;
	for (int i = 0; i < sub_size; i++) {
		if (sub[i].ocenka == 'n' || sub[i].ocenka == 'N') {
			sum += 2;
			continue;
		}

		if (sub[i].ocenka == 'c' || sub[i].ocenka == 'C') {
			sum += 5;
			continue;
		}

		sum += sub[i].ocenka - '0';
	}
	sum /= sub_size;
	return sum;
}

void Student::resize_sub() {
	int new_size = sub_size + 1;
	subjects* new_ = new subjects[new_size];
	for (int i = 0; i < sub_size; ++i)
		new_[i] = sub[i];
	delete[] sub;
	sub = new_;
	sub_size++;
}

bool Student::Cor_ocenk(char a) {
	if (a != '2' && a != '3' && a != '4' && a != '5' && a != 'c' && a != 'C' && a != 'n' && a != 'N') return true;
	return false;
}
