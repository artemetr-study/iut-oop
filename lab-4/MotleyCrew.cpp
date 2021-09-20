/*================================================================
 * Contents(Содержание):
 * | 28   - app-cpp-node module
 * | 157  - app-cpp-node-pointer module
 * | 267  - app-cpp-list module
 * | 936  - Stack module
 * | 969  - Queue module
 * | 1002 - Dequeue module
 * | 1050 - CalcSymbol module
 * | 1126 - PostfixCalc module
 * | 1207 - InfixCalc module
 * | 1308 - Main module
 *   | 1409 - Stack tests
 *   | 1516 - Queue tests
 *   | 1691 - Dequeue tests
 *   | 1698 - Task 1
 *   | 1736 - Task 2
 *   | 1745 - Task 3 and 4
 *   | 1769 - Main function
 *================================================================*/

#include <iostream>
#include <string>

using namespace std;


/*======================art-cpp-node module======================*/

template <typename Type>
class Node
{
private:
	Type value_ = NULL;
	Node<Type>* next_ = NULL;
	Node<Type>* prev_ = NULL;

	void copy(const Node<Type>* node);

public:
	Node() {};
	Node(const Type& value);
	Node(const Node<Type>* node);
	~Node();

	Type get_value() const;
	void set_value(const Type& value);

	Node<Type>* get_next() const;
	void set_next(Node<Type>* node);

	Node<Type>* get_prev() const;
	void set_prev(Node<Type>* node);

	template<typename AnyType>
	static bool is_null(const AnyType& node);

	template <typename AnyType>
	friend std::ostream& operator<<(std::ostream& out, const Node<AnyType>*& node);

	template <typename AnyType>
	friend std::istream& operator>> (std::istream& in, Node<AnyType>*& node);
};

template <typename AnyType>
std::ostream& operator<<(std::ostream& out, const Node<AnyType>*& node)
{
	out << node->get_value();
	return out;
}

template <typename AnyType>
std::istream& operator>>(std::istream& in, Node<AnyType>*& node)
{
	AnyType value;
	in >> value;
	node->set_value(value);

	return in;
}

template <typename Type>
void Node<Type>::copy(const Node<Type>* node)
{
	set_value(node->get_value());
}

template <typename Type>
Node<Type>::Node(const Type& value)
{
	set_value(value);
}

template <typename Type>
Node<Type>::Node(const Node<Type>* node)
{
	copy(node);
}

template <typename Type>
Node<Type>::~Node()
{
	if (!is_null(get_next()))
	{
		get_next()->set_prev(get_prev());
	}
	if (!is_null(get_prev()))
	{
		get_prev()->set_next(get_next());
	}
}

template <typename Type>
Type Node<Type>::get_value() const
{
	return value_;
}

template <typename Type>
void Node<Type>::set_value(const Type& value)
{
	value_ = value;
}

template <typename Type>
Node<Type>* Node<Type>::get_next() const
{
	return next_;
}

template <typename Type>
void Node<Type>::set_next(Node<Type>* node)
{
	next_ = node;
}

template <typename Type>
Node<Type>* Node<Type>::get_prev() const
{
	return prev_;
}

template <typename Type>
void Node<Type>::set_prev(Node<Type>* node)
{
	prev_ = node;
}

template <typename Type>
template <typename AnyType>
bool Node<Type>::is_null(const AnyType& node)
{
	return node == NULL;
}


/*======================art-cpp-node-pointer module======================*/

template <typename Type>
class NodePointer
{
private:
	Node<Type>* node_ = NULL;

	void copy(const NodePointer<Type>*& node_pointer);
	static void throw_exception();

public:
	NodePointer() {};
	NodePointer(const Node<Type>*& node);
	NodePointer(const NodePointer<Type>*& node_pointer);
	~NodePointer() {};

	Node<Type>* get_node() const;
	void set_node(Node<Type>* node);

	bool is_null() const;

	NodePointer<Type>& operator++();
	NodePointer<Type> operator++(int);

	NodePointer<Type>& operator--();
	NodePointer<Type> operator--(int);
};

template <typename Type>
void NodePointer<Type>::copy(const NodePointer<Type>*& node_pointer)
{
	set_node(node_pointer->get_node());
}

