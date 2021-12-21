#include <iostream>
using namespace std;
int main() {

	setlocale(LC_ALL, "ru");

	// ���� �������, �������� � ����� �������

	cout << "������� ���������� ����� �������: ";
	int n, m;
	cin >> n;
	cout << "������� ���������� �������� �������: ";
	cin >> m;

	int arr[50][50];

	cout << endl << "�������� ������: " << endl;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			arr[i][j] = rand() % 50;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << arr[i][j] <<"\t";
			if (j == m - 1) { cout << endl; }
		}
	}

	// ����� ��������� ���� ������� ���������

	int min = arr[0][0];

	for (int i = 0; i < n; i++) 
	{
		for (int j = m-1; j > i; j--)
		{
			if (arr[i][j] < min ) { min = arr[i][j]; }
		}
	}
	
	cout << endl << "����������� �������� ���� ������� ���������: " << min << endl;

	return 0;
}