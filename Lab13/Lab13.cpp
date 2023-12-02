#include <iostream>
#include <fstream>
#include <time.h>
#include <stdlib.h>
#include <vector>
#include <utility>
#include <Windows.h>
using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int n;
    cout << "7:\nВведіть n: ";
    cin >> n;
    ofstream out;
    srand(time(NULL));
    out.open("out.txt"); //УСІ ДАНІ ТУТ!!!
    vector<vector<int>> matrix(n, vector<int>(n));
    for (int d=1; d <= 2 * n - 1; d++) //номер діагоналі
    {
        int i, j;
        if (d <= n)
        {
            i = n - 1;
            j = d - 1;
        }
        else
        {
            i = 2 * n - d-1;
            j = n - 1;
        }
        while (i >= 0 && j >= 0)
        {
            matrix[i][j] = rand()%251-100;
            i--;
            j--;
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            out << matrix[i][j] << ' ';
        out << '\n';
    }
}
