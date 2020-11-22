#pragma once

#include <iostream> 
#include <ctime>

using namespace std;

#define N 10
#define M 10
class CPlayGround
{
private:
    int area[N][N];            //Игровое поле
    bool open[N][N];           //Показывает, открыта или закрыта клетка
public:
    CPlayGround ();            //Конструктор
    bool Mine(int x, int y);   //Проверяет клетку на наличие мины. Если выход за границу поля, то возвращает false
    bool Empty(int x, int y);  //Проверяет клетку на пустоту. Если выход за границу поля, то возвращает false
    void Clean(int x, int y);  //Открывает поля в выбранной клетке
    bool Check();              //Проверяет все ли поле открыто, кроме мин (условие победы)
    void OpenMines();          //Открывает все мины в случае проигрыша
    void Final();              //Функция завершает игру
    void Print();              //Вывод на экран
};

