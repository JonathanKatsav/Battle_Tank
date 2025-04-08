#pragma once
#include "utils.h"


class Menu {
public:
    static bool useColor;
    static bool useEmojis;

   /* void winningMenu(int playerScore) {
        displayMenu("You Won!!!!!", "Your Score is: " + std::to_string(playerScore), "Press any key to return to the main menu");
    }*/

    void pausingGameMenu() {
        displayMenu("Game paused", "Press ESC again to continue", "Press X key to go back to the main menu");
    }

    void exitGameMenu() {
        displayMenu("Thanks for playing!", "", "Press any key to exit");
    }

    void deathMenu(int playerWon, int playerLost) {
        displayMenu("Player number " + std::to_string(playerLost) + " died", "Player number " + std::to_string(playerWon) + " won", "Press any key to return to the main menu");
    }

    void showInstructionsMenu();
    void startingMenu();
    void showInvalidBoardMessage(const std::string& fileName, const std::string& errorMessage = "");
    void mapChooser(std::vector<std::string> boardFilesNames);
    void showNoValidBoardsMessage();

private:
    void displayMenu(const std::string& line1, const std::string& line2, const std::string& line3);
};