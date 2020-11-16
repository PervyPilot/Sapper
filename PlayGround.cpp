#include "PlayGround.h"

CPlayGround::CPlayGround()   //�����������
{
    int x, y, k = 0;
    // �������������� ������ ����
    for (int i = 0; i < 100; i++)
    {
        area[i / 10][i % 10] = 0;
        open[i / 10][i % 10] = false;
    }

    srand((int)time(0));
    // ��������� ����������� ��� �� ����, ���� � ������ ����� �������� -1 = ����
    for (int i = 1; i <= 10; i++)
    {
        x = rand() % M;
        y = rand() % M;
        area[x][y] = -1; 
    }

    // ��������� ���� �������
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (area[i][j] != -1)
            {
                k = 0;
                if (Mine(i - 1, j - 1))
                    k++;
                if (Mine(i - 1, j))
                    k++;
                if (Mine(i - 1, j + 1))
                    k++;
                if (Mine(i, j - 1))
                    k++;
                if (Mine(i, j + 1))
                    k++;
                if (Mine(i + 1, j - 1))
                    k++;
                if (Mine(i + 1, j))
                    k++;
                if (Mine(i + 1, j + 1))
                    k++;
                area[i][j] = k;
            }
}

//========================================
//��������� ������ �� ������� ����. ���� ����� �� ������� ����, �� ���������� false
bool CPlayGround::Mine(int x, int y)
{
    if ((x >= 0) && (x < N))
        if ((y >= 0) && (y < N))
            if (area[x][y] == -1)
                return true;

    return false;
}

//========================================
//��������� ������ �� �������. ���� ����� �� ������� ����, �� ���������� false
bool CPlayGround::Empty(int x, int y)
{
    if ((x >= 0) && (x < N))
        if ((y >= 0) && (y < N))
            if (area[x][y] == 0)
                return true;

    return false;
}

//========================================
//��������� ���� � ��������� ������
void CPlayGround::Clean(int x, int y)
{
    //�������� �� ����� �� ������� �������
    if ((x >= 0) && (x < N))
    {
        if ((y >= 0) && (y < N))
        {
            if (!open[x][y])         //��������, �� ���� �� ������� ���� ������
            {
                open[x][y] = true;    //��������� ������
                if (area[x][y] == 0)     //���� ���� ������ (=0), �� ��������� ���� ��� �������
                {
                    Clean(x - 1, y - 1);
                    Clean(x - 1, y);
                    Clean(x - 1, y + 1);
                    Clean(x, y - 1);
                    Clean(x, y + 1);
                    Clean(x + 1, y - 1);
                    Clean(x + 1, y);
                    Clean(x + 1, y + 1);
                }
                //���� �� ������ (!=0) ��������� ������ ������ (=0) �������
                else
                {
                    if (Empty(x - 1, y - 1))
                        Clean(x - 1, y - 1);
                    if (Empty(x - 1, y))
                        Clean(x - 1, y);
                    if (Empty(x - 1, y + 1))
                        Clean(x - 1, y + 1);
                    if (Empty(x, y - 1))
                        Clean(x, y - 1);
                    if (Empty(x, y + 1))
                        Clean(x, y + 1);
                    if (Empty(x + 1, y - 1))
                        Clean(x + 1, y - 1);
                    if (Empty(x + 1, y))
                        Clean(x + 1, y);
                    if (Empty(x + 1, y + 1))
                        Clean(x + 1, y + 1);
                }
            }
        }
    }
}

//========================================
//��������� ��� �� ���� �������, ����� ��� (�c����� ������)
bool CPlayGround::Check()
{
    for (int x = 0; x < N; x++)
        for (int y = 0; y < N; y++)
            if ((area[x][y] != -1) && (!open[x][y]))
                return false;
    return true;
}

//========================================
//��������� ��� ���� � ������ ���������
void CPlayGround::OpenMines()
{
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (area[i][j] == -1)
                open[i][j] = true;
}

//========================================
//���������� ����
void CPlayGround::Final()
{
    system("cls");
    Print();
    if (Check())
        cout << "\n\n�� ��������!";
    else
        cout << "\n\n�� ���������!";
    cout << "\n\n\n\n";
}

//========================================
//����� �� �����
void CPlayGround::Print()
{
    cout << "  ";
    for (int i = 0; i < N; i++)
        cout << i << " ";
    cout << endl;
    for (int x = 0; x < N; x++)
    {
        cout << x << " ";
        for (int y = 0; y < N; y++)
        {
            if (open[x][y])
            {
                if (area[x][y] == -1)
                    cout << "* ";
                else
                    if (area[x][y] == 0)
                        cout << ". ";
                    else
                        cout << area[x][y] << " ";
            }
            else
                cout << "  ";
        }
        cout << "\n";
    }
}
