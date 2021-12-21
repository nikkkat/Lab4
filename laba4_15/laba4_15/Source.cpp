#include <iostream>
using namespace std;

int main() 
{
	setlocale(LC_ALL, "ru");

	// создание таблицы

	cout << "введите размер таблицы: ";
	int n;
	cin >> n;

	int** a = new int* [n];
	for (int i = 0; i < n; i++)
	{
		a[i] = new int[n];
	}

	// заполнение таблицы, вывод

	int x = 0;
	int num = 1;
	for (int j = 0; j < n; j++)
	{
		for (int i = 0; i < x; i++)
		{
			a[i][j] = num;
			num++;
		}
		for (int m = j; m >= 0; m--)
		{
			a[x][m] = num;
			num++;
		}
		x++;
	}

	cout << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << a[i][j] << "\t";
		}
		cout << endl;
	}

	// ввод числа из таблицы

	cout << endl << "введите натуральное число: ";
	int k; cin >> k;

	while (k > n * n)
	{
		cout << "введите ещё раз: ";
		cin >> k;
	}

	// вывод строки и столбца, где находится число

	cout << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (k == a[i][j])
			{
				int m = j;
				cout << "строка:" << endl;
				for (j = 0; j < n; j++)
				{
					cout << a[i][j] << "\t";
				}
				cout << endl << "столбец:" << endl;
				for (i = 0; i < n; i++)
				{
					cout << a[i][m] << "\t";
				}
				goto end;
			}
		}
	}

end: cout << endl;
	
	// очистка памяти

	for (int i = 0; i < n; i++)
	{
		delete[] a[i];
	}
	delete[] a;

	return 0;
}