#include "Fraction.h"

//::::::::::::::::::::::::::::::Fraction:: Fraction:: Fraction:: Fraction:: Fraction:: Fraction:: Fraction:: Fraction::::::::::::::::::::::::::::::
int Fraction::MaxCommonDivider(int a, int b)
{
	while (a > 0 && b > 0)
	{
		if (a > b)	a %= b;
		else		b %= a;
	}
	return a + b;
}
void Fraction::Fraction_reduction()
{
	//(Get_numerator() < 0) ? (-Get_numerator()) : (Get_numerator());
	//int max_common_divider = MaxCommonDivider(Get_numerator(), Get_denominator());
	//int max_common_divider = MaxCommonDivider((Get_numerator() < 0) ? (-Get_numerator()) : (Get_numerator()) , Get_denominator());
	//int max_common_divider = MaxCommonDivider(abs(Get_numerator()), Get_denominator());
	int max_common_divider = MaxCommonDivider(abs(Get_numerator()), abs(Get_denominator()));
	Set_numerator(Get_numerator() / max_common_divider);
	Set_denominator(Get_denominator() / max_common_divider);
}
void Fraction::Set_static_pointer_Available_fractions(std::vector<Fraction*>& Available_fractions)
{
	static_pointer_Available_fractions = &Available_fractions;
}
Fraction::Fraction(int A1, int A2, std::vector<Fraction*>& Available_fractions) : _numerator(A1), _denominator(A2)
{
	Available_fractions.push_back(this);
	Fraction_reduction();
}
Fraction::Fraction(int new_numerator, int new_denominator) : _numerator{ new_numerator }, _denominator{ new_denominator }
{
	Fraction_reduction();
	static_pointer_Available_fractions->push_back(this);
}
void Fraction::Set_denominator(int denominator)
{
	assert(denominator && "Division by zero is undefined");
	_denominator = denominator;
}
void Fraction::ShowValues() { std::cout << this->Get_numerator() << " / " << this->Get_denominator(); }
void Fraction::ShowMethods()
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
void Fraction::ShowAvailableFractions(std::vector<Fraction*> Available_fractions)
{
	std::cout << "\nAvailable fractions:";
	for (int i = 0; i < Available_fractions.size(); i++)
	{
		std::cout << "\nFraction [" << i + 1 << "] -> " << Available_fractions[i]->Get_numerator() << " / " << Available_fractions[i]->Get_denominator();
	}
	std::cout << "\n";
}
void Fraction::ShowAvailableFractions()
{
	std::cout << "\nAvailable fractions:";
	for (int i = 0; i < (*static_pointer_Available_fractions).size(); i++)
	{
		//	std::cout << "\nFraction [" << i + 1 << "] -> " << Available_fractions[i]->Get_numerator() << " / " << Available_fractions[i]->Get_denominator();
		//	std::cout << "\nFraction [" << i + 1 << "] -> " << (*static_pointer_Available_fractions)[i]->ShowValues();
		std::cout << "\nFraction [" << i + 1 << "] -> " << *(*static_pointer_Available_fractions)[i];
	}
	std::cout << "\n";
}
void Fraction::Memory_Clean(const std::vector<Fraction*>& Available_fractions)
{
	for (int i = 0; i < Available_fractions.size(); i++)
		delete Available_fractions[i];
}
Fraction* Fraction::operator+(const Fraction& another_Fraction) {
	std::cout << "\n" << "var2 Using member-function const& overload parameter, pointer return" << "\n";
	int new_numerator = (this->_numerator) * (another_Fraction._denominator) + (another_Fraction._numerator) * (this->_denominator);
	int new_denominator = (this->_denominator) * (another_Fraction._denominator);
	Fraction* result_fraction = new Fraction(new_numerator, new_denominator);
	return result_fraction;
}
Fraction* Fraction::operator+(Fraction& another_Fraction)
{
	std::cout << "\n" << "var3 Using member-function & overload parameter, pointer return" << "\n";
	int new_numerator = (this->_numerator) * (another_Fraction._denominator) + (another_Fraction._numerator) * (this->_denominator);
	int new_denominator = (this->_denominator) * (another_Fraction._denominator);
	Fraction* result_fraction = new Fraction(new_numerator, new_denominator);
	return result_fraction;
}
Fraction* Fraction::Add(Fraction& another_Fraction, std::vector<Fraction*>& Available_fractions)

