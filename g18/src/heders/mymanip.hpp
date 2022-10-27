#ifndef MYMANIP_H
#define MYMANIP_H
#include <iostream>
using namespace std;
//процесс создания манипулятора с параметрами
//1 задаём короткое имя PTF для типа указателя
//на функцию ostream& f(ostream &, int)
typedef ostream &(*PTF) (ostream &, int);

//2Создаём класс MyManip с полями для указателя
//на функцию и необходимых параметров
class MyManip
{
public:
    // конструктор
    MyManip(PTF F, int W) : f(F), w(W){cout<<"MyManip constructor work\n";}

protected:
    PTF f;
    int w;

    friend ostream &operator <<(ostream &, MyManip);
    //в классе должен быть переопределён оператор <<
    //для случая когда второй аргумент - объект этого класса
};

//3 пишем определение для оператора << указанного в классе как дружественный.
//он принемает объект MyManip и выполняет функцию содержащуюся в этом объекте
//беря оттуда же дополнительные аргументы
ostream &operator <<(ostream &out, MyManip my)
{
    cout<<"operator<<(ostream &out, MyManip my) work\n";
    return my.f(out, my.w);
}

//4 пишем функцию, применяющую к потоку (первый параметр)
//нужные операции с параметрами из остальных позиций своео
//списка аргументов и возвращающую поток
ostream& fmanip(ostream &s, int w)
{
    cout<<"fmanip(ostream &out, int w) work\n";
    s.width(w);
    return s;
}

//5пишем функцию которая создаёт  и возвращает объект класса МайМанип,
//со ссылкой на функцию применяющую изменения к потоку в качестве
//первого аргумента конструктора и со
//всеми необходимыми аргументами в качестве остальных аргументов
MyManip mywp(int w =10)
{
    cout<<"mywp work\n";
    return MyManip(fmanip, w);
}

/*
 * 1 mywp work
 * 2 MyManip constructor work
 * 3 operator<< work
 * 4 fmanip work
 * mywp порождает объект класса MyManip, к которому 
 * применяется оператор <<
 * Так как в классе MyManip оператор<< переопределён, 
 вызывается соответствующая
 * версия оператора
 * Которая вместо вывода символов применяет к потоку функцию,
 * заданную как параметр конструктора в классе MyManip
*/

#endif //MYMANIP_H