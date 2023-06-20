#pragma once
#include <vector>
#include <map>
#include <string>
#include <iostream>
#include "Service functions.h"
#include <conio.h>
#include <iomanip>

class Money
{
	int _roubles;
	int _coins;
	static std::vector <Money> _money_list;
public:
	static void User_Choice_Handle();
	static void Show_List_of_available_numbers();
	static void ShowMethods();
	static ComplexNumber_class_through_including* New_number_input();
	static ComplexNumber_class_through_including* Get_Operand(int operand_number);

	static std::map <int, std::string> codes_of_operation;

	// Constructors // Initialisation // Destructors // Memory Clean -------
	Money(int roubles = 0, int coins = 0) { Set_roubles(roubles).Set_coins(coins); _money_list.push_back(*this); }	
	Money() {}
	~Money()
	{
		std::cout << "\nDestructor at work\n";
		//_getch();
	}
	static void Initialisation(int provided_at_startup_money_holders_quantity)
	{
		for (int i = 0; i < provided_at_startup_money_holders_quantity; i++)
			_money_list.push_back(Money(Get_Random(0, 100), Get_Random(0, 100)));
	}
	static void Memory_Clean()
	{
		for (int i = 0; i < _money_list.size(); i++)
			delete[] &_money_list[i];
		_money_list.clear();
	}

	// Setters // Getters --------------------------------------------------
	Money& Set_roubles(int rubles) { _roubles = rubles; return *this; }
	Money& Set_coins(int coins) { _coins = coins; return *this;	}
	int Get_roubles() { return _roubles; }
	int Get_coins() { return _coins; }

	// Shows ---------------------------------------------------------------
	void ShowValues()	{ std::cout << this; }
	void ShowMethods()
	{
		std::cout << "\nAvailable methods:\n\nBinary:\t\t\t\t" << "Unary:\n";
		std::cout << "Summation [+] -> [1]" << "\t\t" << "Prefix increment  [++v] -> [5]" << '\n';
		std::cout << "Substract [-] -> [2]" << "\t\t" << "Postfix increment [v++] -> [6]" << '\n';
		std::cout << "Multiply  [*] -> [3]" << "\t\t" << "Prefix decrement  [--v] -> [7]" << '\n';
		std::cout << "Divide    [/] -> [4]" << "\t\t" << "Postfix decrement [v--] -> [8]" << '\n';
		std::cout << "\t\t\t\tUnary plus        [+v]  -> [9]" << '\n';
		std::cout << "\t\t\t\tUnary minus       [-v]  -> [0]" << '\n';

		/*std::cout << "\nUnary:\n";
		std::cout << "Prefix increment  [++v] -> [5]" << '\n';
		std::cout << "Postfix increment [v++] -> [6]" << '\n';
		std::cout << "Prefix increment  [--v] -> [7]" << '\n';
		std::cout << "Postfix decrement [v--] -> [8]" << '\n';
		std::cout << "Unary plus        [+v]  -> [9]" << '\n';
		std::cout << "Unary minus       [-v]  -> [0]" << '\n';*/
	}
	static void ShowAvailableMoneyObjects()
	{
		for (int i = 0; i < _money_list.size(); i++)
			_money_list[i].ShowValues();
	}
	// Inputs handle -------------------------------------------------------		
	static int UserChoiceHandle()
	{
		int action = Check_action_input();
		if (action == -1) return;
		std::cout << "-------->  " << codes_of_operation[action] << "                                 ";

		Money& Operand_1 = Choose_Operand_Handle(1);
		if (&Operand_1 == nullptr) return;
		std::cout << "\n   " << codes_of_operation[action];
		Money& Operand_2 = Choose_Operand_Handle(2);
		if (&Operand_2 == nullptr) return;



		std::cout << "\n\n";
		Operand_1.Show();
		std::cout << "  " << codes_of_operation[action] << "  ";
		Operand_2.Show();
		std::cout << " = ";
		switch (action)
		{
		case 1: (Operand_1 + Operand_2).Show(); break;
		case 2: (Operand_1 - Operand_2).Show(); break;
		case 3: (Operand_1 * Operand_2).Show(); break;
		case 4: (Operand_1 / Operand_2).Show(); break;

		default: std::cout << "\nkeycode " << action;
		}
	}
	static Money& Choose_Operand_Handle(int Operand_number) {

		std::cout << "\nchoose operand " << Operand_number << ": ";
		//std::string coomment = "index out of range "+"[1.." + std::to_string(static_pointer_Available_Moneys->size());
		std::string comment = "index out of range ";
		comment += "[1.." + std::to_string(_money_list.size()) + "] ";
		int Money_index = Get_Int_Positive(1, _money_list.size(), comment);
		--Money_index; //transform number to index

		return *(*static_pointer_Available_Moneys)[Money_index];
	}
	static int Check_action_input()
	{
		int keycode = _getch();
		std::cout << console_clear;
		if (keycode == 27) return -1;
		if (keycode >= 48 && keycode <= 58)
			return (keycode - 48);	
		//std::cout << "\nkeycode " << keycode;
		std::cout << "Press a number of operation [0..9]";
		Check_action_input();
		
	}


