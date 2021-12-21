#include <iostream>
#include <iomanip>
using namespace std;

int main() {

	setlocale(LC_ALL, "ru");

	// �������� � ���������� �������

	int rows = 5, cols = 5;
	cout << "������� ����� �����: ";
	cin >> rows;
	cout << "������� ����� ��������: ";
	cin >> cols;
	double** arr = new double* [rows]; // arr - ����������� �������
	double** a = new double* [rows]; // a - ����� �����������

	for (int i = 0; i < rows; i++) {
		arr[i] = new double[cols];
		a[i] = new double[cols];
	}

	cout << "�������� ������:" << endl;

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			arr[i][j] = (rand() % 100)/10.;
			cout << arr[i][j] << "\t";
		}
		cout << endl;
	}

	// ���� ��������� ������� a

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++)
		{
			if (i == 0 && j != 0 && j != (cols - 1))
			{
				a[i][j] = (arr[i][j - 1] + arr[i + 1][j - 1] + arr[i + 1][j] + arr[i + 1][j + 1] + arr[i][j + 1]) / 5;
			}
			else if (i == (rows - 1) && j != 0 && j != (cols - 1))
			{
				a[i][j] = (arr[i][j - 1] + arr[i - 1][j - 1] + arr[i - 1][j] + arr[i - 1][j + 1] + arr[i][j + 1]) / 5;
			}
			else if (j == (cols - 1) && i != 0 && i != (rows - 1))
			{
				a[i][j] = (arr[i - 1][j] + arr[i - 1][j - 1] + arr[i][j - 1] + arr[i + 1][j - 1] + arr[i + 1][j]) / 5;
			}
			else if (j == 0 && i != 0 && i != (rows - 1))
			{
				a[i][j] = (arr[i - 1][j] + arr[i - 1][j + 1] + arr[i][j + 1] + arr[i + 1][j + 1] + arr[i + 1][j]) / 5;
			}
			else if (i == 0 && j == 0)
			{
				a[i][j] = (arr[i][j + 1] + arr[i + 1][j + 1] + arr[i + 1][j]) / 3;
			}
			else if (i == 0 && j == (cols - 1))
			{
				a[i][j] = (arr[i][j - 1] + arr[i + 1][j - 1] + arr[i + 1][j]) / 3;
			}
			else if (i == (rows - 1) && j == (cols - 1))
			{
				a[i][j] = (arr[i][j - 1] + arr[i - 1][j - 1] + arr[i - 1][j]) / 3;
			}
			else if (i == (rows - 1) && j == 0)
			{
				a[i][j] = (arr[i][j + 1] + arr[i - 1][j + 1] + arr[i - 1][j]) / 3;
			}
			else 
			{
				a[i][j] = (arr[i - 1][j] + arr[i - 1][j - 1] + arr[i][j - 1] + arr[i + 1][j - 1] + arr[i + 1][j]
					+ arr[i + 1][j + 1] + arr[i][j + 1] + arr[i - 1][j + 1]) / 8;
			}
		}
	}

	// ����� ����������� � ������� ������

	cout << "��������� �����������: " << endl;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			cout << fixed << setprecision(2) << a[i][j] << "\t";
		}
		cout << endl;
	}

	for (int i = 0; i < rows; i++) {
		delete[] arr[i];
		delete[] a[i];
	}
	delete[] arr;
	delete[] a;

	return 0;
}