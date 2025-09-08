#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define int long long
#define dbl long double
#define all(x) (x).begin(), (x).end()
using namespace std;
using namespace __gnu_pbds;
template<class T> using ost = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int MOD = 1000000007;
const char nl = '\n';

int ds(int a, int b){ return a + b; }

struct Info { int x, y, cnt; };

bool cmp(Info a, Info b) {
  int da = a.x + a.y, db = b.x + b.y;
  if(da != db) return da < db;
  if(a.x != b.x) return a.x < b.x;
  return a.y < b.y;
}

int MX = 16e4;
vector<Info> tbl(MX);
vector<tuple<int, int, int>> st(MX * 4);

bool cmp2(tuple<int, int, int> a, tuple<int, int, int> b){
  int da = get<0>(a) + get<1>(a), db = get<0>(b) + get<1>(b);
  if(da != db) return da < db;
  if(get<0>(a) != get<0>(b)) return get<0>(a) < get<0>(b);
  return get<1>(a) < get<1>(b);
}

void pre() {
  int s = sqrt(MX);
  for (int i = 0; i < s; i++){
    for (int j = 0; j < s; j++){
      int id = i * s + j;
      tbl[id] = {3 * i + 1, 3 * j + 1, 0};
      st[id * 4]     = {3 * i + 1, 3 * j + 1, id};
      st[id * 4 + 1] = {3 * i + 1, 3 * j + 2, id};
      st[id * 4 + 2] = {3 * i + 2, 3 * j + 1, id};
      st[id * 4 + 3] = {3 * i + 2, 3 * j + 2, id};
    }
  }
  sort(tbl.begin(), tbl.end(), cmp);
  sort(st.begin(), st.end(), cmp2);
}

struct Info2 {
  int e, x, y, id;
};

struct cmp3 {
  bool operator()(const Info2 &a, const Info2 &b) const {
    if(a.e != b.e) return a.e < b.e;
    if(a.x != b.x) return a.x < b.x;
    if(a.y != b.y) return a.y < b.y;
    return a.id < b.id;
  }
};

int L;
vector<Info> sel;
vector<int> occ;
set<Info2, cmp3> s0, s1;
int nxt;

Info2 getInfo2(int id, int o) {
  int bx = sel[id].x, by = sel[id].y;
  Info2 k; k.id = id;
  if(o == 0){ k.e = bx + by; k.x = bx; k.y = by; }
  else if(o == 1){ k.e = bx + by + 1; k.x = bx; k.y = by + 1; }
  else if(o == 2){ k.e = bx + by + 1; k.x = bx + 1; k.y = by; }
  else { k.e = bx + by + 4; k.x = bx + 1; k.y = by + 1; }
  return k;
}

void solve(int tc) {
  int n; cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; i++) cin >> arr[i];
  
  L = min(n * 2LL, (int)tbl.size());
  sel.resize(L);
  occ.assign(L, 0);
  for (int i = 0; i < L; i++){
    sel[i] = tbl[i];
    occ[i] = 0;
  }
  
  s0.clear(); s1.clear();
  for (int i = 0; i < L; i++){
    s0.insert(getInfo2(i, 0));
  }
  nxt = L;
  
  for (int i = 0; i < n; i++){
    Info2 k;
    bool from0 = false;
    if(arr[i] == 0){
      while(s0.empty() && nxt < (int)tbl.size()){
        sel.push_back(tbl[nxt]);
        occ.push_back(0);
        s0.insert(getInfo2(sel.size()-1, 0));
        nxt++;
      }
      k = *s0.begin(); from0 = true;
    } else {
      Info2 a, b;
      bool has0 = !s0.empty(), has1 = !s1.empty();
      if(!has0 && !has1){
        while(nxt < (int)tbl.size()){
          sel.push_back(tbl[nxt]);
          occ.push_back(0);
          s0.insert(getInfo2(sel.size()-1, 0));
          nxt++;
          if(!s0.empty()) break;
        }
        has0 = !s0.empty();
      }
      if(has0 && has1){
        a = *s0.begin(); b = *s1.begin();
        k = cmp3()(a, b) ? a : b;
      } else if(has0) k = *s0.begin();
      else k = *s1.begin();
      from0 = (s0.find(k) != s0.end());
    }
    
    if(from0) s0.erase(k); else s1.erase(k);
    int id = k.id, o = occ[id];
    int rx, ry;
    int bx = sel[id].x, by = sel[id].y;
    if(o == 0){ rx = bx; ry = by; }
    else if(o == 1){ rx = bx; ry = by + 1; }
    else if(o == 2){ rx = bx + 1; ry = by; }
    else { rx = bx + 1; ry = by + 1; }
    cout << rx << " " << ry << nl;
    occ[id]++;
    if(occ[id] < 4) s1.insert(getInfo2(id, occ[id]));
  }
}

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t; cin >> t;
  pre();
  for (int i = 1; i <= t; i++){
    solve(i);
  }
}
