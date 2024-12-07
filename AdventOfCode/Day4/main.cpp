//
// Created by lever on 12/3/2024.
//
#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define iter(i, n) for(int i = 0; i < n; i++)
#define rngIt(n, m, s) if(n>m){for(int i = n-1; i >= m-1; i-=s)}else{for(int i = n; i < m; i+=s)}
#define it(arr) for(ll i : arr) std::cout << i << ' '; cout << '\n';
#define printl(s) cout<<s<<endl;
#define endl "\n";
vector<string> split(string s, string delimiters) {
    set<char> delim(delimiters.begin(), delimiters.end());
    string now = "";
    vector<string> ret;
    for (auto c : s) {
        if (delim.count(c)) {
            if (now != "")
                ret.push_back(now);
            now = "";
        } else {
            now += c;
        }
    }
    if (now != "")
        ret.push_back(now);
    return ret;
}
static string read(istream &stream, uint32_t count)
{
    auto bytes = unique_ptr<char[]>(new char[count]);
    stream.read(bytes.get(), count);
    return string(bytes.get(), count);
}
void test()
{
    int n = 140;
    vector<vector<char>>grid(n,vector<char>(n));
    iter(i,n)
    {
        string s; cin>>s;
        iter(j,n)
        {
            grid[i][j]=s[j];
        }
    }
    ll ct = 0;
    iter(i,n)
    {
        iter(j,n-3) {
            if(grid[i][j]=='X'&&grid[i][j+1]=='M'&&grid[i][j+2]=='A'&&grid[i][j+3]=='S')
                ct++;
            if(grid[i][j+3]=='X'&&grid[i][j+2]=='M'&&grid[i][j+1]=='A'&&grid[i][j]=='S')
                ct++;
        }
    }
    iter(j,n)
    {
        iter(i,n-3)
        {
            if(grid[i][j]=='X'&&grid[i+1][j]=='M'&&grid[i+2][j]=='A'&&grid[i+3][j]=='S')
                ct++;
            if(grid[i+3][j]=='X'&&grid[i+2][j]=='M'&&grid[i+1][j]=='A'&&grid[i][j]=='S')
                ct++;
        }
    }
    iter(i,n-3)
    {
        iter(j,n-3)
        {
            if(grid[i][j]=='X'&&grid[i+1][j+1]=='M'&&grid[i+2][j+2]=='A'&&grid[i+3][j+3]=='S')
                ct++;
            if(grid[i+3][j+3]=='X'&&grid[i+2][j+2]=='M'&&grid[i+1][j+1]=='A'&&grid[i][j]=='S')
                ct++;
        }
    }
    iter(i,n-3)
    {
        iter(j,n)
        {
            if(j<3)continue;
            if(grid[i][j]=='X'&&grid[i+1][j-1]=='M'&&grid[i+2][j-2]=='A'&&grid[i+3][j-3]=='S')
                ct++;
            if(grid[i+3][j-3]=='X'&&grid[i+2][j-2]=='M'&&grid[i+1][j-1]=='A'&&grid[i][j]=='S')
                ct++;
        }
    }
    //printl(ct)
    //pt2
    int ct2 = 0;
    iter(i,n-1)
    {
        if(i==0)continue;
        iter(j,n-1) {
            if (j == 0)continue;
            if (grid[i][j] != 'A')continue;
            set<char> s;
            set<char> s2;
            s.insert(grid[i - 1][j + 1]);
            s.insert(grid[i + 1][j - 1]);
            s2.insert(grid[i - 1][j - 1]);
            s2.insert(grid[i + 1][j + 1]);
            if (s.count('M') && s.count('S') && s2.count('M') && s2.count('S')) {
                ct2++;
                // printl(i<<" "<<j);
            }
        }
    }
    printl(ct2)
}
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    test();
    return 0;
}