#include <iostream>
using namespace std;

// ������� ��� �������� ���������� �� �������

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

	// �������� � ����� �������

	int size;
	cout << "������� ����� �������: ";
	cin >> size;
	int* arr = new int[size];
	
	cout << "������:" << endl;
	for (int i = 0; i < size; i++)
	{
		arr[i] = rand() % 20;
		cout << arr[i] << "\t";
	}

	// ���������� ������� � ����� �������� ������

	foo(arr, size);

	cout << endl << "�������� ������:" << endl;
	for (int i = 0; i < size; i++) 
	{
		cout << arr[i] << "\t";
	}

	// ����� �������� ����� ������� � ������� ������

	cout << endl << "�����: " << size << endl;
	delete[] arr;

	return 0;
}