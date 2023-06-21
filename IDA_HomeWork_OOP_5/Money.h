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
	long long _roubles;
	unsigned char _coins;
	static std::vector <Money> _money_list;
	static std::map <int, std::string> codes_of_operation;
public:
	//static std::vector <Money> _money_list;

	//std::map <int, std::string> Fraction::codes_of_operation
	//static std::map <int, std::string> codes_of_operation;



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
			delete[] & _money_list[i];
		_money_list.clear();
	}

	// Setters // Getters --------------------------------------------------
	Money& Set_roubles(long long rubles) { _roubles = rubles; return *this; }
	Money& Set_coins(long long coins) { _coins = coins; return *this; }
	long long Get_roubles() { return _roubles; }
	int Get_coins() { return _coins; }

	// Shows ---------------------------------------------------------------
	void ShowValues() { std::cout << *this; }
	static void ShowMethods()
	{
		std::cout << "\nAvailable methods:\n\n";
		std::cout << "Summation [+] -> [1]" << "\t\t" << "Multyply by [real] -> [5]" << '\n';
		std::cout << "Substract [-] -> [2]" << "\t\t" << "Divide   by [real] -> [6]" << '\n';
		std::cout << "Multiply  [*] -> [3]" << "\t\t" << "is_more     [>]    -> [7]" << '\n';
		std::cout << "Divide    [/] -> [4]" << "\t\t" << "is_less     [<]    -> [8]" << '\n';
		std::cout << "\t\t                                is_equal    [=]    -> [9]" << '\n';
		

		// Вариант от дробей	
		/*std::cout << "\nAvailable methods:\n\nBinary:\t\t\t\t" << "Unary:\n";
		std::cout << "Summation [+] -> [1]" << "\t\t" << "Prefix increment  [++v] -> [5]" << '\n';
		std::cout << "Substract [-] -> [2]" << "\t\t" << "Postfix increment [v++] -> [6]" << '\n';
		std::cout << "Multiply  [*] -> [3]" << "\t\t" << "Prefix decrement  [--v] -> [7]" << '\n';
		std::cout << "Divide    [/] -> [4]" << "\t\t" << "Postfix decrement [v--] -> [8]" << '\n';
		std::cout << "\t\t\t\tUnary plus        [+v]  -> [9]" << '\n';
		std::cout << "\t\t\t\tUnary minus       [-v]  -> [0]" << '\n';*/

	}
	static void ShowAvailableMoneyObjects()
	{
		for (int i = 0; i < _money_list.size(); i++)
			_money_list[i].ShowValues();
	}

	// Inputs handle -------------------------------------------------------	
		
	// getch модификация - удобный интерфейс ввода без нажатия Enter и с обработкой Esc, пока только для списков 0..9 (надо придумать как принимать одно- и двух-циферные значения в одном интерфейсе через _getch
	// getline модификация - c вводом произвольных чисел и конторолем ввода через функцию Get_Int_Positive(), ввод необходимо подтверждать Enter

	//for (;;)
	//{
	//	cout << "You are playing for:" << playtime << "seconds." << endl;
	//	cout << "You have " << bytes << " bytes." << endl;
	//	cout << "You are compiling " << bps << " bytes per second." << endl;
	//	cout << "Press a to buy assembler monkey (produces 1 byte per second)/(cost 10 bytes)" << endl;
	//	if (kbhit()) {  //is true when a key was pressed
	//		char c = getch();   //capture the key code and insert into c

	//		switch (c)
	//		{
	//		case 'a': bytes = bytes - 10; bps++; break;
	//		}
	//	}
	//	bytes = bytes + bps;
	//	playtime++;
	//	Sleep(1000);
	//	system("cls");
	//}

	static int UserChoiceHandle_getch()
	{
		int method_choice = Check_method_input_getch();
		if (method_choice == -1) return;
		std::cout << "-------->  " << codes_of_operation[action] << big_space;

		Money& Operand_1 = Get_Operand_getch(1);
		if (&Operand_1 == nullptr) return;
		std::cout << "\n   " << codes_of_operation[action];
		Money& Operand_2 = Get_Operand_getch(2);
		if (&Operand_2 == nullptr) return;


		Operation_module(action, Operand_1, Operand_2);

	}
	static int UserChoiceHandle_getline()
	{
		int action = Check_action_input_getline();
		if (action == -1) return;
		std::cout << "-------->  " << codes_of_operation[action] << big_space;


		Money& Operand_1 = Get_Operand_getline(1);
		if (&Operand_1 == nullptr) return;
		std::cout << "\n   " << codes_of_operation[action];
		Money& Operand_2 = Get_Operand_getline(2);
		if (&Operand_2 == nullptr) return;

		Operation_module(action, Operand_1, Operand_2);
	}

	static Money& Get_Operand_getch(int operand_number)
	{
		std::cout << "\nOperand_" << operand_number << ": Choose operand from list[number] or enter new[press Enter]";
		do
		{
			int input = _getch();
			//std::cout << console_clear;
			if (keycodes[input] == "Enter")
				//if (input == 27)
			{
				std::cout << console_clear;
				return New_number_input();
			}
			else if (keycodes[input] == "Esc") return nullptr;
			//else if (input == 27) return;
			/*else if (input == 0 || input == 224)
			{
				_getch();
				std::cout << "\nTurn NumLock On";
				return nullptr;
			}*/
			else if (49 <= input && input <= 57)
			{
				//_getch(); придумать 2х значный ввод
				std::cout << console_clear;
				if (codes_of_digits[input] >= _numbers_list.size())
				{
					std::cout << console_clear << "index out of range" << big_space;
					return nullptr;
				}
				std::cout << "  [" << codes_of_digits[input] + 1 << "]                                                        ";
				return _numbers_list[codes_of_digits[input]];
			}
		} while (true);
	}
	static Money& Get_Operand_getline(int Operand_number) {

		if (Operand_number)	std::cout << "\nchoose operand " << Operand_number << ": ";
		else std::cout << "\nchoose operand: ";
		std::string comment = "index out of range ";
		comment += "[1.." + std::to_string(_money_list.size()) + "] ";
		int Money_index = Get_Int_Positive(1, _money_list.size(), comment);
		--Money_index; //transform number to index

		return _money_list[Money_index];
	}
	static Money& New_money_holder_input()
	{
		std::cout << big_space;
		std::cout << "\nEnter roubles -> ";
		long long roubles = Get_Int_Positive();
		std::cout << "Enter coins   -> ";
		int coins = Get_Int_Positive();

		return *new Money(roubles, coins);
	}

	static int Check_method_input_getch()
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
	static int Check_action_input_getline()
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

	static void Operation_module(int action, Money& Operand_1, Money& Operand_2)
	{
		std::cout << "\n\n";
		Operand_1.Show();
		std::cout << "  " << codes_of_operation[action] << "  ";
		Operand_2.Show();
		std::cout << " = ";

		do
		{
			system("cls");
			std::cout << "***\t" << name_of_task << "\n";

			Fraction::ShowAvailableFractions();
			Fraction::ShowMethods();

			int action = Fraction::UserChoiceHandle();
			if (action <= 4 && action > 0)//разделеям бинарные и унарные операции
			{
				Fraction& Operand_1 = Fraction::Choose_Operand_Handle(1);
				Fraction& Operand_2 = Fraction::Choose_Operand_Handle(2);

				//switch (Fraction::UserChoiceHandle(_getch())))
				//switch (Fraction::UserChoiceHandle())
				switch (action)
				{
				case 1: Operand_1 + Operand_2; break;
					// Няглядная демонстрация упрощения кода от итерации к итерации ДЗ:
					//case 2: Available_fractions[fraction_index_1]->Subtract(*Available_fractions[fraction_index_2], Available_fractions); break;
					//case 2: Available_fractions.push_back(Operand_1 - Operand_2); break;		
				case 2: Operand_1 - Operand_2; break;
				case 3: Operand_1 * Operand_2; break;
				case 4: Operand_1 / Operand_2; break;
				}
				std::cout << std::endl << Operand_1 << Fraction::codes_of_operation[action] << Operand_2 << " = " << *Available_fractions[Available_fractions.size() - 1];

			}
			else
			{
				Fraction& Operand = Fraction::Choose_Operand_Handle(0);
				Fraction tmp(Operand); // Благодаря конструктору копирования этот временный объект не попадает в общий вектор объектов
				switch (action)
				{
				case 5: ++Operand; break;
				case 6: Operand++; break;
				case 7: --Operand; break;
				case 8: Operand--; break;
				case 9: +Operand; break;
				case 0: -Operand; break;
				}
				if (action == 8 || action == 6)
					std::cout << std::endl << "(" << tmp << ")" << Fraction::codes_of_operation[action] << " = " << Operand;
				else
					std::cout << std::endl << Fraction::codes_of_operation[action] << "(" << tmp << ") = " << Operand;


			}
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

		friend Money* operator+(const Money & Money_Operand_1, const Money & Money_Operand_2);
		Money* operator+(const Money & another_Money);
		Money* operator+(Money & another_Money);
		Money* operator-(const Money & another_Money);
		Money* operator*(const Money & another_Money);
		Money* operator/(const Money & another_Money);

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

		friend std::ostream& operator << (std::ostream & out, Money * just_a_Money)
		{
			out << just_a_Money->Get_roubles() << " roubles" << just_a_Money->Get_coins() << " coins";
			return out;
		}

	};

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

	Money* Add(Money& another_Money, std::vector<Money*>& Available_Moneys);
	Money* Subtract(Money& another_Money, std::vector<Money*>& Available_Moneys);
	Money* Multiply(Money& another_Money, std::vector<Money*>& Available_Moneys);
	Money* Divide(Money& another_Money, std::vector<Money*>& Available_Moneys);

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

	friend std::ostream& operator << (std::ostream& out, Money& Money_holder)
	{		
		out << Money_holder.Get_roubles() << ", " << Money_holder.Get_coins();
		return out;	
	}


};