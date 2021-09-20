#pragma once
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

template<typename T>
void showArray(T* array, int length)
{
	cout << "\n--------Array--------\n";
	for (int i = 0; i < length; i++) {
		cout << array[i] << "\n";
	}
	cout << "----------------------\n";
}

template<typename T>
void flipflop(T& a, T& b) {
	T tmp = a;
	a = b;
	b = tmp;
}

bool inLength(int length, int index)
{
	return (index >= 0 && index < length);
}

template<typename T>
bool sortingRule(T a, T b, string rule)
{
	return rule == "ASC" ? (a < b) : rule == "DESC" ? (b < a) : false;
}

template<typename T>
void fillArrayRandomValues(T* array, int& length)
{
	for (int i = 0; i < length; i++) {
		int rnd = 0;
		while (rnd == 0) {
			rnd = rand();
		}
		int polar = rand() % 2 == 0 ? -1 : 1;
		array[i] = (T)(1.0 * rand() / rnd * polar);
	}
}

string getArrayDataByFile(string path)
{
	string result = "";
	string line;
	ifstream in(path);
	if (in.is_open()) {
		while (getline(in, line)) {
			result += line;
		}
	}
	else {
		throw std::invalid_argument("Invalide path to file!");
	}
	in.close();
	return result;
}

template<typename T>
void fillArrayByFile(T*& array, int& length, string path)
{
	string array_data = getArrayDataByFile(path);

	length = 0;
	for (int i = 0; i < array_data.size(); i++) {
		if (array_data[i] == ';') {
			length++;
		}
	}

	delete[] array;
	array = new T[length];

	int current_index = 0;
	string current_value = "";
	for (int i = 0; i < array_data.size(); i++) {
		if (array_data[i] == ';') {
			array[current_index] = (T)(current_value);
			current_index++;
			current_value = "";
			continue;
		}
		current_value.push_back(array_data[i]);
	}
}

template<typename T>
void push(T*& array, int& length, int index, T value)
{
	if (!inLength(length, index)) {
		return;
	}

	T* tmp_array = new T[length + 1];

	for (int i = 0; i < index; i++) {
		tmp_array[i] = array[i];
	}

	tmp_array[index] = value;

	length++;

	for (int i = index + 1; i < length; i++) {
		tmp_array[i] = array[i - 1];
	}

	delete[] array;
	array = tmp_array;
}

template<typename T>
void pushBack(T*& array, int& length, T value)
{
	T* tmp_array = new T[length + 1];

	for (int i = 0; i < length; i++) {
		tmp_array[i] = array[i];
	}

	tmp_array[length] = value;

	length++;

	delete[] array;
	array = tmp_array;
}

template<typename T>
void bubbleSortArray(T* array, int length, string sorting_rule = "ASC" = "ASC")
{
	for (int i = 0; i < length; i++) {
		for (int j = length - 1; j > i; j--) {
			if (sortingRule(array[j - 1], array[j], sorting_rule)) {
				flipflop(array[j - 1], array[j]);
			}
		}
	}
}

template<typename T>
void shakerSortArray(T* array, int length, string sorting_rule = "ASC" = "ASC")
{
	int leftEnd = 1;
	int rightEnd = length - 1;
	while (leftEnd <= rightEnd) {
		for (int i = rightEnd; i >= leftEnd; i--) {
			if (sortingRule(array[i - 1], array[i], sorting_rule)) {
				flipflop(array[i - 1], array[i]);
			}
		}
		leftEnd++;

		for (int i = leftEnd; i <= rightEnd; i++) {
			if (sortingRule(array[i - 1], array[i], sorting_rule)) {
				flipflop(array[i - 1], array[i]);
			}
		}
		rightEnd--;
	}
}

template<typename T>
void insertionSortArray(T* array, int length, string sorting_rule = "ASC")
{
	for (int i = 1; i < length; i++) {
		int tmp_i = i;
		for (int j = i - 1; j >= 0; j--) {
			if (sortingRule(array[i - 1], array[i], sorting_rule)) {
				flipflop(array[tmp_i], array[j]);
				tmp_i--;
			}
		}
	}
}

