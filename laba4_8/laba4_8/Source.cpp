#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");

	// создание массива и заполнение

	int size;
	cout << "введите длину массива: ";
	cin >> size;
	int* arr = new int[size];

	cout << "массив:" << endl;
	for (int i = 0; i < size; i++)
	{
		arr[i] = rand() % 50;
		cout << arr[i] << "\t";
	}

	int nummin = 0, nummax = 0; 
	int min = 51, max = -1;

	// поиск номера минимального значения

	for (int i = 0; i < size; i++)
	{
		if (arr[i] < min)
		{
			min = arr[i];
			nummin = i;
		}
		
	}

	cout << endl << "номер минимального: " << nummin << endl;

	// поиска номера максимального значения

	for (int i = 0; i < size; i++)
	{
		if (arr[i] > max)
		{
			max = arr[i];
			nummax = i;
		}
	}
	
	cout << "номер максимального: " << nummax << endl;

	// создание массива с нулями между наибольшим и наименьшим значениями

	cout << endl << "массив с нулями:" << endl;

	int i = 0;
	while (i != nummax && i != nummin)
	{
		cout << arr[i] << "\t";
		i++;
	}
	if (i == nummax || i == nummin)
	{
		cout << arr[i] << "\t";
		i++;
	}
	while (i != nummax && i != nummin)
	{
		arr[i] = NULL;
		cout << arr[i] << "\t";
		i++;
	}
	if (i == nummax || i == nummin)
	{
		cout << arr[i] << "\t";
		i++;
	}
	while (i < size)
	{
		cout << arr[i] << "\t";
		i++;
	}
	
	// подсчёт нулей

	int z = 0;
	for (i = 0; i < size; i++)
	{
		if (arr[i] == 0) { z += 1; }
	}

	cout << endl << "нулей: " << z << endl;

	// если нулей больше половины количества элементов, создаём новый массив без них, очистка памяти

	int a = (size - 1) / 2;
	if (z >= a)
	{
		int* newarr = new int[size];
		for (int n = 0; n < size; n++)
		{
			if (arr[n] != 0) { newarr[n] = arr[n]; }
		}
		delete[] arr;
		arr = newarr;

		cout << endl << "итоговые данные:" << endl;
		for (int n = 0; n < size; n++)
		{
			if (arr[n] > 0) { cout << arr[n] << "\t"; }
		}
		cout << endl;
	}
	delete[] arr;

	return 0;
}