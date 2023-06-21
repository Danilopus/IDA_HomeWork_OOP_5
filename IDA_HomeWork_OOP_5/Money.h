#pragma once
#include <vector>
#include <map>
#include <string>
#include <iostream>
#include "Service functions.h"
#include <conio.h>
#include <iomanip>
#include <cassert>

class Money
{
	long long _roubles;
	unsigned char _coins;
	static std::vector <Money> _money_list;
	static std::map <int, std::string> codes_of_operation;
public:
	// Constructors // Initialisation // Destructors // Memory Clean -------
	Money(long long coins = 0, long long roubles = 0);
	//Money() {}
	~Money()
	{
		//std::cout << "Vector reallocates memory";
		//_getch();
	}
	static void Initialisation(int provided_at_startup_money_holders_quantity);
	static void Memory_Clean();

	// Setters // Getters --------------------------------------------------
	Money& Set_roubles(long long rubles);
	Money& Set_coins(long long coins);
	long long Get_roubles() { return _roubles; }
	int Get_coins() { return _coins; }

	// Shows ---------------------------------------------------------------
	void ShowValues() { std::cout << *this; }
	//void ShowValues() { std::cout << this; }
	static void ShowMethods();
	static void ShowAvailableMoneyObjects();

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

	static int UserChoiceHandle_getch();
	static int UserChoiceHandle_getline();

	static Money* Get_Operand_getch(int Operand_number);
	static Money& Get_Operand_getline(int Operand_number);
	static Money& New_money_holder_input();

	static int Check_method_input_getch();
	static int Check_action_input_getline();

	static void Operation_module(int action, Money& Operand_1, Money& Operand_2);
	static void Operation_module(int action, Money& Operand_1, double Operand_2);

	//Overload operators - reference returned -----------------------------------------

	//Money* operator+(Money & another_Money);
	Money& operator+(const Money& another_Money) const;
	Money& operator-(const Money& another_Money) const;
	Money& operator*(const Money& another_Money) const;
	Money& operator*(double multiplier) const;
	Money& operator/(double divider) const;
	double operator/(const Money& another_Money) const;
	bool operator>(const Money& another_Money) const;
	bool operator<(const Money& another_Money) const;
	bool operator==(const Money& another_Money) const;

	friend std::ostream& operator << (std::ostream& out, Money* just_a_Money);
	friend std::ostream& operator << (std::ostream& out, Money& Money_holder);
};