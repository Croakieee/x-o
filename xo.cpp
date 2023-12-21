#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Глобальные переменные
char board[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
char currentPlayer = 'X';

// Функция для отрисовки доски
void drawBoard() {
    cout << "  1 2 3\n";
    for (int i = 0; i < 3; ++i) {
        cout << i + 1 << ' ';
        for (int j = 0; j < 3; ++j) {
            cout << board[i][j];
            if (j < 2) cout << '|';
        }
        cout << '\n';
        if (i < 2) cout << "  -----\n";
    }
    cout << "\n";
}

// Функция для смены текущего игрока
void switchPlayer() {
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}

// Функция для проверки на выигрыш
bool checkWin() {
    // Проверка по горизонтали и вертикали
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer)
            return true;
        if (board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer)
            return true;
    }

    // Проверка по диагоналям
    if (board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer)
        return true;
    if (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer)
        return true;

    return false;
}

// Функция для проверки на ничью
bool checkTie() {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] == ' ')
                return false; // На доске есть свободные клетки, игра не окончена
        }
    }
    return true; // На доске нет свободных клеток, ничья
}

// Функция для хода компьютера
void computerMove() {
    srand(static_cast<unsigned int>(time(nullptr)));
    int row, col;
    do {
        row = rand() % 3;
        col = rand() % 3;
    } while (board[row][col] != ' '); // Пока не найдена свободная клетка
    board[row][col] = currentPlayer;
}

int main() {
    cout << "Крестики-нолики\n";
    drawBoard();

    // Игровой цикл
    while (true) {
        // Ход игрока
        int row, col;
        cout << "Ход игрока " << currentPlayer << "\n";
        cout << "Введите номер строки (1-3): ";
        cin >> row;
        cout << "Введите номер столбца (1-3): ";
        cin >> col;

        // Проверка на корректность ввода
        if (row < 1 || row > 3 || col < 1 || col > 3 || board[row - 1][col - 1] != ' ') {
            cout << "Некорректный ход, попробуйте снова.\n";
            continue;
        }

        board[row - 1][col - 1] = currentPlayer;
        drawBoard();

        // Проверка на выигрыш
        if (checkWin()) {
            cout << "Игрок " << currentPlayer << " победил!\n";
            break;
        }

        // Проверка на ничью
        if (checkTie()) {
            cout << "Ничья!\n";
            break;
        }

        // Смена игрока
        switchPlayer();

        // Ход компьютера
        cout << "Ход компьютера (" << currentPlayer << ")\n";
        computerMove();
        drawBoard();

        // Проверка на выигрыш
        if (checkWin()) {
            cout << "Компьютер победил!\n";
            break;
        }

        // Проверка на ничью
        if (checkTie()) {
            cout << "Ничья!\n";
            break;
        }

        // Смена игрока
        switchPlayer();
    }

    return 0;
}