template <typename Type>
void NodePointer<Type>::throw_exception()
{
	throw "Error: out of range";
}

template <typename Type>
NodePointer<Type>::NodePointer(const Node<Type>*& node)
{
	set_node(node);
}

template <typename Type>
NodePointer<Type>::NodePointer(const NodePointer<Type>*& node_pointer)
{
	copy(node_pointer);
}

template <typename Type>
Node<Type>* NodePointer<Type>::get_node() const
{
	return node_;
}

template <typename Type>
void NodePointer<Type>::set_node(Node<Type>* node)
{
	node_ = node;
}

template <typename Type>
bool NodePointer<Type>::is_null() const
{
	return Node<Type>::is_null(get_node());
}

template <typename Type>
NodePointer<Type>& NodePointer<Type>::operator++()
{
	if (this->is_null() || Node<Type>::is_null(get_node()->get_next()))
	{
		throw_exception();
	}

	set_node(get_node()->get_next());
	return *this;
}

template <typename Type>
NodePointer<Type> NodePointer<Type>::operator++(int)
{
	++(*this);
	return *this;
}

template <typename Type>
NodePointer<Type>& NodePointer<Type>::operator--()
{
	if (this->is_null() || Node<Type>::is_null(get_node()->get_prev()))
	{
		throw_exception();
	}

	set_node(get_node()->get_prev());
	return *this;
}

template <typename Type>
NodePointer<Type> NodePointer<Type>::operator--(int)
{
	--(*this);
	return *this;
}


/*======================art-cpp-list module======================*/

template <typename Type>
class List
{
private:
	Node<Type>* start_ = NULL;
	Node<Type>* end_ = NULL;
	NodePointer<Type>* pointer_ = new NodePointer<Type>();

	std::size_t length_ = 0;

	void initializate(const Type value);
	void go_to_node(const int index);

	template <class Function>
	void if_empty_execute(Function function);

	template <class Function>
	void if_not_empty_execute(Function function);

	template <class Function>
	void if_index_not_in_list(Function function, const int index);

	void del_start();
	void del_end();

	static void throw_index_out_of_range();
	static void throw_already_initialized();

	void set_pointer(Node<Type>* node) const;
	Node<Type>* get_pointer() const;
	void next() const;
	void prev() const;
	void to_start() const;
	void to_end() const;

public:
	List();
	List(const Type value);
	List(const Type array[], const int length);
	List(List<Type>*& list);
	~List();

	/*Adds its argument as a single element to the end of a list.
	 *The length of the list increases by one.*/
	void append(const Type value);
	void append(const Type array[], const int length);
	void append(const List<Type>*& node);

	/*Inserts the element at the given index, shifting elements to the right*/
	void insert(const Type value, const int index);
	void insert(const Type array[], const int length, const int index);
	void insert(const List<Type>*& node, const int index);

	/*Iterates over its argument and adding each element to the list and extending the list.
	 *The length of the list increases by number of elements in it’s argument.*/
	void extend(const Type value);
	void extend(const Type array[], const int length);
	void extend(const List<Type>*& node);

	/*Remove items by index.*/
	void del(const int index);
	/*Remove an item by value.*/
	void remove(const Type value);
	/*Remove an item by index and get its value.*/
	Type pop(const int index);
	/*Remove all items.*/
	void clear();

	/*Return the length of the list.*/
	int length() const;

	/*Return the length of the list.*/
	bool is_empty() const;

	Type* to_array();

	std::string to_string() const;

	Type get_value(const int index);

	Type operator[](const int index);

	template <class Function>
	List<Type>* map(Function function);

	template <class Function>
	List<Type>* filter(Function function);

	template <typename AnyType>
	friend std::ostream& operator<< (std::ostream& out, const List<AnyType>& list);

	template<typename AnyType>
	friend std::istream& operator>> (std::istream& in, List<AnyType>& list);
};

template <typename AnyType>
std::ostream& operator<<(std::ostream& out, const List<AnyType>& list)
{
	out << list.to_string();

	return out;
}

