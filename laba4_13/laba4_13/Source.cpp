#include <iostream>
using namespace std;

int main() 
{
	setlocale(LC_ALL, "ru");

	// �������� �������, ����������

	int n;
	cout << "������� ���������� ������������: ";
	cin >> n;

	int* arr = new int[n];

	cout << endl << "���������� ������� � ������:" << endl;
	for (int i = 0; i < n; i++) {
		arr[i] = rand() % 10;
		cout << arr[i] << "\t";
	}
	cout << endl;

	// ������� ����� ���������� �������

	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += arr[i];
	}
	
	// ���������� ��������� ��� ������������� �������, �����, ������� ������

	int res = sum - n + 1;
	cout << endl << "�������: " << res << endl;

	delete[] arr;

	return 0;
}