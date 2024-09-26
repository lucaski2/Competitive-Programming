#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <map>
#include <algorithm>
using namespace std;

typedef long long ll;

int main()
{
    int n, m;
    cin >> n >> m;

    vector<set<int> > components;
    set<int> elements;
    vector<vector<int> > graph(n);
    int cur_am = 0;
    map<pair<int, int>, bool> already_confirmed;

    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        graph[x - 1].push_back(y - 1);
        graph[y - 1].push_back(x - 1);
        pair<int, int> edge = make_pair(min(x, y) - 1, max(x, y) - 1);
        if (already_confirmed.find(edge) == already_confirmed.end()) {
            cur_am++;
            already_confirmed[edge] = true;
        }
    }

    for (int i = 0; i < n; i++)
    {
        elements.insert(i);
    }

    while (!elements.empty())
    {
        int v = *elements.begin();
        elements.erase(elements.begin());

        set<int> component;
        queue<int> q;
        q.push(v);
        component.insert(v);

        while (!q.empty())
        {
            int u = q.front();
            q.pop();

            for (vector<int>::iterator it = graph[u].begin(); it != graph[u].end(); ++it)
            {
                int w = *it;
                if (component.find(w) == component.end())
                {
                    q.push(w);
                    component.insert(w);
                    elements.erase(w);
                }
            }
        }
        components.push_back(component);
    }

    ll s = 0;
    for (vector<set<int> >::iterator it = components.begin(); it != components.end(); ++it)
    {
        ll size = static_cast<ll>(it->size());
        s += size * (size - 1) / 2;
    }

    cout << s - cur_am << endl;

    return 0;
}