template <typename AnyType>
std::istream& operator>>(std::istream& in, List<AnyType>& list)
{
	AnyType value = AnyType();
	list.to_start();
	for (int i = 0; i < list.length(); i++)
	{
		in >> value;
		list.get_pointer()->set_value(value);

		if (i < list.length() - 1)
		{
			list.next();
		}
	}

	return in;
}

template <typename Type>
void List<Type>::initializate(const Type value)
{
	this->if_not_empty_execute(List::throw_already_initialized);

	Node<Type>* node = new Node<Type>(value);

	this->start_ = node;
	this->end_ = node;
	set_pointer(node);

	++this->length_;
}

template <typename Type>
void List<Type>::go_to_node(const int index)
{
	this->if_index_not_in_list(List::throw_index_out_of_range, index);

	if (this->length() / 2 > index)
	{
		pointer_->set_node(start_);
		for (int i = 0; i < index; i++)
		{
			next();
		}
	}
	else
	{
		pointer_->set_node(end_);
		for (int i = this->length() - 1; i > index; --i)
		{
			prev();
		}
	}
}

template <typename Type>
template <class Function>
void List<Type>::if_empty_execute(Function function)
{
	if (this->is_empty())
	{
		function();
	}
}

template <typename Type>
template <class Function>
void List<Type>::if_not_empty_execute(Function function)
{
	if (!this->is_empty())
	{
		function();
	}
}

template <typename Type>
template <class Function>
void List<Type>::if_index_not_in_list(Function function, const int index)
{
	if (index < 0 || index >= this->length())
	{
		function();
	}
}

template <typename Type>
void List<Type>::del_start()
{
	this->if_empty_execute(List::throw_index_out_of_range);

	if (this->length() == 1)
	{
		this->clear();
		return;
	}

	this->start_ = this->start_->get_next();
	delete this->start_->get_prev();
	this->start_->set_prev(NULL); //mb needed
	this->to_start();

	--this->length_;
}

template <typename Type>
void List<Type>::del_end()
{
	this->if_empty_execute(List::throw_index_out_of_range);

	if (this->length() == 1)
	{
		this->clear();
		return;
	}

	this->end_ = this->end_->get_prev();
	delete this->end_->get_next();
	this->end_->set_next(NULL); //mb needed
	this->to_start();

	--this->length_;
}

template <typename Type>
void List<Type>::throw_index_out_of_range()
{
	throw "IndexError: index out of range";
}

template <typename Type>
void List<Type>::throw_already_initialized()
{
	throw "InitialError: list has already initialized";
}

template <typename Type>
void List<Type>::set_pointer(Node<Type> * node) const
{
	pointer_->set_node(node);
}

template <typename Type>
Node<Type>* List<Type>::get_pointer() const
{
	return pointer_->get_node();
}

template <typename Type>
void List<Type>::next() const
{
	++(*pointer_);
}

template <typename Type>
void List<Type>::prev() const
{
	--(*pointer_);
}

template <typename Type>
void List<Type>::to_start() const
{
	pointer_->set_node(start_);
}

template <typename Type>
void List<Type>::to_end() const
{
	pointer_->set_node(end_);
}

template <typename Type>
List<Type>::List()
{
}

template <typename Type>
List<Type>::List(const Type value)
{
	this->initializate(value);
}

template <typename Type>
List<Type>::List(const Type array[], const int length)
{
	this->append(array, length);
}

template <typename Type>
List<Type>::List(List<Type> * &list)
{
	append(list);
}

template <typename Type>
List<Type>::~List()
{
	this->clear();
}

template <typename Type>
void List<Type>::append(const Type value)
{
	switch (this->length())
	{
	case 0:
		this->initializate(value);
		break;
	default:
		Node<Type>* node = new Node<Type>(value);

		node->set_prev(this->end_);
		this->end_->set_next(node);

		this->end_ = node;
		set_pointer(node);

		++this->length_;
		break;
	}
}

template <typename Type>
void List<Type>::append(const Type array[], const int length)
{
	for (int i = 0; i < length; i++)
	{
		this->append(array[i]);
	}
}

template <typename Type>
void List<Type>::append(const List<Type> * &node)
{
	for (int i = 0; i < node.length(); i++)
	{
		this->append(node[i]);
	}
}

