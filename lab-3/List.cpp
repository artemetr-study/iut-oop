#include "List.h"


template <typename T>
Node<T>* List<T>::get_node(int position)
{
	this->current_ = this->start_;

	for(int i = 0; i < position; i++)
	{
		++this->current_;
	}

	return this->current_;
}

template <typename T>
void List<T>::to_node(int position)
{
	this->get_node(position);
}

template <typename T>
List<T>::List(T start)
{
	this->put_to_start(start);
	this->end_ = this->start_;
}

template <typename T>
List<T>::List(T array[], int length)
{
	if (!this->is_empty())
	{
		return;
	}

	for(int i = 0; i < length; i++)
	{
		this->put_to_end(array[i]);
	}
}

template<typename T>
List<T>::~List()
{
	if (this->is_empty())
	{
		return;
	}
	this->remove();
}

template <typename T>
void List<T>::put_to_start(T value)
{
	++this->length_;

	Node<T> n_node;
	n_node.set_value(value);
	
	if(!this->is_empty())
	{
		Node<T>* tmp = this->start_;
		n_node.set_forward(tmp);
		tmp->set_backward(n_node);
	}
	
	this->start_ = n_node;

	this->current_ = this->start_;
}

template <typename T>
void List<T>::put_to_end(T value)
{
	if (this->is_empty())
	{
		this->put_to_start(value);
		this->end_ = this->start_;
		return;
	}
	
	++this->length_;

	Node<T> n_node;
	n_node.set_value(value);

	Node<T>* tmp = this->end_;
	n_node.set_backward(tmp);
	tmp->set_forward(n_node);

	this->current_ = this->end_;
}

template <typename T>
void List<T>::put(T value, int position)
{
	if (position >= this->length())
	{
		throw "Invalided position number!";
	}

	++this->length_;

	Node<T> n_node;
	n_node.set_value(value);

	for(int i = 0; i < position; i++)
	{
		++this->current_;
	}
	
	n_node.set_backward(this->current_->get_backward());
	this->current_->get_backward()->set_forward(n_node);

	n_node.set_forward(this->current_);
	this->current_->set_backward(n_node);
	
	--this->current_;
}

template <typename T>
void List<T>::remove_start()
{
	if (this->is_empty())
	{
		return;
	}

	if (this->length() == 1)
	{
		delete this->start_;
		this->start_ = nullptr;
		this->current_ = nullptr;
		this->end_ = nullptr;
	} else
	{
		++this->start_;

		delete this->start_->get_backward();
		this->current_ = this->start_;
	}

	--this->length_;
}

template <typename T>
void List<T>::remove_end()
{
	if (this->is_empty())
	{
		return;
	}

	if (this->length() == 1)
	{
		delete this->end_;
		this->start_ = nullptr;
		this->current_ = nullptr;
		this->end_ = nullptr;
	}
	else
	{
		++this->end_;

		delete this->end_->get_forward();
		this->end_->set_forward(nullptr);
		this->current_ = this->end_;
	}

	--this->length_;
}

template <typename T>
void List<T>::remove(int position)
{
	if (this->is_empty() || position >= this->length())
	{
		return;
	}

	if (this->length() == 1 || position == 0)
	{
		this->remove_start();
	}
	else if (position == this->length() - 1)
	{
		this->remove_end();
	}
	else
	{
		this->to_node(position);
		++this->current_;
		delete this->current_->get_backward();
		--this->length_;
	}
}

template <typename T>
void List<T>::remove()
{
	while(!this->is_empty())
	{
		this->remove_end();
	}
}

template <typename T>
int List<T>::length()
{
	return this->length_;
}

template <typename T>
bool List<T>::is_empty()
{
	return !(this->length() > 0);
}

template <typename T>
T* List<T>::to_array()
{
	T* result = new T[this->length()];
	this->current_ = this->start_;
	for(int i = 0; i < this->length(); i++)
	{
		result[i] = this->current_->get_value();
		if (i + 1 != this->length())
		{
			++this->current_;
		}
	}
	return result;
}

template <typename T>
std::string List<T>::to_string()
{
	std::string result = "[";
	this->current_ = this->start_;
	for (int i = 0; i < this->length(); i++)
	{
		result.append(this->current_->get_value());
		if (i + 1 != this->length())
		{
			result.append(",");
			++this->current_;
		}
	}
	result.append("]");
	return result;
}

template <typename T>
T List<T>::operator[](int position)
{
	if (this->is_empty() || position >= this->length())
	{
		throw "Invalided position number!";
	}
	
	this->current_ = this->start_;

	for(int i = 0; i < position; i++)
	{
		++this->current_;
	}

	return this->current_->get_value();
}

template<typename T>
std::ostream& operator<<(std::ostream& out, const List<T>& obj)
{
	out << obj.to_string();
	return out;
}
