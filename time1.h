#ifndef TIME_H
#define TIME_H

#include <iostream>
using namespace std;
class Time {
private:
    int hours;
    int minutes;
    static int count; // ����������� ���������� ��� �������� ���������� ��������� ��������
public:
    Time(int h, int m) : hours(h), minutes(m) {

        while (minutes >= 60) { // ���������, ��� ������ �� ������ 59
            minutes -= 60;
            hours++;
        }
        while (hours >= 24) { // ���������, ��� ���� �� ������ 23
            hours -= 24;
        }
        count++;
    }

    Time() {
        setlocale(0, "");
        cout << "������� ����: ";
        cin >> hours;
        while (hours < 0) { // ��������� ����, ���� �� ����� ������� ������������� �����
            cout << "���� �� ����� ���� ��������������. ������� ������������� �����: ";
            cin >> hours;
        }
        cout << "������� ������: ";
        cin >> minutes;
        while (minutes < 0) { // ��������� ����, ���� �� ����� ������� ������������� �����
            cout << "������ �� ����� ���� ��������������. ������� ������������� �����: ";
            cin >> minutes;
        }
        count++; // ����������� ������� ��� �������� ������ �������
    }
    void displayTime() {
        cout  << hours << " ����� � " << minutes << " �����" << endl;
    }
    static int getCount() {
        return count; // ����������� ������� ��� ��������� ���������� ��������� ��������
    }
    Time subtractSeconds(int seconds) {
        int totalSeconds = hours * 3600 + minutes * 60;
        totalSeconds -= seconds;
        if (totalSeconds < 0) {
            totalSeconds = 0;
        }
        hours = totalSeconds / 3600;
        minutes = (totalSeconds % 3600) / 60;
        return *this;
    }

};

int Time::count = 0; // ������������� ����������� ���������� ������.

#endif