/*
Лабораторная работа №4.1
Задание: Отсортировать одномерный массив вещественных чисел
Алексей Шапран 
Группа: ИУ8-14
*/
#include <iostream>
#include <conio.h>
#include <stdlib.h>
using namespace std; 

int main(void)
{	
	
	double *parray = 0; // Инициализация указателя на массив
	unsigned int size = 0; // Заранее неизвестная размерность массива
	cout << "The number of array's elements: size = "; 
	cin >> size; // Ввод размерности массива с клавиатуры

	parray = (double *)malloc( size*sizeof(double) ); // Динамическое выделение памяти

	for ( int i = 0; i < size; i++ )
	{
		parray[i] = rand() % 100; // Заполнение массива случайными числами в интервале [0, 100)
		cout << parray[i] << " "; 
	}
	cout << endl;

	// Сортировка массива
	for ( int i = 0; i < size; i++ )
	{
		for (int j = i+1; j < size; j++ )
		{
			if (parray[i] < parray[j]) // Сравнение i-ого элемента с j-ым
				{ 
					double a = parray[i]; // Дополнительная переменная для хранения i-ого элемента
					parray[i] = parray[j]; // Присвоение i-ому элементу значения j-ого элемента
					parray[j] = a; // Присвоение j-ому элементу значения переменной а, т.е. значения i-ого элемента
				}
		}
	}

	cout << "Sorted array: ";
	for (int i = 0; i < size; i++) cout << parray[i] << " ";

	free(parray); // Освобождение памяти
	
	cout << endl << "Press any button to exit the program";
	_getch();
	return 0;
}