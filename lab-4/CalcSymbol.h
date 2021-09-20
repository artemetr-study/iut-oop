#pragma once
#include "string"

using namespace std;

class CalcSymbol
{
private:
	int type_ = NULL;
	char operation_ = NULL;
	double argument_ = NULL;
public:
	static const int type_operation = 0;
	static const int type_argument = 1;
	static const char open_round_bracket = '(';
	static const int open_round_importance = -1;
	static const char close_round_bracket = ')';
	static const int close_round_importance = -1;
	static const char plus = '+';
	static const int plus_importance = 0;
	static const char negative = '-';
	static const int negative_importance = 0;
	static const char multiple = '*';
	static const int multiple_importance = 1;
	static const char division = '/';
	static const int division_importance = 1;

	static bool is_operator(char symbol)
	{
		return symbol == open_round_bracket
			|| symbol == close_round_bracket
			|| symbol == plus
			|| symbol == negative
			|| symbol == multiple
			|| symbol == division;
	}

	CalcSymbol() {}
	
	CalcSymbol(char operation)
	{
		type_ = type_operation;
		operation_ = operation;
	}

	CalcSymbol(double argument)
	{
		type_ = type_argument;
		argument_ = argument;
	}

	char get_operation()
	{
		return operation_;
	}

	double get_argument()
	{
		return argument_;
	}

	int get_type()
	{
		return type_;
	}

	int get_impotance()
	{
		return operation_ == open_round_bracket ? open_round_importance
		: operation_ == close_round_bracket ? close_round_importance
		: operation_ == plus ? plus_importance
		: operation_ == negative ? negative_importance
		: operation_ == multiple ? multiple_importance
		: operation_ == division ? division_importance
		: -2;
	}
};