#include <bits/stdc++.h>

using namespace std;

int countPossibleFirstColors(int n, vector<vector<int>>& canvas) {
    set<int> visibleColors;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (canvas[i][j] != 0) {
                visibleColors.insert(canvas[i][j]);
            }
        }
    }

    map<int, vector<int>> bounds;
    for (int color : visibleColors) {
        bounds[color] = {n, 0, n, 0}; // {minRow, maxRow, minCol, maxCol}
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int color = canvas[i][j];
            if (color != 0) {
                bounds[color][0] = min(bounds[color][0], i);
                bounds[color][1] = max(bounds[color][1], i);
                bounds[color][2] = min(bounds[color][2], j);
                bounds[color][3] = max(bounds[color][3], j);
            }
        }
    }

    int ans = 0;

    for (int color : visibleColors) {
        set<int> otherColors = visibleColors;
        otherColors.erase(color);

        vector<int> perm(otherColors.begin(), otherColors.end());
        do {
            vector<vector<int>> cur(n, vector<int>(n, 0));

            // Paint the `color` area first
            for (int i = bounds[color][0]; i <= bounds[color][1]; ++i) {
                for (int j = bounds[color][2]; j <= bounds[color][3]; ++j) {
                    cur[i][j] = color;
                }
            }

            // Paint the rest of the colors in the order of the permutation
            bool matches = true;
            for (int curColor : perm) {
                for (int i = bounds[curColor][0]; i <= bounds[curColor][1]; ++i) {
                    for (int j = bounds[curColor][2]; j <= bounds[curColor][3]; ++j) {
                        cur[i][j] = curColor;
                    }
                }
            }

            if (cur == canvas) {
                ans++;
                break; // We only need one valid permutation for this color
            }

        } while (next_permutation(perm.begin(), perm.end()));
    }

    return ans;
}

int main() {
    ifstream inp("art.in");
    ofstream out("art.out");

    int n;
    inp >> n;

    vector<vector<int>> canvas(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        string row;
        inp >> row;
        for (int j = 0; j < n; ++j) {
            canvas[i][j] = row[j] - '0';
        }
    }

    out << countPossibleFirstColors(n, canvas) << endl;

    return 0;
}
