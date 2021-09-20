#include "iostream"
#include "string"
#include "Stack.h"
#include "Queue.h"
#include "Dequeue.h"
#include "PostfixCalc.h"
#include "InfixCalc.h"

using namespace std;

void test_stack_int()
{
	cout << "test_stack_int has been started" << endl;
	
	Stack<int>* stack = new Stack<int>();
	int values[3] = {1, 2, 3};

	stack->push(values[0]);
	stack->push(values[1]);
	stack->push(values[2]);
	
	if (stack->size() != 3)
	{
		throw "test_stack_int test has been failed: stack->size()";
	}
	if (stack->pop() != values[2])
	{
		throw "test_stack_int test has been failed: stack->pop()";
	}
	if (stack->back() != values[1])
	{
		throw "test_stack_int test has been failed: stack->back()";
	}

	stack->clear();
	if (stack->size() != 0)
	{
		throw "test_stack_int test has been failed: stack->clear()";
	}

	cout << "test_stack_int has been finished successful" << endl;
}

void test_stack_char()
{
	cout << "test_stack_char has been started" << endl;

	Stack<char>* stack = new Stack<char>();
	char values[3] = { '1', '2', '3' };

	stack->push(values[0]);
	stack->push(values[1]);
	stack->push(values[2]);

	if (stack->size() != 3)
	{
		throw "test_stack_char test has been failed: stack->size()";
	}
	if (stack->pop() != values[2])
	{
		throw "test_stack_char test has been failed: stack->pop()";
	}
	if (stack->back() != values[1])
	{
		throw "test_stack_char test has been failed: stack->back()";
	}

	stack->clear();
	if (stack->size() != 0)
	{
		throw "test_stack_char test has been failed: stack->clear()";
	}

	cout << "test_stack_char has been finished successful" << endl;
}

void test_stack_bool()
{
	cout << "test_stack_bool has been started" << endl;

	Stack<bool>* stack = new Stack<bool>();
	bool values[3] = { true, false, true };

	stack->push(values[0]);
	stack->push(values[1]);
	stack->push(values[2]);

	if (stack->size() != 3)
	{
		throw "test_stack_bool test has been failed: stack->size()";
	}
	if (stack->pop() != values[2])
	{
		throw "test_stack_bool test has been failed: stack->pop()";
	}
	if (stack->back() != values[1])
	{
		throw "test_stack_bool test has been failed: stack->back()";
	}

	stack->clear();
	if (stack->size() != 0)
	{
		throw "test_stack_bool test has been failed: stack->clear()";
	}

	cout << "test_stack_bool has been finished successful" << endl;
}

void test_stack()
{
	test_stack_int();
	test_stack_char();
	test_stack_bool();
}

void test_queue_int()
{
	cout << "test_queue_int has been started" << endl;

	Queue<int>* queue = new Queue<int>();
	int values[3] = { 1, 2, 3 };

	queue->push(values[0]);
	queue->push(values[1]);
	queue->push(values[2]);

	if (queue->size() != 3)
	{
		throw "test_queue_int test has been failed: queue->size()";
	}
	if (queue->pop() != values[0])
	{
		throw "test_queue_int test has been failed: queue->pop()";
	}
	if (queue->front() != values[1])
	{
		throw "test_queue_int test has been failed: queue->front()";
	}

	queue->clear();
	if (queue->size() != 0)
	{
		throw "test_queue_int test has been failed: queue->clear()";
	}

	cout << "test_queue_int has been finished successful" << endl;
}


void test_queue_char()
{
	cout << "test_queue_char has been started" << endl;

	Queue<char>* queue = new Queue<char>();
	char values[3] = { '1', '2', '3' };

	queue->push(values[0]);
	queue->push(values[1]);
	queue->push(values[2]);

	if (queue->size() != 3)
	{
		throw "test_queue_char test has been failed: queue->size()";
	}
	if (queue->pop() != values[0])
	{
		throw "test_queue_char test has been failed: queue->pop()";
	}
	if (queue->front() != values[1])
	{
		throw "test_queue_char test has been failed: queue->front()";
	}

	queue->clear();
	if (queue->size() != 0)
	{
		throw "test_queue_char test has been failed: queue->clear()";
	}

	cout << "test_queue_char has been finished successful" << endl;
}

void test_queue_bool()
{
	cout << "test_queue_bool has been started" << endl;

	Queue<bool>* queue = new Queue<bool>();
	bool values[3] = { true, false, true };

	queue->push(values[0]);
	queue->push(values[1]);
	queue->push(values[2]);

	if (queue->size() != 3)
	{
		throw "test_queue_bool test has been failed: queue->size()";
	}
	if (queue->pop() != values[0])
	{
		throw "test_queue_bool test has been failed: queue->pop()";
	}
	if (queue->front() != values[1])
	{
		throw "test_queue_bool test has been failed: queue->front()";
	}

	queue->clear();
	if (queue->size() != 0)
	{
		throw "test_queue_bool test has been failed: queue->clear()";
	}

	cout << "test_queue_bool has been finished successful" << endl;
}

void test_queue()
{
	test_queue_int();
	test_queue_char();
	test_queue_bool();
}

