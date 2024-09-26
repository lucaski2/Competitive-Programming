#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

vector<vector<char> > rotate(const vector<vector<char> >& m) {
    int size = m.size();
    vector<vector<char> > rotated(size, vector<char>(size, 0));
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            rotated[j][size-i-1] = m[i][j];
        }
    }
    return rotated;
}

vector<vector<char> > stamp_sheet(const vector<vector<char> >& g1, const vector<vector<char> >& g2, int x, int y) {
    vector<vector<char> > ret = g1;
    for (int i = 0; i < g2.size(); ++i) {
        for (int j = 0; j < g2[0].size(); ++j) {
            if (g2[i][j] == '*') {
                ret[x+i][y+j] = g2[i][j];
            }
        }
    }
    return ret;
}

bool allowed(const vector<vector<char> >& g1, const vector<vector<char> >& g2) {
    for (int i = 0; i < g2.size(); ++i) {
        for (int j = 0; j < g2[0].size(); ++j) {
            if (g1[i][j] == '.' && g2[i][j] == '*') {
                return false;
            }
        }
    }
    return true;
}

vector<pair<int, int> > get_positions(int n, int k) {
    vector<pair<int, int> > positions;
    for (int i = 0; i <= n-k; ++i) {
        for (int j = 0; j <= n-k; ++j) {
            positions.push_back(make_pair(i, j));
        }
    }
    return positions;
}

int difference(const vector<vector<char> >& start_grid, const vector<vector<char> >& end_grid) {
    int dif = 0;
    for (int i = 0; i < start_grid.size(); ++i) {
        for (int j = 0; j < start_grid[0].size(); ++j) {
            if (start_grid[i][j] != end_grid[i][j]) {
                ++dif;
            }
        }
    }
    return dif;
}

bool compare_pair(const pair<int, int>& p1, const pair<int, int>& p2) {
    return p1.second < p2.second;
}

int main() {
    int inp;
    cin >> inp;

    for (int _ = 0; _ < inp; ++_) {
        string dummy;
        getline(cin, dummy);  // consume newline
        
        int n;
        cin >> n;
        getline(cin, dummy);  // consume newline

        vector<vector<char> > target_grid(n, vector<char>(n));
        for (int i = 0; i < n; ++i) {
            string row;
            getline(cin, row);
            for (int j = 0; j < n; ++j) {
                target_grid[i][j] = row[j];
            }
        }

        vector<vector<char> > grid(n, vector<char>(n, '.'));

        int k;
        cin >> k;
        getline(cin, dummy);  // consume newline

        vector<vector<char> > stamp(k, vector<char>(k));
        for (int i = 0; i < k; ++i) {
            string row;
            getline(cin, row);
            for (int j = 0; j < k; ++j) {
                stamp[i][j] = row[j];
            }
        }

        vector<pair<int, int> > possible_positions = get_positions(n, k);

        int nothing_count = 0;

        while (grid != target_grid) {
            map<int, int> possibilities;
            for (int i = 0; i < possible_positions.size(); ++i) {
                const pair<int, int>& pos = possible_positions[i];
                vector<vector<char> > cur = stamp_sheet(grid, stamp, pos.first, pos.second);
                if (allowed(target_grid, cur)) {
                    int key = pos.first * n + pos.second;
                    possibilities[key] = difference(grid, cur);
                }
            }

            if (possibilities.empty()) {
                ++nothing_count;
                stamp = rotate(stamp);
                if (nothing_count >= 4) {
                    cout << "NO" << endl;
                    goto next_case;
                }
                continue;
            } else if (max_element(possibilities.begin(), possibilities.end(), compare_pair)->second == 0) {
                ++nothing_count;
                stamp = rotate(stamp);
                if (nothing_count >= 4) {
                    cout << "NO" << endl;
                    goto next_case;
                }
                continue;
            } else {
                nothing_count = 0;
            }

            map<int, int>::iterator max_pos = max_element(possibilities.begin(), possibilities.end(), compare_pair);
            int max_pos_key = max_pos->first;
            int max_pos_x = max_pos_key / n;
            int max_pos_y = max_pos_key % n;
            grid = stamp_sheet(grid, stamp, max_pos_x, max_pos_y);
        }

        cout << "YES" << endl;

        next_case:
        continue;
    }

    return 0;
}