#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

typedef std::pair<int, int> Cell;
typedef std::vector<std::vector<Cell> > Board;

const int INF = std::numeric_limits<int>::max();

int get_winner(const Board& board) {
    int neg = 0, pos = 0;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j].second == 1) {
                pos += board[i][j].first;
            } else if (board[i][j].second == -1) {
                neg += board[i][j].first;
            }
        }
    }

    bool all_filled = true;
    for (int i = 0; i < 3 && all_filled; ++i) {
        for (int j = 0; j < 3 && all_filled; ++j) {
            if (board[i][j].second == 0) {
                all_filled = false;
            }
        }
    }
    if (all_filled) {
        return (neg > pos) ? -1 : 1;
    }

    for (int i = 0; i < 3; ++i) {
        int row_sum = board[i][0].second + board[i][1].second + board[i][2].second;
        if (row_sum == 3) return 1;
        if (row_sum == -3) return -1;
    }

    for (int j = 0; j < 3; ++j) {
        int col_sum = board[0][j].second + board[1][j].second + board[2][j].second;
        if (col_sum == 3) return 1;
        if (col_sum == -3) return -1;
    }

    int diag1 = board[0][0].second + board[1][1].second + board[2][2].second;
    int diag2 = board[0][2].second + board[1][1].second + board[2][0].second;

    if (diag1 == 3 || diag2 == 3) return 1;
    if (diag1 == -3 || diag2 == -3) return -1;

    return 0;
}

int minimax(Board& board, int player) {
    int winner = get_winner(board);
    if (winner != 0) {
        return winner;
    }

    if (player == 1) {
        int best = -10;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (board[i][j].second == 0) {
                    board[i][j].second = 1;
                    best = std::max(best, minimax(board, -1));
                    board[i][j].second = 0;
                }
            }
        }
        return best;
    } else {
        int best = 10;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (board[i][j].second == 0) {
                    board[i][j].second = -1;
                    best = std::min(best, minimax(board, 1));
                    board[i][j].second = 0;
                }
            }
        }
        return best;
    }
}

int main() {
    Board board(3, std::vector<Cell>(3));
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            int value;
            std::cin >> value;
            board[i][j] = std::make_pair(value, 0);
        }
    }

    if (minimax(board, 1) == 1) {
        std::cout << "Takahashi" << std::endl;
    } else {
        std::cout << "Aoki" << std::endl;
    }

    return 0;
}