#include <iostream>
using namespace std;

int main()
{
	srand(time(0));
	setlocale(LC_ALL, "ru");

	// �������� �������, �����

	int n;
	cout << "������� ������ �������: ";
	cin >> n;
	int*** a = new int** [n];

	for (int i = 0; i < n; i++)
	{
		a[i] = new int* [n];
		for (int j = 0; j < n; j++)
		{
			a[i][j] = new int[n];
		}
	}

	cout << endl << "������" << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < n; k++)
			{
				a[i][j][k] = rand() % 15;
				cout << a[i][j][k] << "\t";
			}
			cout << endl;
		}
		cout << endl;
	}

	int sum1 = 0, sum2 = 0, sum3 = 0, sum4 = 0, i, j, k, sum = 0;

	// ����� ��������� � ���������� ������ �����, ����� ����������

	for (i = j = k = 0; i < n; i++, j++, k++)
	{
		sum1 = sum1 + a[i][j][k];
	}
	if (sum1 > sum) { sum = sum1; }

	k = n - 1;
	for (i = j = 0; i < n; i++, j++)
	{
		sum2 = sum2 + a[i][j][k];
		k--;
		if (k >= 0) { continue; }
		else { break; }
	}
	if (sum2 > sum) { sum = sum2; }
	
	j = n - 1;
	for (i = k = 0; i < n; i++, k++)
	{
		sum3 = sum3 + a[i][j][k];
		j--;
		if (j >= 0) { continue; }
		else { break; }
	}
	if (sum3 > sum) { sum = sum3; }

	i = n - 1;
	for (j = k = 0; i > 0; j++, k++)
	{
		sum4 = sum4 + a[i][j][k];
		i--;
		if (i >= 0) { continue; }
		else { break; }
	}
	if (sum4 > sum) { sum = sum4; } 

	cout << endl << "���������� ����� � ���������: " << sum << endl; 

	// ������� ������

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			delete[] a[i][j];
		}
		delete[] a[i];
	}
	delete[] a;

	return 0;
}