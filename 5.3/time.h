#ifndef TIME_H
#define TIME_H

#include <iostream>
using namespace std;
class Time {
private:
    int hours;
    int minutes;
    int  seconds;
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
        setlocale(0, "");
    
        count++; // увеличиваем счётчик при создании нового объекта
    }
    void displayTime() {
        cout << "Время: " << hours << " часов и " << minutes << " минут" << endl;
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
    // Перегруженные операции
    Time operator-() {
        hours = 0;
        minutes = 0;
        return *this;
    }

    Time operator--() {
        if (minutes > 0) {
            --minutes;
        }
        else {
            if (hours > 0) {
                --hours;
                minutes = 59;
            }
            else {
                hours = 0;
                minutes = 0;
            }
        }
        return *this;
    }
 

    operator int() {
        return hours;
    }
    explicit operator bool() {
        return (hours != 0 || minutes != 0);
    }
    bool operator==(const Time& t) {
        return (hours == t.hours && minutes == t.minutes);
    }
    bool operator!=(const Time& t) {
        return !(*this == t);
    }
};

int Time::count = 0; // инициализация статической переменной класса.

#endif