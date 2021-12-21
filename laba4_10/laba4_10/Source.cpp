#include <iostream>
using namespace std;

int main() {
    
    setlocale(LC_ALL, "ru");
    
    const int n = 6; // ������ ����������� ��������

    // �������� �������

    int** a = new int*[n];
    for (int i = 0; i < n; i++) 
    {
        a[i] = new int[n];
    }

    // ���������� ����������� ��������

    for (int i = 1; i <= n; ++i) 
    {
        for (int j = 1; j <= n; ++j) 
        {
            a[i - 1][j - 1] = 1 + ((i + j - 1 + (n - 1) / 2) % n) * n + ((i + 2 * j + 2) % n);
        }
    }

    // �����

    cout << "���������� �������:" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << a[i][j] << "\t";
        }
        cout << endl;
    }

    // ������� ������

    for (int i = 0; i < n; ++i) {
        delete[] a[i];
    }
    delete[] a;

    return 0;
}