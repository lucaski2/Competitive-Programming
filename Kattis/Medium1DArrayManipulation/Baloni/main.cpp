#include <iostream>
#include <vector>
using namespace std;

int arrows[1000009];
vector<int> arr;
int main(){
    int n; 
    cin >> n;
    arr.resize(n);
    for (int i=0; i<n; ++i){
        cin >> arr[i];
    }

    int ans = 0;
    for (auto c: arr){
        if (arrows[c] == 0){
            ans++;
        }
        else{
            arrows[c]--;
        }
        if (c == 1) continue;
        arrows[c-1] += 1;
    }
    cout << ans << endl;
    return 0;
}