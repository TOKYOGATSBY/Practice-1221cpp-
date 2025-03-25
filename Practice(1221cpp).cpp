#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// Проверяем, можно ли вырезать "чёрный квадрат + белый ромб" с центром (x, y) и половиной стороны s
bool isValid(const vector<vector<int>>& grid, int x, int y, int s, int N) {
    // Проверка границ
    if (x - s < 0 || x + s >= N || y - s < 0 || y + s >= N)
        return false;

    // Проверка внешнего квадрата
    for (int i = x - s; i <= x + s; ++i) {
        for (int j = y - s; j <= y + s; ++j) {
            // Точки вне ромба должны быть черными
            if (abs(i - x) + abs(j - y) > s && grid[i][j] != 1)
                return false;
        }
    }

    // Проверка ромба - все точки белые
    for (int i = -s; i <= s; ++i) {
        for (int j = -s; j <= s; ++j) {
            if (abs(i) + abs(j) <= s && grid[x + i][y + j] != 0)
                return false;
        }
    }

    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while (true) {
        int N;
        cin >> N;
        if (!cin || N == 0) {
            // Конец входных данных
            break;
        }

        // Считываем всю матрицу NxN
        vector<vector<int>> grid(N, vector<int>(N));
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                cin >> grid[i][j];
            }
        }

        int maxSize = 0; // запомним здесь максимальный (2*s + 1)

        // Перебираем s (полусторону) от большего к меньшему
        for (int s = N / 2; s >= 1; --s) {
            bool found = false;
            // Центр (x,y) должен быть таким, чтобы x±s и y±s не вылезали
            for (int x = s; x < N - s; ++x) {
                for (int y = s; y < N - s; ++y) {
                    if (isValid(grid, x, y, s, N)) {
                        // Нашли вырез размера 2*s + 1
                        maxSize = 2 * s + 1;
                        found = true;
                        break;
                    }
                }
                if (found) break;
            }
            if (found) break;
        }

        if (maxSize > 0)
            cout << maxSize << "\n";
        else
            cout << "No solution\n";
    }

    return 0;
}
