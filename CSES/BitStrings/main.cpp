#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;

long long modpow(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b % 2 == 1) {
            res = (res * a) % MOD;
        }
        a = (a * a) % MOD;
        b /= 2;
    }
    return res;
}

int main() {
    int n;
    cin >> n;
    vector<long long> factorial(n + 1);
    factorial[0] = 1;
    for (int i = 1; i <= n; i++) {
        factorial[i] = (factorial[i - 1] * i) % MOD;
    }
    
    vector<long long> inv(n + 1);
    for (int i = 0; i <= n; i++) {
        inv[i] = modpow(factorial[i], MOD - 2);
    }

    
    long long ans = 0;

    for (int i = 0; i <= n; i++)
    {
        ans += (factorial[n] * inv[i] % MOD * inv[n - i] % MOD) % MOD;
        ans %= MOD;
    }
    cout << ans << endl;
}