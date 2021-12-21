#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");
	srand(time(0));

	// �������� � ���������� ���� ����

	cout << "������� ���������� �����: ";
	int rows;
	cin >> rows;
	cout << "������� ���������� ��������: ";
	int cols; 
	cin >> cols;

	char** a = new char* [rows];
	for (int i = 0; i < rows; i++)
	{
		a[i] = new char[cols];
	}
	
	cout << endl << "���� ����: " << endl;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (rand() % 2 == 1)
			{
				a[i][j] = '*';
			}
			else 
			{
				a[i][j] = '.';
			}
			cout << a[i][j] << "\t";
		}
		cout << endl;
	}

	// ���� �����, ��� ������ ���� ������ �����

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			int num = 0;
			if (a[i][j] == '.') 
			{
				if (i == 0 && j != 0 && j != cols - 1) 
				{
					if (a[i][j - 1] == '*')
					{
						num += 1;
					}
					if (a[i][j + 1] == '*')
					{
						num += 1;
					}
					if (a[i + 1][j + 1] == '*')
					{
						num += 1;
					}
					if (a[i + 1][j] == '*')
					{
						num += 1;
					}
					if (a[i + 1][j - 1] == '*')
					{
						num += 1;
					}
				}

				else if (i == rows - 1 && j != 0 && j != cols - 1)
				{
					if (a[i][j - 1] == '*')
					{
						num += 1;
					}
					if (a[i - 1][j - 1] == '*')
					{
						num += 1;
					}
					if (a[i - 1][j] == '*')
					{
						num += 1;
					}
					if (a[i - 1][j + 1] == '*')
					{
						num += 1;
					}
					if (a[i][j + 1] == '*')
					{
						num += 1;
					}
				}

				else if (j == 0 && i != 0 && i != rows - 1)
				{
					if (a[i - 1][j] == '*')
					{
						num += 1;
					}
					if (a[i - 1][j + 1] == '*')
					{
						num += 1;
					}
					if (a[i][j + 1] == '*')
					{
						num += 1;
					}
					if (a[i + 1][j + 1] == '*')
					{
						num += 1;
					}
					if (a[i + 1][j] == '*')
					{
						num += 1;
					}
				}

				else if (j == cols - 1 && i != 0 && i != rows - 1)
				{
					if (a[i][j - 1] == '*')
					{
						num += 1;
					}
					if (a[i - 1][j - 1] == '*')
					{
						num += 1;
					}
					if (a[i - 1][j] == '*')
					{
						num += 1;
					}
					if (a[i + 1][j] == '*')
					{
						num += 1;
					}
					if (a[i + 1][j - 1] == '*')
					{
						num += 1;
					}
				}

				else if (i == 0 && j == 0)
				{
					if (a[i][j + 1] == '*')
					{
						num += 1;
					}
					if (a[i + 1][j + 1] == '*')
					{
						num += 1;
					}
					if (a[i + 1][j] == '*')
					{
						num += 1;
					}
				}

				else if (i == 0 && j == cols - 1)
				{
					if (a[i][j - 1] == '*')
					{
						num += 1;
					}
					if (a[i + 1][j] == '*')
					{
						num += 1;
					}
					if (a[i + 1][j - 1] == '*')
					{
						num += 1;
					}

				}

				else if (i == rows - 1 && j == cols - 1)
				{
					if (a[i][j - 1] == '*')
					{
						num += 1;
					}
					if (a[i - 1][j - 1] == '*')
					{
						num += 1;
					}
					if (a[i - 1][j] == '*')
					{
						num += 1;
					}
				}

				else if (i == rows - 1 && j == 0)
				{
					if (a[i - 1][j] == '*')
					{
						num += 1;
					}
					if (a[i - 1][j + 1] == '*')
					{
						num += 1;
					}
					if (a[i][j + 1] == '*')
					{
						num += 1;
					}
				}

				else
				{
					if (a[i][j - 1] == '*')
					{
						num += 1;
					}
					if (a[i - 1][j - 1] == '*')
					{
						num += 1;
					}
					if (a[i - 1][j] == '*')
					{
						num += 1;
					}
					if (a[i - 1][j + 1] == '*')
					{
						num += 1;
					}
					if (a[i][j + 1] == '*')
					{
						num += 1;
					}
					if (a[i + 1][j + 1] == '*')
					{
						num += 1;
					}
					if (a[i + 1][j] == '*')
					{
						num += 1;
					}
					if (a[i + 1][j - 1] == '*')
					{
						num += 1;
					}
				}

				a[i][j] = num + '0';
			}
			else { a[i][j] = '*'; }
		}
	}

	// ����� ����������

	cout << endl << "����:" << endl;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << a[i][j] << "\t";
		}
		cout << endl;
	}
	cout << endl;

	// ������� ������

	for (int i = 0; i < rows; i++)
	{
		delete[] a[i];
	}
	delete[] a;

	return 0;
}