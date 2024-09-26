#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <set>
#include <algorithm>

using namespace std;

vector<char> get_adjacent_in_grid(const vector<string>& g, int i, int j) {
    vector<char> adjacent;
    if (i > 0) adjacent.push_back(g[i-1][j]);
    if (i < static_cast<int>(g.size()) - 1) adjacent.push_back(g[i+1][j]);
    if (j > 0) adjacent.push_back(g[i][j-1]);
    if (j < static_cast<int>(g[i].size()) - 1) adjacent.push_back(g[i][j+1]);
    return adjacent;
}

vector<pair<int, int> > get_adjacent_indexes_grid(const vector<string>& g, int i, int j) {
    vector<pair<int, int> > adjacent;
    if (i > 0) adjacent.push_back(make_pair(i-1, j));
    if (i < static_cast<int>(g.size()) - 1) adjacent.push_back(make_pair(i+1, j));
    if (j > 0) adjacent.push_back(make_pair(i, j-1));
    if (j < static_cast<int>(g[i].size()) - 1) adjacent.push_back(make_pair(i, j+1));
    return adjacent;
}

int main() {
    int h, w;
    cin >> h >> w;

    vector<string> grid(h);
    for (int i = 0; i < h; i++) {
        cin >> grid[i];
    }

    set<pair<int, int> > possible_starts;

    for (int i = 0; i < static_cast<int>(grid.size()); i++) {
        for (int j = 0; j < static_cast<int>(grid[i].size()); j++) {
            vector<char> adjacent = get_adjacent_in_grid(grid, i, j);
            if (find(adjacent.begin(), adjacent.end(), '#') == adjacent.end() && grid[i][j] != '#') {
                possible_starts.insert(make_pair(i, j));
            }
        }
    }

    int s = 1;

    while (!possible_starts.empty()) {
        set<pair<int, int> >::iterator it = possible_starts.begin();
        pair<int, int> start = *it;
        possible_starts.erase(it);

        set<pair<int, int> > component;
        component.insert(start);
        queue<pair<int, int> > q;
        q.push(start);

        while (!q.empty()) {
            pair<int, int> cur = q.front();
            q.pop();

            vector<char> adjacents = get_adjacent_in_grid(grid, cur.first, cur.second);
            if (find(adjacents.begin(), adjacents.end(), '#') != adjacents.end()) {
                continue;
            }

            vector<pair<int, int> > adj_indexes = get_adjacent_indexes_grid(grid, cur.first, cur.second);
            for (vector<pair<int, int> >::const_iterator adj = adj_indexes.begin(); adj != adj_indexes.end(); ++adj) {
                if (component.find(*adj) == component.end()) {
                    q.push(*adj);
                    component.insert(*adj);
                    possible_starts.erase(*adj);
                }
            }
        }

        s = max(s, static_cast<int>(component.size()));
    }

    cout << s << endl;

    return 0;
}