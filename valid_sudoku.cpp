#include <bits/stdc++.h>
using namespace std;

int checkRows(vector<vector<char>>& board) {
    unordered_map<char, char> mp;
    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 9; j++) {
            if(board[i][j] != '.' && mp.find(board[i][j]) != mp.end()) {
                return 0;
            }
            mp[board[i][j]] = 'y';
        }
        mp.clear();
    }
    return 1;
}

int checkColumns(vector<vector<char>>& board) {
    unordered_map<char, char> mp;
    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 9; j++) {
            if(board[j][i] != '.' && mp.find(board[j][i]) != mp.end()) {
                return 0;
            }
            mp[board[j][i]] = 'y';
        }
        mp.clear();
    }
    return 1;
}

int checkBlocks(vector<vector<char>>& board) {
    for(int block = 0; block < 9; block++) {
        unordered_map<char, char> mp;
        for(int i = block/3*3; i < block/3*3+3; i++) {
            for(int j = block%3*3; j < block%3*3+3; j++) {
                if(board[i][j] != '.' && mp.find(board[i][j]) != mp.end()) {
                    return 0;
                }
                mp[board[i][j]] = 'y';
            }
        }
    }
    return 1;
}

bool isValidSudoku(vector<vector<char>>& board) {
    return checkBlocks(board) && checkColumns(board) && checkRows(board);
}

int main() {

    return 0;
}