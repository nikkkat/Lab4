#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");

	// �������� �������� ��� �������, �����������������, ��������� � ������������
	int n;
	cout << "������� ������ ������� n: ";
	cin >> n;
	int** arr = new int* [n];
	int** at = new int* [n];
	int** ae = new int* [n];
	int** au = new int* [n];

	for (int i = 0; i < n; i++)
	{
		arr[i] = new int[n];
		at[i] = new int[n];
		ae[i] = new int[n];
		au[i] = new int[n];
	}

	cout << "�������:" << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			arr[i][j] = rand() % 20;
			cout << arr[i][j] << "\t";
		}
		cout << endl;
	}

	// ���������������� � ���������� ��������� 

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i != j)
			{
				at[i][j] = arr[j][i];
				ae[i][j] = NULL;
			}
			else
			{
				at[i][j] = arr[i][j];
				ae[i][j] = 1;
			}
		}
	}

	/*cout << "����������������� �������:" << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << at[i][j] << "\t";
		}
		cout << endl;
	}

	cout << "��������� ������� ������� n:" << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << ae[i][j] << "\t";
		}
		cout << endl;
	}*/

	// ��������� arr * at

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			au[i][j] = 0;
			for (int k = 0; k < n; k++)
			{
				au[i][j] += arr[i][k] * at[k][j];
			}
		}
	}

	/*cout << "������������ ������� �� �����������������:" << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << au[i][j] << "\t";
		}
		cout << endl;
	}*/

	// �������� �� ������������������� � ������� ������

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (au[i][j] != ae[i][j])
			{
				cout << endl << "������� �� �������� �����������������" << endl;

				for (int i = 0; i < n; i++) {
					delete[] arr[i];
					delete[] at[i];
					delete[] ae[i];
					delete[] au[i];
				}
				delete[] arr;
				delete[] at;
				delete[] ae;
				delete[] au;

				return 0;
			}
		}
	}

	cout << endl << "������� �����������������" << endl;

	for (int i = 0; i < n; i++)
	{
		delete[] arr[i];
		delete[] at[i];
		delete[] ae[i];
		delete[] au[i];
	}
	delete[] arr;
	delete[] at;
	delete[] ae;
	delete[] au;

	return 0;
}
