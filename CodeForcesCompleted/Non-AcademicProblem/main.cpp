#include <bits/stdc++.h>
#define ll long long

using namespace std;

const long long INF = 1e18;

class Elements {
public:
    int n, m;
    vector<vector<ll>> graph;
    vector<pair<ll, ll>> edges;
    vector<bool> visited;
    vector<ll> depths;
    vector<ll> parents;
    vector<ll> highest;
    vector<ll> sum_under;

    Elements(ll n, ll m) : n(n), m(m), graph(n), visited(n, false), depths(n, -1), parents(n, -1), highest(n, INF), sum_under(n, 0) {
        depths[0] = 0;
        for (int i = 0; i < m; ++i) {
            ll u, v;
            cin >> u >> v;
            u--; v--;  // Decrease index to match zero-based indexing
            graph[u].push_back(v);
            graph[v].push_back(u);
            edges.emplace_back(u, v);
        }
    }
};

void dfs(Elements &elements, int cur_node) {
    elements.visited[cur_node] = true;
    elements.highest[cur_node] = elements.depths[cur_node];
    ll cur_s = 0;

    for (int neighbor : elements.graph[cur_node]) {
        if (!elements.visited[neighbor]) {
            // Set parent
            elements.parents[neighbor] = cur_node;
            // Set depth
            elements.depths[neighbor] = elements.depths[cur_node] + 1;
            // Call dfs on neighbor
            dfs(elements, neighbor);

            elements.highest[cur_node] = min(elements.highest[cur_node], elements.highest[neighbor]);

            cur_s += elements.sum_under[neighbor];
        } else if (neighbor != elements.parents[cur_node]) {
            elements.highest[cur_node] = min(elements.highest[cur_node], elements.depths[neighbor]);
        }
    }

    elements.sum_under[cur_node] = cur_s + 1;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        Elements els(n, m);
        dfs(els, 0);

        long long ans = (n - 1) * n / 2;

        for (const auto& edge : els.edges) {
            ll u = edge.first, v = edge.second;

            if (els.depths[u] > els.depths[v]) swap(u, v);

            if (els.highest[v] > els.depths[u]) {
                long long cur_am = (els.sum_under[v] - 1) * els.sum_under[v] / 2 +
                                   (n - els.sum_under[v] - 1) * (n - els.sum_under[v]) / 2;
                ans = min(ans, cur_am);
            }
        }

        cout << ans << endl;
    }

    return 0;
}