void test_dequeue_int()
{
	cout << "test_dequeue_int has been started" << endl;

	Dequeue<int>* dequeue = new Dequeue<int>();
	int values[3] = { 1, 2 , 3 };

	dequeue->push_back(values[0]);
	dequeue->push_back(values[1]);
	dequeue->push_back(values[2]);

	if (dequeue->size() != 3)
	{
		throw "test_dequeue_int test has been failed: dequeue->size()";
	}
	if (dequeue->pop_back() != values[2])
	{
		throw "test_dequeue_int test has been failed: dequeue->pop_back()";
	}
	if (dequeue->back() != values[1])
	{
		throw "test_dequeue_int test has been failed: dequeue->back()";
	}

	dequeue->clear();
	if (dequeue->size() != 0)
	{
		throw "test_dequeue_int test has been failed: dequeue->clear()";
	}

	dequeue->push_front(values[0]);
	dequeue->push_front(values[1]);
	dequeue->push_front(values[2]);

	if (dequeue->size() != 3)
	{
		throw "test_dequeue_int test has been failed: dequeue->size()";
	}
	if (dequeue->pop_front() != values[2])
	{
		throw "test_dequeue_int test has been failed: dequeue->pop_front()";
	}
	if (dequeue->front() != values[1])
	{
		throw "test_dequeue_int test has been failed: dequeue->front()";
	}

	dequeue->clear();
	if (dequeue->size() != 0)
	{
		throw "test_dequeue_char test has been failed: dequeue->clear()";
	}

	cout << "test_dequeue_char has been finished successful" << endl;
}

void test_dequeue_char()
{
	cout << "test_dequeue_char has been started" << endl;

	Dequeue<char>* dequeue = new Dequeue<char>();
	char values[3] = { '1', '2' , '3' };

	dequeue->push_back(values[0]);
	dequeue->push_back(values[1]);
	dequeue->push_back(values[2]);

	if (dequeue->size() != 3)
	{
		throw "test_dequeue_char test has been failed: dequeue->size()";
	}
	if (dequeue->pop_back() != values[2])
	{
		throw "test_dequeue_char test has been failed: dequeue->pop_back()";
	}
	if (dequeue->back() != values[1])
	{
		throw "test_dequeue_char test has been failed: dequeue->back()";
	}

	dequeue->clear();
	if (dequeue->size() != 0)
	{
		throw "test_dequeue_char test has been failed: dequeue->clear()";
	}

	dequeue->push_front(values[0]);
	dequeue->push_front(values[1]);
	dequeue->push_front(values[2]);

	if (dequeue->size() != 3)
	{
		throw "test_dequeue_char test has been failed: dequeue->size()";
	}
	if (dequeue->pop_front() != values[2])
	{
		throw "test_dequeue_char test has been failed: dequeue->pop_front()";
	}
	if (dequeue->front() != values[1])
	{
		throw "test_dequeue_char test has been failed: dequeue->front()";
	}

	dequeue->clear();
	if (dequeue->size() != 0)
	{
		throw "test_dequeue_char test has been failed: dequeue->clear()";
	}

	cout << "test_dequeue_char has been finished successful" << endl;
}

void test_dequeue_bool()
{
	cout << "test_dequeue_bool has been started" << endl;

	Dequeue<bool>* dequeue = new Dequeue<bool>();
	bool values[3] = { true, false, true };

	dequeue->push_back(values[0]);
	dequeue->push_back(values[1]);
	dequeue->push_back(values[2]);

	if (dequeue->size() != 3)
	{
		throw "test_dequeue_bool test has been failed: dequeue->size()";
	}
	if (dequeue->pop_back() != values[2])
	{
		throw "test_dequeue_bool test has been failed: dequeue->pop_back()";
	}
	if (dequeue->back() != values[1])
	{
		throw "test_dequeue_bool test has been failed: dequeue->back()";
	}

	dequeue->clear();
	if (dequeue->size() != 0)
	{
		throw "test_dequeue_bool test has been failed: dequeue->clear()";
	}

	dequeue->push_front(values[0]);
	dequeue->push_front(values[1]);
	dequeue->push_front(values[2]);

	if (dequeue->size() != 3)
	{
		throw "test_dequeue_bool test has been failed: dequeue->size()";
	}
	if (dequeue->pop_front() != values[2])
	{
		throw "test_dequeue_bool test has been failed: dequeue->pop_front()";
	}
	if (dequeue->front() != values[1])
	{
		throw "test_dequeue_bool test has been failed: dequeue->front()";
	}

	dequeue->clear();
	if (dequeue->size() != 0)
	{
		throw "test_dequeue_bool test has been failed: dequeue->clear()";
	}

	cout << "test_dequeue_bool has been finished successful" << endl;
}

void test_dequeue()
{
	test_dequeue_int();
	test_dequeue_char();
	test_dequeue_bool();
}

void task_1()
{
	string expression;
	string result = "Right expression";
	bool revers_flag = false;
	Stack<char>* stack = new Stack<char>();

	cout << "Task 1 - Input expression formatted like 'w$w':" << endl;
	getline(cin, expression);

	for(int i = 0; i < expression.length(); i++)
	{
		if (expression[i] == '$')
		{
			revers_flag = true;
		} else if (revers_flag)
		{
			if (stack->pop() != expression[i])
			{
				result = "Invalid expression";
				break;
			}
		} else
		{
			stack->push(expression[i]);
		}
	}

	if (stack->size() > 0)
	{
		result = "Invalid expression";
	}

	cout << result << endl;
}

void task_2()
{
	string expression;
	cout << "Task 2 - Input postfix expression (use spaces as delimiter):" << endl;
	getline(cin, expression);

	cout << "Result: " << PostfixCalc::processing(expression) << endl;
}

void task_3_and_4()
{
	double result;
	double zero = 0.0;
	string expression;
	
	cout << "Task 3(4) - Input infix expression (if is invalid expression, we say about this):" << endl;
	getline(cin, expression);

	try
	{
		result = InfixCalc::processing(expression);
		if (result == 1/zero)
		{
			throw "Unknown exception";
		}
		cout << "Result: " << result << endl;
	} catch (...)
	{
		cout << "Invalid expression" << endl;
	}
}

int main()
{
	test_stack();
	test_queue();
	test_dequeue();
	task_1();
	task_2();
	task_3_and_4();

	return 0;
}
