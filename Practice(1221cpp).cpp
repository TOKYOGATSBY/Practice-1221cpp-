#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

bool isValid(const vector<vector<int>>& grid, int x, int y, int s, int N) {
    if (x - s < 0 || x + s >= N || y - s < 0 || y + s >= N)
        return false;

    for (int i = x - s; i <= x + s; ++i) {
        for (int j = y - s; j <= y + s; ++j) {
            if (abs(i - x) + abs(j - y) > s && grid[i][j] != 1)
                return false;
        }
    }

    for (int i = -s; i <= s; ++i) {
        for (int j = -s; j <= s; ++j) {
            if (abs(i) + abs(j) <= s && grid[x + i][y + j] != 0)
                return false;
        }
    }

    return true;
}

int main() {
    while (true) {
        int N;
        cin >> N;
        if (!cin || N == 0) {
            break;
        }

        vector<vector<int>> grid(N, vector<int>(N));
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                cin >> grid[i][j];
            }
        }

        int maxSize = 0;

        for (int s = N / 2; s >= 1; --s) {
            bool found = false;
            for (int x = s; x < N - s; ++x) {
                for (int y = s; y < N - s; ++y) {
                    if (isValid(grid, x, y, s, N)) {
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
