// Sapper.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//#include "stdafx.h"
#include <iostream>
#include <time.h>
#include <windows.h>
#include "PlayGround.h"

using namespace std;



int main()
{
    setlocale(LC_ALL, "RUS");

    CPlayGround play;
    int x, y;

    while (true) 
    {
        system("cls"); // Очищаем экран
        play.Print();
        cout << "\n";
        cout << "Введите координаты по горизонтали: ";
        cin >> x;
        cout << "Введите координаты по вертикали: ";
        cin >> y;
        play.Clean(y, x);

        if (play.Mine(y, x))
        {
            play.OpenMines();
            play.Final();
            break;
        }                              //Программа покидает цикл в случае проигрыша
        if (play.Check())
        {
            play.Final();
            break;
        }                 //Или победы
    }
    return 0;
}