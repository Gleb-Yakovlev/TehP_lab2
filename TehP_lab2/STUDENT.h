#pragma once
/*Определить класс с именем STUDENT, содержащий следующие поля:
● фамилия и инициалы;
● номер группы;
● изучаемые предметы и соответствующие им оценки.
Определить методы доступа к этим полям и перегруженные операции
извлечения и вставки для объектов типа STUDENT.
Заранее число объектов не известно.
Написать программу, выполняющую следующие действия:
● записи должны быть упорядочены по возрастанию среднего балла;
● вывод на дисплей фамилий и номеров групп для всех студентов,
имеющих хотя бы одну оценку 2;
● если таких студентов нет, вывести соответствующее сообщение.*/

#include "SAFE_INPUT.h"

#include <iostream>
#include <string>
using namespace std;

struct subjects
{
	string title;
	char ocenka;
};  

class Student {
public:
	string surname;
	string group_number;
	int id;

	int sub_size = 0;
	subjects* sub = new subjects[sub_size];
	void resize_sub();
	bool Cor_ocenk(char);

	void Add(int);
	void Add(int, string, string, int, subjects*);
	void Show();
	bool Prolem();
	int Average_score();
	void Change_title();
};