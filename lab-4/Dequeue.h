#pragma once
#include "art-cpp.h"

using namespace art::addons;

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
