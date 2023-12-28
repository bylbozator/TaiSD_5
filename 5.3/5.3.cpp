#include <iostream>
#include <time.h>
#include "timeArray.h"

using namespace std;

TimeArray Arr1(int size);
TimeArray ArrRand(int size);

int main()
{
    srand(time(0));
    setlocale(0, "");
    Time T;
    TimeArray arr;
    int  size, index, choice;

    cout << "Введите количество данных: ";
    cin >> size;

    cout << "Выберите тип заполнения данных:" << endl;
    cout << "1. Вручную" << endl;
    cout << "2. Рандомными значениями" << endl;
    cout << "Ваш выбор: ";
    cin >> choice;
    switch (choice)
    {
    case 1:
        arr = Arr1(size);
        break;
    case 2:
        arr = ArrRand(size);
        break;
    default:
        cout << "Ошибка ввода. Выход" << endl;
        return 0;
        break;
    }
    cout << "Ваши данные:"<<endl;
    arr.ArrayOut();
    cout << "Введите какое время вы хотите посмотреть: ";
    cin >> index;
    cout << "Результат:" << endl;
    arr.getTimeByIndexAndPrint(index);

    arr.findAndDisplayMinTime();


    cout << "Количество объектов времени: " << Time::getCount() << endl;
    return 0;
}

TimeArray Arr1(int size)
{
    TimeArray arr(size);
    return arr;
}

TimeArray ArrRand(int size)
{
    TimeArray arr(size, true);
    return arr;
}