#include <bits/stdc++.h>
#include <iostream>
#define ll long long
using namespace std;

bool check_bingo(vector<vector<int> > &board, int row, int col) {
    bool bingo = true;
    for (int i = 0; i < board.size(); i++) {
        if (board[row][i] != 1) {
            bingo = false;
            break;
        }
    }
    if (bingo) return true;
    bingo = true;
    for (int i = 0; i < board.size(); i++) {
        if (board[i][col] != 1) {
            bingo = false;
            break;
        }
    }
    if (bingo) return true;

    bingo = true;

    for (int i = 0; i < board.size(); i++)
    {
        if (board[i][i] != 1) {
            bingo = false;
            break;
        }
    }
    if (bingo) return true;
    bingo = true;

    for (int i = 0; i < board.size(); i++)
    {
        if (board[i][board.size() - i - 1] != 1) {
            bingo = false;
            break;
        }
    }
    if (bingo) return true;
    return false;
}

int main()
{
    int n, t;
    cin >> n >> t;
    vector<vector<int> > board(n, vector<int>(n));

    vector<ll> a(t);

    for (int i = 0; i < t; i++)
    {
        cin >> a[i];
        int x = (a[i] - 1) / n;
        int y = (a[i] - 1) % n;
        board[x][y] = 1;
        if (check_bingo(board, x, y)) {
            cout << i + 1 << endl;
            return 0;
        }
    }
    cout << -1 << endl;
}