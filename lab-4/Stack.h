#pragma once
#include "art-cpp.h"

using namespace art::addons;

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
