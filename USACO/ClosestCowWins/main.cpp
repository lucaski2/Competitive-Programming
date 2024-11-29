#include <bits/stdc++.h>
#define ll long long
#define mod 1e9 + 7
#define en '\n'
using namespace std;

bool comp(tuple<ll, ll, ll> &a, tuple<ll, ll, ll> &b)
{
  // comparison for max heap
  return get<0>(a) < get<0>(b);
}

// function to find the item less than the key given
ll find_less(map<double, pair<ll, ll>> &cur_patches, double key)
{
  auto it = cur_patches.lower_bound(key);
  if (it == cur_patches.begin())
    // if not found, return last element
    return (--cur_patches.end())->second.second;
  
  // if found, return the previous element
  return (--it)->second.second;
}

void solve()
{
  ll k, m, n;
  cin >> k >> m >> n;

  vector<pair<ll, ll>> patches(k);
  vector<ll> cows(m);
  for (ll i = 0; i < k; ++i)
    cin >> patches[i].first >> patches[i].second;
  for (ll i = 0; i < m; ++i)
    cin >> cows[i];

  sort(patches.begin(), patches.end());
  sort(cows.begin(), cows.end());

  // max partial then max full
  vector<pair<ll, ll>> maxes;

  // placement in number line, then pair of amount of food and prefix sum index
  map<double, pair<ll, ll>> cur_patches;
  ll prev = -2e9;

  for (ll patch = 0, cow = 0; patch < k or cow < m;)
  {
    if (cow >= m or (patch < k and patches[patch].first < cows[cow]))
    {
      cur_patches[patches[patch].first] = {patches[patch].second, cur_patches.size()};
      patch++;
    }
    else
    {
      if (!cur_patches.empty())
      {
        // find sum
        ll full = 0;
        for (auto item : cur_patches)
        {
          full += item.second.first;
        }

        // create prefix sum
        vector<ll> prefix_sum;
        prefix_sum.push_back(0);
        for (auto item : cur_patches)
        {
          prefix_sum.push_back(prefix_sum.back() + item.second.first);
        }


        // find max with one cow
        ll max_part = 0;
        for (auto item : cur_patches)
        {
          double bound = item.first + (cows[cow] - prev) / 2.0;
          ll less = find_less(cur_patches, bound);
          ll sum = prefix_sum[less + 1] - prefix_sum[item.second.second];
          max_part = max(max_part, sum);  
        }
        maxes.push_back({max_part * 2, full});
      }

      prev = cows[cow];
      cow++;
      cur_patches.clear();
    }
  }

  if (!cur_patches.empty())
  {
    ll full = 0;
    for (auto item : cur_patches)
    {
      full += item.second.first;
    }
    maxes.push_back({full * 2, full});
  }

  // for (auto it : maxes)
  // {
  //   cout << it.first << " " << it.second << en;
  // }


  vector<tuple<ll, ll, ll>> heap;
  ll ans = 0;
  
  for (int i = 0; i < maxes.size(); ++i)
  {
    heap.push_back({max(maxes[i].first, maxes[i].second), i, maxes[i].first >= maxes[i].second});
  }

  make_heap(heap.begin(), heap.end(), comp);

  while (n > 1)
  {
    tuple<ll, ll, ll> top = heap.front();
    pop_heap(heap.begin(), heap.end(), comp);
    heap.pop_back();
    // cout << get<0>(top) << " " << get<1>(top) << " " << get<2>(top) << endl;

    if (get<2>(top) == 1)
    {
      ans += get<0>(top) / 2;
      heap.push_back({(maxes[get<1>(top)].second - get<0>(top) / 2) * 2, get<1>(top), 2}); // 2 is for the final type
      push_heap(heap.begin(), heap.end(), comp);
    }
    else if (get<2>(top) == 0)
    {
      ans += get<0>(top);
      n -= 1;
    }
    else
    {
      ans += get<0>(top) / 2;
    }

    n--;
  }
  if (n == 1)
  {
    while (!heap.empty())
    {
      tuple<ll, ll, ll> top = heap.front();
      pop_heap(heap.begin(), heap.end(), comp);
      heap.pop_back();

      if (get<2>(top) != 0)
      {
        ans += get<0>(top) / 2;
        break;
      }

    }
  }

  cout << ans << en;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
}
