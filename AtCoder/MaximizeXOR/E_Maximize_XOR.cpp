#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long

using namespace std;

// Helper function to generate combinations
void generate_combinations(vector<vector<ll>>& result, vector<ll>& current, ll n, ll k, ll start) {
    if (current.size() == k) {
        result.push_back(current);
        return;
    }
    
    for (ll i = start; i < n; i++) {
        current.push_back(i);
        generate_combinations(result, current, n, k, i + 1);
        current.pop_back();
    }
}

vector<vector<ll>> combinations(ll n, ll k) {
    vector<vector<ll>> result;
    vector<ll> current;
    generate_combinations(result, current, n, k, 0);
    return result;
}

int main() {
    ll n, k;
    cin >> n >> k;
    
    vector<ll> a(n);
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    ll ans = 0;
    if (k <= n / 2) {
        // Generate all combinations of size k
        vector<vector<ll>> combs = combinations(n, k);
        
        // Process each combination
        for (const auto& comb : combs) {
            ll cur = 0;
            for (ll num : comb) {
                cur ^= a[num];
            }
            ans = max(cur, ans);
        }
    } else {
        // Calculate full XOR of all elements
        ll full_xor = 0;
        for (ll i = 0; i < n; i++) {
            full_xor ^= a[i];
        }
        
        // Generate combinations of size (n-k)
        vector<vector<ll>> combs = combinations(n, n - k);
        
        // Process each combination
        for (const auto& comb : combs) {
            ll cur = full_xor;
            for (ll num : comb) {
                cur ^= a[num];
            }
            ans = max(cur, ans);
        }
    }
    
    cout << ans << endl;
    return 0;
}