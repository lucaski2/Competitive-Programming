#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

class Elements {
public:
    int n, m;
    vector<pair<int, int>> edges;
    vector<vector<int>> graph;
    vector<bool> visited;
    vector<int> lowest;
    vector<int> parent;
    vector<int> depths;
    set<pair<int, int>> bridges;

    Elements() {
        cin >> n >> m;
        graph.resize(n);
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            u--; v--;  // Adjusting for 0-indexed graph
            edges.push_back({u, v});
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        visited.resize(n, false);
        lowest.resize(n, INF);
        parent.resize(n, -1);
        depths.resize(n, INF);
    }

    void recursive_dfs(int node, int parent) {
        visited[node] = true;
        if (parent == -1) {
            depths[node] = 0;
        } else {
            depths[node] = depths[parent] + 1;
        }

        lowest[node] = depths[node];

        for (int child : graph[node]) {
            if (!visited[child]) {
                this->parent[child] = node;
                recursive_dfs(child, node);
                lowest[node] = min(lowest[node], lowest[child]);
            } else if (child != parent) {
                lowest[node] = min(lowest[node], depths[child]);
            }
        }
    }

    void find_bridges() {
        recursive_dfs(0, -1);

        for (auto edge : edges) {
            int u = edge.first;
            int v = edge.second;
            if (depths[u] > depths[v]) {
                swap(u, v);
            }

            if (lowest[v] > depths[u]) {
                bridges.insert({u, v});
            }
        }
    }

    int compress_graph() {
        find_bridges();
        set<int> not_visited;
        for (int i = 0; i < n; i++) {
            not_visited.insert(i);
        }

        map<int, int> m_to_component;
        int count = 0;

        while (!not_visited.empty()) {
            int node = *not_visited.begin();
            not_visited.erase(node);
            queue<int> q;
            q.push(node);
            vector<int> cur_comp;

            while (!q.empty()) {
                node = q.front();
                q.pop();
                not_visited.erase(node);
                cur_comp.push_back(node);

                for (int neighbor : graph[node]) {
                    if (bridges.count({node, neighbor}) || bridges.count({neighbor, node})) {
                        continue;
                    }
                    if (not_visited.count(neighbor)) {
                        q.push(neighbor);
                    }
                }
            }

            for (int node : cur_comp) {
                m_to_component[node] = count;
            }

            count++;
        }

        vector<vector<int>> compressed_graph(count);
        for (auto bridge : bridges) {
            int u = m_to_component[bridge.first];
            int v = m_to_component[bridge.second];
            compressed_graph[u].push_back(v);
            compressed_graph[v].push_back(u);
        }

        queue<int> q;
        q.push(0);
        vector<bool> visited(count, false);
        vector<int> depths(count, 0);

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            visited[node] = true;
            for (int neighbor : compressed_graph[node]) {
                if (!visited[neighbor]) {
                    q.push(neighbor);
                    depths[neighbor] = depths[node] + 1;
                }
            }
        }

        q.push(distance(depths.begin(), max_element(depths.begin(), depths.end())));

        fill(visited.begin(), visited.end(), false);
        fill(depths.begin(), depths.end(), 0);

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            visited[node] = true;
            for (int neighbor : compressed_graph[node]) {
                if (!visited[neighbor]) {
                    q.push(neighbor);
                    depths[neighbor] = depths[node] + 1;
                }
            }
        }

        return *max_element(depths.begin(), depths.end());
    }
};

int main() {
    Elements elements;
    cout << elements.compress_graph() << endl;
    return 0;
}