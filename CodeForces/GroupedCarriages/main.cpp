#include <bits/stdc++.h>
#define ll long long
using namespace std;

void update(vector<pair<ll, ll>> &tree, ll i, ll x)
{
    i += tree.size() / 2;
    tree[i].first = x;
    for (i /= 2; i > 0; i /= 2)
    {
        tree[i] = tree[2 * i].first < 0 ? tree[2 * i] : min(tree[2 * i], tree[2 * i + 1]);
    }
}

pair<ll, ll> query(vector<pair<ll, ll>> &tree, ll query_left, ll query_right, ll node, ll node_left, ll node_right)
{
    if (query_left >= node_right || query_right <= node_left)
    {
        return {10000000, 0};
    }
    if (query_left <= node_left && query_right >= node_right)
    {
        return tree[node];
    }
    ll last_left = (node_left + node_right) / 2;
    pair<ll, ll> left = query(tree, query_left, query_right, 2 * node, node_left, last_left);
    pair<ll, ll> right = query(tree, query_left, query_right, 2 * node + 1, last_left, node_right);
    if (left.first < 0)
    {
        return left;
    }
    return min(left, right);
}

bool eval(ll mid, vector<ll> &a, vector<ll> &d)
{
    ll n = a.size();
    vector<pair<ll, ll>> tree(2 * n);
    for (ll i = 0; i < n; i++)
    {
        tree[n + i] = {a[i] - mid, i};
    }
    for (ll i = n - 1; i > 0; i--)
    {
        if (tree[2 * i].first < 0)
        {
            tree[i] = tree[2 * i];
        }
        else
        {
            tree[i] = tree[2 * i + 1];
        }
    }

    for (ll i = 0; i < n; i++)
    {
        pair<ll, ll> p = query(tree, max(0LL, i - d[i]), min((ll)n, i + d[i] + 1), 1, 0, n);

        while (p.first < 0 and tree[i].first > 0)
        {
            ll am = min(-p.first, tree[i].first);
            update(tree, p.second, p.first + am);
            update(tree, i, tree[i].first - am);
            p = query(tree, max(0LL, i - d[i]), min((ll)n, i + d[i] + 1), 1, 0, n);
        }
    }
    if (mid == 4)
    {
        for (ll i = 0; i < 2 * n; i++)
        {
            cout << tree[i].first << " ";
        }
        cout << endl;
    }
    for (ll i = 0; i < n; i++)
    {
        if (tree[n + i].first > 0)
        {
            return false;
        }
    }

    return true;
}


int main()
{
    ll n;
    cin >> n;
    vector<ll> a;
    vector<ll> d;
    for (ll i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        a.push_back(x);
    }
    for (ll i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        d.push_back(x);
    }


    
    ll l = 0, r = 100000000000;
    ll ans = 0;
    while (l < r) // Binary search because continuous 
    {
        ll mid = (l + r) / 2;

        if (eval(mid, a, d))
        {
            cout << mid << endl;
            ans = mid;
            r = mid;
        }
        else
        {
            l = mid + 1;
        }
    }
    eval(4, a, d);
    cout << ans << endl;
}