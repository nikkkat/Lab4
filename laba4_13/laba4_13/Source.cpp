#include <iostream>
using namespace std;

int main() 
{
	setlocale(LC_ALL, "ru");

	// создание массива, заполнение

	int n;
	cout << "введите количество удлиннителей: ";
	cin >> n;

	int* arr = new int[n];

	cout << endl << "количество розеток в каждом:" << endl;
	for (int i = 0; i < n; i++) {
		arr[i] = rand() % 10;
		cout << arr[i] << "\t";
	}
	cout << endl;

	// подсчёт всего количества розеток

	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += arr[i];
	}
	
	// количество возможных для использования розеток, вывод, очистка памяти

	int res = sum - n + 1;
	cout << endl << "розеток: " << res << endl;

	delete[] arr;

	return 0;
}