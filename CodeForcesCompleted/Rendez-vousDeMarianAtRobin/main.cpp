#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
using namespace std;

const long long INF = 1e18;

struct Node {
    long long dist;
    int node, horse;
    bool operator>(const Node& other) const {
        return dist > other.dist;
    }
};

vector<vector<pair<int, int>>> graph;
vector<int> horses;

vector<vector<long long>> dijkstra(int start, int n) {
    vector<vector<long long>> dists(n, vector<long long>(2, INF));
    vector<vector<bool>> visited(n, vector<bool>(2, false));
    priority_queue<Node, vector<Node>, greater<Node>> heap;

    dists[start][0] = 0;
    heap.push({0, start, 0});

    while (!heap.empty()) {
        Node current = heap.top();
        heap.pop();

        long long dist = current.dist;
        int node = current.node;
        int horse = current.horse;

        if (visited[node][horse]) continue;
        visited[node][horse] = true;

        horse |= horses[node];

        for (auto& edge : graph[node]) {
            int neighbor = edge.first;
            int weight = edge.second;
            long long am = dist + weight / 2 * (2 - horse);
            if (dists[neighbor][horse] > am) {
                dists[neighbor][horse] = am;
                heap.push({dists[neighbor][horse], neighbor, horse});
            }
        }
    }

    return dists;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m, h;
        cin >> n >> m >> h;

        horses.assign(n, 0);
        vector<int> hor(h);
        for (int i = 0; i < h; i++) {
            cin >> hor[i];
            horses[hor[i] - 1] = 1;
        }

        graph.assign(n, vector<pair<int, int>>());

        for (int i = 0; i < m; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            u--; v--;
            graph[u].emplace_back(v, w);
            graph[v].emplace_back(u, w);
        }

        long long ans = INF;
        vector<vector<long long>> d1 = dijkstra(0, n);
        vector<vector<long long>> d2 = dijkstra(n - 1, n);

        for (int i = 0; i < n; i++) {
            ans = min(ans, max(min(d1[i][0], d1[i][1]), min(d2[i][0], d2[i][1])));
        }

        cout << (ans == INF ? -1 : ans) << endl;
    }

    return 0;
}
