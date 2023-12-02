#include <iostream>
#include <Windows.h>
#include <time.h>
#include <stdlib.h>
#include <vector>
#include <cmath>
using namespace std;

void fill(vector<vector<int>> &arr, int n)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            arr[i][j] = rand() % 201 - 100;
}
double aver(const vector<vector<int>>& arr, int n)
{
    double a = 0;
    for (int i = 0; i < n; i++)
        a += arr[i][0];
    a /= n;
    return a;
}


int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    srand(time(NULL));
    int a;
    cout << "12\nВведіть номер завдання: ";
    cin >> a;
    switch (a)
    {
    case 1:
    {
        cout << "\nВведіть розміри матриці: ";
        int n, m;
        cin >> n >> m;
        vector<vector<int>> matrix(n, vector<int>(m));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> matrix[i][j];
        for (int i = 0; i < n; i++)
        {
            int sum = 0;
            for (int j = 0; j < m; j++)
                if (matrix[i][j] < 0)
                    sum += matrix[i][j];
            cout << i + 1 << ": " << sum << endl;
        }
        break;
    }
    case 2:
    {
        cout << "\nВведіть розміри матриці: ";
        int n, m;
        cin >> n >> m;
        vector<vector<int>> matrix(n, vector<int>(m));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> matrix[i][j];
        int *minm = &matrix[0][0];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (abs(*minm) > abs(matrix[i][j]))
                    minm = &matrix[i][j];
        cout << "min=" << *minm << endl;
        break;
    }
    case 3:
    {
        cout << "\nВведіть розмір матриці: ";
        int n;
        cin >> n;
        vector<vector<int>> matrix(n, vector<int>(n));
        fill(matrix, n);
        double k = aver(matrix, n);
        int res = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (matrix[i][j] > k)
                    res++;
        cout << "Середнє: " << k << "\nКількість: " << res << endl;
        break;
    }
    }
    cin.ignore();
}