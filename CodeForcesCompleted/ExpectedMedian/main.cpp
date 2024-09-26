#include <iostream>
#include <vector>
#include <algorithm>

const long long mod = 1e9 + 7;

long long pow_mod(long long base, long long exp, long long modulus) {
    long long result = 1;
    base %= modulus;
    while (exp > 0) {
        if (exp & 1) result = (result * base) % modulus;
        base = (base * base) % modulus;
        exp >>= 1;
    }
    return result;
}

long long mod_comb(int n, int k) {
    if (n < k) return 0;
    long long acc = 1;
    for (int i = n - k + 1; i <= n; ++i) {
        acc = (acc * i) % mod;
    }
    for (int i = 1; i <= k; ++i) {
        acc = (acc * pow_mod(i, mod - 2, mod)) % mod;
    }
    return acc;
}

int main() {
    int t;
    std::cin >> t;
    
    while (t--) {
        int n, k;
        std::cin >> n >> k;
        
        std::vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            std::cin >> a[i];
        }
        
        int ones = std::count(a.begin(), a.end(), 1);
        int zeros = std::count(a.begin(), a.end(), 0);
        
        long long s = 0;
        for (int i = 0; i <= k / 2; ++i) {
            s += (mod_comb(ones, k - i) % mod) * (mod_comb(zeros, i) % mod) % mod;
            s %= mod;
        }
        
        std::cout << s << std::endl;
    }
    
    return 0;
}