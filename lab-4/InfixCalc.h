#pragma once
#include "string"
#include "PostfixCalc.h"
#include "CalcSymbol.h"
#include "Stack.h"
#include "Queue.h"

using namespace std;

class InfixCalc
{
public:
	static double processing(string expression)
	{
		return processing(get_infix_queue(expression));
	}
	
	static double processing(Queue<CalcSymbol*>* infix_queue)
	{
		Queue<CalcSymbol*>* postfix_queue = get_postfix_queue(infix_queue);
		return PostfixCalc::processing(postfix_queue);
	}

	static Queue<CalcSymbol*>* get_postfix_queue(Queue<CalcSymbol*>* infix_queue)
	{
		Queue<CalcSymbol*>* postfix_queue = new Queue<CalcSymbol*>();
		Stack<CalcSymbol*>* operations_stack = new Stack<CalcSymbol*>();
		
		while(infix_queue->size() > 0)
		{
			switch (infix_queue->front()->get_type())
			{
			case CalcSymbol::type_argument:
				postfix_queue->push(infix_queue->pop());
				break;
			case CalcSymbol::type_operation:
				if (operations_stack->size() == 0)
				{
					operations_stack->push(infix_queue->pop());
				}
				else
				{
					if (infix_queue->front()->get_operation() == CalcSymbol::open_round_bracket 
						|| operations_stack->back()->get_operation() == CalcSymbol::open_round_bracket)
					{
						operations_stack->push(infix_queue->pop());
					}
					else if (infix_queue->front()->get_operation() == CalcSymbol::close_round_bracket)
					{
						while (operations_stack->back()->get_operation() != CalcSymbol::open_round_bracket)
						{
							postfix_queue->push(operations_stack->pop());
						}
						operations_stack->pop();
						infix_queue->pop();
					} else
					{
						if (infix_queue->front()->get_impotance() <= operations_stack->back()->get_impotance())
						{
							postfix_queue->push(operations_stack->pop());
						}
						operations_stack->push(infix_queue->pop());
					}
				}
				break;
			}
		}

		while (operations_stack->size() > 0)
		{
			postfix_queue->push(operations_stack->pop());
		}

		return postfix_queue;
	}

	static Queue<CalcSymbol*>* get_infix_queue(string expression)
	{
		Queue<CalcSymbol*>* queue = new Queue<CalcSymbol*>();

		while(expression.length() > 0)
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
			expression.erase(0, 1);
			
			return new CalcSymbol(symbol);
		}
		
		int i = 0;
		for (i = 0; i < expression.length() && !CalcSymbol::is_operator(expression[i]); i++) {}
		CalcSymbol* result = new CalcSymbol(stod(expression.substr(0, i)));
		expression.erase(0, i);
		
		return result;
	}
};
