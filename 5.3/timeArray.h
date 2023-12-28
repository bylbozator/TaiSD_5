#ifndef NEWTIME_H
#define NEWTIME_H

#include <iostream>
#include <windows.h>
#include <time.h>
#include "time.h"
using namespace std;

class TimeArray {
private:

	static int count;
	int h, m;;
public:
	int SizeArr;
	Time* arr;
	// Конструктор без параметров
	TimeArray() {
		count++;
	}
	// Конструктор с параметрами, позволяющий заполнить массив элементами, заданными пользователем с клавиатуры
	TimeArray(int size) {
		count++;
		SizeArr = size;
		arr = new Time[SizeArr];
		for (int i = 0; i < size; i++)
		{
			cout << "Введите часы: ";
			cin >> h;
			while (h< 0) { // Повторный ввод, пока не будет введено положительное число
				cout << "Часы не могут быть отрицательными. Введите положительное число: ";
				cin >> h;
			}
			cout << "Введите минуты: ";
			cin >> m;
			while (m < 0) { // Повторный ввод, пока не будет введено положительное число
				cout << "Минуты не могут быть отрицательными. Введите положительное число: ";
				cin >> m;
			}
		
			arr[i] = Time(h, m);
		}
	}
	// Конструктор с параметрами, заполняющий элементы случайными значениями
	TimeArray(int size, bool b) {
		count++;
		SizeArr = size;
		arr = new Time[SizeArr];
		for (int i = 0; i < size; i++)
		{
			h = rand() % 23;
			m = rand() % 59;
		
			arr[i] = Time(h, m);
		}
	}

	void ArrayOut() {
		for (int i = 0; i < SizeArr; i++)
		{
			arr[i].displayTime();
		}
	}

	// метод для поиска минимального времени в массиве и его вывода
	void findAndDisplayMinTime() {
		if (SizeArr == 0) {
			cout << "Пустое значение" << endl;
			return;
		}

		Time minTime = arr[0];
		for (int i = 1; i < SizeArr; i++) {
			if (arr[i] < minTime) {
				minTime = arr[i];
			}
		}

		cout << "Минимальное время:" << endl;
		minTime.displayTime();
		
	}

	void getTimeByIndexAndPrint(int index) {
		if (index >= 0 && index < SizeArr) {
			cout << "Время по индексу " << index << ": " << h<< " часов " << m << " минут " << endl;
			
		}
		else {
			cout<<"Индекс вне диапазона"<<endl;
		}
	}


	static int GetCount() {
		return count;
	}

	
};

int TimeArray::count = 0;
#endif