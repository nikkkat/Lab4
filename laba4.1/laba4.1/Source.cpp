#include <iostream>
using namespace std;
int main() 
{

	setlocale(LC_ALL, "ru");

	// ���� �������

	cout << "������� ���������� ��������� �������: ";
	int k, n, i = 0;
	cin >> k;
	int arr[100];

	for (i = 0; i < k; i++) {
		cout << "������� ������� �������: ";
		cin >> n;
		arr[i] = n;
	}

	cout << "�������� ������: " << endl;

	for (i = 0; i < k; i++) {
		cout << arr[i] << "\t";
	}

	// ����� ����������� � ����������� ����� � �������

	int min = arr[0], max = arr[0];

	for (i = 1; i < k; i++) {
		if (arr[i] < min) { min = arr[i]; }
		if (arr[i] > max) { max = arr[i]; }
	}

	// ����� ������ ��� ����������� � ����������� 

	cout << endl << "�������� ������: " << endl;

	for (i = 0; i < k; i++) {
		if (arr[i] != min && arr[i] != max) { cout << arr[i] << "\t"; }
	}

	return 0;

}