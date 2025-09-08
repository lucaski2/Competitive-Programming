#include <iostream>
#include <vector>
using namespace std;
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> p(n);
        for (int i = 0; i < n; i++){
            cin >> p[i];
        }
        
        // pos[i] will store the index (0-indexed) of element i in p.
        // Since the permutation contains 1..n, we create an array of size n+1.
        vector<int> pos(n+1);
        for (int i = 0; i < n; i++){
            pos[p[i]] = i;
        }
        
        // Count the number of blocks (contiguous segments in the order 1,2,...,n)
        int blocks = 1;
        for (int i = 1; i < n; i++){
            if (pos[i+1] < pos[i])
                blocks++;
        }
        
        // The answer is the number of blocks minus one.
        cout << blocks - 1 << "\n";
    }
    return 0;
}
