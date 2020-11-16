#include "PlayGround.h"

CPlayGround::CPlayGround()   //Конструктор
{
    int x, y, k = 0;
    // инициализируем массив поля
    for (int i = 0; i < 100; i++)
    {
        area[i / 10][i % 10] = 0;
        open[i / 10][i % 10] = false;
    }

    srand((int)time(0));
    // Случайная расстановка мин на поле, если в клетке стоит значение -1 = мина
    for (int i = 1; i <= 10; i++)
    {
        x = rand() % M;
        y = rand() % M;
        area[x][y] = -1; 
    }

    // Заполняем поле цифрами
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
//Проверяет клетку на наличие мины. Если выход за границу поля, то возвращает false
bool CPlayGround::Mine(int x, int y)
{
    if ((x >= 0) && (x < N))
        if ((y >= 0) && (y < N))
            if (area[x][y] == -1)
                return true;

    return false;
}

//========================================
//Проверяет клетку на пустоту. Если выход за границу поля, то возвращает false
bool CPlayGround::Empty(int x, int y)
{
    if ((x >= 0) && (x < N))
        if ((y >= 0) && (y < N))
            if (area[x][y] == 0)
                return true;

    return false;
}

//========================================
//Открывает поля в выбранной клетке
void CPlayGround::Clean(int x, int y)
{
    //Проверка на выход за пределы массива
    if ((x >= 0) && (x < N))
    {
        if ((y >= 0) && (y < N))
        {
            if (!open[x][y])         //Проверим, не было ли открыто поле раньше
            {
                open[x][y] = true;    //Открываем клетку
                if (area[x][y] == 0)     //Если поле пустое (=0), то открываем всех его соседей
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
                //Если не пустое (!=0) открываем только пустых (=0) соседей
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
//Проверяет все ли поле открыто, кроме мин (уcловие победы)
bool CPlayGround::Check()
{
    for (int x = 0; x < N; x++)
        for (int y = 0; y < N; y++)
            if ((area[x][y] != -1) && (!open[x][y]))
                return false;
    return true;
}

//========================================
//Открывает все мины в случае проигрыша
void CPlayGround::OpenMines()
{
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (area[i][j] == -1)
                open[i][j] = true;
}

//========================================
//Завершение игры
void CPlayGround::Final()
{
    system("cls");
    Print();
    if (Check())
        cout << "\n\nВы выиграли!";
    else
        cout << "\n\nВы проиграли!";
    cout << "\n\n\n\n";
}

//========================================
//Вывод на экран
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
