// chessboard.cpp
#include <iostream>
#include "chessboard.h"
#include "chessman.h"
#include "bishop.h"
#include "king.h"
#include "knight.h"
#include "pawn.h"
#include "queen.h"
#include "rook.h"

Chessboard::Chessboard() : currentPlayer(Color::WHITE) {
    for (auto& row : board) {
        for (auto& cell : row) {
            cell.reset(nullptr);
        }
    }
}

bool Chessboard::isGameOver() const {
    return checkForEssentialPieceLoss();
}

Chessman* Chessboard::getPieceAt(int x, int y) const {
    if (x >= 0 && x < BOARD_SIZE && y >= 0 && y < BOARD_SIZE) {
        return board[x][y].get();
    }
    return nullptr;
}



void Chessboard::setPieceAt(int x, int y, std::unique_ptr<Chessman> piece) {
    if (x >= 0 && x < BOARD_SIZE && y >= 0 && y < BOARD_SIZE) {
        board[x][y] = std::move(piece);
    }
}

int Chessboard::getSize() const {
    return BOARD_SIZE;
}

Color Chessboard::getCurrentPlayer() const {
    return currentPlayer;
}

void Chessboard::switchPlayer() {
    currentPlayer = currentPlayer == Color::WHITE ? Color::BLACK : Color::WHITE;
}

bool Chessboard::checkForEssentialPieceLoss() const {
    for (const auto& row : board) {
        for (const auto& piece : row) {
            if (piece && piece->isEssential()) {
                return false;
            }
        }
    }
    return true;
}

void Chessboard::initializeGame() {
    // Setzt alle Figuren auf ihre Startpositionen
    // Weiß
    board[0][0] = std::make_unique<Rook>(Color::WHITE);
    board[0][1] = std::make_unique<Knight>(Color::WHITE);
    board[0][2] = std::make_unique<Bishop>(Color::WHITE);
    board[0][3] = std::make_unique<Queen>(Color::WHITE);
    board[0][4] = std::make_unique<King>(Color::WHITE);
    board[0][5] = std::make_unique<Bishop>(Color::WHITE);
    board[0][6] = std::make_unique<Knight>(Color::WHITE);
    board[0][7] = std::make_unique<Rook>(Color::WHITE);
    for (int i = 0; i < BOARD_SIZE; ++i) {
        board[1][i] = std::make_unique<Pawn>(Color::WHITE);
    }

    // Schwarz
    board[7][0] = std::make_unique<Rook>(Color::BLACK);
    board[7][1] = std::make_unique<Knight>(Color::BLACK);
    board[7][2] = std::make_unique<Bishop>(Color::BLACK);
    board[7][3] = std::make_unique<Queen>(Color::BLACK);
    board[7][4] = std::make_unique<King>(Color::BLACK);
    board[7][5] = std::make_unique<Bishop>(Color::BLACK);
    board[7][6] = std::make_unique<Knight>(Color::BLACK);
    board[7][7] = std::make_unique<Rook>(Color::BLACK);
    for (int i = 0; i < BOARD_SIZE; ++i) {
        board[6][i] = std::make_unique<Pawn>(Color::BLACK);
    }

    // Rest des Bretts mit nullptr füllen
    for (int y = 2; y <= 5; ++y) {
        for (int x = 0; x < BOARD_SIZE; ++x) {
            board[y][x] = nullptr;
        }
    }

    // Setzen des aktuellen Spielers auf Weiß, da Weiß immer das Spiel beginnt
    currentPlayer = Color::WHITE;
}


void Chessboard::drawBoard() const {
    // Zeichne die Spaltenbuchstaben
    std::cout << "    a b c d e f g h  " << std::endl;
    const char* topBottomBorder = "  +-----------------+";
    const char* sideBorder = "|";

    // Zeichne den oberen Rand
    std::cout << topBottomBorder << std::endl;

    // Zeichne das Schachbrett
    for (int y = BOARD_SIZE - 1; y >= 0; --y) {
        std::cout << y + 1 << " "; // Zeilennummer am linken Rand
        std::cout << sideBorder << " "; // Linker Rand des Bretts
        for (int x = 0; x < BOARD_SIZE; ++x) {
            if (board[y][x]) {
                std::cout << board[y][x]->getSymbol() << " "; // Figur zeichnen
            }
            else {
                // Abwechselndes Muster für leere Felder
                std::cout << (((x + y) % 2 == 0) ? '.' : '*') << " ";
            }
        }
        std::cout << sideBorder << " " << y + 1; // Zeilennummer am rechten Rand
        std::cout << std::endl;
    }

    // Zeichne den unteren Rand
    std::cout << topBottomBorder << std::endl;

    // Zeichne die Spaltenbuchstaben
    std::cout << "    a b c d e f g h  " << std::endl;
}

void Chessboard::markSelectedPiece(const std::string& position) {
    // Umwandeln der Position (z.B. "e2") in Array-Indizes
    int x = position[0] - 'a';
    int y = position[1] - '1';

    // Prüfen, ob die Koordinaten innerhalb des Bretts liegen
    if (x < 0 || x >= BOARD_SIZE || y < 0 || y >= BOARD_SIZE) {
        return; // Ungültige Position, keine Aktion
    }

    // Prüfen, ob an der Position eine Figur des aktuellen Spielers steht
    Chessman* piece = getPieceAt(x, y);
    if (piece && piece->getColor() == currentPlayer) {
        selectedPiecePosition = { x, y }; // Markiere die Figur als ausgewählt
        highlightedMoves.clear(); // Bereite vor, um die möglichen Züge zu speichern

        // Gehe durch das Brett und füge gültige Züge zu highlightedMoves hinzu
        for (int i = 0; i < BOARD_SIZE; ++i) {
            for (int j = 0; j < BOARD_SIZE; ++j) {
                if (piece->canMoveTo(x, y, i, j)) {
                    highlightedMoves.push_back({ i, j });
                }
            }
        }
    }
}
