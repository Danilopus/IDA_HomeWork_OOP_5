﻿#include "Money.h"

std::vector <Money&> Money::_money_list;

static std::map <int, std::string> keycodes{ {27, "Esc"}, {13, "Enter"} };
static std::string console_clear = "\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b";
static std::string big_space = "                                                           ";
static std::map <int, int> codes_of_digits{ {49, 0}, {50, 1}, {51, 2},{52, 3},{53, 4},{54, 5},{55, 6},{56, 7},{57, 8} };
static std::map <int, char> codes_of_operation{ {1,'+'}, {2,'-'}, {3,'*'}, {4,'/'} };

//:::::::::::::::::::::::::::::::::::::::::::::::::::ComplexNumber_class_through_inheritance::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

ComplexNumber_class_through_inheritance::ComplexNumber_class_through_inheritance(double real_part, double imagine_part)
{
	ComplexNumber::_real_part = real_part;
	_imagine_part = imagine_part;
	_numbers_list.push_back(this);
}

void ComplexNumber_class_through_inheritance::Initialisation(int provided_at_startup_complex_number_quantity)
{
	for (int i{ 0 }; i < provided_at_startup_complex_number_quantity; i++)
	{
		ComplexNumber_class_through_inheritance* ptr = new ComplexNumber_class_through_inheritance(Get_Random(-100.0, 100.0), Get_Random(-100.0, 100.0));
		//_numbers_list.push_back(ptr);
	}
}

void ComplexNumber_class_through_inheritance::MemoryClean()
{
	for (int i = 0; i < _numbers_list.size(); i++)
	{
		delete _numbers_list[i];
	}
	_numbers_list.clear();
}

void ComplexNumber_class_through_inheritance::User_Choice_Handle()
{
	int action = Check_action_input();
	if (action == -1) return;
	std::cout << "-------->  " << codes_of_operation[action] << "                                 ";

	ComplexNumber_class_through_inheritance& Operand_1 = *Get_Operand(1);
	if (&Operand_1 == nullptr) return;
	std::cout << "\n   " << codes_of_operation[action];
	ComplexNumber_class_through_inheritance& Operand_2 = *Get_Operand(2);
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


void ComplexNumber_class_through_inheritance::Show()
{
	char plus_for_positive = '+';
	if (_imagine_part < 0) plus_for_positive = '\0';
	std::cout << std::setprecision(4) << std::setw(5) << _real_part << plus_for_positive << std::setprecision(4) << _imagine_part << "i";
}

ComplexNumber_class_through_inheritance* ComplexNumber_class_through_inheritance::New_number_input()
{
	std::cout << big_space;
	std::cout << "\nEnter real part    -> ";
	double real_part = Get_Dbl_SA();
	std::cout << "Enter imagine part -> ";
	double imagine_part = Get_Dbl_SA();
	//ComplexNumber_class_through_inheritance& new_obj_ref = *new ComplexNumber_class_through_inheritance(real_part, imagine_part);
	//return new_obj_ref;
	return new ComplexNumber_class_through_inheritance(real_part, imagine_part);
}

ComplexNumber_class_through_inheritance* ComplexNumber_class_through_inheritance::Get_Operand(int operand_number)
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


void Money::Initialisation(int provided_at_startup_money_holders_quantity)
{
	for (int i{ 0 }; i < provided_at_startup_money_holders_quantity; i++)
	{
		Money* ptr = new Money(Get_Random(-100, 100), Get_Random(-100, 100));
		//_numbers_list.push_back(ptr);
	}
}
