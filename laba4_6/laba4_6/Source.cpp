#include <iostream>
using namespace std;

int main() {

	setlocale(LC_ALL, "ru");

	// создание матрицы А

	int rows = 5, cols = 5, min = 0;
	cout << "введите число строк: ";
	cin >> rows;
	cout << "введите число столбцов: ";
	cin >> cols;
	int** arr = new int* [rows];

	for (int i = 0; i < rows; i++) {
		arr[i] = new int[cols];
	}
	
	cout << "матрица А:" << endl;

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			arr[i][j] = rand() % 20;
			cout << arr[i][j] << "\t";
		}
		cout << endl;
	}
	
	// пересчёт элементов матрицы А в элементы матрицы В, вывод результата

	cout << "матрица В:" << endl;

	for (int i = 0; i < rows; i++) 
	{
		for (int j = 0; j < cols; j++) 
		{
			int max = arr[0][0];

			if (i == 0 && j == 0) 
			{
				arr[i][j] = arr[i][j];
			}
			else if (j == 0)
			{
				for (int k = 0; k <= i; k++)
				{
					if (arr[k][j] > max)
					{
						max = arr[k][j];
					}
				}
				arr[i][j] = max;
			}
			else if (i == 0)
			{
				for (int k = 0; k <= j; k++)
				{
					if (arr[i][k] > max)
					{
						max = arr[i][k];
					}
				}
				arr[i][j] = max;
			}
			else
			{ 
				for (int k = 0; k <= i; k++)
				{
					for (int n = 0; n <= j; n++)
					{
						if (arr[k][n] > max)
						{
							max = arr[k][n];
						}
					}
				}
				arr[i][j] = max;
			}
			cout << arr[i][j] << "\t";
		}
		cout << endl;
	}
	
	// очистка памяти

	for (int i = 0; i < rows; i++) {
		delete[] arr[i];
	}
	delete[] arr;

	return 0;
}