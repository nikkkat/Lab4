#include <iostream>
using namespace std;
int main() {

	setlocale(LC_ALL, "ru");

	// ���� �����

	cout << "������� �����: ";
	int n, im = 0;
	cin >> n;

	int nn = n;

	// ���� ���������� ��������

	while (n != 0) {
		n /= 10;
		im++;
	}

	// ���� �������

	cout << "������� ����� ������� �� 0 �� " << im - 1 << " : ";
	int i;
	cin >> i;

	// ���������� ����� � ������ �������, ����� ����������

	if (i == 0) { cout << "����� � �������: " << nn % 10; return 0; }

	for (im = 1; im <= i; im++) {
		nn /= 10;
	}

	cout << "����� � �������: " << nn % 10;

	return 0;
}