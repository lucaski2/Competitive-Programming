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
                trees[cur].push_back(neighbor);
                trees[neighbor.first].push_back({cur, neighbor.second});
            }
        }
        
    }
}

void find_order(vector<vector<pair<int, int>>> &forest, vector<pair<int, int>> &cows, vector<bool> &visited, vector<bool> &taken_cereals, vector<int> &order, int current_edge)
{
    order.push_back(current_edge);
    visited[current_edge] = true;
    if (taken_cereals[cows[current_edge].first])
    {
        taken_cereals[cows[current_edge].second] = true;
    }
    else
    {
        taken_cereals[cows[current_edge].first] = true;
    }

    // explore both the left and the right cereal
    for (pair<int, int> edge : forest[cows[current_edge].first])
    {
        if (not visited[edge.second])
        {
            find_order(forest, cows, visited, taken_cereals, order, edge.second);
        }
    }

    for (pair<int, int> edge : forest[cows[current_edge].second])
    {
        if (not visited[edge.second])
        {
            find_order(forest, cows, visited, taken_cereals, order, edge.second);
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

    vector<bool> visited2(num_cows, false);
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



            // for (int a : component)
            // {
            //     cout << a << ' ';
            // }
            // cout << en;

            int num_edges_in_component = 0;
            for (int v : component)
            {
                num_edges_in_component += undirected[v].size();
            }
            num_edges_in_component /= 2;

            if (num_edges_in_component == component.size() - 1)
            {
                start_edge = undirected[i][0].second;
            }
            // cout << start_edge << en;

            // dfs through the tree to find the order
            vector<int> order;
            find_order(forest, cows, visited2, taken_cereals, order, start_edge);
            for (int id : order)
            {
                // cout << id << ' ';
                final_order.push_back(id);
            }

        }
    }


    // for (int i = 0; i < num_cereals; i++)
    // {
    //     cout << i << ": ";
    //     for (pair<int, int> edge : forest[i])
    //     {
    //         cout << edge.first << ' ';
    //     }
    //     cout << en;
    // }


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

