/*
 * tic tac toe
 *
 * M x N grid, for an arbitrary choice of M rows and N columns
 * K = the length of a "win"
 *
 */

#include <iostream>
#include <sstream>
#include <vector>
#include <unordered_map>

using namespace std;

enum class Piece {
    Empty,
    X,
    O
};

class Engine {
public:
    Engine(int rows, int cols, int winLength) : M{ rows }, N{ cols }, K{ winLength } {}

    /*
     * return true if and only if the move was made successfully
     */
    bool makeMove(int row, int col, Piece piece) {
        if (!isValidMove(row, col, piece))
            return false;
        A[row][col] = piece;
        last_row = row;
        last_col = col;
        return true;
    }

    /*
     * return true if and only if the move results in a win
     */
    bool isWin() {
        auto [i, j] = tie(last_row, last_col);
        return isRowWin(i, j) || isColWin(i, j) || isDiagWin(i, j);
    }

    bool isMoveAvailable() const {
        return A.size() < M * N;
    }

    string printBoard() {
        ostringstream os;
        for (auto i{ 0 }; i < M; ++i, os << endl)
            for (auto j{ 0 }; j < N; ++j)
                os << (A[i][j] == Piece::X ? "X" : A[i][j] == Piece::O ? "O" : ".");
        return os.str();
    }

private:

    /*
     * if memory consumption is an issue for large MxN, then we can use an associative array (ie. unordered_map) for storing the pieces for O(1) future lookups
     *
        using Pieces = vector<Piece>;
        using Board = vector<Pieces>;
        Board board;
     *
     *
     */
    int M, N, K;
    int last_row, last_col; // used for isWin() lookups
    using Board = unordered_map<int, unordered_map<int, Piece>>;
    Board A;

    bool isValidMove(int i, int j, Piece piece) {
        return 0 <= i && i < M && 0 <= j && j < N && A[i][j] == Piece::Empty && piece != Piece::Empty;
    }

    bool isRowWin(int row, int col) {
        auto target = A[row][col];
        auto len = 0;
        for (auto j = min(0, col - K); j < max(N, col + K); ++j) { // iterate through i-th row's j-th columns
            len = A[row][j] == target ? len + 1 : 0;
            if (len == K)
                return true;
        }
        return false;
    }

    bool isColWin(int row, int col) {
        auto target = A[row][col];
        auto len = 0;
        for (auto i = min(0, row - K); i < max(row + K, M); ++i) { // iterate through j-th col's i-th rows
            len = A[i][col] == target ? len + 1 : 0;
            if (len == K)
                return true;
        }
        return false;
    }

    bool isDiagWin(int row, int col) {
        auto target = A[row][col];
        // let i,j be the top-left most starting position of the diagonal
        {
            auto len = 0;
            auto offset = min(row, col);  // min(☝️ up, 👈 left)
            auto i = row - offset, // minus offset to go ☝️ up
                 j = col - offset;
            while (i < M && j < N) {
                len = A[i][j] == target ? len + 1 : 0;
                if (len == K)
                    return true;
                ++i, ++j; // down 👇, right 👉
            }
        }
        // let i,j be the bottom-left most starting position of the current diagonal
        {
            auto len = 0;
            auto offset = min(M - row, col); // min(👇 down, 👈 left)
            auto i = row + offset, // plus offset to go 👇 down
                 j = col - offset;
            while (0 <= i && j < N) {
                len = A[i][j] == target ? len + 1 : 0;
                if (len == K)
                    return true;
                --i, ++j; // ☝️ up, right 👉
            }
        }
    }
};

int main() {
    bool ok;
    int M, N, K;
    do {
        ok = true;
        cout << "row: "; cin >> M;
        cout << "col: "; cin >> N;
        cout << "win: "; cin >> K;
        if (M <= 0 || N <= 0 || K <= 0 || M < K || N < K)
            ok = false, cout << "invalid input, try again"; // FIXME: provide better reason for failure
    } while (!ok);
    Engine engine{ M, N, K };
    auto piece = Piece::X;
    while (engine.isMoveAvailable()) {
        do {
            int row, col;
            cout << "it is " << (piece == Piece::X ? "X" : "O") << "'s turn (enter row and col): ";
            cin >> row >> col;
            ok = engine.makeMove(row, col, piece);
            if (!ok)
                cout << "invalid move, try again (enter row and col): ";
        } while (!ok);
        if (engine.isWin()) { // 🎯 target (exit condition)
            cout << endl << (piece == Piece::X ? "X" : "O") << " won the game!" << endl
                 << "Better luck next time " << (piece != Piece::X ? "X" : "O") << "...  ¯\\_(ツ)_/¯  " << endl;

            break;
        } else {
            cout << engine.printBoard();
        }
        piece = piece == Piece::X ? Piece::O : Piece::X; // round robin, every other turn
    }
    return 0;
}
