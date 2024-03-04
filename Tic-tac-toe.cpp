/* CODSOFT Interships
   Task - 5: Tic Tac Toe 
   Authored by Rishika Thakur
   */
#include <iostream>
#include <vector>

using namespace std;

// Function to draw the Tic-Tac-Toe board
void drawBoard(const vector<vector<char>>& board) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << board[i][j];
            if (j < 2)
                cout << " | ";
        }
        cout << endl;
        if (i < 2)
            cout << "---------" << endl;
    }
}

// Function to check if a player has won
bool checkWin(const vector<vector<char>>& board, char player) {
    // Check rows and columns
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
            return true;
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player)
            return true;
    }
    // Check diagonals
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player))
        return true;
    return false;
}

// Function to check if the board is full
bool boardFull(const vector<vector<char>>& board) {
    for (const auto& row : board) {
        for (char cell : row) {
            if (cell == ' ')
                return false;
        }
    }
    return true;
}

// Function to play the game
void playGame() {
    vector<vector<char>> board(3, vector<char>(3, ' '));
    char currentPlayer = 'X';
    bool gameWon = false;

    while (!gameWon && !boardFull(board)) {
        cout << "Player " << currentPlayer << "'s turn. Enter row and column (0-2): ";
        int row, col;
        cin >> row >> col;

        // Check if the cell is empty and the input is within range
        if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ') {
            board[row][col] = currentPlayer;
            drawBoard(board);
            gameWon = checkWin(board, currentPlayer);
            if (!gameWon)
                currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        } else {
            cout << "Invalid move. Try again." << endl;
        }
    }

    if (gameWon) {
        cout << "Player " << currentPlayer << " wins!" << endl;
    } else {
        cout << "It's a draw!" << endl;
    }
}

int main() {
    cout << "Welcome to Tic-Tac-Toe!" << endl;
    playGame();
    return 0;
}

