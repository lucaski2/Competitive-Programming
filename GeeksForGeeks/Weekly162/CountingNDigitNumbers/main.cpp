#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

class Solution {
private:
    long long power(long long x, long long y, long long p) {
        long long res = 1;
        x = x % p;
        while (y > 0) {
            if (y & 1)
                res = (res * x) % p;
            y = y >> 1;
            x = (x * x) % p;
        }
        return res;
    }

    bool miillerTest(long long d, long long n) {
        long long a = 2 + rand() % (n - 4);
        long long x = power(a, d, n);

        if (x == 1 || x == n - 1)
            return true;

        while (d != n - 1) {
            x = (x * x) % n;
            d *= 2;

            if (x == 1)
                return false;
            if (x == n - 1)
                return true;
        }

        return false;
    }

public:
    bool isPrime(long long n, int k) {
        if (n <= 1 || n == 4)
            return false;
        if (n <= 3)
            return true;

        long long d = n - 1;
        while (d % 2 == 0)
            d /= 2;

        for (int i = 0; i < k; i++)
            if (!miillerTest(d, n))
                return false;

        return true;
    }

    bool not_prime(int n) {
        if (n == 1)
            return true;
        for (int i = 2; i <= sqrt(n); i++)
            if (n % i == 0)
                return true;
        return false;
    }

    int maximumSum(int n, int k) {
        long long s = 0;
        int cur = (n % 2 == 1) ? n : n - 1;
        int num = 0;
        while (cur > 0 && num < k) {
            if (!isPrime(cur, 5)) {
                s += cur;
                num++;
            }
            cur -= 2;
        }
        return (num == k) ? s : -1;
    }
};


int main() {
    srand(time(0));  // Seed for random number generation
    int t;
    t = 1;
    for (int i = 0; i < t; i++) {
        int n, k;
        cin >> n >> k;
        Solution obj;
        int res = obj.maximumSum(n, k);
        cout << res << endl;
    }
    return 0;
}