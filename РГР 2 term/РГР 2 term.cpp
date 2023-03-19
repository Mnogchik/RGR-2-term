#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <cmath>
#include <iomanip>
using namespace std;

void setcur(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
};
void show_menu(char s[])
{
    setcur(0, 0);
    cout << "1. Заставка " <<s[0]<< endl
        << "2. Таблица " << s[1] << endl
        << "3. Графики " << s[2] << endl
        << "4. Уравнения " << s[3] <<endl
        << "5. Интергал " << s[4] << endl
        << "6. Об авторе " << s[5] << endl
        << "7. Выход " << s[6] <<endl;
}
char menu_down(char s[])
{
    for (int i = 0; i < 7; i++)
    {
        if (s[i] == '<')
        {
            s[i] = ' ';
            s[i + 1] = '<';
            break;
        }
    }
    return *s;
}
char menu_up(char s[]) 
{
    for (int i = 0; i < 7; i++)
    {
        if (s[i] == '<')
        {
            s[i] = ' ';
            s[i - 1] = '<';
            break;
        }
    }
    return *s;
}


double max_arr(double a[], int N)
{
    double max = a[0];
    for (int i = 1; i < N; i++)
    {
        if (a[i] > max)
            max = a[i];
    }
    return max;
}
double min_arr(double a[], int N)
{
    double min = a[0];
    for (int i = 1; i < N; i++)
    {
        if (a[i] < min)
            min = a[i];
    }
    return min;
}
void cursor_off()
{
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO info;
    info.dwSize = 100;
    info.bVisible = FALSE;
    SetConsoleCursorInfo(consoleHandle, &info);
}
double resh_urav(double x)
{
    double X = (2 * x * pow(sin(x), 2) - 3 * sqrt(x + cos(x)));
    return X;
}
double resh_integral(double x)
{
    double y = ((x * x) * log(x));
    return y;
}




void intro()
{
    system("cls");
    cout << "Пошёл нахер";
    _getch();
    

}
void table()
{
    int a = 1, b = 3;
    const int N = 15;
    double mass_table_x[N], mass_table_y[N];
    double x = a, y;
    double dx = (double)(((fabs(b - a))) / (N - 1));
    cout << "x*ln(x)^2" << endl;
    for (int i = 0; i < N; i++)
    {
        mass_table_x[i] = x;
        y = x * (log(x) * log(x));
        mass_table_y[i] = y;
        x += dx;
    }
    for (int i = 0; i < N; i++)
    {
        cout << "| " << setw(8) << left << mass_table_x[i] << "| " << mass_table_y[i] << endl;
    }
    cout << "Максимальное значение функции = " << max_arr(mass_table_y, N) << endl;
    cout << "Минимальное значение функции = " << min_arr(mass_table_y, N) << endl;
    _getch();
    setcur(0, 0);
    x = a;
    cout << "cos(3x)/(1+x^2)"<<endl;
    for (int i = 0; i < N; i++)
    {
        mass_table_x[i] = x;
        y = (double)(cos(3*x)/(1+x*x));
        mass_table_y[i] = y;
        x += dx;
    }
    for (int i = 0; i < N; i++)
    {
        cout << "| " << setw(8) << left << mass_table_x[i] << "| " << mass_table_y[i] << endl;
    }
    cout << "Максимальное значение функции = " << max_arr(mass_table_y, N) << endl;
    cout << "Минимальное значение функции = " << min_arr(mass_table_y, N) << endl;
    _getch();
    system("cls");

}
void graphick();
void uravn()
{
    system("cls");
    cout << " Решение уравнения: 2x*sin^2(x)-3*sqrt(x+cos(x))=0" << endl;
    double a, b, e=0.001;
    cout << "Введите нижнию границу интервала" << endl;
    cin >> a;
    cout << "Введите верхнюю границу интервала" << endl;
    cin >> b;
    
    double c = 0, fc=0;
    double fa = resh_urav(a), fb = resh_urav(b);
    while (b-a>e)
    {
        
        c = ((a + b) / 2.0);
        fc = resh_urav(c);
        if (fa * fc < 0)
            b = c, fb = fc;
        else
            a = c, fa = fc;        

    }
    cout << c << endl << fc << endl;
    _getch();
    system("cls");

}
void integral()
{
    system("cls");
    double a, b, dx, answ=0;
    cout << "Введите нижнию границу интегрирования" << endl;
    cin >> a;
    cout << "Введите верхнюю границу верхнюю" << endl;
    cin >> b;
    dx = (b - a) / 100000.0;
    for (double i = a; i <= b; i += dx)
    {
        answ += dx * resh_integral(i);
    }
    cout << answ << endl;
    _getch();
    system("cls");
}
void about_autor() 
{
    system("cls");
    cout << "Шашков Данил ПИН-222" << endl;
    _getch();
    system("cls");
}



void call_func(char s[])
{
    setcur(0, 0);
    int num_func;
    for (int i = 0; i < 7; i++)
    {
        if (s[i] == '<')
        {
            num_func = i;
            break;
        }
    }
    switch (num_func)
    {
    case(0):
    {
        intro();
        break;
    }
    case (1):
        table();
        break;
    case (2):
       // graphick();
        break;
    case (3):
       uravn();
        break;
    case(4):
        integral();
        break;
    case(5):
        about_autor();
        break;
    case (6):
        system("cls");
        exit(1);
        break;


    }

}


int main()
{
    char s[] = { '<', ' ', ' ', ' ', ' ', ' ', ' ' };
    cursor_off();
    setlocale(LC_ALL, "");

    
    while (true)
    {
        show_menu(s);
        switch (_getch())
        {
        case('P'):
        {
            menu_down(s);
            show_menu(s);
            break;
        }
        case('H'):
        {
            menu_up(s);
            show_menu(s);
            break;
        }
        case('\r'):
        {
            call_func(s);
        }
        }



    }
}

