#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, q;
        cin >> n >> q;
        string a, b;
        cin >> a >> b;

        vector<pair<pair<int, int>, int> > queries(q);
        for (int i = 0; i < q; i++) {
            cin >> queries[i].first.first >> queries[i].first.second;
            queries[i].second = i;
            queries[i].first.first--;
            queries[i].first.second--;
        }

        sort(queries.begin(), queries.end());

        pair<int, int> cur_range = queries[0].first;
        vector<int> cur_diffs(26, 0);
        string alphabet = "abcdefghijklmnopqrstuvwxyz";

        for (int i = cur_range.first; i <= cur_range.second; i++) {
            cur_diffs[alphabet.find(a[i])]++;
            cur_diffs[alphabet.find(b[i])]--;
        }

        vector<int> out(q, 0);

        for (int i = 0; i < q; i++) {
            if (cur_range.first < queries[i].first.first) {
                for (int j = cur_range.first; j < queries[i].first.first; j++) {
                    cur_diffs[alphabet.find(a[j])]--;
                    cur_diffs[alphabet.find(b[j])]++;
                }
            }
            if (cur_range.second > queries[i].first.second) {
                for (int j = queries[i].first.second + 1; j <= cur_range.second; j++) {
                    cur_diffs[alphabet.find(a[j])]--;
                    cur_diffs[alphabet.find(b[j])]++;
                }
            }
            if (cur_range.second < queries[i].first.second) {
                for (int j = cur_range.second + 1; j <= queries[i].first.second; j++) {
                    cur_diffs[alphabet.find(a[j])]++;
                    cur_diffs[alphabet.find(b[j])]--;
                }
            }

            cur_range = queries[i].first;
            int s1 = 0, s2 = 0;
            for (int cur : cur_diffs) {
                if (cur > 0) {
                    s1 += abs(cur);
                } else {
                    s2 += abs(cur);
                }
            }
            out[queries[i].second] = min(s1, s2) + abs(s1 - s2);
        }

        for (int o : out) {
            cout << o << endl;
        }
    }
    return 0;
}