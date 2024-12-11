#include <bits/stdc++.h>
#define ll long long
#define mint 2147483647
#define mod 1e9 + 7
#define en '\n'
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ifstream cin("badmilk.in");
    ofstream cout("badmilk.out");

    int n, m, d, s;
    cin >> n >> m >> d >> s;

    vector<vector<pair<int, int>>> drinks(n);
    for (int i = 0; i < d; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        drinks[a].push_back({c, b});
    }

    for (int i = 0; i < n; i++) {
        sort(drinks[i].begin(), drinks[i].end());
    }

    map<int, int> sickness_time;

    for (int i = 0; i < n; i++) {
        sickness_time[i] = mint;
    }

    for (int i = 0; i < s; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        sickness_time[a] = b;
    }

    int max_doses = 0;

    for (int milk = 0; milk < m; milk++) {
        // Can milk be used
        bool glob_ok = true;
        int people = 0;
        for (int person = 0; person < n; person++) {
            // See if they had the milk, and when they had the milk
            int s_time = sickness_time[person];
            int discovery_time = -1;
            for (pair<int, int> drink : drinks[person]) {
                if (drink.second == milk) {
                    people++;
                    discovery_time = drink.first;
                    break;
                }
            }
            if (s_time <= discovery_time || (discovery_time == -1 && s_time != mint)) {
                glob_ok = false;
            }
        }
        max_doses = max(glob_ok * people, max_doses);
    }
    cout << max_doses << endl;

    return 0;
}
