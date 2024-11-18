#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t; // Number of test cases

    while (t--) {
        int H, W, D;
        cin >> H >> W >> D;

        vector<string> original(H);
        cin.ignore();
        for (int i = 0; i < H; i++) {
            getline(cin, original[i]);
        }

        vector<string> new_grid(H + D + 1, string(W + D + 1, ' '));
        for (int i = 0; i < H; i++) {
            new_grid[i] = original[i] + string(D + 1, ' ');
        }

        for (int i = H; i < H + D + 1; i++) {
            new_grid.push_back(string(W + D + 1, ' '));
        }

        for (int x = 0; x < H; x++) {
            for (int y = 0; y < W; y++) {
                if (original[x][y] == '+') {
                    for (int i = 1; i <= D; i++) {
                        new_grid[x + i][y + i] = '\\';
                    }
                }
            }
        }

        for (int x = 0; x < H; x++) {
            for (int y = 0; y < W; y++) {
                if (original[x][y] == '+' || original[x][y] == '-' || original[x][y] == '|') {
                    new_grid[x + D + 1][y + D + 1] = original[x][y];
                }
            }
        }

        for (const auto &line : new_grid) {
            cout << line << endl;
        }
    }

    return 0;
}
