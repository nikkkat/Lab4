#include <iostream>
using namespace std;

int main() {

	setlocale(LC_ALL, "ru");

	// создание матрицы

	int rows = 5, cols = 5, min = 0; // min - количество локальных минимумов
	cout << "введите число строк: ";
	cin >> rows;
	cout << "введите число столбцов: ";
	cin >> cols;
	int** arr = new int* [rows];
	
	for (int i = 0; i < rows; i++) {
		arr[i] = new int[cols];
	}

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			arr[i][j] = rand() % 20;
			cout << arr[i][j] << "\t";
		}
		cout << endl;
	}

	// поиск локальных минимумов

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) 
		{
			if (i == 0 && j != 0 && j != cols - 1)
			{
				if (arr[i][j] < arr[i][j - 1] && arr[i][j] < arr[i + 1][j - 1] && arr[i][j] < arr[i + 1][j]
					&& arr[i][j] < arr[i + 1][j + 1] && arr[i][j] < arr[i][j + 1]) 
				{
					min += 1;
				}
			}
			else if (i == rows - 1 && j != 0 && j != cols - 1)
			{
				if (arr[i][j] < arr[i][j - 1] && arr[i][j] < arr[i - 1][j - 1] && arr[i][j] < arr[i - 1][j]
					&& arr[i][j] < arr[i - 1][j + 1] && arr[i][j] < arr[i][j + 1]) 
				{
					min += 1;
				}
			}
			else if (j == cols - 1 && i != 0 && i != rows - 1)
			{
				if (arr[i][j] < arr[i-1][j] && arr[i][j] < arr[i - 1][j - 1] && arr[i][j] < arr[i][j-1]
					&& arr[i][j] < arr[i + 1][j - 1] && arr[i][j] < arr[i+1][j]) 
				{
					min += 1;
				}
			}
			else if (j == 0 && i != 0 && i != rows - 1)
			{
				if (arr[i][j] < arr[i - 1][j] && arr[i][j] < arr[i - 1][j + 1] && arr[i][j] < arr[i][j + 1]
					&& arr[i][j] < arr[i + 1][j + 1] && arr[i][j] < arr[i + 1][j]) 
				{
					min += 1;
				}
			}
			else if (i == 0 && j == 0)
			{
				if (arr[i][j] < arr[i][j+1] && arr[i][j] < arr[i + 1][j + 1] && arr[i][j] < arr[i+1][j]) 
				{
					min += 1;
				}
			}
			else if (i == 0 && j == cols-1)
			{
				if (arr[i][j] < arr[i][j - 1] && arr[i][j] < arr[i + 1][j - 1] && arr[i][j] < arr[i + 1][j]) 
				{
					min += 1;
				}
			}
			else if (i == rows-1 && j == cols - 1)
			{
				if (arr[i][j] < arr[i][j - 1] && arr[i][j] < arr[i - 1][j - 1] && arr[i][j] < arr[i - 1][j]) 
				{
					min += 1;
				}
			}
			else if (i == rows - 1 && j == 0)
			{
				if (arr[i][j] < arr[i][j + 1] && arr[i][j] < arr[i - 1][j + 1] && arr[i][j] < arr[i - 1][j]) 
				{
					min += 1;
				}
			}
			else {
				if (arr[i][j] < arr[i - 1][j] && arr[i][j] < arr[i - 1][j - 1] && arr[i][j] < arr[i][j - 1] && arr[i][j] < arr[i + 1][j - 1] && arr[i][j] < arr[i + 1][j]
					&& arr[i][j] < arr[i + 1][j + 1] && arr[i][j] < arr[i][j + 1] && arr[i][j] < arr[i - 1][j + 1])
				{
					min += 1;
				}
			}
		}
	}

	// вывод результата и очистка памяти

	cout << endl << "число локальных минимумов: " << min << endl;

	for (int i = 0; i < rows; i++) {
		delete[] arr[i];
	}
	delete[] arr;

	return 0;
}