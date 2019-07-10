#include <algorithm>
#include <cstring>
#include <climits>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include <sstream>


#include "../utils/VectorUtils.hpp"
#include "../utils/PrintUtils.hpp"

// https://leetcode.com/problems/available-captures-for-rook/

// #include "../utils/HeapUtils.hpp"
// #include "../utils/BinarySearch.hpp"
// #include "../utils/TreeUtils.hpp"

using namespace std;

#pragma GCC diagnostic ignored "-Wunknown-pragmas"

// Live coding problems, watch at
// https://www.twitch.tv/yipcubed
// https://www.youtube.com/channel/UCTV_UOPu7EWXvYWsBFxMsSA/videos
//

// makes code faster, but larger. Just for LeetCode fun!
#pragma GCC optimise ("Ofast")

// makes stdin not synced so it is faster. Just for LeetCode fun!
static auto __ __attribute__((unused)) = []() {              // NOLINT
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    void findRook(vector<vector<char>>& board, int& row, int& col) {
        for (int r = 0; r < 8; ++r) {
            for (int c = 0; c < 8; ++c) {
                if (board[r][c] == 'R') {
                    row = r;
                    col = c;
                    return;
                }
            }
        }
        assert("Bad board");
    }

    void checkPosition(char c) {
        switch (c) {
            case '.': break;
            case 'p': break;
            case 'B': break;
        }
    }
    int numRookCaptures(vector<vector<char>>& board) {
        int row, col;
        findRook(board, row, col);
        int capture = 0;
        for (int c = col + 1; c < 8 && board[row][c] != 'B'; ++c) {
            if (board[row][c] == 'p') {
                ++capture;
                break;
            }
        }
        for (int c = col - 1; c >= 0 && board[row][c] != 'B'; --c) {
            if (board[row][c] == 'p') {
                ++capture;
                break;
            }
        }
        for (int r = row + 1; r < 8 && board[r][col] != 'B'; ++r) {
            if (board[r][col] == 'p') {
                ++capture;
                break;
            }
        }
        for (int r = row - 1; r >= 0 && board[r][col] != 'B'; --r) {
            if (board[r][col] == 'p') {
                ++capture;
                break;
            }
        }
        return capture;
    }
};

void test1() {
    vector<vector<char>> v1  {
            {'.','.','.','.','.','.','.','.'},
            {'.','.','.','p','.','.','.','.'},
            {'.','.','.','R','.','.','.','p'},
            {'.','.','.','.','.','.','.','.'},
            {'.','.','.','.','.','.','.','.'},
            {'.','.','.','p','.','.','.','.'},
            {'.','.','.','.','.','.','.','.'},
            {'.','.','.','.','.','.','.','.'}
    };

    cout << " ? " << Solution().numRookCaptures(v1) << endl;
}

void test2() {

}

void test3() {

}