{
	int new_numerator = _numerator * another_Fraction.Get_denominator() + another_Fraction.Get_numerator() * _denominator;
	int new_denominator = _denominator * another_Fraction.Get_denominator();
	//вариант с сокращением дроби в момент создания через вызов Fraction_reduction в конструкторе
	Fraction* result_fraction = new Fraction(new_numerator, new_denominator, Available_fractions); // вариант с внешним вектором для хранения объектов
	return result_fraction;
}
Fraction* Fraction::Subtract(Fraction& another_Fraction, std::vector<Fraction*>& Available_fractions)
{
	int new_numerator = _numerator * another_Fraction.Get_denominator() - another_Fraction.Get_numerator() * _denominator;
	int new_denominator = _denominator * another_Fraction.Get_denominator();
	//вариант с сокращением дроби в момент создания через вызов Fraction_reduction в конструкторе
	Fraction* result_fraction = new Fraction(new_numerator, new_denominator, Available_fractions); // вариант с внешним вектором для хранения объектов

	//Fraction* result_fraction = new Fraction(Available_fractions); // вариант с внешним вектором для хранения объектов
	//result_fraction->Set_numerator(_numerator * another_Fraction.Get_denominator() - another_Fraction.Get_numerator() * _denominator);
	//result_fraction->Set_denominator(_denominator * another_Fraction.Get_denominator());
	//Fraction_reduction();
	return result_fraction;
}
Fraction* Fraction::Multiply(Fraction& another_Fraction, std::vector<Fraction*>& Available_fractions)
{
	int new_numerator = _numerator * another_Fraction.Get_numerator();
	int new_denominator = _denominator * another_Fraction.Get_denominator();
	//вариант с сокращением дроби в момент создания через вызов Fraction_reduction в конструкторе
	Fraction* result_fraction = new Fraction(new_numerator, new_denominator, Available_fractions); // вариант с внешним вектором для хранения объектов

	//Fraction* result_fraction = new Fraction(Available_fractions); // вариант с внешним вектором для хранения объектов
	//result_fraction->Set_numerator(_numerator * another_Fraction.Get_numerator());
	//result_fraction->Set_denominator(_denominator * another_Fraction.Get_denominator());
	//Fraction_reduction();
	return result_fraction;
}
Fraction* Fraction::Divide(Fraction& another_Fraction, std::vector<Fraction*>& Available_fractions)
{
	int new_numerator = _numerator * another_Fraction.Get_denominator();
	int new_denominator = _denominator * another_Fraction.Get_numerator();
	//убираем знак из знаменателя
	if (new_denominator < 0) { new_denominator = -1 * new_denominator; new_numerator = -1 * new_numerator; }
	//вариант с сокращением дроби в момент создания через вызов Fraction_reduction в конструкторе
	Fraction* result_fraction = new Fraction(new_numerator, new_denominator, Available_fractions); // вариант с внешним вектором для хранения объектов
	//Fraction* result_fraction = new Fraction(Available_fractions); // вариант с внешним вектором для хранения объектов
	//result_fraction->Set_numerator(_numerator * another_Fraction.Get_denominator());
	//result_fraction->Set_denominator(_denominator * another_Fraction.Get_numerator());
	//Fraction_reduction();
	return result_fraction;
}
Fraction* Fraction::operator-(const Fraction& another_Fraction)
{
	std::cout << "\n" << "Using member-function const& overload parameter, pointer return" << "\n";
	int new_numerator = (this->_numerator) * (another_Fraction._denominator) - (another_Fraction._numerator) * (this->_denominator);
	int new_denominator = (this->_denominator) * (another_Fraction._denominator);
	Fraction* result_fraction = new Fraction(new_numerator, new_denominator);
	return result_fraction;
}
Fraction* Fraction::operator*(const Fraction& another_Fraction)
{
	std::cout << "\n" << "Using member-function const& overload parameter, pointer return" << "\n";
	int new_numerator = (this->_numerator) * (another_Fraction._numerator);
	int new_denominator = (this->_denominator) * (another_Fraction._denominator);
	Fraction* result_fraction = new Fraction(new_numerator, new_denominator);
	return result_fraction;
}
Fraction* Fraction::operator/(const Fraction& another_Fraction)
{
	std::cout << "\n" << "Using member-function const& overload parameter, pointer return" << "\n";
	int new_numerator = (this->_numerator) * (another_Fraction._denominator);
	int new_denominator = (this->_denominator) * (another_Fraction._numerator);
	Fraction* result_fraction = new Fraction(new_numerator, new_denominator);
	return result_fraction;
}
Fraction* Fraction::operator++() //prefix
{
	_numerator++;
	return this;
}
//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
//Q6 есть ли утечка памяти? Объект tmp_obj остаеся в памяти без указателя? 
// А если при размещении в стеке (вариант под комментами)?
// *Конструктор и деструктор по умолчанию
//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
Fraction* Fraction::operator++(int) //postfix
{
	//Fraction& tmp_obj(*this);
	Fraction* tmp_obj = new Fraction(*this);
	_numerator++;
	//return &tmp_obj;
	return tmp_obj;
}
//??? как правильно объявить friend
//Fraction* Fraction::operator+(const Fraction& Fraction_Operand_1, const Fraction& Fraction_Operand_2)
Fraction* operator+(const Fraction& Fraction_Operand_1, const Fraction& Fraction_Operand_2)
{
	std::cout << "\n" << "var1 Using friend-function const& overload parameter, return pointer" << "\n";
	int new_numerator = (Fraction_Operand_1._numerator) * (Fraction_Operand_2._denominator) + (Fraction_Operand_2._numerator) * (Fraction_Operand_1._denominator);
	int new_denominator = (Fraction_Operand_1._denominator) * (Fraction_Operand_2._denominator);
	Fraction* result_fraction = new Fraction(new_numerator, new_denominator);
	return result_fraction;
}
std::ostream& operator<<(std::ostream& out, Fraction& just_a_fraction)
{
	//just_a_fraction.ShowValues();

	out << just_a_fraction._numerator << "/" << just_a_fraction._denominator;

	return out;
}
//const std::vector<Fraction*> * Fraction::static_pointer_Available_fractions;
//std::vector<Fraction*>* Fraction::static_pointer_Available_fractions;
std::vector<Fraction*>* Fraction::static_pointer_Available_fractions{ nullptr };
std::map <int, std::string> Fraction::codes_of_operation{ {1," + "}, {2," - "}, {3," * "}, {4, " / "}, {5, "++"}, {6,"++"}, {7, "--"}, {8,"--"},{9,"+"}, {0, "-"} };

