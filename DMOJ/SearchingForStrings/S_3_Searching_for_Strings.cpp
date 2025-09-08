#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define int long long
#define double long double
#define all(a) (a).begin(), (a).end()
#define f first 
#define s second

using namespace std;
using namespace __gnu_pbds;

// Define the modulus M = 2^61 - 1
static const unsigned long long M = ((1ULL << 61) - 1);

// Use __int128 for safe multiplication
inline unsigned long long modMul(unsigned long long a, unsigned long long b) {
    unsigned __int128 t = (unsigned __int128)a * b;
    // Split and reduce: high part plus low part thanks to Mersenne property: 2^61 ≡ 1 (mod M)
    t = (t >> 61) + (t & M);
    if (t >= M) t -= M;
    return (unsigned long long)t;
}

template<class T> using ost = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

// Problem URL here:
// Start time here: 
// End time here:

const char en = '\n';

struct mi {
  unsigned long long v;
  mi() : v(0) {}
  mi(long long _v) {
    // Fix negative values and make sure 0 <= v < M
    _v %= (long long)M;
    if (_v < 0) _v += M;
    v = _v;
  }
  
  // Addition operator modulo M
  friend mi operator+(const mi& a, const mi& b) {
    unsigned long long s = a.v + b.v;
    if (s >= M) s -= M;
    return mi(s);
  }
  
  // Subtraction operator modulo M
  friend mi operator-(const mi& a, const mi& b) {
    unsigned long long s = (a.v + M - b.v);
    if (s >= M) s -= M;
    return mi(s);
  }
  
  // Multiplication operator using __int128 multiplication
  friend mi operator*(const mi& a, const mi& b) {
    return mi((long long)modMul(a.v, b.v));
  }
  
  // Binary exponentiation modulo M
  friend mi pow(mi a, int p) { 
    mi ans(1);
    while(p > 0) { 
      if(p & 1) ans = ans * a; 
      a = a * a; 
      p /= 2;
    }
    return ans;
  }
  
  // Modular inverse using Fermat's little theorem (M is prime)
  friend mi inv(const mi& a) { 
    return pow(a, M - 2); 
  }
  
  friend mi operator/(mi a, const mi& b) { 
    return a * inv(b); 
  }
  
  mi& operator+=(const mi& o) { 
    return (*this) = (*this) + o; 
  }
  
  mi& operator-=(const mi& o) { 
    return (*this) = (*this) - o; 
  }
  
  mi& operator*=(const mi& o) { 
    return (*this) = (*this) * o; 
  }
  
  mi& operator/=(const mi& o) { 
    return (*this) = (*this) / o; 
  }
};

int pow(int a, int b, int m){ 
  int ans = 1; 
  while(b) { 
    if (b & 1) ans = (ans * a) % m; 
    b /= 2; 
    a = (a * a) % m; 
  } 
  return ans; 
}

int factorial(int n) { 
  int am = 1; 
  for (int i = 1; i <= n; i++) 
    am = (am * i) % M; 
  return am; 
}

int choose(int n, int k) { 
  return (factorial(n) * pow(factorial(k), M - 2, M)) % M * pow(factorial(n - k), M - 2, M) % M; 
}

int permute(int n, int k) { 
  return (factorial(n) * pow(factorial(n - k), M - 2, M)) % M; 
}

struct DSU {
  vector<int> e; 
  void init(int N) { 
    e = vector<int>(N, -1); 
  }
  int get(int x) { 
    return e[x] < 0 ? x : e[x] = get(e[x]); 
  } 
  bool sameSet(int a, int b) { 
    return get(a) == get(b); 
  }
  int size(int x) { 
    return -e[get(x)]; 
  }
  bool unite(int x, int y) { // union by size
    x = get(x), y = get(y); 
    if (x == y) return false;
    if (e[x] > e[y]) swap(x, y);
    e[x] += e[y]; 
    e[y] = x; 
    return true;
  }
};

struct Seggy {
  int len;
  vector<int> seggy;
  int DEFAULT;
  int combine(int a, int b) { 
    return a + b; 
  }
  Seggy(int n, int DEFAULT) : len(n), DEFAULT(DEFAULT) {
    seggy = vector<int>(n * 2, INT64_MAX);
  }
  
  void add(int ind, int am) {
    for (ind += len; ind > 0; ind /= 2) 
      seggy[ind] = combine(seggy[ind], am);
  }
  
  int query(int l, int r, int cur_l, int cur_r, int ind) {
    if (cur_l >= l && cur_r <= r) 
      return seggy[ind];
    if (cur_l > r || cur_r < l) 
      return DEFAULT;
    int mid = (cur_l + cur_r) / 2;
    return combine(query(l, r, cur_l, mid, ind * 2), query(l, r, mid + 1, cur_r, ind * 2 + 1));
  }
};

void solve(int tc) {
  string t, s;
  cin >> t >> s;
  int m = t.size(), n = s.size();
  
  vector<int> t_cnt(26);
  vector<int> cnts(26);
  mi hash;
  set<unsigned long long> ans;
  
  for (int i = 0; i < m; i++)
    t_cnt[t[i] - 'a']++;
  
  for (int i = 0; i < m; i++) {
    cnts[s[i] - 'a']++;
    hash += mi(s[i] - 'a') * pow(mi(26), i);
  }
  
  auto ch = [&]() -> bool {
    for (int i = 0; i < 26; i++)
      if (t_cnt[i] != cnts[i])
        return false;
    return true;
  };
  
  if (ch()) 
    ans.insert(hash.v);
  
  for (int i = m; i < n; i++) {
    cnts[s[i - m] - 'a']--;
    cnts[s[i] - 'a']++;
    
    // Remove s[i-m]'s contribution and update hash similar to a rolling hash:
    hash -= mi(s[i - m] - 'a');
    // Multiply hash by modular inverse of base 26 (i.e. divide by 26)
    hash *= pow(mi(26), M - 2);  // Using Fermat's little theorem since M is prime
    // Add the new character at the high order position (i.e. at power m-1)
    hash += pow(mi(26), m - 1) * mi(s[i] - 'a');
    
    if (ch()) 
      ans.insert(hash.v);
  }
  
  cout << ans.size() << "\n";
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  
  int t = 1;
  // cin >> t;
  for (int i = 1; i <= t; i++) {
    solve(i);
  }
}
