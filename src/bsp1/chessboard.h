// chessboard.h
#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#include "chessman.h"
#include <array>
#include <memory>
#include <vector>
#include <string>

class Chessboard {
public:
    static const int BOARD_SIZE = 8;

    Chessboard();

    bool isGameOver() const;
    Chessman* getPieceAt(int x, int y) const;
    void setPieceAt(int x, int y, std::unique_ptr<Chessman> piece);
    int getSize() const;
    Color getCurrentPlayer() const;
    void switchPlayer();
    void initializeGame();
    void drawBoard() const;
    Chessboard(const Chessboard&) = delete;
    Chessboard& operator=(const Chessboard&) = delete;
    void markSelectedPiece(const std::string& position);
    void showPossibleMoves(const std::string& from);
    void markPossibleMoves(const std::vector<std::pair<int, int>>& moves);

private:
    Color currentPlayer;
    std::array<std::array<std::unique_ptr<Chessman>, BOARD_SIZE>, BOARD_SIZE> board;
    bool checkForEssentialPieceLoss() const;
    std::pair<int, int> selectedPiecePosition;
    std::vector<std::pair<int, int>> highlightedMoves;
};

#endif
