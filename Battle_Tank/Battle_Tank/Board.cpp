#include "Board.h"
#include "Entity.h"
#include "Tank.h"

void Board::reset() {
    for (size_t i = 0; i < screenY; i++) {
        memcpy(currentBoard[i], originalBoard[i], screenX + 1);
    }
}

void Board::print() const {
    system("cls");
    changeColor(false, true);
    for (size_t i = 0; i < screenY; ++i) {
        for (size_t j = 0; j < screenX; ++j) {
            char c = originalBoard[i][j];
            printToScreen(j, i, c, true);
        }
    }
    changeColor(true);
}

bool Board::load(const std::string& filename, Tank& player1, Tank& player2) {
    Menu menu;
    std::ifstream screen_file(filename);

    if (!screen_file.is_open()) {
        return false;
    }

    int curr_row = 0;
    std::string line;

    while (std::getline(screen_file, line) && curr_row < screenY) {
        if (line.length() > screenX) {
            line = line.substr(0, screenX);
        }

        strncpy_s(originalBoard[curr_row], line.c_str(), screenX);
        originalBoard[curr_row][screenX] = '\0';

        for (size_t curr_col = 0; curr_col < line.length(); ++curr_col) {
            char c = line[curr_col];
            switch (c) {
            case playerChar:
                if (!isTherePlayer1) {
                    player1.setStartingPosition(curr_col, curr_row);
                    originalBoard[curr_row][curr_col] = emptyChar;
                    isTherePlayer1 = true;
                    break;
                }
                else if (!isTherePlayer2) {
                    player2.setStartingPosition(curr_col, curr_row);
                    originalBoard[curr_row][curr_col] = emptyChar;
                    isTherePlayer2 = true;
                    break;
                }
                else {
                    menu.showInvalidBoardMessage(filename, "Error: Multiple Mario characters found on the board.");
                    return false;
                }
            default:
                originalBoard[curr_row][curr_col] = c;
                break;
            }

        }

        for (size_t curr_col = line.length(); curr_col < screenX; ++curr_col) {
            originalBoard[curr_row][curr_col] = emptyChar;
        }

        ++curr_row;
    }

    for (; curr_row < screenY; ++curr_row) {
        std::fill_n(originalBoard[curr_row], screenX, emptyChar);
        originalBoard[curr_row][screenX] = '\0';
    }

    std::fill_n(originalBoard[0], screenX, strongWall);
    originalBoard[0][screenX] = '\0';

    std::fill_n(originalBoard[screenY - 1], screenX, strongWall);
    originalBoard[screenY - 1][screenX] = '\0';

    reset();
    

    if (!isTherePlayer2)
        menu.showInvalidBoardMessage(filename, "Error: not enough players on the board");

    return isTherePlayer2;
}
