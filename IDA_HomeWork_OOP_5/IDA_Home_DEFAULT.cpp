// HomeWork template project v 4.0 // 20.06.2023 //

/*
Основы ООП на языке С++
Перегрузка унарных операторов
Задание
В реализованном ранее классе дробь реализовать перегрузку следующих унарных
поераторов :
инкримент "++"
декримент "--"
унарный минус "-"
унарный плюс "+"
Обратить внимание на конструкторы класса и те которые представляются нужными отметить
как explicit.выбор пояснить комментарием
Добавить в класс методы : -получения целой части от дроби - получения дробной части от
дроби - сокращение дроби(уменьшение знаменателя до возможного минимума) - получение
обратной дроби
``` задание сдаётся в виде ссылки на репозиторий либо подготовленным архивом проекта
*/

#include <iostream>
#include <string>
#include <windows.h>
#include <time.h>
#include <algorithm>
#include <conio.h>
//#include <array>
//My own headers
#include "Service functions.h"
#include "MainMenu.h"
//#include "Fraction.h"
#include "Money.h"



// Homework OOP 5 ----------------------------------------------------	


//Task 1 "Money class demo with overloaded operators:\n\tBinary: + | - | / | * \n\tUnary: + | - | ++ | --"
void Task_1(std::string name_of_task)
{
	//std::cout << "***\t ComplexNumber class through inheritance with overloaded operators: + | - | / | * demo\n";
	std::cout << "Enter provided_at_startup_money_holders_quantity -> ";
	int provided_at_startup_money_holders_quantity = Get_Int_Positive(0, 10, "it's too much, reasonable limit is 10 -> ");
	Money::Initialisation(provided_at_startup_money_holders_quantity);

	do
	{
		system("cls");
		std::cout << "***\t" << name_of_task << "\n";
		Money::ShowAvailableMoneyObjects();
		Money::ShowMethods();
		if (Money::UserChoiceHandle_getch()) break;

		std::cout << "\n\nEsc - exit | any key to continue";
	} while (_getch() != 27);
	Money::Memory_Clean();
}

//Task 2
void Task_2(){}

//Task 3 
void Task_3() {}

//Task 4
void Task_4() {}

// MAIN ------- MAIN ------- MAIN ------- MAIN ------- MAIN --------
int main()
{
	srand(time(NULL));
	//setlocale(LC_CTYPE, "Russian");
	//system("mode con cols=60 lines=40"); 
	Main_menu MainMenu;	
	MainMenu.AddElement("OOP Home Work 05: Classes. Money container");	// Homework name
	MainMenu.AddElement("Money class demo with overloaded operators:\n\tBinary: + | - | / | * \n\tUnary: + | - | ++ | --");
	//MainMenu.AddElement("XXX");
	do 
	{		
		MainMenu.Show_menu();
		if (!MainMenu.User_Choice_Handle(_getch()))	break;
	} while (true);
	return 0;
}