template <typename Type>
void List<Type>::insert(const Type value, const int index)
{
	this->if_index_not_in_list(List::throw_index_out_of_range, index);
	const int first_case = this->length() - 1;

	if (index == 0)
	{
		this->extend(value);
	}
	else if (index == length() - 1)
	{
		this->append(value);
	}
	else
	{
		this->go_to_node(index);

		Node<Type>* node = new Node<Type>(value);

		node->set_next(get_pointer());
		node->set_prev(get_pointer()->get_prev());
		get_pointer()->set_prev(node);

		++this->length_;
	}
}

template <typename Type>
void List<Type>::insert(const Type array[], const int length, const int index)
{
	for (int i = length - 1; i >= 0; i--)
	{
		this->insert(array[i], index);
	}
}

template <typename Type>
void List<Type>::insert(const List<Type> * &node, const int index)
{
	for (int i = length - 1; i >= 0; i--)
	{
		this->insert(node[i], index);
	}
}

template <typename Type>
void List<Type>::extend(const Type value)
{
	switch (this->length())
	{
	case 0:
		this->initializate(value);
		break;
	default:
		Node<Type>* node = new Node<Type>(value);

		node->set_next(this->start_);
		this->start_->set_prev(node);

		this->start_ = node;
		set_pointer(node);

		++this->length_;
		break;
	}
}

template <typename Type>
void List<Type>::extend(const Type array[], const int length)
{
	for (int i = length - 1; i >= 0; i--)
	{
		this->extend(array[i]);
	}
}

template <typename Type>
void List<Type>::extend(const List<Type> * &node)
{
	for (int i = length - 1; i >= 0; i--)
	{
		this->extend(node[i]);
	}
}

template <typename Type>
void List<Type>::del(const int index)
{
	this->if_index_not_in_list(List::throw_index_out_of_range, index);

	if (index == 0)
	{
		this->del_start();
	}
	else if (index == this->length() - 1)
	{
		this->del_end();
	}
	else
	{
		this->go_to_node(index);
		delete get_pointer();
		pointer_->set_node(start_);
		--this->length_;
	}
}

template <typename Type>
void List<Type>::remove(const Type value)
{
	if (this->is_empty())
	{
		return;
	}

	pointer_->set_node(start_);
	for (int i = 0; i < this->length(); i++)
	{
		if (get_pointer()->get_value() == value)
		{
			this->del(i);
			break;
		}

		if (i != this->length() - 1)
		{
			next();
		}
	}
}

template <typename Type>
Type List<Type>::pop(const int index)
{
	Type value = this->get_value(index);
	this->del(index);

	return value;
}

template <typename Type>
void List<Type>::clear()
{
	while (this->length() > 1)
	{
		this->del_start();
	}

	/*This place is memory stiller location.*/
	delete get_pointer();

	this->start_ = NULL;
	this->end_ = NULL;
	set_pointer(NULL);

	this->length_ = 0;
}

template <typename Type>
int List<Type>::length() const
{
	return this->length_;
}

template <typename Type>
bool List<Type>::is_empty() const
{
	return !(this->length() > 0);
}

template <typename Type>
Type* List<Type>::to_array()
{
	if (this->is_empty())
	{
		return new Type[0];
	}

	Type* array = new Type[this->length()];

	pointer_->set_node(start_);
	for (int i = 0; i < this->length(); i++)
	{
		array[i] = get_pointer()->get_value();

		if (i != this->length() - 1)
		{
			next();
		}
	}

	return array;
}

template <typename Type>
std::string List<Type>::to_string() const
{
	std::string result;
	result.append("[");

	to_start();
	for (int i = 0; i < this->length(); i++)
	{

		result.append(get_pointer()->get_value()->to_string());

		if (i < this->length() - 1)
		{
			next();
			result.append(", ");
		}
	}
	result.append("]");

	return result;
}

template <typename Type>
Type List<Type>::get_value(const int index)
{
	this->go_to_node(index);

	return get_pointer()->get_value();
}

template <typename Type>
Type List<Type>::operator[](const int index)
{
	return get_value(index);
}

