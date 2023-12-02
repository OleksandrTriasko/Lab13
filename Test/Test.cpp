#include <iostream>
#include <vector>

using namespace std;

void fillZigzag(vector<vector<int>>& matrix) {
    int n = matrix.size();
    int value = 1;

    for (int sum = 0; sum < n + n - 1; sum++) {
        if (sum % 2 == 0) {
            // ������ ����� - �������� ����
            for (int i = min(sum, n - 1); i >= max(0, sum - n + 1); i--) {
                matrix[i][sum - i] = value++;
            }
        }
        else {
            // �������� ����� - �������� �����
            for (int i = max(0, sum - n + 1); i <= min(sum, n - 1); i++) {
                matrix[i][sum - i] = value++;
            }
        }
    }
}

int main() {
    int n;
    cout << "������� ����������� �������: ";
    cin >> n;

    vector<vector<int>> matrix(n, vector<int>(n, 0));

    fillZigzag(matrix);

    // ������� ���������
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}
