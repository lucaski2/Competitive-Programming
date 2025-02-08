#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mod = 1000000000 + 7;
const char en = '\n';


template<typename T> optional<T> less_or_equal(const set<T>& s, const T& value) { if (s.empty()) { return nullopt; } auto it = s.upper_bound(value); if (it == s.begin()) { return nullopt; }return *prev(it);}

int pow(int a, int b, int m){
    int ans = 1;
    while(b){
        if (b&1) ans = (ans*a) % m;
        b /= 2;
        a = (a*a) % m;
    }
    return ans;
}

bool comp(pair<int, int> a, pair<int, int> b)
{
  return a.second > b.second;
}

void solve(int tc)
{
  int n, k;
  cin >> n >> k;
  vector<int> a(n), b(n);
  vector<int> nums(n * 2);
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
    nums[i] = a[i];
  }
  for (int i = 0; i < n; i++)
  {
    cin >> b[i];
    nums[i + n] = b[i];
  }
  sort(nums.begin(), nums.end());
  int ans = 0;
  
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> good_pq;
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> bad_pq;

  for (int i = 0; i < n; i++)
  {
    good_pq.push({a[i], i});
  }
  for (int num : nums)
  {
    while (!good_pq.empty() && good_pq.top().first < num)
    {
      auto [val, idx] = good_pq.top();
      good_pq.pop();
      bad_pq.push({b[idx], idx});
    }
    
    while (!bad_pq.empty() && bad_pq.top().first < num)
    {
      auto [val, idx] = bad_pq.top();
      bad_pq.pop();
    }

    if (bad_pq.size() > k)
    {
      continue;
    }
    ans = max(ans, num * (int)(good_pq.size() + bad_pq.size()));
  }



  cout << ans << endl;

}

signed main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  for (int i = 1; i <= t; i++)
  {
    solve(i);
  }
}