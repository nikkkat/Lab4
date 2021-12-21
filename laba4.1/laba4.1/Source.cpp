#include <iostream>
using namespace std;
int main() 
{

	setlocale(LC_ALL, "ru");

	// ввод массива

	cout << "введите количество элементов массива: ";
	int k, n, i = 0;
	cin >> k;
	int arr[100];

	for (i = 0; i < k; i++) {
		cout << "введите элемент массива: ";
		cin >> n;
		arr[i] = n;
	}

	cout << "исходные данные: " << endl;

	for (i = 0; i < k; i++) {
		cout << arr[i] << "\t";
	}

	// поиск наименьшего и наибольшего чисел в массиве

	int min = arr[0], max = arr[0];

	for (i = 1; i < k; i++) {
		if (arr[i] < min) { min = arr[i]; }
		if (arr[i] > max) { max = arr[i]; }
	}

	// вывод данных без наибольшего и наименьшего 

	cout << endl << "итоговые данные: " << endl;

	for (i = 0; i < k; i++) {
		if (arr[i] != min && arr[i] != max) { cout << arr[i] << "\t"; }
	}

	return 0;

}