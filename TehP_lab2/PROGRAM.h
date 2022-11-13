#pragma once
#include <iostream>
#include <fstream>
#include "STUDENT.h"

class Program{
public:
	Program();
	//~Program();

	int stud_size = 0;
	Student* student = new Student[stud_size];
	void resize_stud();

	void Show_all();
	void Show_problem();
	void Change();
	void Delette();
	void Safe();
	void Read_file();
	void Write_file();
};