template<typename T>
void optimizedBubbleSortArray(T* array, int length, string sorting_rule = "ASC")
{
	bool flipped;
	for (int i = 0; i < length; i++) {
		flipped = false;
		for (int j = length - 1; j > i; j--) {
			if (sortingRule(array[j - 1], array[j], sorting_rule)) {
				flipflop(array[j - 1], array[j]);
				flipped = true;
			}
		}
		if (!flipped) {
			return;
		}
	}
}

template<typename T>
int getMinimumElementIndexOfArray(T* array, int length)
{
	int needed_index = 0;
	for (int i = 1; i < length; i++) {
		if (array[needed_index] > array[i]) {
			needed_index = i;
		}
	}
	return needed_index;
}

template<typename T>
int getMaximumElementIndexOfArray(T* array, int length)
{
	int needed_index = 0;
	for (int i = 1; i < length; i++) {
		if (array[needed_index] < array[i]) {
			needed_index = i;
		}
	}
	return needed_index;
}

template<typename T>
int iterationLinearFindElementOfArrayByValue(T* array, int length, T value)
{
	for (int i = 0; i < length; i++) {
		if (array[i] == value) {
			return i;
		}
	}
	return -1;
}

template<typename T>
int iterationBinaryFindElementOfArrayByValue(T* array, int length, T value)
{
	int left_index = 0;
	int right_index = length - 1;
	int middle_index;

	while (true) {
		middle_index = (left_index + right_index) / 2;

		if (value < array[middle_index]) {
			right_index = middle_index - 1;
		}
		else if (value > array[middle_index]) {
			left_index = middle_index + 1;
		}
		else {
			return middle_index;
		}

		if (left_index > right_index) {
			return -1;
		}
	}
}

template<typename T>
int recursiveLinearFindElementOfArrayByValue(T* array, int length, T value)
{
	return length - 1 == -1 ? -1 : array[length - 1] == value ? length - 1 : recursiveLinearFindElementOfArrayByValue(array, length - 1, value);
}

template<typename T>
int recursiveBinaryFindElementOfArrayByValue(T* array, int length, T value, int left_index, int right_index)
{
	if (right_index == -1) {
		right_index = length - 1;
	}
	int middle_index = (left_index + right_index) / 2;
	if (value < array[middle_index]) {
		right_index = middle_index - 1;
	}
	else if (value > array[middle_index]) {
		left_index = middle_index + 1;
	}
	else {
		return middle_index;
	}
	if (left_index > right_index) {
		return -1;
	}
	return recursiveBinaryFindElementOfArrayByValue(array, length, value, left_index, right_index);
}

template<typename T, class F>
int getCountPredicatElementsOfArray(T* array, int length, F predicat)
{
	int count = 0;
	for (int i = 0; i < length; i++) {
		if (predicat(array[i])) {
			count++;
		}
	}
	return count;
}

template<typename T, class F>
T getSumOfPredicatElementsOfArray(T* array, int length, F predicat)
{
	T sum;
	for (int i = 0; i < length; i++) {
		if (predicat(array[i])) {
			if (!sum) {
				sum = array[i];
			}
			else {
				sum += array[i];
			}
		}
	}
	return sum;
}

template<typename T, class F>
T getmultiplicationOfPredicatElementsOfArray(T* array, int length, F predicat)
{
	T multiplication = array[0];
	for (int i = 1; i < length; i++) {
		if (predicat(array[i])) {
			multiplication *= array[i];
		}
	}
	return multiplication;
}

template<typename T, class F>
int* getArrayOfPredicatIndexElementsOfArray(T* array, int length, F predicat)
{
	int* needed_array = new int[getCountPredicatElementsOfArray(array, length, predicat)];

	int needed_i = 0;
	for (int i = 0; i < length; i++) {
		if (predicat(array[i])) {
			needed_array[needed_i] = i;
			needed_i++;
		}
	}
	return needed_array;
}

template<typename T>
void removeElementOfArrayByIndex(T* array, int& length, int index) {
	if (!inLength(length, index)) {
		return;
	}

	for (int i = index; i < length - 1; i++) {
		array[i] = array[i + 1];
	}

	array[length - 1] = (T) 0;
}