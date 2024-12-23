#include <bits/stdc++.h>
using ll = long long;
using namespace std;

const ll mod = 1000000000 + 7;
const char en = '\n';


template<typename T> optional<T> less_or_equal(const set<T>& s, const T& value) { if (s.empty()) { return nullopt; } auto it = s.upper_bound(value); if (it == s.begin()) { return nullopt; }return *prev(it);}

int gcd(int a, int b) 
{ 
    if (b == 0) 
        return a; 
    return gcd(b, a % b); 
}



bool coprime(int a, int b) 
{    
    return gcd(a, b) == 1;
} 

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  vector<pair<int, int>> coprime_pairs;

  for (int i = 1; i <= 1000; i++)
  {
    for (int j = i; j <= 1000; j++)
    {
      if (coprime(i, j))
      {
        coprime_pairs.push_back({i, j});
      }
    }
  }
  
  while (t--)
  {
    int n;
    cin >> n;
    map<int, int> a;
    for (int i = 0; i < n; i++)
    {
      int b;
      cin >> b;
      a[b] = i + 1;
    }
    int m = 0;
    for (pair<int, int> copr : coprime_pairs)
    {
      
      if (a.find(copr.first) == a.end() or a.find(copr.second) == a.end())
      {
        continue;
      }
      m = max(a[copr.first] + a[copr.second], m);
    }
    cout << ((m == 0) ? -1 : m) << en;
  }
}