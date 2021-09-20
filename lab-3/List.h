#pragma once
#include "Node.h"
#include  <iostream>
#include <string>

template<typename T>
class List
{
private:
	Node<T>* start_ = nullptr;
	Node<T>* end_ = nullptr;
	Node<T>* current_ = nullptr;
	int length_ = 0;

	Node<T>* get_node(int position);
	void to_node(int position);
public:
	List(T start);
	List(T array[], int length);
	~List();

	void put_to_start(T value);
	void put_to_end(T value);
	void put(T value, int position);

	void remove_start();
	void remove_end();
	void remove(int position);
	void remove();

	int length();
	bool is_empty();

	T* to_array();
	std::string to_string();

	T operator[](int position);

	friend std::ostream& operator<< (std::ostream& out, const List<T>& obj);
};

