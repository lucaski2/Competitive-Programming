#include <bits/stdc++.h>
#define ll long long
#define en '\n'
using namespace std;


ll dsu_get_root(vector<ll> &dsu, ll node) {
    ll root = node;
    while (dsu[node] >= 0) {
        node = dsu[node];
    }
    while (dsu[root] >= 0) {
        ll temp = dsu[root];
        dsu[root] = node;
        root = temp;
    }

    return node;
}

ll dsu_get_size(vector<ll> &dsu, ll node) {
    int root = dsu_get_root(dsu, node);
    return -dsu[root];
}

void dsu_merge(vector<ll> &dsu, ll node1, ll node2) {
    ll root1 = dsu_get_root(dsu, node1);
    ll root2 = dsu_get_root(dsu, node2);

    if (root1 != root2) {
        if (dsu[root1] > dsu[root2]) swap(root1, root2);
        dsu[root1] += dsu[root2];
        dsu[root2] = root1;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;
    cin >> n >> m;
    vector<vector<ll>> edges(n - 1);
    vector<vector<ll>> queries(m);

    for (ll i = 0; i < n - 1; i++)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        edges[i] = {c, a - 1, b - 1};
    }

    for (ll i = 0; i < m; i++)
    {
        ll a;
        cin >> a;
        queries[i] = {a, i};
    }

    // vector<int> test(10, -1);
    // test[0] = -2;
    // test[1] = 0;
    // cout << dsu_get_root(test, 1) << en;
    // cout << dsu_get_root(test, 2) << en;
    // // dsu_merge(test, dsu_get_root(test, 1), dsu_get_root(test, 2));
    // for (int i = 0; i < 10; i++)
    // {
    //     cout << test[i] << ' ';
    // }

    sort(edges.begin(), edges.end());
    sort(queries.begin(), queries.end());

    vector<ll> query_answers(m);

    vector<ll> dsu(n, -1);

    ll edges_pointer = 0;
    ll cur_sum = 0;

    for (ll query = 0; query < m; query++)
    {
        ll current_query = queries[query][0], ind = queries[query][1];

        while (edges_pointer < n - 1 and current_query >= edges[edges_pointer][0])
        {
            if (dsu_get_root(dsu, edges[edges_pointer][1]) == dsu_get_root(dsu, edges[edges_pointer][2]))
            {
                edges_pointer++;
                continue;
            }
            ll size1 = dsu_get_size(dsu, edges[edges_pointer][1]);
            ll size2 = dsu_get_size(dsu, edges[edges_pointer][2]);

            cur_sum = cur_sum - (size1-1) * size1 / 2 - (size2-1) * size2 / 2 + (size1 + size2 - 1) * (size1 + size2) / 2;

            dsu_merge(dsu, edges[edges_pointer][1], edges[edges_pointer][2]);
            

            edges_pointer++;
        }
        query_answers[ind] = cur_sum;
    }
    for (int i = 0; i < m; i++)
    {
        cout << query_answers[i] << ' ';
    }
    cout << en;
}
