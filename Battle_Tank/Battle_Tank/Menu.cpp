#include "Menu.h"
#include "utils.h"
#include <vector>

bool Menu::useColor = true;
bool Menu::useEmojis = true;


void Menu::showInstructionsMenu() {
    gotoxy(20, 6);
    std::cout << "=========================================" << std::endl;
    gotoxy(20, 7);
    std::cout << "               Instructions              " << std::endl;
    gotoxy(20, 8);
    std::cout << "=========================================" << std::endl;
    gotoxy(20, 9);
    std::cout << " Use the following keys to control the tanks:" << std::endl;
    gotoxy(20, 10);
    std::cout << "  W / I - Shoot                            " << std::endl;
    gotoxy(20, 11);
    std::cout << "  E / O - RIGHT track forward                          " << std::endl;
    gotoxy(20, 12);
    std::cout << "  D / L - RIGHT track backwards                          " << std::endl;
    gotoxy(20, 13);
    std::cout << "  Q / U - LEFT track forward                         " << std::endl;
    gotoxy(20, 14);
    std::cout << "  A / J - LEFT track backwards                            " << std::endl;
    gotoxy(20, 15);
    std::cout << "  S / K - Stay             " << std::endl;
    gotoxy(20, 16);
    std::cout << "  Press ESC to pause the game             " << std::endl;
    gotoxy(20, 17);
    std::cout << "=========================================" << std::endl;
    gotoxy(20, 18);
    std::cout << "Press any key to return to the main menu " << std::endl;
}

void Menu::startingMenu() {
    gotoxy(25, 7);
    std::cout << "==============================" << std::endl;
    gotoxy(25, 8);
    std::cout << "     Welcome to the Game!     " << std::endl;
    gotoxy(25, 9);
    std::cout << "==============================" << std::endl;
    gotoxy(25, 10);
    std::cout << "  Press 1 to start the game   " << std::endl;
    gotoxy(25, 11);
    std::cout << "  Press 6 to Disable/Enable colors" << std::endl;
    gotoxy(25, 12);
    std::cout << "  Press 8 for instructions" << std::endl;
    gotoxy(25, 13);
    std::cout << "  Press 9 to exit    " << std::endl;
    gotoxy(25, 14);
    std::cout << "============================= " << std::endl;
}

void Menu::showInvalidBoardMessage(const std::string& fileName, const std::string& errorMessage) {
    clearConsole();
    gotoxy(15, 12);
    std::cout << "Invalid board file: " << fileName << std::endl;

    if (!errorMessage.empty()) {
        gotoxy(16, 12);
        std::cout << errorMessage << std::endl;
    }
    Sleep(2000); // Pause for 2 seconds to allow the user to read the message
}

void Menu::mapChooser(std::vector<std::string> boardFilesNames) {
    clearConsole();
    gotoxy(15, 6);
    std::cout << "=============================" << std::endl;
    gotoxy(15, 7);
    std::cout << "Choose a board file to load:" << std::endl;
    gotoxy(15, 8);
    std::cout << "=============================" << std::endl;
    for (size_t i = 0; i < boardFilesNames.size(); ++i) {
        gotoxy(15, 9 + i * 2); // Adjusted to provide more space between lines
        std::cout << i + 1 << ". " << boardFilesNames[i] << std::endl;
    }
    gotoxy(15, 9 + boardFilesNames.size() * 2); // Adjusted to match the new spacing
    std::cout << "=============================" << std::endl;
    gotoxy(15, 12 + boardFilesNames.size() * 2);
    std::cout << "press the number of the board file you'd like to load" << std::endl;
}

void Menu::showNoValidBoardsMessage() {
    clearConsole();
    gotoxy(15, 12);
    std::cout << "=============================" << std::endl;
    gotoxy(15, 13);
    std::cout << "       No valid boards       " << std::endl;
    gotoxy(15, 14);
    std::cout << "=============================" << std::endl;
    gotoxy(15, 15);
    std::cout << "Press any key to return to the main menu" << std::endl;
}

// Private functions

void Menu::displayMenu(const std::string& line1, const std::string& line2, const std::string& line3) {
    gotoxy(22, 10);
    std::cout << "========================================" << std::endl;
    gotoxy(22, 11);
    std::cout << "              " << line1 << "              " << std::endl;
    gotoxy(22, 12);
    std::cout << "           " << line2 << "          " << std::endl;
    gotoxy(22, 13);
    std::cout << "========================================" << std::endl;
    gotoxy(22, 14);
    std::cout << line3 << std::endl;
}