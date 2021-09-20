#pragma once
#include <iostream>

template<typename T>
class Node
{
private:
	T value_;
	Node* forward_ = nullptr;
	Node* backward_ = nullptr;
public:
	Node();
	~Node();

	void set_value(T value);
	T get_value();

	void set_forward(Node* forward);
	Node* get_forward();

	void set_backward(Node* backward);
	Node* get_backward();

	void operator=(T value);
	void operator++();
	void operator--();

	friend std::ostream& operator << (std::ostream& out, const Node<T>& node);
	
	friend std::istream& operator >> (std::istream& in, Node<T>& node);
};

