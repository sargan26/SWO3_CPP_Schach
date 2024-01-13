#include "chessboard.h"
#include "chessman.h"
#include "bishop.h"
#include "king.h"
#include "knight.h"
#include "pawn.h"
#include "queen.h"
#include "rook.h"
#include <iostream>
#include <string>

bool isValidPosition(const std::string& position) {
    if (position.length() != 2) return false;
    char col = position[0];
    char row = position[1];
    return (col >= 'a' && col <= 'h') && (row >= '1' && row <= '8');
}

std::string getUserInput(const std::string& prompt) {
    std::string input;
    while (true) {
        std::cout << prompt;
        std::getline(std::cin, input);
        if (isValidPosition(input)) {
            return input;
        }
        else {
            std::cout << "Ungueltige Eingabe. Bitte geben Sie eine Position wie 'a2' ein.\n";
        }
    }
}

int main() {
    Chessboard board;
    board.initializeGame();
    board.drawBoard();

    while (!board.isGameOver()) {
        std::cout << "Aktueller Spieler: " << (board.getCurrentPlayer() == Color::WHITE ? "Weiss" : "Schwarz") << "\n";

        std::string from = getUserInput("Wählen Sie eine Figur aus (z.B. e2): ");
        // TODO: Markiere die gewählte Figur und zeige mögliche Züge an
        // TODO: Zeichnet das Brett mit markierten möglichen Zügen

        std::string to = getUserInput("Wohin moechten Sie ziehen? (z.B. e4): ");
        // TODO: Führe den Zug aus

        board.drawBoard();  
        board.switchPlayer(); 
    }

    std::cout << "Spiel beendet. " << (board.getCurrentPlayer() == Color::WHITE ? "Weiss" : "Schwarz") << " gewinnt!\n";
    return 0;
}
