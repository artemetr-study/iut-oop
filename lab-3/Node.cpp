#include "Node.h"

template<typename T>
Node<T>::Node()
{
	this->forward_ = nullptr;
	this->backward_ = nullptr;
}

template<typename T>
Node<T>::~Node()
{
	if (this->get_forward())
	{
		this->get_forward()->set_backward(this->get_backward());
	}

	if (this->get_backward())
	{
		this->get_backward()->set_forward(this->get_forward());
	}
}

template <typename T>
void Node<T>::set_value(T value)
{
	this->value_ = value;
}

template <typename T>
T Node<T>::get_value()
{
	return this->value_;
}

template <typename T>
void Node<T>::set_forward(Node* forward)
{
	this->forward_ = forward;
	if (forward->get_backward() != this)
	{
		forward->set_backward(this);
	}
}

template <typename T>
Node<T>* Node<T>::get_forward()
{
	return this->forward_;
}

template <typename T>
void Node<T>::set_backward(Node* backward)
{
	this->backward_ = backward;
	if (backward->get_forward() != this)
	{
		backward->set_forward(this);
	}
}

template <typename T>
Node<T>* Node<T>::get_backward()
{
	return this->backward_;
}

template <typename T>
void Node<T>::operator=(T value)
{
	this->set_value(value);
}

template <typename T>
void Node<T>::operator++()
{
	if (!(this->get_forward()))
	{
		throw "Nullable forward of node!";
	}
	this = this->get_forward();
}

template <typename T>
void Node<T>::operator--()
{
	if (!(this->get_backward()))
	{
		throw "Nullable backward of node!";
	}
	this = this->get_backward();
}

template <typename T>
std::ostream& operator << (std::ostream& out, const Node<T>& node)
{
	out << node.get_value();
	return out;
}

template <typename T>
std::istream& operator >> (std::istream& in, Node<T>& node)
{
	T value;
	in >> value;
	node.set_value(value);
	return in;
}


