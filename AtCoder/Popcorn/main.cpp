#include <iostream>
#include <vector>
#include <set>
#include <algorithm> // for min

using namespace std;

int n, m;
vector<string> grid;
set<int> lengths;

bool can_eat_all_popcorn(const vector<bool>& popcorn_eaten) {
    for (bool eaten : popcorn_eaten) {
        if (!eaten) {
            return false;
        }
    }
    return true;
}

bool all_vendors_visited(const vector<bool>& visited_vendors) {
    for (bool visited : visited_vendors) {
        if (!visited) {
            return false;
        }
    }
    return true;
}

void solve(const vector<string>& grid, vector<bool>& popcorn_eaten,
           vector<bool>& visited_vendors, int num_visited) {
    if (can_eat_all_popcorn(popcorn_eaten)) {
        lengths.insert(num_visited);
        return;
    }

    if (all_vendors_visited(visited_vendors)) {
        return;
    }

    for (int i = 0; i < n; ++i) {
        if (visited_vendors[i]) {
            continue;
        }

        vector<bool> new_popcorn_eaten(popcorn_eaten);
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] == 'o') {
                new_popcorn_eaten[j] = true;
            }
        }
        vector<bool> new_visited_vendors(visited_vendors);
        new_visited_vendors[i] = true;
        solve(grid, new_popcorn_eaten, new_visited_vendors, num_visited + 1);
    }
}

int main() {
    cin >> n >> m;

    grid.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> grid[i];
    }

    vector<bool> popcorn_eaten(m, false);
    vector<bool> visited_vendors(n, false);
    solve(grid, popcorn_eaten, visited_vendors, 0);

    if (lengths.empty()) {
        cout << -1 << endl; // No solution found
    } else {
        cout << *min_element(lengths.begin(), lengths.end()) << endl;
    }

    return 0;
}
