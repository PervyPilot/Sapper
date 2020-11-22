#pragma once

#include <iostream> 
#include <ctime>

using namespace std;

#define N 10
#define M 10
class CPlayGround
{
private:
    int area[N][N];            //������� ����
    bool open[N][N];           //����������, ������� ��� ������� ������
public:
    CPlayGround ();            //�����������
    bool Mine(int x, int y);   //��������� ������ �� ������� ����. ���� ����� �� ������� ����, �� ���������� false
    bool Empty(int x, int y);  //��������� ������ �� �������. ���� ����� �� ������� ����, �� ���������� false
    void Clean(int x, int y);  //��������� ���� � ��������� ������
    bool Check();              //��������� ��� �� ���� �������, ����� ��� (������� ������)
    void OpenMines();          //��������� ��� ���� � ������ ���������
    void Final();              //������� ��������� ����
    void Print();              //����� �� �����
};

