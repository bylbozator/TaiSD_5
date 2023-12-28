#include <iostream>
#include "time1.h"
using namespace std;



int main() {
    Time t1;
    Time t2;
    setlocale(0, "");
    cout << "Первоначальное время:"  << endl;
    t1.displayTime();
    t2.displayTime();

    -t1; // обнуление часов и минут
    cout << "Время t1 после одинарной операции -t1:" << endl;
    t1.displayTime();

    --t2; // вычитание 1 минуты
    cout << "Время t2 после одинарной операции -t2:" << endl;
    t2.displayTime();

    int hoursFromT1 = t1;
    cout << "Часы с момента t1: " << hoursFromT1 << endl;

    bool t1NotEmpty = static_cast<bool>(t1);
    cout << "Является ли t1 не пустым:" << (t1NotEmpty ? "правда" : "ложь") << endl;

    cout << "t1 == t2: " << (t1 == t2 ? "правда" : "ложь") << endl;
    cout << "t1 != t2: " << (t1 != t2 ? "правда" : "ложь") << endl;

    cout << "Общее количество созданных объектов:" << Time::getCount() << endl;

    return 0;
}
