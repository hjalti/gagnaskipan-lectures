#include <iostream>
#include <vector>

using namespace std;

const int SIZE = 8;

void print(vector<int>& board) {
    char p;
    for(int i = 2 * SIZE; i >= 0; i--) {
        for(int j = 0; j < 2 * SIZE + 1; j++ ) {
            if(i % 2 == 0 && j % 2 == 0) {
                p = '+';
            } else if(i % 2 == 0 && j % 2 == 1) {
                p = '-';
            } else if(i % 2 == 1 && j % 2 == 0) {
                p = '|';
            } else if(board[j / 2] == i / 2) {
                p = 'Q';
            } else {
                p = ' ';
            }
            cout << p;
        }
        cout << endl;
    }
}

bool valid(vector<int>& board, int pos) {
    for(int i = 0; i < pos; i++) {
        if(board[i] == board[pos]) {
            return false;
        }
        if(board[i] - i == board[pos] - pos) {
            return false;
        }
        if(board[i] + i == board[pos] + pos) {
            return false;
        }
    }
    return true;
}

void queens(int curr, vector<int>& board) {
    if(curr == 8) {
        print(board);
        cout << endl;
    }
    for(int i = 0; i < SIZE; i++) {
        board[curr] = i;
        if(valid(board, curr)) {
            queens(curr + 1, board);
        }
    }
}

int main()
{
    vector<int> board(8);
    queens(0, board);
    return 0;
}
