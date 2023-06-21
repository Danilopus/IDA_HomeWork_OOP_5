#include "Money.h"




static std::map <int, std::string> keycodes{ {27, "Esc"}, {13, "Enter"}, {48, "0"}, {57, "9"} };
static std::string console_clear = "\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b";
static std::string big_space = "                                                           ";
static std::map <int, int> codes_of_digits{ {49, 0}, {50, 1}, {51, 2},{52, 3},{53, 4},{54, 5},{55, 6},{56, 7},{57, 8} };


std::vector <Money> Money::_money_list;
// Операции с дробями 
//std::map <int, std::string> Fraction::codes_of_operation{ {1," + "}, {2," - "}, {3," * "}, {4, " / "}, {5, "++"}, {6,"++"}, {7, "--"}, {8,"--"},{9,"+"}, {0, "-"} };

std::map <int, std::string> Money::codes_of_operation{ {1," + "}, {2," - "}, {3," * "}, {4, " / "}, {5, " * "}, {6," / "}, {7, " > "}, {8," < "},{9," = "}, {0, "=="} };


void Money::Initialisation(int provided_at_startup_money_holders_quantity)
{
	for (int i{ 0 }; i < provided_at_startup_money_holders_quantity; i++)
	{
		Money* ptr = new Money(Get_Random(-100, 100), Get_Random(-100, 100));
		//_numbers_list.push_back(ptr);
	}
}
