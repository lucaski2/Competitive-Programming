#include <bits/stdc++.h>
using namespace std;
 
#define int long long
 
// Recursively generate all subset sums for 'arr' starting from 'index'
// with the current running sum 'current'. The results are stored in 'sums'.
void genSubsetSums(const vector<int>& arr, int index, int current, vector<int>& sums) {
    if(index == arr.size()){
        sums.push_back(current);
        return;
    }
    // Option 1: Do not include current element.
    genSubsetSums(arr, index + 1, current, sums);
    // Option 2: Include current element.
    genSubsetSums(arr, index + 1, current + arr[index], sums);
}
 
void solve() {
    int n, x;
    cin >> n >> x;
    
    // Read the entire array.
    vector<int> arr(n);
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    
    // Split the array into two halves.
    int mid = n / 2;
    vector<int> left(arr.begin(), arr.begin() + mid);
    vector<int> right(arr.begin() + mid, arr.end());
    
    // Generate all subset sums for both halves.
    vector<int> sumLeft, sumRight;
    genSubsetSums(left, 0, 0, sumLeft);
    genSubsetSums(right, 0, 0, sumRight);
    
    // Sort the sums from the second half so we can use binary search.
    sort(sumRight.begin(), sumRight.end());
    
    int ans = 0;
    // For each subset sum in the first half, look for a complement in the second half such that:
    // sumLeft + sumRight = x.
    for (auto s : sumLeft) {
        int target = x - s;
        // equal_range returns the range of elements equal to 'target'
        auto range = equal_range(sumRight.begin(), sumRight.end(), target);
        ans += (range.second - range.first);
    }
    
    // If both halves are empty (their sum equals 0) and x is 0, 
    // we subtract that case as a valid subset is required to be non-empty.
    if (x == 0)
        ans--;
 
    cout << ans << "\n";
}
 
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // For multiple test cases, uncomment the next line:
    // cin >> t;
    while(t--) {
        solve();
    }
}
