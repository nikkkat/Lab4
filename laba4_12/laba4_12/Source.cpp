#include <iostream>
using namespace std;

// функция для удаления дубликатов из массива

void foo(int*& arr, int& size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (arr[i] == arr[j]) {
				arr[i] = arr[size - 1];
				i--;
				size--;
				break;
			}
		}
	}
} 

int main()
{
	setlocale(LC_ALL, "ru");

	// создание и вывод массива

	int size;
	cout << "введите длину массива: ";
	cin >> size;
	int* arr = new int[size];
	
	cout << "массив:" << endl;
	for (int i = 0; i < size; i++)
	{
		arr[i] = rand() % 20;
		cout << arr[i] << "\t";
	}

	// применение функции и вывод итоговых данных

	foo(arr, size);

	cout << endl << "итоговые данные:" << endl;
	for (int i = 0; i < size; i++) 
	{
		cout << arr[i] << "\t";
	}

	// вывод итоговой длины массива и очистка памяти

	cout << endl << "длина: " << size << endl;
	delete[] arr;

	return 0;
}