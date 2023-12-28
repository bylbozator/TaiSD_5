#ifndef TIME_H
#define TIME_H

#include <iostream>
using namespace std;
class Time {
private:
    int hours;
    int minutes;
    static int count; // статическая компонента для подсчёта количества созданных объектов
public:
    Time(int h, int m) : hours(h), minutes(m) {

        while (minutes >= 60) { // Проверяем, что минуты не больше 59
            minutes -= 60;
            hours++;
        }
        while (hours >= 24) { // Проверяем, что часы не больше 23
            hours -= 24;
        }
        count++;
    }

    Time() {
        setlocale(0, "");
        cout << "Введите часы: ";
        cin >> hours;
        while (hours < 0) { // Повторный ввод, пока не будет введено положительное число
            cout << "Часы не могут быть отрицательными. Введите положительное число: ";
            cin >> hours;
        }
        cout << "Введите минуты: ";
        cin >> minutes;
        while (minutes < 0) { // Повторный ввод, пока не будет введено положительное число
            cout << "Минуты не могут быть отрицательными. Введите положительное число: ";
            cin >> minutes;
        }
        count++; // увеличиваем счётчик при создании нового объекта
    }
    void displayTime() {
        cout  << hours << " часов и " << minutes << " минут" << endl;
    }
    static int getCount() {
        return count; // статическая функция для получения количества созданных объектов
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

int Time::count = 0; // инициализация статической переменной класса.

#endif