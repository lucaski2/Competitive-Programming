#include <bits/stdc++.h>
#define ll long long
using namespace std;

// use a priority queue to store the possible flights based on arrival time
// store the lowest arrival time at each airport
// Store edges per airport in a max heap

struct Path
{
  int start;
  int end;
  int dep;
  int arr;
};

// max heap comparator
struct max_heap
{
  bool operator()(Path const &p1, Path const &p2)
  {
    return p1.dep < p2.dep;
  }
};

struct min_heap
{
  bool operator()(Path const &p1, Path const &p2)
  {
    return p1.arr > p2.arr;
  }
};

int main()
{
  int n, m;
  cin >> n >> m;

  vector<priority_queue<Path, vector<Path>, max_heap>> graph(n);

  vector<int> layovers(n);

  for (int i = 0; i < m; i++)
  {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    a--; c--;
    graph[a].push({a, c, b, d});
  }

  for (auto &a : layovers)
  {
    cin >> a;
  }

  // // print graph
  // for (int i = 0; i < n; i++)
  // {
  //   cout << "Airport " << i << endl;
  //   while (!graph[i].empty())
  //   {
  //     Path cur = graph[i].top();
  //     graph[i].pop();
  //     cout << cur.start << " " << cur.end << " " << cur.dep << " " << cur.arr << endl;
  //   }
  // }




  vector<int> lowest_arrival(n, 1e9);

  // we need to store the Path in the priority queue

  priority_queue<Path, vector<Path>, min_heap> cur_flights;

  while (!graph[0].empty())
  {
    cur_flights.push(graph[0].top());
    graph[0].pop();
  }
  lowest_arrival[0] = 0;

  while (!cur_flights.empty())
  {
    Path cur = cur_flights.top();
    cur_flights.pop();

    // update lowest arrival
    lowest_arrival[cur.end] = min(lowest_arrival[cur.end], cur.arr);


    // add items to cur_flights from graph[cur.end]
    int cur_time = cur.arr + layovers[cur.end];

    while (!graph[cur.end].empty())
    {
      Path cur_item = graph[cur.end].top();
      if (cur_item.dep < cur_time)
      {
        break;
      }

      graph[cur.end].pop();

      cur_flights.push(cur_item);
    }
  }

  for (int i = 0; i < n; i++)
  {
    if (lowest_arrival[i] == 1e9)
    {
      cout << -1 << endl;
    }
    else
    {
      cout << lowest_arrival[i] << endl;
    }
  }
}

