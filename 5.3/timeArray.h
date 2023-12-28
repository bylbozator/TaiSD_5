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
	// ����������� ��� ����������
	TimeArray() {
		count++;
	}
	// ����������� � �����������, ����������� ��������� ������ ����������, ��������� ������������� � ����������
	TimeArray(int size) {
		count++;
		SizeArr = size;
		arr = new Time[SizeArr];
		for (int i = 0; i < size; i++)
		{
			cout << "������� ����: ";
			cin >> h;
			while (h< 0) { // ��������� ����, ���� �� ����� ������� ������������� �����
				cout << "���� �� ����� ���� ��������������. ������� ������������� �����: ";
				cin >> h;
			}
			cout << "������� ������: ";
			cin >> m;
			while (m < 0) { // ��������� ����, ���� �� ����� ������� ������������� �����
				cout << "������ �� ����� ���� ��������������. ������� ������������� �����: ";
				cin >> m;
			}
		
			arr[i] = Time(h, m);
		}
	}
	// ����������� � �����������, ����������� �������� ���������� ����������
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

	// ����� ��� ������ ������������ ������� � ������� � ��� ������
	void findAndDisplayMinTime() {
		if (SizeArr == 0) {
			cout << "������ ��������" << endl;
			return;
		}

		Time minTime = arr[0];
		for (int i = 1; i < SizeArr; i++) {
			if (arr[i] < minTime) {
				minTime = arr[i];
			}
		}

		cout << "����������� �����:" << endl;
		minTime.displayTime();
		
	}

	void getTimeByIndexAndPrint(int index) {
		if (index >= 0 && index < SizeArr) {
			cout << "����� �� ������� " << index << ": " << h<< " ����� " << m << " ����� " << endl;
			
		}
		else {
			cout<<"������ ��� ���������"<<endl;
		}
	}


	static int GetCount() {
		return count;
	}

	
};

int TimeArray::count = 0;
#endif