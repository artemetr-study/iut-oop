#pragma once
#include "CalcSymbol.h"
#include "Stack.h"
#include "Queue.h"

class PostfixCalc
{
public:
	
	static double execute_operation(double first_argument, double second_argument, char operation)
	{
		return operation == CalcSymbol::plus ? first_argument + second_argument
			: operation == CalcSymbol::negative ? first_argument - second_argument
			: operation == CalcSymbol::multiple ? first_argument * second_argument
			: operation == CalcSymbol::division ? first_argument / second_argument
			: 0;
	}

	static double processing(string expression)
	{
		Queue<CalcSymbol*>* queue = get_postfix_queue(expression);
		return processing(queue);
	}

	static Queue<CalcSymbol*>* get_postfix_queue(string expression)
	{
		Queue<CalcSymbol*>* queue = new Queue<CalcSymbol*>();
		
		while (expression.length() > 0)
		{
			queue->push(get_next(expression));
		}

		return queue;
	}

	static CalcSymbol* get_next(string& expression)
	{
		if (CalcSymbol::is_operator(expression[0]))
		{
			char symbol = expression[0];
			expression.erase(0, 2);

			return new CalcSymbol(symbol);
		}

		int i = 0;
		for (i = 0; i < expression.length() && expression[i] != ' '; i++) {}
		CalcSymbol* result = new CalcSymbol(stod(expression.substr(0, i)));
		expression.erase(0, i + 1);

		return result;
	}
	
	static double processing(Queue<CalcSymbol*>* queue)
	{
		Stack<double>* arguments = new Stack<double>();

		while (true)
		{
			switch(queue->front()->get_type())
			{
			case CalcSymbol::type_argument:
				arguments->push(queue->pop()->get_argument());
				break;
			case CalcSymbol::type_operation:
				if (arguments->size() < 2)
				{
					throw "Invalid postfix query!";
				}
				arguments->push(execute_operation(arguments->pop(), arguments->pop(), queue->pop()->get_operation()));
				break;
			}
			if (queue->size() == 0)
			{
				break;
			}
		}

		return arguments->pop();
	}
};