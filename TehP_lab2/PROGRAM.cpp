#include "PROGRAM.h"

Program :: Program() {

	Read_file();
	while (1) {
		system("cls");
		cout << "STUDENTS" << endl;
		cout << "Select an action: " << endl
			<< "1)Add student" << endl
			<< "2)Show all students" << endl
			<< "3)Show students with learning problems" << endl
			<< "4)Change Data " << endl
			<< "5)Delete Data" << endl
			<< "0)Save and Exit" << endl;
		int order = 0;
		order = safe_input_int();

		switch (order)
		{
		case 1: {
			resize_stud();
			student[stud_size-1].Add(stud_size);
			break;
		}

		case 2: {
			system("cls");
			Show_all();
			system("pause");
			break;
		}

		case 3: {
			system("cls");
			Show_problem();
			system("pause");
			break;
		}

		case 4: {
			system("cls");
			Show_all();
			Change();
			system("pause");
			break;
		}

		case 5: {
			system("cls");
			Show_all();
			Delette();
			system("cls");
			Show_all();
			break;
		}

		case 0: {
			Write_file();
			return;
		}

		default:
			break;
		}
	}
}

void Program::Read_file() {
	ifstream file("txt_1.txt");

	if (file.peek() == EOF) return;

	string s;
	getline(file, s);
	int s_size = stoi(s);

	for (int i = 0; i < s_size; i++) {

		string sur;
		getline(file, sur);

		string gr;
		getline(file, gr);

		string su_si;
		getline(file, su_si);

		subjects* su = new subjects[stoi(su_si)];
		for (int j = 0; j < stoi(su_si); j++) {
			getline(file, su[j].title);
			string k;
			getline(file, k);
			su[j].ocenka = k[0];

			//cout << su[j].title << " " << su[j].ocenka << endl;
		}

		resize_stud();
		student[stud_size - 1].Add(stud_size, sur, gr, stoi(su_si), su);
	}

	file.close();
}

void Program::Order(){
	for (int i = 0; i < stud_size-1; i++) 
		if (student[i].Average_score() > student[i+1].Average_score()){
			Student s;
			s = student[i];
			student[i] = student[i + 1];
			student[i + 1] = s;
			student[i].id = i+1;
			student[i+1].id = i+2;
			i = -1;
		}
}

void Program::Write_file() {
	ofstream file("txt_1.txt", ios_base::out | ios_base::trunc);
	file << stud_size << endl;

	for (int i = 0; i < stud_size; i++) {
		file << student[i].surname << endl << student[i].group_number << endl << student[i].sub_size << endl;
		for (int j = 0; j < student[i].sub_size; j++) file << student[i].sub[j].title << endl << student[i].sub[j].ocenka << endl;
	}
	file.close();
}

void Program::Show_all() {
	Order();
	for (int i = 0; i < stud_size; i++) 
		student[i].Show();
}

void Program::Show_problem() {
	for (int i = 0; i < stud_size; i++) 
		if (student[i].Prolem()) 
			student[i].Show();
}

void Program::Change() {
	int numb;
	cout << "Select the student's number" << endl;
	while (1) {
		try {
			numb = safe_input_int();
			if(numb <= 0 || numb > stud_size) throw 1;
			break;
		}
		catch (int s) {
			cout << "Incorrect input" << endl;
		}
	}


	for (int i = 0; i < stud_size; i++)
		if (student[i].id == numb) {
			while (1) {
				system("cls");
				student[i].Show();
				cout << "Choose which element to change" << endl;
				cout << "1)Group number" << endl
					<< "2)Surname" << endl
					<< "3)Title and assessment" << endl
					<< "0)Return back" << endl;
				int el = safe_input_int();
				switch (el)
				{
				case 1: {
					cout << "New group number: ";
					student[i].group_number = safe_input_string();
					break;
				}

				case 2: {
					cout << "New surname: ";
					student[i].surname = safe_input_string();
					break;
				}

				case 3: {
					student[i].Change_title();
					break;
				}

				case 0: return;

				default:
					break;
				}
			}
		}
}

void Program::Delette() {
	int numb;
	cout << "Select the student's number" << endl;
	while (1) {
		try {
			numb = safe_input_int();
			if (numb < 0 || numb > stud_size) throw 1;
			break;
		}
		catch (int s) {
			cout << "Incorrect input" << endl;
		}
	}

	for (int i = numb - 1; i < stud_size - 1; i++) student[i] = student[i + 1];
	stud_size--;
}

void Program::resize_stud() {
	int new_size = stud_size + 1;
	Student* new_ = new Student[new_size];
	for (int i = 0; i < stud_size; ++i)
		new_[i] = student[i];
	delete[] student;
	student = new_;
	stud_size++;
}
