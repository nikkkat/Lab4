#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");

	// создание трёх матриц размера n

	int n;
	cout << "введите размер матриц: ";
	cin >> n;
	int** A = new int* [n];
	int** B = new int* [n];
	int** res = new int* [n];

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			A[i] = new int[n];
			B[i] = new int[n];
			res[i] = new int[n];
		}
	}

	// заполнение А и В

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			A[i][j] = rand() % 10;
			B[i][j] = rand() % 10;
		}
	}

	cout << endl << "матрица А:" << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << A[i][j] << "\t";
		}
		cout << endl;
	}

	cout << endl << "матрица В: " << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << B[i][j] << "\t";
		}
		cout << endl;
	}

	// умножение матриц, вывод результата

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int res1 = 0;
			for (int k = 0; k < n; k++)
			{
				res1 += A[i][k] * B[k][j];
			}
			res[i][j] = res1;
		}
	}

	cout << endl << "произведение матриц: " << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++) 
		{
			cout << res[i][j] << "\t";
		}
		cout << endl;
	}

	// очистка памяти

	for (int i = 0; i < n; i++) {
		delete[] A[i];
		delete[] B[i];
		delete[] res[i];
	}
	delete[] A;
	delete[] B;
	delete[] res;

	return 0;
}