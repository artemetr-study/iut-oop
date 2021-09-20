#pragma once
#include "art-cpp.h"

using namespace art::addons;

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
