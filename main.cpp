#include <iostream>
#include <vector>

using namespace std;

class TicTacToe {
public:
    TicTacToe() {
        board = vector<vector<char>>(3, vector<char>(3, ' '));
        currentPlayer = 'X';
    }

    void playGame() {
        bool playAgain = true;
        while (playAgain) {
            resetBoard();
            while (true) {
                displayBoard();
                playerMove();
                if (checkWin()) {
                    displayBoard();
                    cout << "Player " << currentPlayer << " wins!" << endl;
                    break;
                } else if (checkDraw()) {
                    displayBoard();
                    cout << "The game is a draw!" << endl;
                    break;
                }
                switchPlayer();
            }
            playAgain = askPlayAgain();
        }
    }

private:
    vector<vector<char>> board;
    char currentPlayer;

    void resetBoard() {
        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 3; ++j)
                board[i][j] = ' ';
        currentPlayer = 'X';
    }

    void displayBoard() {
        cout << "  0 1 2" << endl;
        for (int i = 0; i < 3; ++i) {
            cout << i << " ";
            for (int j = 0; j < 3; ++j) {
                cout << board[i][j];
                if (j < 2) cout << "|";
            }
            cout << endl;
            if (i < 2) cout << "  -----" << endl;
        }
    }

    void playerMove() {
        int row, col;
        while (true) {
            cout << "Player " << currentPlayer << ", enter your move (row and column): ";
            cin >> row >> col;
            if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ') {
                board[row][col] = currentPlayer;
                break;
            } else {
                cout << "This move is not valid. Try again." << endl;
            }
        }
    }

    bool checkWin() {
        // Check rows and columns
        for (int i = 0; i < 3; ++i) {
            if ((board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer) ||
                (board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer)) {
                return true;
            }
        }
        // Check diagonals
        if ((board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer) ||
            (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer)) {
            return true;
        }
        return false;
    }

    bool checkDraw() {
        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 3; ++j)
                if (board[i][j] == ' ')
                    return false;
        return true;
    }

    void switchPlayer() {
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    bool askPlayAgain() {
        char response;
        while (true) {
            cout << "Do you want to play again? (y/n): ";
            cin >> response;
            if (response == 'y' || response == 'Y')
                return true;
            else if (response == 'n' || response == 'N')
                return false;
            else
                cout << "Invalid response. Please enter 'y' or 'n'." << endl;
        }
    }
};

int main() {
    TicTacToe game;
    game.playGame();
    return 0;
}
