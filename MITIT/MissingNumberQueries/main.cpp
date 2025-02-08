#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N, Q; cin >> N >> Q;
    vector<int> arr(N);
    vector<int> appear(N);
    for (int i = 0; i < N; i++) {
        int x; cin >> x; x--;
        arr[i] = x;
        appear[x]++;
    }
    int notappear = -1;
    for (int i = 0; i < N; i++) {
        if (!appear[i]) { notappear = i; }
    }
    for (int q = 0; q < Q; q++) {
        int t; cin >> t;
        if (t == 2) {
            int l, r; cin >> l >> r; l--; r--;
            if (notappear != -1) { cout << notappear + 1 << "\n"; }
            else if (l > 0) { cout << arr[l-1] << "\n"; }
            else { cout << arr[r+1] << "\n"; }
        }   else {
            int i, y; cin >> i >> y; i--;
            appear[arr[i]]--;
            if (appear[arr[i]] == 0) { notappear = arr[i]; }
            arr[i] = y;
            appear[arr[i]]++;
        }
    }
    //if not then just output -1 or + 1
}