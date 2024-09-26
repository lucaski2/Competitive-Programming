#include <bits/stdc++.h>
using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<vector<int> > graph(n, vector<int>(0));
    vector<int> nums(n, 0);

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        graph[a].push_back(b);
        ++nums[b];
    }
    vector<int> memo(n, 0);


    queue<int> q;
    for (int i = 0; i < n; i++)
    {
        if (nums[i] == 0)
        {
            q.push(i);
        }
    }

    int largest = 0;
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        for (int next: graph[cur])
        {
            if (memo[next] < memo[cur] + 1)
            {
                memo[next] = memo[cur] + 1;
                largest = max(largest, memo[next]);
            }
            if (--nums[next] == 0)
            {
                q.push(next);
            }
        }
    }
    // print memo
    // for (int i = 0; i < n; i++)
    // {
    //     cout << memo[i] << " ";
    // }  
    // cout << endl;


    cout << largest << endl;
}
