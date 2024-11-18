#include <bits/stdc++.h>
#define ll long long
#define mint 2147483647
#define mod 1e9 + 7
#define en '\n'
using namespace std;


int overlap_1d(int a1, int a2, int b1, int b2) {return max(0, min(a2, b2) - max(a1, b1));}
int overlap_2d(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2){ return overlap_1d(ax1, ax2, bx1, bx2) * overlap_1d(ay1, ay2, by1, by2);}
double dist_squared(int x1, int y1, int x2, int y2){ return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);}
double dist(int x1, int y1, int x2, int y2){ return sqrt(dist_squared(x1, y1, x2, y2));}
vector<int> lin(int n) { vector<int> v(n); for (int i = 0; i < n; i++) cin >> v[i]; return v; }
vector<vector<int>> lin2d(int n, int m) { vector<vector<int>> v(n, vector<int>(m)); for (int i = 0; i < n; i++) { for (int j = 0; j < m; j++) cin >> v[i][j];}  return v; }
vector<vector<int>> linlayers(int n) { vector<vector<int>> v(n, vector<int>()); for (int i = 0; i < n; i++) { int m; cin >> m; for (int j = 0; j < m; j++) {int x; cin >> x;  v[i].push_back(x);}} return v;}
vector<ll> linll(int n) { vector<ll> v(n); for (int i = 0; i < n; i++) cin >> v[i]; return v; }
vector<vector<ll>> lin2dll(int n, int m) { vector<vector<ll>> v(n, vector<ll>(m)); for (int i = 0; i < n; i++) { for (int j = 0; j < m; j++) cin >> v[i][j];}  return v; }
vector<vector<char>> lin2dc(int n, int m) { vector<vector<char>> v(n, vector<char>(m)); for (int i = 0; i < n; i++) { for (int j = 0; j < m; j++) cin >> v[i][j];}  return v; }
vector<vector<int>> graph_edges_al(int n, int m) { vector<vector<int>> g(n); for (int i = 0; i < m; i++) { int a, b; cin >> a >> b; a--; b--; g[a].push_back(b); g[b].push_back(a);} return g;}
vector<vector<int>> graph_edges_am(int n, int m) { vector<vector<int>> g(n, vector<int>(n, 0)); for (int i = 0; i < m; i++) { int a, b; cin >> a >> b; a--; b--; g[a][b] = 1; g[b][a] = 1;} return g;}
template<typename T> optional<T> less_or_equal(const set<T>& s, const T& value) { if (s.empty()) { return nullopt; } auto it = s.upper_bound(value); if (it == s.begin()) { return nullopt; }return *prev(it);}
vector<string> instr(int n) { vector<string> v(n); for (int i = 0; i < n; i++) cin >> v[i]; return v; }


bool eval(ll max_number_in_carriage, vector<ll> &a, vector<ll> &d, int n)
{
    vector<tuple<ll, ll, ll>> start_of_carriage;
    for (int i = 0; i < n; i++)
    {
        if (a[i] > max_number_in_carriage)
        {
            start_of_carriage.push_back({max((ll)0, i - d[i]), a[i] - max_number_in_carriage, i});
            push_heap(start_of_carriage.begin(), start_of_carriage.end());
        }
    }

    vector<tuple<ll, ll, ll>> available_people;

    for (int i = 0; i < n; i++)
    {
        while (!start_of_carriage.empty() && get<0>(start_of_carriage.front()) <= i)
        {   
            ll ind = get<2>(start_of_carriage.front());
            ll num_people = get<1>(start_of_carriage.front());
            ll start = get<0>(start_of_carriage.front());
            available_people.push_back({ind, num_people, ind - start + ind});
            push_heap(available_people.begin(), available_people.end());
            pop_heap(start_of_carriage.begin(), start_of_carriage.end());
            start_of_carriage.pop_back();
        }

        while (!available_people.empty() && get<2>(available_people.front()) < i)
        {
            pop_heap(available_people.begin(), available_people.end());
            available_people.pop_back();
        }


        while (!available_people.empty() && a[i] - max_number_in_carriage < 0)
        {
            ll am = min(get<1>(available_people.front()), max_number_in_carriage - a[i]);
            a[i] += am;
            get<1>(available_people.front()) -= am;
            if (get<1>(available_people.front()) == 0)
            {
                pop_heap(available_people.begin(), available_people.end());
                available_people.pop_back();
            }
        }
    }
    if (available_people.empty())
    {
        return true;
    }
    return false;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<ll> a(n);
    vector<ll> d(n);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++)
    {
        cin >> d[i];
    }

    ll l = 0, r = 1000000000;
    ll ans = 10000000000;

    while (l < r)
    {
        ll m = (l + r) / 2;
        if (eval(m, a, d, n))
        {
            r = m;
            ans = min(ans, m);
        }
        else
        {
            l = m + 1;
        }
    }

    cout << ans << endl;
}
