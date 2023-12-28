#include <iostream>
#include "time1.h"
using namespace std;


int main() {
    Time t1;
    /*Time t2;*/
    setlocale(0, "");
    cout << "Первоначальное время t1:" << endl;
    t1.displayTime();
 
    int secondsToSubtract;
    cout << "Введите количество секунд, которое нужно вычесть из t1: ";
    cin >> secondsToSubtract;

    t1.subtractSeconds(secondsToSubtract);
    cout << "Время t1 после вычитания " << secondsToSubtract << " секунд:" << endl;
    t1.displayTime();

    cout << "Общее количество созданных объектов: " << Time::getCount() << endl;

    return 0;
}