	//Overload operators - reference returned -----------------------------------------

	/*
	const Money& operator+(const Money& another_Money)
	{
		std::cout << "\n" << "Using const& overload parameter" << "\n";
		int new_numerator = (this->_numerator) * (another_Money._denominator) + (another_Money._numerator) * (this->_denominator);
		int new_denominator = (this->_denominator) * (another_Money._denominator);
		Money* result_Money = new Money(new_numerator, new_denominator);
		return *result_Money;
	}
	//*/

	/*
	const Money& operator+(Money& another_Money)
	{
		std::cout << "\n" << "Using & overload parameter" << "\n";
		int new_numerator = this->_numerator * another_Money.Get_denominator() + another_Money.Get_numerator() * this->_denominator;
		int new_denominator = this->_denominator * another_Money.Get_denominator();
		Money* result_Money = new Money(new_numerator, new_denominator);
		return *result_Money;
	}
	//*/

	/*
	friend const Money& operator+(const Money& Money_Operand_1, const Money& Money_Operand_2)
	{
		std::cout << "\n" << "Using friend const& overload parameter, return reference" << "\n";

		int new_numerator = (Money_Operand_1._numerator) * (Money_Operand_2._denominator) + (Money_Operand_2._numerator) * (Money_Operand_1._denominator);
		int new_denominator = (Money_Operand_1._denominator) * (Money_Operand_2._denominator);
		Money* result_Money = new Money(new_numerator, new_denominator);
		return *result_Money;
	}
	//*/

	//Overload operators - pointer returned -----------------------------------------

	// Выводы:
	//1 у компилятора в приоритете использование перегрузки через функции-члены
	//2 только потом пытается  использовать friend, причем это проихсодит даже если friend подходит, а member нет!
	//3 также компилятор предпочитает использовать варианты перегрузок с параметрами с простой ссылкой вместо const&
	//4* при попытке выноса определения у friend функции VS пытается вынести его рядом с main (вместо classes.cpp)

	friend Money* operator+(const Money& Money_Operand_1, const Money& Money_Operand_2);
	Money* operator+(const Money& another_Money);
	Money* operator+(Money& another_Money);
	Money* operator-(const Money& another_Money);
	Money* operator*(const Money& another_Money);
	Money* operator/(const Money& another_Money);

	Money* operator++();
	Money* operator++(int);
	Money* operator--() //prefix
	{
		_numerator--;
		return this;
	}
	Money* operator--(int) //postfix
	{
		//Money& tmp_obj(*this);
		Money* tmp_obj = new Money(*this);
		_numerator--;
		//return &tmp_obj;
		return tmp_obj;
	}

	Money* operator+()
	{
		return this;
	}
	Money* operator-()
	{
		_numerator = -_numerator;
		return this;
	}

	friend std::ostream& operator << (std::ostream& out, Money* just_a_Money)
	{
		out << just_a_Money->Get_roubles() << " roubles" << just_a_Money->Get_coins() << " coins";
		return out;
	}

};