#include <iostream>
using namespace std;
int main() {

	setlocale(LC_ALL, "ru");

	// ввод числа

	cout << "введите число: ";
	int n, im = 0;
	cin >> n;

	int nn = n;

	// счёт количества разрядов

	while (n != 0) {
		n /= 10;
		im++;
	}

	// ввод разряда

	cout << "введите номер разряда от 0 до " << im - 1 << " : ";
	int i;
	cin >> i;

	// нахождение числа в нужном разряде, вывод результата

	if (i == 0) { cout << "цифра в разряде: " << nn % 10; return 0; }

	for (im = 1; im <= i; im++) {
		nn /= 10;
	}

	cout << "цифра в разряде: " << nn % 10;

	return 0;
}