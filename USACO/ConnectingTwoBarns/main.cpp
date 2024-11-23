#include <bits/stdc++.h>
#define ll long long
#define mint 2147483647
#define mod 1e9 + 7
#define en '\n'
using namespace std;




int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;

        vector<vector<int>> graph(n);

        for (int i = 0; i < m; i++)
        {
            int a, b;
            cin >> a >> b;
            graph[a - 1].push_back(b - 1);
            graph[b - 1].push_back(a - 1);
        }

        vector<set<int>> components;
        vector<bool> visited(n, false);
        int start = 0;
        int end = 0;
        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                queue<int> q;
                set<int> component;
                q.push(i);
                visited[i] = true;
                while (!q.empty())
                {
                    if (i == 0 or q.front() == 0)
                    {
                        start = components.size();
                    }
                    if (i == n - 1 or q.front() == n - 1)
                    {
                        end = components.size();
                    }
                    int node = q.front();
                    q.pop();
                    component.insert(node);
                    for (int j = 0; j < graph[node].size(); j++)
                    {
                        if (!visited[graph[node][j]])
                        {
                            visited[graph[node][j]] = true;
                            q.push(graph[node][j]);
                        }
                    }
                }
                components.push_back(component);
            }
        }

        ll ans = 1e10;
        for (int i = 0; i < components.size(); i++)
        {
            ll m = 1e10;
            for (int vertex : components[i])
            {
                auto ptr1 = lower_bound(components[start].begin(), components[start].end(), vertex);
                auto ptr2 = upper_bound(components[start].begin(), components[start].end(), vertex);

                if (ptr2 == components[start].begin())
                {
                    m = min(m, (ll)pow((vertex - *ptr1), 2));
                }
                else
                {
                    ptr2--;
                    m = min(m, (ll)pow((vertex - *ptr2), 2));
                }
            }

            ll m2 = 1e10;
            for (int vertex : components[i])
            {
                auto ptr1 = lower_bound(components[end].begin(), components[end].end(), vertex);
                auto ptr2 = upper_bound(components[end].begin(), components[end].end(), vertex);

                if (ptr2 == components[end].begin())
                {
                    m2 = min(m2, (ll)pow((vertex - *ptr1), 2));
                }
                else
                {
                    ptr2--;
                    m2 = min(m2, (ll)pow((vertex - *ptr2), 2));
                }
            }
            ans = min(ans, m + m2);
        }


        
        cout << ans << en;

    }

}
