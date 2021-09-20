#include "ArrayTemplateFunctionsLibrary.h"
#include <string>
#include <iostream>

using namespace std;

void main() {
	//filling array
	int length = 10;
	int* array = new int[length];
	fillArrayRandomValues(array, length);
	showArray(array, length);

	//get count nullable elements after negative elements of array
	int* nullable_index_array = getArrayOfPredicatIndexElementsOfArray(array, length, [](int value) {return value == 0; });
	int nullable_index_array_length = getCountPredicatElementsOfArray(array, length, [](int value) {return value == 0; });
	int* negative_index_array = getArrayOfPredicatIndexElementsOfArray(array, length, [](int value) {return value < 0; });
	int negative_index_array_length = getCountPredicatElementsOfArray(array, length, [](int value) {return value < 0; });
	int count_nullable_after_negative = 0;
	for (int i = 0; i < nullable_index_array_length; i++) {
		if (iterationBinaryFindElementOfArrayByValue(negative_index_array, negative_index_array_length, nullable_index_array[i] - 1) != -1) {
			count_nullable_after_negative++;
		}
	}
	cout << count_nullable_after_negative << endl;

	//get multiplication of elements before last negative element of array
	int multiplication = 1;
	for (int i = 0; i < negative_index_array[negative_index_array_length - 1]; i++) {
		multiplication *= array[i];
	}
	cout << multiplication << endl;

	//sorting array
	showArray(array, length);
	optimizedBubbleSortArray(array, length);
	showArray(array, length);

	//etc.
	int number = 2;
	int* divisible_index_array = getArrayOfPredicatIndexElementsOfArray(array, length, [number](int value) {return value % number == 0; });
	int divisible_index_array_length = getCountPredicatElementsOfArray(array, length, [number](int value) {return value % number == 0; });

	for (int i = 0; i < divisible_index_array_length; i++) {
		removeElementOfArrayByIndex(array, length, divisible_index_array[i] - i);
	}
	showArray(array, length);
	system("pause");
}