#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool dfs(vector<vector<char>> &board, string &word, int row, int col, int index);

bool exist(vector<vector<char>> &board, string word)
{
    if(word.empty()) return true;
    if (board.empty() || board[0].empty()) return false;

    int rows = board.size(), cols = board[0].size();

    //Iterate through each letter in the board

    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            if(board[i][j] == word[0] && dfs(board, word, i, j, 0)) return true;
        }
    }

    return false;
}

bool dfs(vector<vector<char>> &board, string &word, int row, int col, int index)
{
    if(index == word.length()) return true;

    if(row < 0 || row >= board.size() || col < 0 || col >= board[0].size() || board[row][col] != word[index]) return false;


    char temp = board[row][col];
    board[row][col] = '*';

    bool found = dfs(board, word, row + 1, col, index + 1) || dfs(board, word, row - 1, col, index + 1) ||
                 dfs(board, word, row, col + 1, index + 1) || dfs(board, word, row , col - 1, index + 1);

    board[row][col] = temp;

    return found;
}

int main()
{
    vector<vector<char>> board = 
    {
        {'A','B','C','E'},
        {'S','F','C','S'},
        {'A','D','E','E'}
    };

    string word = "ABCCX";

    if(exist(board, word)) cout << "Found!" << endl;
    else cout << "Not found." << endl;

    return 0;
}