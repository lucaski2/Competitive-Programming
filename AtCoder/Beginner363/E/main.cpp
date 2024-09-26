#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <functional>

using namespace std;

struct Cell {
    int height;
    int i;
    int j;
    Cell(int h, int x, int y) : height(h), i(x), j(y) {}
};

struct CompareCell : public binary_function<Cell, Cell, bool> {
    bool operator()(const Cell& lhs, const Cell& rhs) const {
        return lhs.height > rhs.height;
    }
};

int main() {
    int h, w, y;
    cin >> h >> w >> y;

    vector<vector<int> > grid(h, vector<int>(w));
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cin >> grid[i][j];
        }
    }

    vector<Cell> heap;
    set<pair<int, int> > visited;

    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (i == 0 || j == 0 || i == h-1 || j == w-1) {
                heap.push_back(Cell(grid[i][j], i, j));
                visited.insert(make_pair(i, j));
            }
        }
    }

    make_heap(heap.begin(), heap.end(), CompareCell());
    int floating = h * w;

    for (int height = 1; height <= y; ++height) {
        while (!heap.empty() && heap.front().height <= height) {
            Cell cell = heap.front();
            pop_heap(heap.begin(), heap.end(), CompareCell());
            heap.pop_back();

            int di[] = {-1, 1, 0, 0};
            int dj[] = {0, 0, -1, 1};

            for (int k = 0; k < 4; ++k) {
                int ni = cell.i + di[k];
                int nj = cell.j + dj[k];

                if (ni >= 0 && ni < h && nj >= 0 && nj < w && 
                    visited.find(make_pair(ni, nj)) == visited.end()) {
                    heap.push_back(Cell(grid[ni][nj], ni, nj));
                    push_heap(heap.begin(), heap.end(), CompareCell());
                    visited.insert(make_pair(ni, nj));
                }
            }

            --floating;
        }
        cout << floating << endl;
    }

    return 0;
}