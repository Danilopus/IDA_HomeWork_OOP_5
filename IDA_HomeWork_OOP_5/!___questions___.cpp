
//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
//Q1 Почему при передаче аргумента по константной ссылке перестают работать геттеры?
//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

// не работает:

/*
const Fraction& operator+(const Fraction& another_Fraction)
{
	int new_numerator = this->_numerator * another_Fraction.Get_denominator() + another_Fraction.Get_numerator() * this->_denominator;
	int new_denominator = this->_denominator * another_Fraction.Get_denominator();
	//вариант с сокращением дроби в момент создания через вызов Fraction_reduction в конструкторе
	Fraction* result_fraction = new Fraction(new_numerator, new_denominator);
	//return result_fraction;
	return *result_fraction;
}
*/

// рабтает:

/*
const Fraction& operator+(Fraction& another_Fraction)
{
	int new_numerator = this->_numerator * another_Fraction.Get_denominator() + another_Fraction.Get_numerator() * this->_denominator;
	int new_denominator = this->_denominator * another_Fraction.Get_denominator();
	//вариант с сокращением дроби в момент создания через вызов Fraction_reduction в конструкторе
	Fraction* result_fraction = new Fraction(new_numerator, new_denominator);
	//return result_fraction;
	return *result_fraction;
}
*/


//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
//Q2 Почему не могу заменить?
//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

// это

/*	
void Set_numerator(int numerator) { _numerator = numerator; }	
*/

// на это

/*	
void Set_numerator(int numerator) : _numerator{numerator} {}	
*/



//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
//Q3 Как перегрузить вот такое (принимаем указатели на операнды)?
//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

/*
Fraction* operator+(Fraction* Fraction_Operand_1, Fraction* Fraction_Operand_2)
{
	int new_numerator = (Fraction_Operand_1->_numerator) * (Fraction_Operand_2._denominator) + (Fraction_Operand_2._numerator) * (Fraction_Operand_1._denominator);
	int new_denominator = (Fraction_Operand_1._denominator) * (Fraction_Operand_2._denominator);
	Fraction* result_fraction = new Fraction(new_numerator, new_denominator);
	return result_fraction;
}
*/

//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
//Q4 ??? при объявлении Fraction* operator+(Fraction& another_Fraction) в .h все было нормально, при переносе в .cpp вдруг давай ругаться ???
//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

/*
Fraction* operator+(Fraction& another_Fraction)
{
	std::cout << "\n" << "var3 Using member-function & overload parameter, pointer return" << "\n";
	int new_numerator = (this->_numerator) * (another_Fraction._denominator) + (another_Fraction._numerator) * (this->_denominator);
	int new_denominator = (this->_denominator) * (another_Fraction._denominator);
	Fraction* result_fraction = new Fraction(new_numerator, new_denominator);
	return result_fraction;
}
//*/

//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
//Q5 пока вот это 
// std::vector <ComplexNumber_class_through_inheritance*> ComplexNumber_class_through_inheritance::_numbers_list;
// не было перенесено из .h в .cpp была ошибка LINK2005
//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
//Q6 есть ли утечка памяти? Объект tmp_obj остаеся в памяти без указателя? 
// А если при размещении в стеке (вариант под комментами)?
// *Конструктор и деструктор по умолчанию
//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
//Fraction* Fraction::operator++(int) //postfix
//{
//	//Fraction& tmp_obj(*this);
//	Fraction* tmp_obj = new Fraction(*this);
//	_numerator++;
//	//return &tmp_obj;
//	return tmp_obj;
//}

//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
//Q7 есть ли утечка памяти? В векторе создается копия *this? А сам *this остаеся в памяти без указателя? 
// Надо ли удалять (вариант под комментами)?
// *Конструктор копирования и деструктор по умолчанию
//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

//std::vector <Money> Money::_money_list;
//
//Money::Money(long long coins, long long roubles)
//{
//	Set_roubles(roubles).Set_coins(coins);
//	_money_list.push_back(*this);
//	// delete this;
//}
