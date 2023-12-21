Project Overview

This project is a console-based Tic-Tac-Toe game written in the C++ programming language. The game features a simple text-based interface, win and tie checks, and the option to play against the computer.
How the Game Works

    The Board:
        The board is represented as three rows and three columns.

    Players:
        Player "X" and the computer (playing as "O").
        The player makes a move by entering the row and column numbers.

    Player's Move:
        The player inputs the row (1-3) and column (1-3) numbers to place their symbol ("X").
        Example input:

        mathematica

    Player X's move
    Enter the row number (1-3): 2
    Enter the column number (1-3): 3

Computer's Move:

    The computer makes a random move by choosing an available cell.
    Example:

    scss

        Computer's move (O)

    Win Check:
        If three symbols in a row, column, or diagonal, the player wins.
        If all cells are filled, and there's no win, it's a tie.

How to Run

    Ensure you have a C++ compiler installed, such as g++:
        Install g++ on Windows
        Install g++ on Linux

    Clone the repository:

    bash

git clone https://github.com/your-username/tic-tac-toe-cpp.git
cd tic-tac-toe-cpp

Compile and run the game:

bash

    g++ tic_tac_toe.cpp -o tic_tac_toe
    ./tic_tac_toe

    Follow the instructions in the console to make moves.

Additional Features

    Enhanced Interface:
        Improve the text-based interface for a more user-friendly interaction.

    Advanced Computer Move Algorithm:
        Implement a more intelligent algorithm for the computer's move selection.

    Multiplayer Mode:
        Add support for two players playing on the same device.

    Save and Load Game:
        Implement the ability to save the current game state and resume later.

    Menu and Settings:
        Add a menu for game settings, such as choosing player symbols.
