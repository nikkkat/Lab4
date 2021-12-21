#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");

	// �������� ������� � ����������

	int size;
	cout << "������� ����� �������: ";
	cin >> size;
	int* arr = new int[size];

	cout << "������:" << endl;
	for (int i = 0; i < size; i++)
	{
		arr[i] = rand() % 50;
		cout << arr[i] << "\t";
	}

	int nummin = 0, nummax = 0; 
	int min = 51, max = -1;

	// ����� ������ ������������ ��������

	for (int i = 0; i < size; i++)
	{
		if (arr[i] < min)
		{
			min = arr[i];
			nummin = i;
		}
		
	}

	cout << endl << "����� ������������: " << nummin << endl;

	// ������ ������ ������������� ��������

	for (int i = 0; i < size; i++)
	{
		if (arr[i] > max)
		{
			max = arr[i];
			nummax = i;
		}
	}
	
	cout << "����� �������������: " << nummax << endl;

	// �������� ������� � ������ ����� ���������� � ���������� ����������

	cout << endl << "������ � ������:" << endl;

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
	
	// ������� �����

	int z = 0;
	for (i = 0; i < size; i++)
	{
		if (arr[i] == 0) { z += 1; }
	}

	cout << endl << "�����: " << z << endl;

	// ���� ����� ������ �������� ���������� ���������, ������ ����� ������ ��� ���, ������� ������

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

		cout << endl << "�������� ������:" << endl;
		for (int n = 0; n < size; n++)
		{
			if (arr[n] > 0) { cout << arr[n] << "\t"; }
		}
		cout << endl;
	}
	delete[] arr;

	return 0;
}