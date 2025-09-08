#include <iostream>
#include <vector>
#include <string>
using namespace std;

void build(vector<vector<char>> &o, int n) {
    for (int i = 1; i <= n; i++){
        string s;
        cin >> s;
        for (int j = 1; j <= i; j++){
            o[i][j] = s[j-1];
        }
    }
    for (int i = 1; i <= n; i++){
        for (int j = i+1; j <= n; j++){
            if(o[j][i]=='W')
                o[i][j] = 'L';
            else if(o[j][i]=='L')
                o[i][j] = 'W';
            else
                o[i][j] = 'D';
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    cin >> n >> m;
    vector<vector<char>> o(n+1, vector<char>(n+1, ' '));
    
    build(o, n);
    
    for (int k = 0; k < m; k++){
        int a, b;
        cin >> a >> b;
        int v = 0;
        for (int x = 1; x <= n; x++){
            if(o[x][a]=='W' && o[x][b]=='W')
                v++;
        }
        int r = n*n - (n - v)*(n - v);
        cout << r << "\n";
    }
    
    return 0;
}
