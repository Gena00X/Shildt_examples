/*	Простая программа ведения инвентарной ведомости,
	в которой используется массив структур.
	Шилдт, С++: базовый курс 2019 СПб. ООО Диалектика стр. 245*/


#include <iostream>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include "ruconsole.h"
using namespace std;

template <class T> void testvar(T i)
{
	cout<<"i="<<i<<'\n';
}

const int MYSIZE = 100;

struct inv_type 
{
	char item[40];	//наименование товара
	double cost;	//стоимость
	double retail;	//розничная цена
	int on_hand;	//имеющееся в наличии количество
	int lead_time;	//время до пополнения запасов
} invtry[MYSIZE];

void enter(), 
     init_list(), 
	 display(), 
	 update(), 
	 input(int i), 
	 search(), 
	 clear();
int menu();



int main()
{
	char choice;
	
	for(;;)
	{
		choice = menu();
		switch(choice)
		{
			case 'e': enter();
				break;
			case 'd': display();
				break;
			case 'u': update();
				break;
			case 's': search();
				break;
			case 'c': clear();
				break;
			case 'l': system("cls");
				break;
			case 'q': return 0;
		}
	}
}

//инициализация массива структур
void init_list()
{
	int t;
	
	for(t = 0; t<MYSIZE; t++) *invtry[t].item = '\0';
}

//получение команды меню выбранной пользователем
int menu()
{
	char ch;
	cout<<'\n';
	do{
		cout<<"(E)nter\n"; 			//Ввести новый элемент
		cout<<"(D)isplay\n";		//Отобразить всю ведомость
		cout<<"(U)pdate\n";			//Изменить элемент
		cout<<"(S)earch\n";			//Поиск элемента
		cout<<"(C)lear\n";			//Очистка списка (удаление заголовков)
		cout<<"c(l)ear scrin\n";	//Очистка экрана
		cout<<"(Q)uit\n";			//Выйти из программы
		cout<<"Выберете команду: ";
		cin>>ch;
		
	}while(!strchr("edusclq", tolower(ch)));
	return tolower(ch);
}

//ввод элементов в инвентарную ведомость
void enter()
{	
	int i;
	//находим первую свободную структуру
	for(i = 0; i<MYSIZE; i++)
		if(!*invtry[i].item) break;
	
	//если массив полон, значение i будет равно MYSIZE
	if(i==MYSIZE)
	{
		cout<<"Список полон!\n";
		return;
	}
	//testvar(i);
	input(i);
}

//ввод информации (используется в enter() и в update())
//вынесен в отдельную функцию во избежание дублирования кода
void input(int i)
{
	//testvar(i);
	cout << "Товар: ";
	cin >> invtry[i].item;
	
	cout << "Стоимость: ";
	cin >> invtry[i].cost;
	
	cout << "Розничная цена ";
	cin >> invtry[i].retail;
	
	cout << "В наличии: ";
	cin >> invtry[i].on_hand;
	
	cout << "Время до пополнения запасов (в днях): ";
	cin >> invtry[i].lead_time;
}

//модификация существующего элемента
void update()
{
	
	int i;
	char name[80];
	
	cout<<"Введите наименование товара: ";
	cin >> name;
	
	for(i = 0; i < MYSIZE; i++)
		if(!strcmp(name, invtry[i].item)) break;
	
	if(i==MYSIZE)
	{
		cout<<"Товар не найден.\n";
		return;
	}
	
	cout<<"Ввеите новую информацию\n";
	//testvar(i);
	input(i);
}

//Отображение инвентарной ведомости на экране
void display()
{
	int t;
	bool not_empty = 0;
	for(t=0; t<MYSIZE; t++)
	{
		if(*invtry[t].item)
		{
			if(!not_empty) not_empty = true;
			cout << invtry[t].item <<'\n';
			cout << "Стоимость: $" << invtry[t].cost << '\n';
			cout << "В Розницу: $" << invtry[t].retail << '\n';
			cout << "В наличии: " << invtry[t].on_hand << '\n';
			cout << "До пополнения осталось: " << invtry[t].lead_time << " дней \n\n";
		}
	}
	if(!not_empty)
		cout<<"Список пуст.\n";
}

//Поиск товара
void remove(int i){
	cout<<"remove "<<invtry[i].item<<" \n";
	invtry[i].item[0]='\0';
}

void update(int i){
	cout<<invtry[i].item<<" will be updated\n";
	cout<<"Ввеите новую информацию\n";
	//testvar(i);
	input(i);
}

void display(int i)
{
			cout << invtry[i].item <<'\n';
			cout << "Стоимость: $" << invtry[i].cost << '\n';
			cout << "В Розницу: $" << invtry[i].retail << '\n';
			cout << "В наличии: " << invtry[i].on_hand << '\n';
			cout << "До пополнения осталось: " << invtry[i].lead_time << " дней \n\n";
}

void search_menu(int i);

void search_menu(int i)
{
	char ch;
	cout<<"Что вы хотите сделать?\n";
	cout<<"(U)pdate\n";
	cout<<"(R)emove\n";
	cout<<"(D)isplay\n";
	cout<<"(Q)uit\n";
	cin>>ch;
	if(strchr("urdq", tolower(ch)))
	{
			switch(tolower(ch)){
				case 'r': 
					remove(i);
					break;
				case 'u': 
					update(i);
					break;
				case 'd': 
					display(i);
					break;
				case 'q':
					return;
		}
	}else search_menu(i);

}

void search()
{
	int i;
	char name[80];
	
	cout<<"Введите наименование товара: ";
	cin >> name;
	
	for(i = 0; i < MYSIZE; i++)
		if(!strcmp(name, invtry[i].item)) break;
	
	if(i==MYSIZE)
	{
		cout<<"Товар не найден.\n";
		return;
	}
	else
	{
		search_menu(i);
	}
	
}

void clear()
{
	char ch;
	cout<<"Вы уверены?\n Это действие удалит ВСЕ записи инвентарной ведомости!\n";
	cout<<"(Y)es/(N)o\n";
	cin>>ch;
	if(strchr("yn", tolower(ch)))
	{
		if(tolower(ch)=='y')
		{
			for(int t=0; t<MYSIZE; t++)
			{
				if(*invtry[t].item)
				{
					remove(t);
				}
			}
		}else return;
	}else return;
}
