#include <iostream>
#include <cstdio>
#include <ctime>
using namespace std;
#define SIZE 11
#define MIN 0
#define MAX 100

template<typename T>
void fillArray(T *ar, int size = SIZE) {
	srand(time(NULL));
	for (int i = 0; i < size; i++) {
		double m { (double) rand() / RAND_MAX };
		*(ar + i) = (MAX - MIN) * m;
	}
}

template<typename T>
void printArray(T *ar, int size = SIZE) {
	for (int i = 0; i < size; i++) {
		cout << *(ar + i) << " ";
	}
	cout << endl;
}

/* Задание 1.
 * Используя два указателя на массив целых
 чисел, скопировать один массив в другой. Использовать
 в программе арифметику указателей для продвижения
 по массиву, а также оператор разыменования.
 */

template<typename T, typename S>
void copyArray(T *src, S *dst, int size = SIZE) {
	for (int i = 0; i < size; i++) {
		*(dst + i) = *(src + i);
	}
}

/* Задание 2.
 * Используя указатель на массив целых чисел,
 изменить порядок следования элементов массива на
 противоположный.
 Использовать в программе арифметику указателей
 для продвижения по массиву, а также оператор разыме-
 нования.
 */
template<typename T>
void invertArray(T *ar, int size = SIZE) {
	T t { };
	T *left { ar }, *right { ar + size - 1 };
	for (int i = 0; i < size / 2; i++, left++, right--) {
		t = *left;
		*left = *right;
		*right = t;
	}
}

/*Задание 3.
 * Используя два указателя на массивы целых
 чисел, скопировать один массив в другой так, чтобы во
 втором массиве элементы находились в обратном порядке.
 Использовать в программе арифметику указателей
 для продвижения по массиву, а также оператор разыме-
 нования.
 */
template<typename T, typename S>
void copyInverted(T *src, S *dst, int size = SIZE) {
	T *left { src };
	S *right { dst + size - 1 };
	for (int i = 0; i < size; i++, left++, right--) {
		*right = *left;
	}
}

int main() {
	int *ar1 = new int[SIZE];
	double *ar2 = new double[SIZE];
	long *ar3 = new long[SIZE];
	fillArray(ar1);
	printArray(ar1);
	copyArray(ar1, ar2);
	invertArray(ar2);
	printArray(ar2);
	copyInverted(ar2, ar3);
	printArray(ar3);
	delete[] ar1;
	delete[] ar2;
	delete[] ar3;

	return 0;
}
