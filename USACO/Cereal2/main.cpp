#include <bits/stdc++.h>
#define ll long long
#define mint 2147483647
#define mod 1e9 + 7
#define en '\n'
using namespace std;


void make_component(vector<vector<pair<int, int>>> &undirected, vector<int> &component, vector<bool> &visited, vector<vector<pair<int, int>>> &trees, vector<bool> &visited_edges, int cur, int &leftover)
{
    component.push_back(cur);
    visited[cur] = true;
    for (pair<int, int> neighbor : undirected[cur])
    {
        if (not visited[neighbor.first])
        {
            trees[cur].push_back(neighbor);
            trees[neighbor.first].push_back({cur, neighbor.second});
            visited_edges[neighbor.second] = true;
            make_component(undirected, component, visited, trees, visited_edges, neighbor.first, leftover);
        }
        else
        {
            if (leftover == -1 and not visited_edges[neighbor.second])
            {
                leftover = neighbor.second;
                visited_edges[neighbor.second] = true;
            }
        }
        
    }
}

void dfs2(vector<vector<pair<int, int>>> &forest, vector<bool> &taken_cereals, vector<pair<int, int>> &cows, vector<bool> &visited_edges, vector<int> &order, int cur)
{
    
    for (pair<int, int> neighbor : forest[cur])
    {
        if (not visited_edges[neighbor.second])
        {
            visited_edges[neighbor.second] = true;
            order.push_back(neighbor.second);
            if (not taken_cereals[cows[neighbor.second].first])
            {
                taken_cereals[cows[neighbor.second].first] = true;
                dfs2(forest, taken_cereals, cows, visited_edges, order, neighbor.first);
            }
            else 
            {
                taken_cereals[cows[neighbor.second].second] = true;
                dfs2(forest, taken_cereals, cows, visited_edges, order, neighbor.first);
            }
        }
    }
}


int main()
{

    ios::sync_with_stdio(0);
    cin.tie(nullptr);

    int num_cows, num_cereals;
    cin >> num_cows >> num_cereals;
    
    vector<vector<pair<int, int>>> undirected(num_cereals, vector<pair<int, int>>());
    vector<pair<int, int>> cows(num_cows);
    for (int i = 0; i < num_cows; i++)
    {
        int a, b;
        cin >> a >> b;
        a--; b--;
        cows[i] = {a, b};
        undirected[a].push_back({b, i});
        undirected[b].push_back({a, i});
    }



    vector<bool> visited(num_cereals, false);

    vector<vector<pair<int, int>>> forest(num_cereals, vector<pair<int, int>>());

    vector<bool> visited_edges2(num_cows, false);
    vector<bool> taken_cereals(num_cereals, false);
    vector<int> final_order;
    vector<bool> visited_edges(num_cows, false);

    for (int i = 0; i < num_cereals; i++)
    {
        if (not visited[i])
        {
            vector<int> component;
            // create the component and make the tree for each component
            // set start edge where dfs will start
            int start_edge = -1;
            
            make_component(undirected, component, visited, forest, visited_edges, i, start_edge);

            
            if (component.size() == 1)
            {
                continue;
            }
            vector<int> order;

            if (start_edge != -1)
            {
                final_order.push_back(start_edge);
                visited_edges[start_edge] = true;
                taken_cereals[cows[start_edge].first] = true;
                dfs2(forest, taken_cereals, cows, visited_edges2, order, cows[start_edge].first);
            }
            else
            {
                dfs2(forest, taken_cereals, cows, visited_edges2, order, component[0]);
            }


            for (int a : order)
            {
                final_order.push_back(a);
            }
        }
    }

    visited_edges.resize(num_cows, false);

    for (int a : final_order)
    {
        visited_edges[a] = true;
    }
    int count = 0;
    for (int i = 0; i < num_cows; i++)
    {
        if (not visited_edges[i])
        {
            final_order.push_back(i);
            count++;
        }
    }

    cout << count << en;
    for (int a : final_order)
    {
        cout << a + 1 << en;
    }
}