template <typename Type>
template <class Function>
List<Type>* List<Type>::map(Function function)
{
	if (this->is_empty())
	{
		return new List<Type>();
	}

	List<Type>* list = new List<Type>();

	pointer_->set_node(start_);
	for (int i = 0; i < this->length(); i++)
	{
		list->append(function(get_pointer()->get_value()));

		if (i != this->length() - 1)
		{
			next();
		}
	}

	return list;
}

template <typename Type>
template <class Function>
List<Type>* List<Type>::filter(Function function)
{

	if (this->is_empty())
	{
		return new List<Type>();
	}

	List<Type>* list = new List<Type>();

	pointer_->set_node(start_);
	for (int i = 0; i < this->length(); i++)
	{
		if (function(get_pointer()->get_value()))
		{
			list->append(get_pointer()->get_value());
		}

		if (i != this->length() - 1)
		{
			next();
		}
	}

	return list;
}

template <typename Type>
List<Type>* to_list(const Type array[], const int length)
{
	return new List<Type>(array, length);
}

template <typename Type>
Type* to_array(List<Type> & list)
{
	return list.to_array();
}

template <typename Type, class Function>
List<Type> map(Function function, List<Type> & list)
{
	return list.map(function);
}

template <typename Type, class Function>
List<Type>* map(Function function, List<Type> * &list)
{
	return list->map(function);
}

template <typename Type, class Function>
List<Type> filter(Function function, List<Type> & list)
{
	return list.filter(function);
}

template <typename Type, class Function>
List<Type>* filter(Function function, List<Type> * &list)
{
	return list->filter(function);
}


/*======================Stack module======================*/

template <typename Type>
class Stack : private List<Type>
{
public:
	void push(const Type value)
	{
		this->append(value);
	}

	Type pop()
	{
		return List<Type>::pop(this->size() - 1);
	}

	Type back()
	{
		return List<Type>::get_value(this->size() - 1);
	}

	int size() const
	{
		return this->length();
	}

	void clear()
	{
		List<Type>::clear();
	}
};


/*======================Queue module======================*/

template <typename Type>
class Queue : protected List<Type>
{
public:
	void push(const Type value)
	{
		this->append(value);
	}

	Type pop()
	{
		return List<Type>::pop(0);
	}

	Type front()
	{
		return List<Type>::get_value(0);
	}

	int size() const
	{
		return this->length();
	}

	void clear()
	{
		List<Type>::clear();
	}
};


/*======================Dequeue module======================*/

template <typename Type>
class Dequeue : protected List<Type>
{
public:
	void push_front(const Type value)
	{
		this->extend(value);
	}

	void push_back(const Type value)
	{
		this->append(value);
	}

	Type pop_front()
	{
		return List<Type>::pop(0);
	}

	Type pop_back()
	{
		return List<Type>::pop(this->size() - 1);
	}

	Type front()
	{
		return List<Type>::get_value(0);
	}

	Type back()
	{
		return List<Type>::get_value(this->size() - 1);
	}

	int size() const
	{
		return this->length();
	}

	void clear()
	{
		List<Type>::clear();
	}
};


/*======================CalcSymbol module======================*/

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


/*======================PostfixCalc module======================*/

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

	static double processing(Queue<CalcSymbol*> * queue)
	{
		Stack<double>* arguments = new Stack<double>();

		while (true)
		{
			switch (queue->front()->get_type())
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


/*======================InfixCalc module======================*/

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

		while (infix_queue->size() > 0)
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
					}
					else
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

/*======================Main module======================*/

void test_stack_int()
{
	cout << "test_stack_int has been started" << endl;

	Stack<int>* stack = new Stack<int>();
	int values[3] = { 1, 2, 3 };

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

	for (int i = 0; i < expression.length(); i++)
	{
		if (expression[i] == '$')
		{
			revers_flag = true;
		}
		else if (revers_flag)
		{
			if (stack->pop() != expression[i])
			{
				result = "Invalid expression";
				break;
			}
		}
		else
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
		if (result == 1 / zero)
		{
			throw "Unknown exception";
		}
		cout << "Result: " << result << endl;
	}
	catch (...)
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
